
#pragma once

// include the auto-generated exports for the exported C++ functions
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
}
