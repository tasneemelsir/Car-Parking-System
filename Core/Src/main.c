#include "stm32f4xx.h"

void delay_loop(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 1000; i++) {
        __NOP();
    }
}

void display_number(uint8_t number) {
    switch (number) {
        case 0: GPIOB->ODR = 0x3F; break;
        case 1: GPIOB->ODR = 0x06; break;
        case 2: GPIOB->ODR = 0x5B; break;
        case 3: GPIOB->ODR = 0x4F; break;
        case 4: GPIOB->ODR = 0x66; break;
        case 5: GPIOB->ODR = 0x6D; break;
        case 6: GPIOB->ODR = 0x7D; break;
        case 7: GPIOB->ODR = 0x07; break;
        case 8: GPIOB->ODR = 0x7F; break;
        case 9: GPIOB->ODR = 0x6F; break;
        default: GPIOB->ODR = 0x00; break;
    }
}


// Global Variables
uint8_t number_hundreds = 0;
uint8_t number_tens = 0;
uint8_t number_ones = 5;
uint8_t is_full = 0;

void check_increment(void){
    if ((GPIOA->IDR & 0x40)==0) { // Check for increment button press
        GPIOA->BSRR = (1 << 4);
        number_hundreds = 0;
        number_tens = 0;
        number_ones = 1;
        is_full = 0;
    }
}

void display_digit(uint8_t digit) {
    uint16_t digit_values[4] = {0x0E, 0x0D, 0x0B, 0x07};
    if (digit >= 1 && digit <= 4) {
        GPIOC->ODR = digit_values[digit - 1];
    }
}

void display_letter(char letter) {
    switch (letter) {
        case 'F':GPIOB->ODR = 0x71; break;
        case 'U':GPIOB->ODR = 0x3E; break;
        case 'L':GPIOB->ODR = 0x38; break;
        default:
            break;
    }
}


int main(void) {
    RCC->AHB1ENR = 0x07;
    GPIOA->MODER = 0x101;
    GPIOA->OTYPER = 0x0;
    GPIOA->PUPDR = 0x1004;

    GPIOB->MODER = 0x5555;
    GPIOB->OTYPER = 0x0;

    GPIOC->MODER = 0x55;
    GPIOC->OTYPER = 0x0;

    uint8_t increment_pressed = 0;
    uint8_t decrement_pressed = 0;

    for (int i = 0; i <= 400 ; i++) {

        display_digit(2);
        display_number(9);
        delay_loop(5);

        display_digit(3);
        display_number(0);
        delay_loop(5);

        display_digit(4);
        display_number(6);
        delay_loop(5);


            }


    while (1) {
        // Check if number is FULL
        if (number_hundreds == 0 && number_tens == 0 && number_ones == 0) {
            is_full = 1;

           for (uint8_t i = 0; i < 200; i++) {
                GPIOA->BSRR = (1 << 0);
                display_digit(2);
                display_number(0);
                delay_loop(5);

                display_digit(3);
                display_number(0);
                delay_loop(5);

                display_digit(4);
                display_number(0);
                delay_loop(5);
            }

            GPIOA->BSRR = (1 << 16 );

            // Display FULL state
            while (is_full) {

                display_digit(1);
                display_letter('F');
                delay_loop(500);
                check_increment();

                display_digit(2);
                display_letter('U');
                delay_loop(500);
                check_increment();

                display_digit(3);
                display_letter('L');
                delay_loop(500);
                check_increment();

                display_digit(4);
                display_letter('L');
                delay_loop(500);
                check_increment();

                for (uint8_t blink_count = 0; blink_count < 3; blink_count++) {

                        for (uint8_t cycle = 0; cycle < 100; cycle++) {
                            display_digit(1);
                            display_letter('F');
                            delay_loop(5);

                            display_digit(2);
                            display_letter('U');
                            delay_loop(5);

                            display_digit(3);
                            display_letter('L');
                            delay_loop(5);

                            display_digit(4);
                            display_letter('L');
                            delay_loop(5);

                            check_increment();
                        }

                        GPIOB->ODR = 0x00;
                        delay_loop(500);
                        check_increment();
                    }
                }
        }






        else {
            // Display the current number
            display_digit(2);
            display_number(number_hundreds);
            delay_loop(5);

            display_digit(3);
            display_number(number_tens);
            delay_loop(5);

            display_digit(4);
            display_number(number_ones);
            delay_loop(5);





            // Decrement logic
            if ((GPIOA->IDR & 0x02)==0) {
                if (!decrement_pressed) {
                    decrement_pressed = 1;
                    GPIOA->BSRR = (1 << 0);
                    int total_number = (number_hundreds * 100) + (number_tens * 10) + number_ones;
                    total_number = (total_number > 0) ? total_number - 1 : 0;
                    number_hundreds = total_number / 100;
                    number_tens = (total_number / 10) % 10;
                    number_ones = total_number % 10;
                }
            } else {
                GPIOA->BSRR = (1 << 16);
                decrement_pressed = 0;
            }









            // Increment logic
            if ((GPIOA->IDR & 0x40)==0) {
                if (!increment_pressed) {
                    increment_pressed = 1;
                    GPIOA->BSRR = (1 << 4);
                    int total_number = (number_hundreds * 100) + (number_tens * 10) + number_ones;

                    total_number = (total_number <200) ? total_number + 1 : 200;

                        number_hundreds = total_number / 100;
                        number_tens = (total_number / 10) % 10;
                        number_ones = total_number % 10;

                }
            } else {
                increment_pressed = 0;
                GPIOA->BSRR = (1 << 20);
            }

        }






    }
}
