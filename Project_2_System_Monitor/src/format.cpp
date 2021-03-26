#include "format.h"

#include <cmath>
#include <iomanip>
#include <string>

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  string timeString;
  int mm{0};
  int hh{0};
  float ss;
  mm = floor(seconds / 60);
  ss = ((seconds / 60.0) - mm) * 60;
  while (mm > 59) {
    mm = mm - 60;
    hh++;
  }

  std::stringstream hhs, mms, sss;
  hhs << std::setw(2) << std::setfill('0') << hh;
  mms << std::setw(2) << std::setfill('0') << mm;
  sss << std::setw(2) << std::setfill('0') << ss;

  timeString = hhs.str() + ":" + mms.str() + ":" + sss.str();

  return timeString;
}