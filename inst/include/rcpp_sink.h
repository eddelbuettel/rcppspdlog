
#ifndef _RcppSpdlog_Rcpp_Sink_h_
#define _RcppSpdlog_Rcpp_Sink_h_

// this define is important to no include another logger pulling in stdout
#define SPDLOG_DISABLE_DEFAULT_LOGGER 1

#include "spdlog/spdlog.h"
#include "spdlog/sinks/base_sink.h"

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

#endif
