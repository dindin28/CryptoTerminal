#include <utilities/logger.hpp>
#include <utilities/definitions.h>

#include <iostream>
#include <fstream>
#include <chrono>

std::mutex LOG::mutex_;
LogLevel LOG::log_level_ = LogLevel::WARN;

LOG::LOG(LogLevel log_level, const std::string& file_path,
         int line, const std::string& func_name)
  : level_(log_level), file_path_(file_path), line_(line),
    func_name_(func_name), outputed_extra_info_(false)
{} // Constructor (LOG)

void LOG::SetLogLevel(LogLevel log_level)
{
  log_level_ = log_level;
} // Function (SetLogLevel)

LOG::~LOG()
{
  mutex_.lock();

  if (string_stream_.peek())
  {
    string_stream_ << std::endl;
  }

  // Outputting to file
  std::ofstream file_handler(definitions::kLOG_FILE.data(), std::ios_base::app);
  if (file_handler.is_open())
  {
    file_handler << string_stream_.str();
    file_handler.close();
  }

  // Outputting to console
  std::cout << string_stream_.rdbuf();
  std::cout.flush();

  mutex_.unlock();
} // Destructor (LOG)

std::string LogTypeHelper::ToString(const LogLevel log_level)
{
  std::string string_log_level;

  switch (log_level)
  {
    case (DISABLED):
      string_log_level = "DISABLED";
      break;

    case (VERBOSE):
      string_log_level = "VERBOSE";
      break;

    case (DEBUG):
      string_log_level = "DEBUG";
      break;

    case (WARN):
      string_log_level = "WARN";
      break;

    case (INFO):
      string_log_level = "INFO";
      break;

    case (ERROR):
      string_log_level = "ERROR";
      break;
  }

  return string_log_level;
} // Function (ToString)

LogLevel LogTypeHelper::ToLogLevel(const std::string &string_log_level)
{
  LogLevel log_level;

  if (string_log_level == "DISABLED")
  { log_level = DISABLED; }
  else if (string_log_level == "VERBOSE")
  { log_level = VERBOSE; }
  else if (string_log_level == "DEBUG")
  { log_level = DEBUG; }
  else if (string_log_level == "INFO")
  { log_level = INFO; }
  else if (string_log_level == "ERROR")
  { log_level = ERROR; }
  else
  { log_level = WARN; }

  return log_level;
}