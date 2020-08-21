
#include <RcppSpdlog>

//' Fourth Example
//'
//' A simple example invoking a derived Rcpp logger.
//'
//' Note that this no longer triggers R warnings thanks to excellent help by
//' Gabi Melman.
//' @return None
//' @examples
//' exampleFour()
// [[Rcpp::export]]
void exampleFour() {
    std::string logname = "fromR"; 							// fix a name for this logger
    auto sp = spdlog::get(logname);       					// retrieve existing one
    if (sp == nullptr) sp = spdlog::r_sink_mt(logname);   	// or create new one if needed

    // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
    sp->set_pattern("[%H:%M:%S.%f] [%n] [%^%L%$] [thread %t] %v");

    sp->info("Welcome to spdlog!");
    sp->error("Some error message with arg: {}", 1);

    sp->warn("Easy padding in numbers like {:08d}", 12);
    sp->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    sp->info("Support for floats {:03.2f}", 1.23456);
    sp->info("Positional args are {1} {0}..", "too", "supported");
    sp->info("{:<30}", "left aligned");

}
