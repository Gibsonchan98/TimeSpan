//
// Timestamp Created by Melanie Palomino on 01/16/2020.
//

#include "timespan.h"
#include <iostream>

//Constructor
TimeSpan::TimeSpan(float hr, float min, float sec){
   this-> hours = int(hr);
    if(min<0 || sec<0){
        setTime(hr,min,sec);
    }
   this-> minutes = int(min);
    cout<< minutes << endl;
    cout << (hr-hours)*60 << endl;
    //converts any double minutes to seconds
    int secs =  ((min-minutes) * 60);
    cout << sec << endl;
    minutes = min + (hr-hours)*60;
   this-> seconds = secs + int(sec);
   // cout << hours << minutes << seconds << endl;
}

bool TimeSpan :: setTime(const float& h, float& m, float& s){
    minutes = int(m);
    seconds = s;
    while(m<-60){
        minutes+=60;
        hours-=1;
    }
    while(s<-60){
        seconds+= 60;
        minutes+=1;
    }

    return true;
}
//overloading << function
ostream& operator<<(ostream& output, const TimeSpan& timespan) {
    output << timespan.hours << ":" << timespan.minutes << ":"<< timespan.seconds;
  return output;
}

TimeSpan TimeSpan::operator+(const TimeSpan& timespan) const {
  TimeSpan ts;
    ts.hours = hours + timespan.hours;
    ts.minutes = minutes + timespan.minutes;
    ts.seconds = seconds + timespan.seconds;

    if(ts.seconds > 60){
        ts.seconds -= 60;
        ts.minutes += 1;
    }
    if(ts.minutes > 60){
        ts.minutes -= 60;
        ts.hours += 1;
    }
  return ts;
}

TimeSpan TimeSpan::operator-(const TimeSpan& timespan) const {
  TimeSpan ts;
    ts.hours = hours - timespan.hours;
    ts.minutes = minutes - timespan.minutes;
    ts.seconds = seconds - timespan.seconds;

    if(ts.seconds < -60){
        ts.seconds += 60;
        ts.minutes -= 1;
    }
    if(ts.minutes < -60){
        ts.minutes += 60;
        ts.hours -= 1;
    }
  return ts;
}

TimeSpan TimeSpan::operator+=(const TimeSpan& timespan) const {
    TimeSpan ts;
    ts.hours = hours + timespan.hours;
    ts.minutes = minutes + timespan.minutes;
    ts.seconds = seconds + timespan.seconds;

    if(ts.seconds > 60){
        ts.seconds -= 60;
        ts.minutes += 1;
    }
    if(ts.minutes > 60){
        ts.minutes -= 60;
        ts.hours += 1;
    }
    return ts;
}

TimeSpan TimeSpan::operator-=(const TimeSpan& timespan) const {
    TimeSpan ts;
    ts.hours = hours - timespan.hours;
    ts.minutes = minutes - timespan.minutes;
    ts.seconds = seconds - timespan.seconds;

    if(ts.seconds < -60){
        ts.seconds += 60;
        ts.minutes -= 1;
    }
    if(ts.minutes < -60){
        ts.minutes += 60;
        ts.hours -= 1;
    }
    return ts;
}

TimeSpan TimeSpan::operator*(int number) {
    TimeSpan ts;
    ts.hours = hours * number;
    ts.minutes = minutes * number;
    ts.seconds = seconds * number;

    if(ts.seconds > 60){
        ts.seconds -= 60;
        ts.minutes += 1;
    }
    if(ts.minutes > 60){
        ts.minutes -= 60;
        ts.hours += 1;
    }
    return ts;
}
//returns true if they are equal
bool TimeSpan::operator==(const TimeSpan& timespan) const {
    bool equal = false;
    //checks if hours, minutes, and minutes of each timespan are equal
   if(this->hours == timespan.hours && this->minutes == timespan.minutes){
       if(this->seconds == timespan.seconds){
           equal= true;
       }
   }
    return equal;
}
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
