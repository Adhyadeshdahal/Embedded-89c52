#include <reg51.h> // Header file for 89C52

//Control Signals for LCD
sbit RS = P3^2;
sbit RW = P3^3;
sbit EN = P3^4;

#define LCD_PORT P2


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
	
}

// initialize lcd
void init(){
	sendCommand(0x38); //2 lines ,5x7
	delay(12);
	sendCommand(0x0F); //display on,cursor on
	delay(12);
}

void run(char* message1,char* message2){
	unsigned short int i;	
	while(1){
		sendCommand(0x01); //clear screen
			delay(10);
		sendCommand(0x80); //1st line
			delay(10);
		i=0;
		
		while(message1[i] != '\0'){
			sendData(message1[i]); //send Data
			i++;
			delay(30);
		};
		
		i=0;
		
		sendCommand(0xC0); //2nd line
		delay(10);
		
		while(message2[i] != '\0'){
			sendData(message2[i]); //send Data
			i++;
			delay(30);
		};
			
	}
	
}


void main() {
	init();
	run("Hello","World");
}