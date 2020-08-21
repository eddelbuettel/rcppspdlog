
## RcppSpdlog: Bundling of spdlog for use from R and Rcpp

[![Build Status](https://travis-ci.org/eddelbuettel/rcppspdlog.png)](https://travis-ci.org/eddelbuettel/rcppspdlog) 
[![License](https://img.shields.io/badge/license-GPL%20%28%3E=%202%29-brightgreen.svg?style=flat)](https://www.gnu.org/licenses/gpl-2.0.html) 

### About

The [spdlog](https://github.com/gabime/spdlog) library is a widely-used and very capable header-only
C++ library for logging.  This package includes its headers as an R package to permit other R
packages to deploy it via a simple `LinkingTo: RcppSpdlog` as described in [Section 1.1.3 of
WRE](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Package-Dependencies).


### Example

A simple first example, following the upstream examples:

```sh
edd@rob:~$ Rscript -e 'Rcpp::sourceCpp("inst/examples/exampleOne.cpp")'

R> exampleOne()
[07:45:57.168673] [I] [thread 1500593] Welcome to spdlog!
[07:45:57.168704] [E] [thread 1500593] Some error message with arg: 1
[07:45:57.168707] [W] [thread 1500593] Easy padding in numbers like 00000012
[07:45:57.168710] [C] [thread 1500593] Support for int: 42;  hex: 2a;  oct: 52; bin: 101010
[07:45:57.168728] [I] [thread 1500593] Support for floats 1.23
[07:45:57.168731] [I] [thread 1500593] Positional args are supported too..
[07:45:57.168734] [I] [thread 1500593] left aligned                  
[07:45:57.168737] [D] [thread 1500593] This message should be displayed..
edd@rob:~$ 
```

This logs the hour, minute, second, microsecond followed by a one-char code for info, error, warning
or critical followed by the thread id and the actual loggable message. The code, apart from the
included headers and more, is simply

```c++
// [[Rcpp::export]]
void exampleOne() {

  // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
  spdlog::set_pattern("[%H:%M:%S.%f] [%L] [thread %t] %v");

  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);

  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");
  spdlog::info("{:<30}", "left aligned");

  spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  spdlog::debug("This message should be displayed..");

  // Compile time log levels
  // define SPDLOG_ACTIVE_LEVEL to desired level
  SPDLOG_TRACE("Some trace message with param {}", {});
  SPDLOG_DEBUG("Some debug message");

}
```

Many other customizations are possible, see the [spdlog
wiki](https://github.com/gabime/spdlog/wiki).

Note that using `spdlog` examples directly _may_ well trigger warning from R during package checking
as `stdout` and/or `stderr` may be used. See the included example function described in the next
section which uses a derived class to pass logging output explicitly to the R input/output stream as
per the R coding requirements, see [Section 1.3.1 (and others) of
WRE](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Checking-packages).


### Use in R Packages and Warnings

As shipped, both [spdlog](https://github.com/gabime/spdlog) and the embedded
[fmt](https://github.com/fmtlib/fmt) use `stdout` and `stderr` in ways that may make it non-trivial
to fully replace them with R input/output as required by [Section 1.3.1 (and others) of
WRE](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Checking-packages). 

However, based on some initial trials and some excellent help from upstream we have defined a
specific sink for R in the header
[`rcpp_sink.h`](https://github.com/eddelbuettel/rcppspdlog/blob/master/inst/include/rcpp_sink.h),
corrected one `stderr` use and added one `#define`.  That combination now passes as can be seen in
checks of the package `RcppSpdlog` and the included function `exampleRsink()` whose complete source
code is included here:

```c++

// this define is important to not include another logger pulling in stdout
#define SPDLOG_DISABLE_DEFAULT_LOGGER 1

// this portmanteau include also defines the r_sink we use below, and which
// diverts all logging to R via the Rcpp::Rcout replacement for std::cout
#include <RcppSpdlog>

//' spdlog Example using a sink for R
//'
//' A simple example invoking a derived R/Rcpp logger.
//'
//' Note that this no longer triggers R warnings thanks to excellent help by
//' Gabi Melman.
//' @return None
//' @examples
//' exampleRsink()
// [[Rcpp::export]]
void exampleRsink() {

    std::string logname = "fromR";                          // fix a name for this logger
    auto sp = spdlog::get(logname);                         // retrieve existing one
    if (sp == nullptr) sp = spdlog::r_sink_mt(logname);     // or create new one if needed

    // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
    sp->set_pattern("[%H:%M:%S.%f] [%n] [%^%L%$] [thread %t] %v");

    sp->info("Welcome to spdlog!");
    sp->error("Some error message with arg: {}", 1);

    sp->warn("Easy padding in numbers like {:08d}", 12);
    sp->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    sp->info("Support for floats {:03.2f}", 1.23456);
    sp->info("Positional args are {1} {0}..", "too", "supported");
    sp->info("{:<30}", "left aligned");

}
```

Note that it is deliberately similar in use to the example above.  A new instance of the logger is
instantiated as a shared pointer `sp` to a `spdlog` object. 

We may make additional package features available in the future.


### Author

[Gabi Melman](https://github.com/gabime) is the main author of [spdlog](https://github.com/gabime/spdlog).

[Victor Zverovich](https://github.com/vitaut) is the main author of the embedded [fmt](https://github.com/fmtlib/fmt) library.

[Dirk Eddelbuettel](https://dirk.eddelbuettel.com) is author of this package and the R integration.

### License

[spdlog](https://github.com/gabime/spdlog) and [fmt](https://github.com/fmtlib/fmt) are under the
MIT license.

RcppSpdlog is released under the GNU GPL, version 2 or later, just like R and Rcpp.
