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
sbit CON0 = P2^2;
sbit CON1 = P2^3;
sbit CON2 = P2^4;
sbit CON3 = P2^5;
sbit CON4 = P2^6;
sbit CON5 = P2^7;

		unsigned int noOfTimes = 20;
		unsigned char partOfDay = 11;
    unsigned char time[] = {2, 7,0};

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
    0x6F,// 9
		0x40, //:,index 10
		0x77, //index 11 ,A
		0x73 //index 12,P
};

void delay_three_ms(){
	TH1=0xF4;
	TL1=0x48;
	TR1=1;
	while (TF1 != 0);
	TR1=0;
	TF1=0;
}

// Delay function
void delay_ms() {//default 50ms
	TL0 =0x00;
	TH0 =0x4c;
	TR0 =1;
}

void isr_timer() interrupt 1 {
		delay_ms();
		if(noOfTimes == 0) {
        noOfTimes = 20;
        time[2]++;
        if (time[2] < 60) return;
        time[1]++;
        time[2] = 0;
        if (time[1] < 60) return;
        time[1] = 0;
				time[0]++;
				if(time[0]<12) return;
				time[0]=0;
				partOfDay = partOfDay==11 ? 12 :11;
    }else{
        noOfTimes--;
        return;
		}
}


void init(){
	IE = 0x82;
	TMOD =0x01;
	delay_ms();
}

// Function to display a digit on a specific 7-segment display
void display_digit(unsigned char digit, unsigned char position) {
    // Clear all control pins
    CON0 = 0;
    CON1 = 0;
    CON2 = 0;
    CON3 = 0;
		CON4 = 0;
		CON5 = 0;

    // Output the segment data
    P0 = digits[digit];

    // Activate the selected display
    if (position == 0) CON0 = 1;
    if (position == 1) CON1 = 1;
    if (position == 2) CON2 = 1;
    if (position == 3) CON3 = 1;
		if (position == 4) CON4 = 1;
		if (position == 5) CON5 = 1;
    
		delay_three_ms();
}

void main() {
	int i = 80;
	init();
    while (1) {
        display_digit((time[0]/10), 0); 
        display_digit((time[0] % 10), 1); 
				display_digit(10, 2);
        display_digit((time[1]/10), 3); 
        display_digit((time[1]%10), 4);
				display_digit(partOfDay,5);
    }
}