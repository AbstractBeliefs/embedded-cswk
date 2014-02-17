embedded-cswk
=============

My Physical Computing coursework, Year 2 Semester 2.

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
