#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#define HOUR_AM 0
#define HOUR_PM 12
#define HOUR_24 24

#define ERROR -1

/*ONE WHILE ITERATION ~0.001915 ms IN PROCESSOR (ARM CORTEX M3) TIME*/
/*REAL TIME IS ABOUT 0.001634 ms PER WHILE ITERATION*/

struct time
{
    unsigned char hour;
    unsigned char minute;
    unsigned char sec;
    unsigned short millis; 
};

int setHour(struct time* time, unsigned char h, unsigned char hfmt);

void delay_s(int sec);
void delay_ms(int millis);

int setStartTime(unsigned char h, unsigned char hfmt, unsigned char m, unsigned char s, unsigned short ms);

int setAlarmTime(unsigned char h, unsigned char hfmt, unsigned char m);

int waitForAlarm();

#endif
