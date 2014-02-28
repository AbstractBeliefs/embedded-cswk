embedded-cswk
=============

My Physical Computing coursework, Year 2 Semester 2.
This will be an interactive tabletop which can run a variety of "apps".

Device notes:
-------------
This is primarily built for the ATmega328P, and is developed using the Arduino Duemilanove as a dev board.

Fuse     | Setting
---------|--------
BOOTRST  | **ENABLED**
BOOTSZ   | **00** (2048 words)
BODLEVEL | **101** (2.7V BOD)


Bootloader:
-----------
This project will read a binary from an SD card and load it onto the device, much like game carts.

Additionally, you'll need to relocate the .text section of the bootloader to 0x3800 (word address) or 0x7000 (byte address) assuming you are using BOOTSZ=00. Season your linker options to taste.

TTCore:
-------
Table Top Core is a library that provides common functions to access the tables hardware and automate some common activities.
