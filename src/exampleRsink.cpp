
// this portmanteau include also defines the r_sink we use below, and which
// diverts all logging to R via the Rcpp::Rcout replacement for std::cout
#include <RcppSpdlog>
#include <spdlog/stopwatch.h>   		// also support stopwatch feature

//' spdlog Example using a sink for R
//'
//' A simple example invoking a derived R/Rcpp logger. Also demonstrates the
//' stopwatch feature. For more features see the 'spdlog' documnetation.
//'
//' Note that this no longer triggers R warnings thanks to excellent help by
//' Gabi Melman.
//' @return None
//' @examples
//' exampleRsink()
// [[Rcpp::export]]
void exampleRsink() {

    std::string logname = "fromR"; 							// fix a name for this logger
    auto sp = spdlog::get(logname);       					// retrieve existing one
    if (sp == nullptr) sp = spdlog::r_sink_mt(logname);   	// or create new one if needed

    spdlog::stopwatch sw;       							// instantiate a stop watch

    // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
    sp->set_pattern("[%H:%M:%S.%f] [%n] [%^%L%$] [thread %t] %v");

    sp->info("Welcome to spdlog!");
    sp->error("Some error message with arg: {}", 1);
    sp->info("Elapsed time: {}", sw);

    sp->warn("Easy padding in numbers like {:08d}", 12);
    sp->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    sp->info("Support for floats {:03.2f}", 1.23456);
    sp->info("Positional args are {1} {0}..", "too", "supported");
    sp->info("{:<30}", "left aligned");
    sp->info("Elapsed time: {}", sw);

}
