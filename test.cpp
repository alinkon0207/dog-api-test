#include <httplib.h>
#include <iostream>

int main(void)
{
  httplib::Client cli("https://dog-api.kinduff.com");	// Connect to site

  if (auto res = cli.Get("/api/facts?raw=true")) {	// send request
    if (res->status == 200) {	// if success
      std::cout << res->body << std::endl;	// print message
    }
    else
      std::cout << "status: " << res->status << std::endl;	// else, print error status
  } else { // if failed, print error string
    auto err = res.error();
    std::cout << "HTTP error: " << httplib::to_string(err) << std::endl;
  }
}
