#include <reg51.h>
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1275; j++);
    }
}// Simple delay

sbit ON = P2^1;


void main() {
unsigned char digits[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char i;
P2=0;
ON = 1;

while (1) {
for (i = 0; i < 10; i++) {
P0 = digits[i];
delay(500);
}
}
}