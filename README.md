# geyserwise-1wire
An ATTiny firmware for an interposer between an analog geyserwise thermostat, and a digital Sonoff relay

This firmware is intended to run on an ATTiny85 (or other hardware at your own risk!), and read the
analogue thermistor in a Geyserwise thermostat, and make the value available over the OneWire protocol
used by the Sonoff THR320 (and possibly other smart relays).

Pictures in the images/ directory show how I put it together, but please feel free to do it any way you
prefer!

![Top of ATTiny85](./images/attiny_top.jpg)

There is a ground "rail" running down the left hand side of the VeroBoard, and a Vcc "rail" running down
the right hand side. The bluey wire is the digital data line (in this case, connected to GPIO27 in the
Sonoff THR320). The resistor attached to the blue wire is the required pull up according to the OneWire
spec, but may not be strictly required since we are providing Vcc separately. The 10k resistor at the
bottom of the image is making a resistor divider, so that the ATTiny85 can read the resulting voltage.

![RJ9 connector to Sonoff THR320](./images/attiny_rj9.jpg)

This picture is intended to show the pinout for the RJ9 connector to the Sonoff THR320.

![Analogue connector to the GeyserWise thermostat](./images/attiny_analogue.jpg)

This picture shows the connector to the Geyserwise thermostat. It doesn't really matter which way around
it is connected, since a thermistor is not polarised.

![Underside of ATTiny85 on VeroBoard](./images/attiny_bottom.jpg)

This picture shows the jumpers from the ground rail to the ATTiny85 Gnd pin, and similarly for Vcc. It
also shows the cut tracks between the pins of the ATTiny85.
