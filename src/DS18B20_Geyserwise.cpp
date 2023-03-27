/*
 *    Converts a reading from an NTC thermistor to a temperature reading
 *    on a simulated DS18B20. Intended for use with e.g. Sonoff THR320
 *    which only has a 1-wire interface for sensors.
 *
 *    Tested with:
 *    - THR320 running ESPHome as Master, ATTiny85@8MHz as Slave
 *
 *    NOTE: Make sure to "Flash bootloader" on a new chip, to be sure
 *    the fuses are correctly set. Alternatively, the following might
 *    also work (using Arduino as ISP):
 *
 *    avrdude -P /dev/cu.usbmodem2101 -p attiny85 -c stk500v1 -U lfuse:w:0xe2:m
 *
 *    and verify with:
 *
 *    avrdude -P /dev/cu.usbmodem2101 -p attiny85 -c stk500v1 -U lfuse:r:-:h
 *
 *    Should return 0xe2
 *
 */

#include "OneWireHub.h"
#include "DS18B20.h"
#include <avr/wdt.h>
#include "thermistor_table.h"

#if defined (__AVR_ATtiny85__)
constexpr uint8_t pin_led       { PB4 };
constexpr uint8_t pin_onewire   { PB3 };
#else
constexpr uint8_t pin_led       { 8 };
constexpr uint8_t pin_onewire   { 1 };
#endif

auto hub    = OneWireHub(pin_onewire);

auto ds18b20 = DS18B20(0x28, 0x00, 0x55, 0x44, 0x33, 0x22, 0x11);

// which analog pin to connect
constexpr uint8_t pin_thermistor { A1 };

bool blinking(void);

int sample_adc(void);

void setup()
{
    wdt_reset();
    wdt_enable (WDTO_250MS);

    pinMode(pin_led, OUTPUT);
    pinMode(pin_thermistor, INPUT);

    // Setup OneWire
    hub.attach(ds18b20);

    wdt_reset();
}

void loop()
{
    wdt_reset();
    hub.poll();

    // Blink triggers the state-change
    if (blinking()) {
        int adc = sample_adc();
        int16_t temp = adc_to_temp(adc);
        ds18b20.setTemperature((int8_t) temp);
    }
}

bool blinking(void) {
    constexpr  uint32_t interval    = 500;          // interval at which to blink (milliseconds)
    static uint32_t nextMillis  = millis();     // will store next time LED will updated

    if (millis() > nextMillis)
    {
        nextMillis += interval;             // save the next time you blinked the LED
        static uint8_t ledState = LOW;      // ledState used to set the LED
        if (ledState == LOW)    ledState = HIGH;
        else                    ledState = LOW;
        digitalWrite(pin_led, ledState);
        return 1;
    }
    return 0;
}

int sample_adc() {
    constexpr uint8_t num_samples {5};
    static int samples[num_samples];
    static int sum = 0;

    sum = sum - samples[num_samples - 1];
    for (uint8_t i = num_samples - 1; i > 0; i--) {
        samples[i] = samples[i - 1];
    }
    samples[0] = analogRead(pin_thermistor);
    sum = sum + samples[0];
    return sum / num_samples;
}