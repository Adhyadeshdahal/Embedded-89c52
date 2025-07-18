#include <reg51.h>


void init(){
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 = 1;		
}

void transmitData(unsigned char*d){
	unsigned char i=0;
	while(d[i]!='\0'){
		SBUF=d[i];
		while(TI == 0);
		TI=0;
		i++;
}
TR1 =0;
}


void main() {
init();
transmitData("Hello World");
while(1);
}