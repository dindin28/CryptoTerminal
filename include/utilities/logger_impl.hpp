#ifndef EMPIREBUCHABOT_INCLUDE_UTILITIES_LOGGERIMPL_H
#define EMPIREBUCHABOT_INCLUDE_UTILITIES_LOGGERIMPL_H

#include "logger.hpp"

template<class T>
LOG &LOG::operator<<(const T &message)
{
  if (level_ >= log_level_)
  {
    if (outputed_extra_info_ == false)
    {
      // Outputting log level
      string_stream_ << "[" + LogTypeHelper::ToString(level_) + "] ";

      // Outputting run-time time
      char buffer[32];
      std::time_t now = std::chrono::system_clock::to_time_t(
                          std::chrono::system_clock::now());
      std::strftime(buffer, 32, "%T %d.%m.%Y ", std::localtime(&now)) ;
      string_stream_ << buffer;

      // Outputting file name and line
      string_stream_ << "(" << std::string(file_path_.filename()) << ":" << line_ <<
                     ") ";

      // Outputting function name
      string_stream_ << "(" << func_name_ << ") ";

      outputed_extra_info_ = true;
    } // Condition (outputed_extra_info_ == false)

    string_stream_ << message;
  } // Condition (level_ >= log_level_)

  return *this;
}

#endif // Header Guard