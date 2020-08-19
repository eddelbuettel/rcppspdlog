
//#include "spdlog/spdlog.h"
//#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/details/synchronous_factory.h>
#include "spdlog/sinks/base_sink.h"
#include "spdlog/details/null_mutex.h"

//#include "spdlog/sinks/basic_file_sink.h"
#include <mutex>

#include <Rcpp.h>

namespace spdlog {
namespace sinks {

template<typename Mutex>
class my_sink : public base_sink<Mutex> {

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

using my_sink_mt = my_sink<std::mutex>;
using my_sink_st = my_sink<details::null_mutex>;

} // namespace sinks

// factory functions
template<typename Factory = spdlog::synchronous_factory>
inline std::shared_ptr<logger> my_sink_mt(const std::string &logger_name) {
    return Factory::template create<sinks::my_sink_mt>(logger_name);
}

template<typename Factory = spdlog::synchronous_factory>
inline std::shared_ptr<logger> my_sink_st(const std::string &logger_name) {
    return Factory::template create<sinks::my_sink_st>(logger_name);
}

} // namespace spdlog

//' Fourth Example
//'
//' A simple example invoking a derived Rcpp logger.
//'
//' Note that this still triggers R warnings, so consider it work in progress.
//' @return None
// [[Rcpp::export]]
void exampleFour() {
  //auto mysink = spdlog::basic_logger_mt("file_logger", "/tmp/demosink.txt", false);
  auto mysink = spdlog::my_sink_mt("rcpp_logger");

  // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
  mysink->set_pattern("[%H:%M:%S.%f] [%n] [%^%L%$] [thread %t] %v");
  //mysink->info("This an info message with custom format");
  //mysink->set_pattern("%+"); // back to default format

  mysink->info("Welcome to spdlog!");
  mysink->error("Some error message with arg: {}", 1);

  mysink->warn("Easy padding in numbers like {:08d}", 12);
  mysink->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  mysink->info("Support for floats {:03.2f}", 1.23456);
  mysink->info("Positional args are {1} {0}..", "too", "supported");
  mysink->info("{:<30}", "left aligned");

}

/*** R
exampleFour()
*/
