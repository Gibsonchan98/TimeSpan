//
// Timespan created by Melanie Palomnino on 1/15/2020
//
#ifndef TIMESPAN_H
#define TIMESPAN_H

#pragma once
#include <iostream>
using namespace std;

class TimeSpan {
  friend ostream &operator<<(ostream& output, const TimeSpan& timespan);

public:
  //explicit TimeSpan(int hours = 0, int minutes = 0, int seconds = 0);
  explicit TimeSpan(float hr = 0, float min = 0, float sec = 0);
  //sets time
  bool setTime(const float& h, float& m, float& s);
  // add
  TimeSpan operator+(const TimeSpan& timespan) const;
  //add number given
  TimeSpan operator+=(const TimeSpan& timespan) const;
  // subtract
  TimeSpan operator-(const TimeSpan& timespan) const;
  //subtract number given
  TimeSpan operator-=(const TimeSpan& timespan) const;
  // check equality
  bool operator==(const TimeSpan& timespan) const;
  // check if not equal
  bool operator!=(const TimeSpan& timespan) const;
  // check if equal or less than
  bool operator<=(const TimeSpan& timespan) const;
  // check if less than or equal to
  bool operator>=(const TimeSpan& timespan) const;
  // multiply timespan by a number
  TimeSpan operator*(int number);

private:
    //declare private ints for class
    int hours;
    int minutes;
    int seconds;


};

#endif
