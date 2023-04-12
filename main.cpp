#include "mbed.h"

// main() runs in its own thread in the OS
PwmOut PWM1(D6);

AnalogIn Ain(A0);

Thread t1, t2;

float DR;

void sweep(void) {
    float DutyRatiol[9] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    int i;
    while (1) {
        for (i = 0; i < 9; i++) {
            DR = DutyRatiol[i];
            ThisThread::sleep_for(10ms);
        }
    }
}

void sampleAin(void) {
    while (1) {
        printf("%f\n",Ain.read());
    }
}

int main()
{
    t1.start(sweep);
    t2.start(sampleAin);
    while (true) {
        PWM1.period_us(50);
        PWM1 = DR;
        //printf("%f\n", PWM1.read());
        ThisThread::sleep_for(10ms);
    }
}