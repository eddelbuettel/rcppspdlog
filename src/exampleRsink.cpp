
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
    spdlog::set_default_logger(sp);                         // and set as default

    spdlog::stopwatch sw;       							// instantiate a stop watch

    // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
    spdlog::set_pattern("[%H:%M:%S.%f] [%n] [%^%L%$] [thread %t] %v");

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    spdlog::info("Elapsed time: {}", sw);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");
    spdlog::info("Elapsed time: {}", sw);

}

//' spdlog Logging Lever Setter
//'
//' A helper function to turn a logging level given as string
//' into the current logging level
//'
//' @param name A string with the logging level. Value understood are,
//' in decreasing verbosity \sQuote{trace}, \sQuote{debug}, \sQuote{info},
//' \sQuote{warning}, \sQuote{error}, \sQuote{critical}, and \sQuote{off}.
//' Unrecognised names are equivalent to \sQuote{off}.
//' @return Nothing is returned.
// [[Rcpp::export]]
void setLogLevel(const std::string &name) {
    spdlog::set_level(spdlog::level::from_str(name));
}
