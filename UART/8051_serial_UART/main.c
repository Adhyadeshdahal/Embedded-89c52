#include <reg51.h> // Header file for 89C52

//Control Signals for LCD
sbit RS = P1^7; //register select
sbit RW = P1^6; // read write select read = 1,write = 0
sbit EN = P1^5; // enable crystal display

#define LCD_PORT P2
#define CLEAR_SCREEN 0x01
#define FIRST_LINE 0x80 
#define SECOND_LINE 0xC0
#define INCREMENT_CURSOR 0x06
#define DECREMENT_CURSOR 0x04
#define SHIFT_CURSOR_LEFT 0x10

#define ENTER_KEY 0x0D
#define BACKSPACE_KEY 0x08

unsigned char i = 0;
// Delay function in milliseconds
void delay(unsigned int time)
{
  unsigned int i, j;
  for(i=0; i<time; i++)    
    for(j=0; j<1275; j++);
}

// Send Command to Lcd

void sendCommand(unsigned char command){
	LCD_PORT = command;
	RW = 0;
	RS = 0;
	EN = 1;
		delay(1);
	EN = 0;
	
}

// send data to lcd to display
void sendData(unsigned char dat){
	
	LCD_PORT = dat;
	RW = 0;
	RS = 1;
	EN = 1;
		delay(1);
	EN = 0;
	sendCommand(INCREMENT_CURSOR);
}

// initialize lcd
void init(){
	EA  = 1;
	ES = 1;
	sendCommand(0x38); //2 lines ,5x7
	delay(12);
	sendCommand(0x0F); //display on,cursor on
	delay(12);
	sendCommand(CLEAR_SCREEN); //clear screen
	delay(10);
	sendCommand(FIRST_LINE); //1st line
	delay(10);
	delay(10);
	
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 = 1;		
}


void display(unsigned char c){
	i++;
	if (i==16) sendCommand(SECOND_LINE);
	if (c == BACKSPACE_KEY){//BACKSPACE
		sendCommand(SHIFT_CURSOR_LEFT); //SHIFT CURSOR LEFT
		return;
}
if(c == ENTER_KEY){ //ENTER
	sendCommand(CLEAR_SCREEN);
	return;
}
	sendData(c);
}

void ISR_SERIAL() interrupt 4 {
    unsigned char d;
    if (RI == 1) {
        RI = 0; // Clear receive interrupt flag
        d = SBUF; // Read data from UART buffer
        SBUF = d; // Echo back to verify UART
        while (TI == 0);
        TI = 0;
        display(d); // Display the character on LCD
    }
}


void main() {
	init();
	while(1);
}