#include <httplib.h>
#include <iostream>

int main(void)
{
  httplib::Client cli("https://dog-api.kinduff.com");

  if (auto res = cli.Get("/api/facts?raw=true")) {
    if (res->status == 200) {
      std::cout << res->body << std::endl;
    }
    else
      std::cout << "status: " << res->status << std::endl;
  } else {
    auto err = res.error();
    std::cout << "HTTP error: " << httplib::to_string(err) << std::endl;
  }
}
