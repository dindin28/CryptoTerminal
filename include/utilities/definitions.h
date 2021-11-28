#ifndef EMPIREBUCHABOT_INCLUDE_UTILITIES_DEFINITIONS_H
#define EMPIREBUCHABOT_INCLUDE_UTILITIES_DEFINITIONS_H

#include <string_view>
namespace definitions
{
  constexpr long kCURLOPT_LOW_SPEED_TIME = 10L;
  constexpr long kCURLOPT_LOW_SPEED_LIMIT = 30L;
  constexpr std::string_view kLOG_FILE = "log.txt";
} // Namespace (definitions)
#endif