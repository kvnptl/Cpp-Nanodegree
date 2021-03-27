#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int p) : pid_(p) {}
  int Pid();                               // TODO: See src/process.cpp - DONE
  std::string User();                      // TODO: See src/process.cpp - DONE
  std::string Command();                   // TODO: See src/process.cpp - DONE
  float CpuUtilization();                  // TODO: See src/process.cpp - DONE
  std::string Ram();                       // TODO: See src/process.cpp - DONE
  long int UpTime();                       // TODO: See src/process.cpp - DONE
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  // TODO: Declare any necessary private members
 private:
  int pid_;
  long cpu_time_ = Process::CpuUtilization();
};

#endif