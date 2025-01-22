#include <reg51.h>
sbit ONE = P2^0;
sbit TWO = P2^1;
sbit THREE = P2^2;
sbit FOUR = P2^3;
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1275; j++);
    }
}// Simple delay

void main() {
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
unsigned char rolls[] = {3,4,5,6,7};
unsigned char N = 5; // Assume N is 10 (can be set dynamically)
unsigned char i;
P2 = 0;
ONE = 1;
TWO = 1;

while (1) {
for (i = 0; i < N; i++) {
P0 = digits[rolls[i]/1000];
ONE = 1;
TWO = 0;
THREE = 0;
FOUR = 0;
delay(10);
P0 = digits[rolls[i]/100];
ONE = 0;
TWO = 1;
THREE = 0;
FOUR = 0;
delay(10);
P0 = digits[rolls[i]/10];
ONE = 0;
TWO = 0;
THREE = 1;
FOUR = 0;
delay(10);
P0 = digits[rolls[i]%10];
ONE = 0;
TWO = 0;
THREE = 0;
FOUR = 1;
delay(30);
}
}
}