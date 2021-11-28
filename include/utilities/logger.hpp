/** @file helper.hpp
 *  File with class LOG
 */

#ifndef EMPIREBUCHABOT_INCLUDE_UTILITIES_LOGGER_H
#define EMPIREBUCHABOT_INCLUDE_UTILITIES_LOGGER_H

#include <sstream>    //std::stringstream
#include <mutex>      // std::mutex
#include <filesystem> // std::filesystem

enum LogLevel
{
  DISABLED = 0, ///< Disable any logging
  VERBOSE = 1, ///< VERBOSE logging and under
  DEBUG = 2, ///< DEBUG logging and under
  WARN = 3, ///< WARN logging and under
  INFO = 4, ///< INFO logging and under
  ERROR = 5, ///< Only ERROR logging
};

/**
 * @def LOGVERBOSE
 * @brief Replace LOG(VERBOSE)
 *
 * Outputting time, date file_name, line and function, from where was activated
 */
#define LOGVERBOSE LOG(VERBOSE, __FILE__, __LINE__, __func__)
/**
 * @def LOGDEBUG
 * @brief Replace LOG(DEBUG)
 *
 * Outputting time, date file_name, line and function, from where was activated
 */
#define LOGDEBUG  LOG(DEBUG, __FILE__, __LINE__, __func__)
/**
 * @def LOGWARN
 * @brief Replace LOG(WARN)
 *
 * Outputting time, date file_name, line and function, from where was activated
 */
#define LOGWARN LOG(WARN, __FILE__, __LINE__, __func__)
/**
 * @def LOGINFO
 * @brief Replace LOG(INFO)
 *
 * Outputting time, date file_name, line and function, from where was activated
 */
#define LOGINFO LOG(INFO, __FILE__, __LINE__, __func__)
/**
 * @def LOGERROR
 * @brief Replace LOG(ERROR)
 *
 * Outputting time, date file_name, line and function, from where was activated
 */
#define LOGERROR  LOG(ERROR, __FILE__, __LINE__, __func__)

/**
  * @class LOG logger.hpp <downloader/logger.hpp>
  * @brief Class for outputing log information
  */
class LOG
{
 public:
  /**
    * @brief A constructor
    *
    * @param[in] log_level - Set output log_level, check types.hpp
    * @param[in] file_path - Set file path
    * @param[in] line - Set line of function
    * @param[in] func_name - Set function name
    */
  LOG(LogLevel log_level, const std::string& file_path,
      int line, const std::string& func_name);

  /**
   * @brief Outputing message
   *
   * @code{.cpp}
   * LOG(INFO) << "Hi" << " there!";
   * @endcode
   *
   * @param[in] message - Any type, that can be put to stream, to output
   */
  template <typename T>
  LOG &operator<<(const T &message);

  /**
   * @brief Setting programme`s log level
   *
   * Setting log level to output during perfoming programme
   * Under current log level, all log levels outputting
   *
   * @param[in] log_level - LogLevel to be set
   */
  static void SetLogLevel(LogLevel log_level);

  /**
   * @brief Finishes outputting
   */
  ~LOG();

 private:
    // *INDENT-OFF*
    LogLevel level_;            ///< Current object LogLevel
    std::filesystem::path file_path_;  ///< File path, from where logger was activated
    int line_;                         ///< Line, from where logger was activated
    std::string func_name_;            ///< Function, from where logger was activated

    bool outputed_extra_info_;         ///< Info about outputted info in the beginning

    static std::mutex mutex_;          ///< Mutex for blocking outputting
    static LogLevel log_level_; ///< Common programme LogLevel

    std::stringstream string_stream_;  ///< String stream to collect data before output
    // *INDENT-ON*
};

class LogTypeHelper
{
 public:
  /**
    * Convertor from LogLevel to std::string
    *
    * @param[in] log_level - LogLevel, which need to convert
    */
  static std::string ToString(const LogLevel log_level);

  /**
    * Convertor from std::string to LogLevel
    *
    * @param[in] string_log_level - std::string, which need to convert
    */
  static LogLevel ToLogLevel(const std::string &string_log_level);
};

#include "logger_impl.hpp" // Templated method

#endif // Header Guard