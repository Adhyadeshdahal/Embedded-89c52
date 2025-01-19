#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// insert time then frequency
//time in ms
//frequency in MHZ
int calculate_delay(int time,double freq) {
    if (time > 70) 
    return -1;
    freq = freq/12;
    double den = 1/freq;
    double div = (time*1000 ) / den;
    int difference = 65536-(int)round(div);
    return difference;
}

int main(int argc,char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <time> <freq>\n",argv[0]);
        return 1;
    }
    int time = atoi(argv[1]);
    float freq = atof(argv[2]);
    int delay = calculate_delay(time,freq);
    if (delay == -1) {
        printf("Time should be less than 70\n");
        return 1;
    };
    printf("Delay: %x\n",delay);
    return 0;

} 