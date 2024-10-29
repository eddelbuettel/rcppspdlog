
#pragma once

#include <Rcpp/Lightest>
#if defined(RCPPSPDLOG_STOPWATCH_NO_FMT)
  #include <spdlog_stopwatch.h>	    	// spdlog::stopwatch without fmt header
#else
  #include <spdlog/stopwatch.h>   		// also support standard spdlog stopwatch feature
#endif
