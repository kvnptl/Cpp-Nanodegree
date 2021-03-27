#include "process.h"

#include <linux_parser.h>
#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  long t = LinuxParser::UpTime();
  vector<string> s = LinuxParser::CpuUtilization(pid_);
  int total_time = std::stoi(s[0]) + std::stoi(s[1]);
  long sec = t - (std::stoi(s[4]) / sysconf(_SC_CLK_TCK));
  float cpu_usage = (((total_time * 1.0) / sysconf(_SC_CLK_TCK)) / sec);
  return cpu_usage;
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a [[maybe_unused]]) const {
  return cpu_time_ > a.cpu_time_;
}