
#pragma once

#if defined(SPDLOG_USE_STD_FORMAT) && __cplusplus < 202002L
#error SPDLOG_USE_STD_FORMAT should only be set when compiling with C++20 and greater
#endif

#include <Rcpp/Lightest>
#if defined(RCPPSPDLOG_STOPWATCH_NO_FMT)
  #include <spdlog_stopwatch.h>	    	// spdlog::stopwatch without fmt header
#else
  #include <spdlog/stopwatch.h>   		// also support standard spdlog stopwatch feature
#endif
