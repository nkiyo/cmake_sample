#include <httplib.h>
#include <stdio.h>
#include <unistd.h>
#include "util/MyClass.h"

using namespace httplib;

int main() {
  MyClass mc;
  printf("### %d\n", mc.myFunc(1));

  Server svr;

  // `curl 127.0.0.1:1234/hi` => hi
  svr.Get("/hi", [](const Request& req, Response& res) { res.set_content("Hello World!", "text/plain"); });

  // `curl 127.0.0.1:1234/numbers/123` => 123
  // `curl 127.0.0.1:1234/numbers/4567` => 4567
  svr.Get(R"(/numbers/(\d+))", [&](const Request& req, Response& res) {
    auto numbers = req.matches[1];
    // printf("before sleep\n");
    // sleep(3);
    res.set_content(numbers, "text/plain");
    // TODO JSON形式で返す
    // res.set_content(numbers, "application/json");
    // printf("after sleep\n");
  });

  // `curl 127.0.0.1:1234/body-header-param?key=on --header "Content-Length: 1234"`
  //   => print "1234"
  //   => print "on"
  svr.Get("/body-header-param", [](const Request& req, Response& res) {
    if (req.has_header("Content-Length")) {
      auto val = req.get_header_value("Content-Length");
      printf("Content-Length=%s\n", val.c_str());
    }
    if (req.has_param("key")) {
      auto val = req.get_param_value("key");
      printf("key=%s\n", val.c_str());
    }
    printf("body is \"%s\"\n", req.body.c_str());  // GET の場合は body を設定できない
    res.set_content(req.body, "text/plain");
  });

  // `curl 127.0.0.1:1234/stop` => サーバ終了
  svr.Get("/stop", [&](const Request& req, Response& res) { svr.stop(); });

  // curl -i -H "Accept: application/json"  -X POST -d "{"name1":"val1"}"  http://127.0.0.1:1234/multipart
  //   => req.body に -d で渡した内容が格納される
  svr.Post("/multipart", [&](const auto& req, auto& res) { printf("body is \"%s\"\n", req.body.c_str()); });

  svr.listen("localhost", 1234);
}
