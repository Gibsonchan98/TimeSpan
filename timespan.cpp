//
// Timespan Created by Melanie Palomino on 01/16/2020.
//

#include "timespan.h"
#include <iomanip>
#include <iostream>

//Constructor
TimeSpan::TimeSpan(float hr, float min, float sec){
    if(min<0 || sec<0){
        setTime(hr,min,sec);
    }
    else{
        int time = int((hr * 3600) + (min*60) + sec);
        hours = time/3600;
        minutes = (time%3600) / 60;
        seconds = (time%3600) % 60;
    }
}
//destructor
TimeSpan::~TimeSpan() = default;

//sets time if values are negative
void TimeSpan :: setTime(const float& h, const float& m, const float& s){
    int time = int((h * 3600) + (m*60) + s);
    hours = time/3600;
    minutes= (time%3600) / 60;
    seconds  = (time%3600) % 60;
    while(minutes < 0){
        minutes+=60;
        hours-=1;
    }
    while(seconds < 0){
        seconds+= 60;
        minutes-=1;
    }
}

//overloading << (output)
ostream& operator<<(ostream& output, const TimeSpan& timespan) {
    if (timespan.seconds < 0 && timespan.minutes <= 0 && timespan.hours <= 0){
        output  << "-" << timespan.hours * -1<< setfill('0')
                << ':' << setw(2) << timespan.minutes * -1 << ':' << setw(2) <<
                timespan.seconds * -1;

    }else {
        output  << timespan.hours << setfill('0') << ':' << setw(2)
                << timespan.minutes << ':' << setw(2) <<
                timespan.seconds;
        return output;
    }
    return output;
}

//overloading addition
TimeSpan TimeSpan::operator+(const TimeSpan& timespan) const {
    TimeSpan ts;
    ts.hours = hours + timespan.hours;
    ts.minutes = minutes + timespan.minutes;
    ts.seconds = seconds + timespan.seconds;

    if(ts.seconds > 59){
        ts.seconds -= 60;
        ts.minutes += 1;
    }
    if(ts.minutes > 59){
        ts.minutes -= 60;
        ts.hours += 1;
    }
    return ts;
}

//overloading subtraction
TimeSpan TimeSpan::operator-(const TimeSpan& timespan) const {
    TimeSpan ts;
    ts.hours = hours - timespan.hours;
    ts.minutes = minutes - timespan.minutes;
    ts.seconds = seconds - timespan.seconds;
    while(ts.seconds < -15){
        ts.seconds+= 60;
        ts.minutes-=1;
    }
    while(ts.minutes < -15){
        ts.minutes+=60;
        ts.hours-=1;
    }
    return ts;
}

//overloading plus number
TimeSpan TimeSpan::operator+=(const TimeSpan& timespan) const {
    TimeSpan ts;
    ts.hours = hours + timespan.hours;
    ts.minutes = minutes + timespan.minutes;
    ts.seconds = seconds + timespan.seconds;

    if(ts.seconds > 59){
        ts.seconds -= 60;
        ts.minutes += 1;
    }
    if(ts.minutes > 59){
        ts.minutes -= 60;
        ts.hours += 1;
    }
    return ts;
}

//overloading minus number
TimeSpan TimeSpan::operator-=(const TimeSpan& timespan) const {
    TimeSpan ts;
    ts.hours = hours - timespan.hours;
    ts.minutes = minutes - timespan.minutes;
    ts.seconds = seconds - timespan.seconds;

    if(ts.seconds < -59){
        ts.seconds += 60;
        ts.minutes -= 1;
    }
    if(ts.minutes < -59){
        ts.minutes += 60;
        ts.hours -= 1;
    }
    return ts;
}

//overloading multiplication
TimeSpan TimeSpan::operator*(int number) {
    TimeSpan ts;
    ts.hours = hours * number;
    ts.minutes = minutes * number;
    ts.seconds = seconds * number;

    while(ts.seconds > 59){
        ts.seconds -= 60;
        ts.minutes += 1;
    }
    while(ts.minutes > 59){
        ts.minutes -= 60;
        ts.hours += 1;
    }
    return ts;
}

//Overloading equals
//returns true if they are equal
bool TimeSpan::operator==(const TimeSpan& timespan) const {
    return hours == timespan.hours&& minutes == timespan.minutes
           && timespan.seconds == seconds;
}
//Overloading not equal
//returns true if they are not equal
bool TimeSpan::operator!=(const TimeSpan& timespan) const {
    bool equal = false;
    //checks if hours, minutes, and minutes of each timespan are equal
    if(this->hours != timespan.hours && this->minutes != timespan.minutes){
        if(this->seconds != timespan.seconds){
            equal = true;
        }
    }
    return equal;
}

//Overloading greater than or equal to
//returns true if ts is greater than or equal to timespan
bool TimeSpan::operator>=(const TimeSpan& timespan) const {
    bool answer = false;
    //checks if hours, minutes, and minutes of each timespan are equal
    if(this->hours >= timespan.hours && this->minutes >= timespan.minutes){
        if(this->seconds >= timespan.seconds){
            answer = true;
        }
    }
    return answer;
}

//Overloading less than or equal to
//returns true if ts is less than or equal to timespan
bool TimeSpan::operator<=(const TimeSpan& timespan) const {
    bool answer = false;
    //checks if hours, minutes, and minutes of each timespan are equal
    if(this->hours <= timespan.hours && this->minutes <= timespan.minutes){
        if(this->seconds <= timespan.seconds){
            answer = true;
        }
    }
    return answer;
}

//Overloading greater than
//returns true if ts is greater than or equal to timespan
bool TimeSpan::operator>(const TimeSpan& timespan) const {
    bool answer = false;
    //checks if hours, minutes, and minutes of each timespan are equal
    if(this->hours > timespan.hours && this->minutes > timespan.minutes){
        if(this->seconds > timespan.seconds){
            answer = true;
        }
    }
    return answer;
}

//Overloading less than
//returns true if ts is less than or equal to timespan
bool TimeSpan::operator<(const TimeSpan& timespan) const {
    bool answer = false;
    //checks if hours, minutes, and minutes of each timespan are equal
    if(this->hours < timespan.hours && this->minutes < timespan.minutes){
        if(this->seconds < timespan.seconds){
            answer = true;
        }
    }
    return answer;
}