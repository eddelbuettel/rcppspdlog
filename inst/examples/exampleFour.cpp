// This example was largely contributed by Young Geun Kim in issue #22
// at https://github.com/eddelbuettel/rcppspdlog/issues/22
//
// The key insight for multi-threaded use is that the actual multithreaded code
// must stay away from R-related data to avoid callback. This is accomplished here
// by relying on the 'Rcout' variant from the 'RcppThread' package. So this adds a
// new (small) dependency for multi-threaded logging.

// [[Rcpp::depends(RcppSpdlog)]]
// [[Rcpp::depends(RcppThread)]]
// [[Rcpp::plugins(openmp)]]

#include <RcppThread.h>
#include <RcppSpdlog>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <omp.h>

namespace mynamespace {

    namespace sinks {

        template<typename Mutex>
        class rcppthread_sink : public spdlog::sinks::r_sink<Mutex> {
        protected:
            void sink_it_(const spdlog::details::log_msg& msg) override {
                spdlog::memory_buf_t formatted;
                spdlog::sinks::base_sink<Mutex>::formatter_->format(msg, formatted);
                #ifdef SPDLOG_USE_STD_FORMAT
                RcppThread::Rcout << formatted;
                #else
                RcppThread::Rcout << fmt::to_string(formatted);
                #endif
            }

            void flush_() override {
                RcppThread::Rcout << std::flush;
            }
        };

        using rcppthread_sink_mt = rcppthread_sink<std::mutex>;

    } // namespace sinks

    template<typename Factory = spdlog::synchronous_factory>
    inline std::shared_ptr<spdlog::logger> rcppthread_sink_mt(const std::string &logger_name) {
        return Factory::template create<sinks::rcppthread_sink_mt>(logger_name);
    }

} // namespace mynamespace


// [[Rcpp::export]]
void omp_spdlog() {
    const int size = 8;
    std::string logname = "console";
    auto console = spdlog::get(logname);
    if (console == nullptr) console = mynamespace::rcppthread_sink_mt(logname);
    spdlog::set_default_logger(console);

    console->set_pattern("[%n] [thread %t] %v");
    console->info("Number of threads: {}", omp_get_max_threads());

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        int thread_id = omp_get_thread_num();
        console->info("Thread {} processing index {}", thread_id, i);
    }
}

/*** R
omp_spdlog()
*/
