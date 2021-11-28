#ifndef EMPIREBUCHABOT_INCLUDE_UTILITIES_REQUESTER_H
#define EMPIREBUCHABOT_INCLUDE_UTILITIES_REQUESTER_H

#include <curl/curl.h>

#include <string>
#include <utility>

class Requester
{
 public:
  Requester();
  ~Requester();

  std::pair<CURLcode, std::string> SendRequest(std::string url);

  static std::string StringError(CURLcode code);

 private:
  friend size_t WriteCallback(char *ptr, size_t size, size_t nmemb,
                              void *userdata);

};

#endif // Header Guard