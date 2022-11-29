#include "alarmclock.h"

/*ONE WHILE ITERATION ~0.001915 ms IN PROCESSOR (ARM CORTEX M3) TIME*/
/*REAL TIME IS ABOUT 0.001634 ms PER WHILE ITERATION*/

struct time start;
struct time end;

int setHour(struct time* time, unsigned char h, unsigned char hfmt)
{
    switch (hfmt)
    {
        case HOUR_24:
            if (h > 23)
                return ERROR;
            time->hour = h;
            break;
        
        case HOUR_AM:
            if (h > 12 || h < 1)
                return ERROR;
            if (h == 12)
                time->hour = 0; // midnight is 12 AM
            else
                time->hour = h;
            break;
        
        case HOUR_PM:
            if (h > 12 || h < 1)
                return ERROR;
            if (h == 12)
                time->hour = h; // noon is 12 PM
            else 
                time->hour = h + 12;
            break;
        
        default: // Same as 24 hour format
            if (h > 23)
                return ERROR;
            time->hour = h;
            break;
    }
    return 0;
}

void delay_s(int sec)
{
    unsigned long long count = 0;
    unsigned long long goal = sec * 522000;
    
    while(count++ < goal);
}

void delay_ms(int ms)
{
    unsigned long long count = 0;
    unsigned long long goal = ms * 522;
    
    while(count++ < goal);
}

int setStartTime(unsigned char h, unsigned char hfmt, unsigned char m, unsigned char s, unsigned short ms)
{
    if (setHour(&start, h, hfmt) == ERROR)
        return ERROR;
    
    if (m > 59)
        return ERROR;
    start.minute = m;
    
    if (s > 59)
        return ERROR;
    start.sec = s;
    
    if (ms > 999)
        return ERROR;
    start.millis = ms;
    
    return 0;
}

int setAlarmTime(unsigned char h, unsigned char hfmt, unsigned char m)
{
    if (setHour(&end, h, hfmt) == ERROR)
        return ERROR;
    
    if (m > 59)
        return ERROR;
    end.minute = m;
    
    return 0;
}

int waitForAlarm()
{
    unsigned int beginTime_ms;
    unsigned int alarmTime_ms;
    unsigned int waitTime_ms;
    beginTime_ms = start.millis + (start.sec * 1000) + (start.minute * 60000) + (start.hour * 3600000);
    alarmTime_ms = (end.minute * 60000) + (end.hour * 3600000);
    // If alarm time is set to next day
    if (start.hour > end.hour)
    {
        beginTime_ms = 86399999 - beginTime_ms;     // 86399999 is max possible time
        if (beginTime_ms >= alarmTime_ms)
        {
            // XOR swap
            beginTime_ms = beginTime_ms ^ alarmTime_ms;
            alarmTime_ms = alarmTime_ms ^ beginTime_ms;
            beginTime_ms = beginTime_ms ^ alarmTime_ms;
        }
    }
    if (beginTime_ms < 0 || alarmTime_ms < 0 || beginTime_ms >= alarmTime_ms)
        return ERROR;
    waitTime_ms = alarmTime_ms - beginTime_ms;
    delay_ms(waitTime_ms);
    return 1;
}
