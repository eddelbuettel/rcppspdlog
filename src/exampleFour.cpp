
// this define is important to no include another logger pulling in stdout
#define SPDLOG_DISABLE_DEFAULT_LOGGER 1

#include "spdlog/sinks/base_sink.h"
#include "spdlog/details/null_mutex.h"
#include "spdlog/details/synchronous_factory.h"

#include <mutex>

#include <Rcpp.h>               // for Rcpp::Rcout

namespace spdlog {
namespace sinks {

template<typename Mutex>
class r_sink : public base_sink<Mutex> {

protected:
    void sink_it_(const spdlog::details::log_msg& msg) override {

        // log_msg is a struct containing the log entry info like level, timestamp, thread id etc.
        // msg.raw contains pre formatted log

        // If needed (very likely but not mandatory), the sink formats the message before
        // sending it to its final destination:
        spdlog::memory_buf_t formatted;
        spdlog::sinks::base_sink<Mutex>::formatter_->format(msg, formatted);
        Rcpp::Rcout << fmt::to_string(formatted);
    }

    void flush_() override {
        Rcpp::Rcout << std::flush;
    }
};

using r_sink_mt = r_sink<std::mutex>;
using r_sink_st = r_sink<details::null_mutex>;

} // namespace sinks

// factory functions
template<typename Factory = spdlog::synchronous_factory>
inline std::shared_ptr<logger> r_sink_mt(const std::string &logger_name) {
    return Factory::template create<sinks::r_sink_mt>(logger_name);
}

template<typename Factory = spdlog::synchronous_factory>
inline std::shared_ptr<logger> r_sink_st(const std::string &logger_name) {
    return Factory::template create<sinks::r_sink_st>(logger_name);
}

} // namespace spdlog

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
    auto rsink = spdlog::r_sink_mt("fromR");

    // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
    rsink->set_pattern("[%H:%M:%S.%f] [%n] [%^%L%$] [thread %t] %v");

    rsink->info("Welcome to spdlog!");
    rsink->error("Some error message with arg: {}", 1);

    rsink->warn("Easy padding in numbers like {:08d}", 12);
    rsink->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    rsink->info("Support for floats {:03.2f}", 1.23456);
    rsink->info("Positional args are {1} {0}..", "too", "supported");
    rsink->info("{:<30}", "left aligned");
}
