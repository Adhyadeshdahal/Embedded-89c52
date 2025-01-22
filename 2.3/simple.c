#include <reg51.h>
sbit ONE = P2^0;
sbit TWO = P2^1;
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1275; j++);
    }
}// Simple delay
void main() {
unsigned char fib[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
unsigned char digits[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char N = 10; // Assume N is 10 (can be set dynamically)
unsigned char i;
P2 = 0;
ONE = 1;
TWO = 1;
while (1) {
for (i = 0; i < N; i++) {
P0 = digits[fib[i]/10];
ONE = 1;
TWO = 0;
delay(10);
P0 = digits[fib[i]%10];
ONE = 0;
TWO = 1;
delay(10);
}
}
}