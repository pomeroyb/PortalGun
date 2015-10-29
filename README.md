# PortalGun
Code to control a Portal Gun (From Rick and Morty)

##Libraries
Download and install the following libraries:

- [ClickEncoder](https://github.com/0xPIT/encoder)
- [Adafruit_GFX](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit_LEDBackpack](https://github.com/adafruit/Adafruit-LED-Backpack-Library)


## Pin Definitions
If you deviate from the following definitions, you will have to change the firmware to account for that.

| LED Display | Trinket Pro Pin |
|--------|--------|
|   SCL  |   A5   |
|	SDA  | 	 A4   |
|	GND  | 	 GND  |
|	Vcc  |   5V   |
|   Vi2c |   5V	  |


| Rotary Encoder | Trinket Pro Pin |
|--------|--------|
|    A    |   A1  |
|    B    |   A0  |
|   GND   |  GND  |
| Button  |   A2  |


| LED | Trinket Pro Pin |
|-------------|---------|
|Top Bulb     |    9    |
|Front Right  |    3    |
|Front Center |    5    |
|Front Left   |    6    |

## Installing Firmware
First, [set up the Arduino IDE according to Adafruit](https://learn.adafruit.com/introducing-pro-trinket/setting-up-arduino-ide). Connect your Trinket Pro and make sure the bootloader is running, then click upload.

## Button Behavior
The rotary encoder has a click button, and we can detect a single click, a double click, and a hold.
- Single Click : Wakes the Trinket Pro from low power mode
- Double Click : Reset to dimension C137
- Hold : Turn off LEDs and put the Trinket Pro into a low power mode.

##Installing SFX
The main branch doesn't have SFX support. Use the SFX branch to test this out (I found that the speaker inside the case was too quiet to hear.)