#include <avr/io.h>

#define LED1 PINB0
#define LED2 PINB1
#define LED3 PINB2

#define BUTTON PINA1
#define POWER PINA0

int main() {
  DDRB |= (1 << LED1) | (1 << LED2) | ( 1 << LED3);
  DDRA |= (1 << POWER);
  PORTA &= ~(1 << BUTTON);

  PORTB = 0;
  PORTA |= (1 << BUTTON);
  PORTA &= ~(1 << POWER);

  int mode = 0;

  while(1) {
    if (!(PINA & (1<< POWER))) {
      _delay_ms(20);

      if (!(PINA & (1<< POWER))) {
        mode += 1;

        while (PINA & (1<< POWER)) {
          _delay_ms(20);
        }
      }
    }

    switch (mode) {
      case 0: {
        PORTB = (1 << LED1);
        break;
      }
      case 1: {
        PORTB = (1 << LED2);
        break;
      }
      case 2: {
        PORTB = (1 << LED3);
        break;
      }
      case 3: {
        PORTB = 0;
        PORTA |= (1 << POWER);
        mode = 0;
        break;
      }
    }
  }

  return 0;
}
