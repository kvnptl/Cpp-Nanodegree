#include "processor.h"

#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::cout;
using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  vector<string> cpuString;

  int total_jiffies_1{0}, work_jiffies_1{0};
  int total_jiffies_2{0}, work_jiffies_2{0};

  int work_over_period{0}, total_over_period{0};
  float cpuUsage{0.0};
  int i = 0;

  // time t1
  cpuString = LinuxParser::CpuUtilization();
  for (auto c : cpuString) {
    total_jiffies_1 += std::stoi(c);
    if (i < 3) {
      work_jiffies_1 += std::stoi(c);
    }
    i++;
  }

  // time t2
  unsigned int microsecond = 1000000;
  usleep(3 * microsecond);  // sleeps for 3 second
  cpuString = LinuxParser::CpuUtilization();
  i = 0;
  for (auto c : cpuString) {
    total_jiffies_2 += std::stoi(c);
    if (i < 3) {
      work_jiffies_2 += std::stoi(c);
    }
    i++;
  }

  work_over_period = work_jiffies_2 - work_jiffies_1;
  total_over_period = total_jiffies_2 - total_jiffies_1;

  cpuUsage = work_over_period / float(total_over_period);

  return cpuUsage;
}