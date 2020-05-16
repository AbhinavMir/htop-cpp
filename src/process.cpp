#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

#include "format.h"
#include "linux_parser.h"
#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid, long Hertz) : pid_(pid), Hertz_(Hertz)
{
    vector<string> cpuNumbers = ReadFile(pid);
    //cout << cpuNumbers;
    utime_ = stof(cpuNumbers[13]);
    stime_ = stof(cpuNumbers[14]);
    cutime_ = stof(cpuNumbers[15]);
    cstime_ = stof(cpuNumbers[16]);
    starttime_ = stof(cpuNumbers[21]);
}

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
    long uptime = LinuxParser::UpTime();
    double total_time = utime_ + stime + cutime + cstime_;
    double seconds = uptime - (starttime_/Hertz_);
    double cpu_usage = (total_time/Hertz_)/seconds;

    return cpu_usage;    
 }

// TODO: Return the command that generated this process
string Process::Command() { 

    string cmd = ParserHelper::GetValue<string>(to_string(pid_) + LinuxParser::kCmdlineFilename);

    size_t maxSize = 50;
    if(cmd.size() > maxSize) {
       cmd.resize(maxSize - 3);
       cmd = cmd + "..."; }    
                                               
  return cmd;
 }

// TODO: Return this process's memory utilization
string Process::Ram() { return string(); }

// TODO: Return the user (name) that generated this process
string Process::User() { return string(); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return 0; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a[[maybe_unused]]) const { return true; }