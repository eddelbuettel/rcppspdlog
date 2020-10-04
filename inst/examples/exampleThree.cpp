
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <Rcpp.h>

// [[Rcpp::depends(RcppSpdlog)]]

// [[Rcpp::export]]
void exampleThree() {

  auto console = spdlog::stdout_color_mt("console");

  // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
  spdlog::set_pattern("[%H:%M:%S.%f] [%^%L%$] [thread %t] %v");
  spdlog::info("This an info message with custom format");
  //spdlog::set_pattern("%+"); // back to default format

  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);

  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");
  spdlog::info("{:<30}", "left aligned");


  // added to this example file allow multiple runs of different package functions
  spdlog::drop("console");

}

/*** R
exampleThree()
*/
