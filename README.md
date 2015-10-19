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

| FX SoundBoard | Trinket Pro Pin |     Sound Effect   |
|---------------|-----------------|--------------------|
|    0          |   10            | Portal Shot        |
|    1          |   11            | Encoder Tick       |
|    2          |   12            | Reset Dimension    |
|    3          |   13            | Dimension Rollover |
|    4          |    4            |   Power Up         |
|	 5	        |    8            |  Power Down        |


| LED | Trinket Pro Pin |
|-------------|---------|
|Top Bulb     |    9    |
|Front Right  |    3    |
|Front Center |    5    |
|Front Left   |    6    |

## Installing Firmware
First, [set up the Arduino IDE according to Adafruit](https://learn.adafruit.com/introducing-pro-trinket/setting-up-arduino-ide). Connect your Trinket Pro and make sure the bootloader is running, then click upload.

##Installing SFX
You should be able to just connect the FX board to the computer, and drop the files in the "sfx" folder onto it. The files do follow a naming convention ([see here](https://learn.adafruit.com/adafruit-audio-fx-sound-board/triggering-audio)), so don't change the file names unless you know what you're doing.