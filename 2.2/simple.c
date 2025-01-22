#include <reg51.h>
sbit ONE = P2^1;
sbit TWO = P2^0;
void delay() {
unsigned int i;
for (i = 0; i < 30000; i++); // Simple delay
}
void main() {
unsigned char digits[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char i, j;
P2 = 0;
ONE = 0;
TWO = 0;
while (1) {
for (i = 0; i <= 2; i++) {
for (j = 0; j < 10; j++) {
if (i == 2 && j == 1) break;
P0 = digits[j];
TWO =0;
ONE = 1;
	
delay();
ONE = 0;
TWO = 1;
P0 = digits[i];
delay();
}
}
}
}