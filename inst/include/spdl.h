
#pragma once

// includes the auto-generated exports for the exported (via a C interface) underlying C++ functions
#include <RcppSpdlog.h>

// for convenience define cuter ones in another (shorter) namespace
namespace spdl {
    inline void setup(const std::string& name = "default", const std::string& level = "warn") {  RcppSpdlog::log_setup(name, level); }
    inline void drop(const std::string& name) { RcppSpdlog::log_drop(name); }
    inline void set_pattern(const std::string& s) { RcppSpdlog::log_set_pattern(s); }
    inline void set_level(const std::string& s) { RcppSpdlog::log_set_level(s); }
    inline void trace(const std::string& s) { RcppSpdlog::log_trace(s); }
    inline void debug(const std::string& s) { RcppSpdlog::log_debug(s); }
    inline void info(const std::string& s) { RcppSpdlog::log_info(s); }
    inline void warn(const std::string& s) { RcppSpdlog::log_warn(s); }
    inline void error(const std::string& s) { RcppSpdlog::log_error(s); }
    inline void critical(const std::string& s) { RcppSpdlog::log_critical(s); }

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

}
