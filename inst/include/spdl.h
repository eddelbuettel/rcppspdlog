
#pragma once

// includes the auto-generated exports for the exported (via a C interface) underlying C++ functions
#include <RcppSpdlog.h>

// expose fmt::format via the courses in spdlog
#include <spdlog/fmt/fmt.h>

#ifdef SPDLOG_USE_STD_FORMAT
#include <string_view>
#endif

// for convenience define cuter ones in another (shorter) namespace
namespace spdl {
    inline void setup(const std::string& name = "default",
                      const std::string& level = "warn") {  RcppSpdlog::log_setup(name, level); }
    inline void init(const std::string& level = "warn") {  RcppSpdlog::log_setup("r", level); }
    inline void log(const std::string& level = "warn") {  RcppSpdlog::log_setup("r", level); }
    inline void filesetup(const std::string& filename = "default",
                          const std::string& name = "default",
                          const std::string& level = "warn") {  RcppSpdlog::log_filesetup(name, level); }
    inline void drop(const std::string& name) { RcppSpdlog::log_drop(name); }
    inline void set_pattern(const std::string& s) { RcppSpdlog::log_set_pattern(s); }
    inline void set_level(const std::string& s) { RcppSpdlog::log_set_level(s); }
    inline void trace(const std::string& s) { RcppSpdlog::log_trace(s); }
    inline void debug(const std::string& s) { RcppSpdlog::log_debug(s); }
    inline void info(const std::string& s) { RcppSpdlog::log_info(s); }
    inline void warn(const std::string& s) { RcppSpdlog::log_warn(s); }
    inline void error(const std::string& s) { RcppSpdlog::log_error(s); }
    inline void critical(const std::string& s) { RcppSpdlog::log_critical(s); }

    // it is highly unlikely we find a package imposing C++98 as R itself now defaults to C++14
    // and many packages have opted into C++11 (or newer) but the check does not hurt
    #if __cplusplus >= 201103L

    #ifdef SPDLOG_USE_STD_FORMAT 
    template <typename... Args>
    inline void trace(const char* fmt, Args&&... args ) { RcppSpdlog::log_trace(std::vformat(std::string_view(fmt), std::make_format_args(args...)).c_str()); }

    template <typename... Args>
    inline void debug(const char* fmt, Args&&... args ) { RcppSpdlog::log_debug(std::vformat(std::string_view(fmt), std::make_format_args(args...)).c_str()); }

    template <typename... Args>
    inline void info(const char* fmt, Args&&... args ) { RcppSpdlog::log_info(std::vformat(std::string_view(fmt), std::make_format_args(args...)).c_str()); }

    template <typename... Args>
    inline void warn(const char* fmt, Args&&... args ) { RcppSpdlog::log_warn(std::vformat(std::string_view(fmt), std::make_format_args(args...)).c_str()); }

    template <typename... Args>
    inline void error(const char* fmt, Args&&... args ) { RcppSpdlog::log_error(std::vformat(std::string_view(fmt), std::make_format_args(args...)).c_str()); }

    template <typename... Args>
    inline void critical(const char* fmt, Args&&... args ) { RcppSpdlog::log_critical(std::vformat(std::string_view(fmt), std::make_format_args(args...)).c_str()); }
    
    #else
    template <typename... Args>
    inline void trace(const char* fmt, Args&&... args ) { RcppSpdlog::log_trace(fmt::format(fmt, std::forward<Args>(args)... ).c_str()); }

    template <typename... Args>
    inline void debug(const char* fmt, Args&&... args ) { RcppSpdlog::log_debug(fmt::format(fmt, std::forward<Args>(args)... ).c_str()); }

    template <typename... Args>
    inline void info(const char* fmt, Args&&... args ) { RcppSpdlog::log_info(fmt::format(fmt, std::forward<Args>(args)... ).c_str()); }

    template <typename... Args>
    inline void warn(const char* fmt, Args&&... args ) { RcppSpdlog::log_warn(fmt::format(fmt, std::forward<Args>(args)... ).c_str()); }

    template <typename... Args>
    inline void error(const char* fmt, Args&&... args ) { RcppSpdlog::log_error(fmt::format(fmt, std::forward<Args>(args)... ).c_str()); }

    template <typename... Args>
    inline void critical(const char* fmt, Args&&... args ) { RcppSpdlog::log_critical(fmt::format(fmt, std::forward<Args>(args)... ).c_str()); }
    #endif
    
    #endif // if C++11

    inline Rcpp::XPtr<spdlog::stopwatch> stopwatch() { return RcppSpdlog::get_stopwatch(); }
    inline double elapsed(Rcpp::XPtr<spdlog::stopwatch> w) { return RcppSpdlog::elapsed_stopwatch(w); }
    inline std::string format(Rcpp::XPtr<spdlog::stopwatch> w) { return RcppSpdlog::format_stopwatch(w); }

}
