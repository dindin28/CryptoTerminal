#include "utilities/requester.h"

#include <memory>

Requester::Requester()
{
  curl_global_init(CURL_GLOBAL_ALL);
}

size_t WriteCallback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
  std::string *str = static_cast<std::string *>(userdata);
  *str += ptr;

  return size * nmemb;
}

Requester::~Requester()
{
  curl_global_cleanup();
}

std::pair<CURLcode, std::string> Requester::SendRequest(std::string url)
{
  CURLcode return_result = CURLE_OK;

  std::unique_ptr<CURL, void(*)(CURL *)> curl_handler(curl_easy_init(),
      curl_easy_cleanup);

  if (curl_handler.get() == NULL)
  {
    return_result = CURLE_FAILED_INIT;
  }

  std::string GETString;
  if (return_result == CURLE_OK)
  {
    curl_easy_setopt(curl_handler.get(), CURLOPT_URL, url.c_str());

    curl_easy_setopt(curl_handler.get(), CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl_handler.get(), CURLOPT_WRITEDATA, &GETString);

    return_result = curl_easy_perform(curl_handler.get());
  }

  return std::make_pair(return_result, GETString);
}

std::string Requester::StringError(CURLcode code)
{ return std::string(curl_easy_strerror(code)); }