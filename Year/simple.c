#include <reg51.h> // Header file for 89C52

// Define segment LEDs
sbit LED0 = P0^0;
sbit LED1 = P0^1;
sbit LED2 = P0^2;
sbit LED3 = P0^3;
sbit LED4 = P0^4;
sbit LED5 = P0^5;
sbit LED6 = P0^6;
sbit LED7 = P0^7;

// Define control pins for the 7-segment displays
sbit CON0 = P2^0;
sbit CON1 = P2^1;
sbit CON2 = P2^2;
sbit CON3 = P2^3;

// Digit patterns for a common cathode 7-segment display (0-9)
unsigned char digits[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F// 9
	};

// Delay function
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1275; j++);
    }
}

// Function to display a digit on a specific 7-segment display
void display_digit(unsigned char digit, unsigned char position) {
    // Clear all control pins
    CON0 = 0;
    CON1 = 0;
    CON2 = 0;
    CON3 = 0;

    // Output the segment data
    P0 = digits[digit];

    // Activate the selected display
switch (position) {
        case 0: CON0 = 1; break;
        case 1: CON1 = 1; break;
        case 2: CON2 = 1; break;
        case 3: CON3 = 1; break;
        default: break;
    }
				

    // Small delay for persistence
    delay_ms(1);
}

void main() {
    unsigned char year[] = {2, 0, 2, 5}; // Digits of the year 2025

    while (1) {
        // Display each digit on the corresponding 7-segment display
        display_digit(year[0], 0); // Display '2' on the first display
        display_digit(year[1], 1); // Display '0' on the second display
        display_digit(year[2], 2); // Display '2' on the third display
        display_digit(year[3], 3); // Display '5' on the fourth display
    }
}