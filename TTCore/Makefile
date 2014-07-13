CC = avr-gcc
AR = avr-ar
MCU = atmega328p

################
# TTCore
TTCore: TTCore.h TTCore.c
	$(CC) -c TTCore.c -o TTCore.o -mmcu=$(MCU)
	$(AR) rcs libTTCore.a TTCore.o

clean:
	rm -f *.o
	rm -f *.a

