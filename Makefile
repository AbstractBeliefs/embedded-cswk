CC = avr-gcc
AR = avr-ar
MCU = atmega328p

all:
	cd TTCore; make

clean:
	cd TTCore; make clean
