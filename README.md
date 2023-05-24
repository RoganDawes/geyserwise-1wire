# geyserwise-1wire
An ATTiny firmware for an interposer between an analog geyserwise thermostat, and a digital Sonoff relay

This firmware is intended to run on an ATTiny85 (or other hardware at your own risk!), and read the
analogue thermistor in a Geyserwise thermostat, and make the value available over the OneWire protocol
used by the Sonoff THR320 (and possibly other smart relays).
