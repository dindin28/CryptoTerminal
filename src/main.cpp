#include <utilities/requester.h>
#include <utilities/logger.hpp>
#include <nlohmann/json.hpp>

int main(void)
{
  Requester requester;
  auto[return_code, return_string] =
    requester.SendRequest("https://api1.binance.com/api/v3/avgPrice?symbol=BTCUSDT");

  nlohmann::json json_string = nlohmann::json::parse(return_string);

  LOG::SetLogLevel(VERBOSE);
  if (return_code == CURLE_OK)
  {
    LOGVERBOSE << "Is string: " << std::boolalpha << json_string["price"].is_string() << " " << json_string["price"];
  }
  else
  {
    LOGERROR << Requester::StringError(return_code);
  }

  return 0;
}