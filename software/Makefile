MCU = attiny461
F_CPU = 8000000UL

upload: main.bin
	avrdude -c usbasp -p $(MCU) -U main.bin

blink.bin: main.c
	avr-gcc main.c -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -o main.bin