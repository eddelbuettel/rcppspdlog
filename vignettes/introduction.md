<!--
%\VignetteIndexEntry{RcppSpdlog Introduction}
%\VignetteEngine{simplermarkdown::mdweave_to_html}
%\VignetteEncoding{UTF-8}
-->
---
title: "Introduction to RcppSpdlog"
author: "Dirk Eddelbuettel"
date: "Initial version dated October 2020"
css: "water.css"
---


## Introducing RcppSpdlog

[spdlog](https://github.com/gabime/spdlog) is a widely-used and very capable header-only C++ library for logging.
The [RcppSpdlog](https://github.com/eddelbuettel/rcppspdlog) package provides R users with easy-to-use customized access to the [spdlog](https://github.com/gabime/spdlog) logging library by including its headers in an R package which permit other R packages to deploy it via a simple `LinkingTo: RcppSpdlog` as described in [Section 1.1.3 of WRE](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Package-Dependencies).

[spdlog](https://github.com/gabime/spdlog) is mature and widely deployed.
It also has a very rich set of features described at [the repository wiki](https://github.com/gabime/spdlog/wiki).
This vignette will highlight a few first use cases.

Note that in order to use [RcppSpdlog](https://github.com/eddelbuettel/rcppspdlog) in an R package that might get distributed to [CRAN](https://cran.r-project.org), the code should follow the example
R and C++ code in function `exampleRsink()` as described below.

We will however start with some simpler examples.
_Do not copy those into your R package._
The package checks used by R test for use of `stdout` and `stderr` which is why the customized setup described later is preferable.


## Initial example: Basics

This example follows the simplest and initial example in the [spdlog](https://github.com/gabime/spdlog).
It is also included in the [RcppSpdlog](https://github.com/eddelbuettel/rcppspdlog) package as [examples/exampleOne.cpp](https://github.com/eddelbuettel/rcppspdlog/blob/master/inst/examples/exampleOne.cpp).
As discussed above, do not use this example as a starting point in an R package.


```c++
// based on the 'basic usage' example in the README.md at https://github.com/gabime/spdlog

#include "spdlog/spdlog.h"

#include <Rcpp.h>

// [[Rcpp::depends(RcppSpdlog)]]

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

/*** R
exampleOne()
*/
```

When built, which is easiest via `Rcpp::sourceCpp()`, the final block ensures that the created function `exampleOne()` is executed.
In one previous run, the following output was produded:

```sh
R> exampleOne()
[14:25:03.362024] [I] [thread 2453030] Welcome to spdlog!
[14:25:03.362047] [E] [thread 2453030] Some error message with arg: 1
[14:25:03.362051] [W] [thread 2453030] Easy padding in numbers like 00000012
[14:25:03.362053] [C] [thread 2453030] Support for int: 42;  hex: 2a;  oct: 52; bin: 101010
[14:25:03.362056] [I] [thread 2453030] Support for floats 1.23
[14:25:03.362058] [I] [thread 2453030] Positional args are supported too..
[14:25:03.362060] [I] [thread 2453030] left aligned
[14:25:03.362061] [D] [thread 2453030] This message should be displayed..
R>
```

We note the easy-to-formatting in the source which benefits from the embedded [fmt](https://github.com/fmtlib/fmt) package for easy-to-use variable expansion.
We also notice the different logging "levels" indicated by single letters: _info_, _errror_, _warning_, _critical_ and _debug_.  More on this below.


## Second example: Showcase

This second example follows a more complete example in the [spdlog](https://github.com/gabime/spdlog) documention and highlights numerous features of the library.
As before, this example is also included in the [RcppSpdlog](https://github.com/eddelbuettel/rcppspdlog) package as [examples/exampleTwo.cpp](https://github.com/eddelbuettel/rcppspdlog/blob/master/inst/examples/exampleTwo.cpp).
And as before, do not use this example as a starting point in an R package.

```c++

#include "spdlog/spdlog.h"

#include <Rcpp.h>

void stdout_logger_example();
void basic_example();
void rotating_example();
void daily_example();
void async_example();
void binary_example();
void trace_example();
void multi_sink_example();
void user_defined_example();
void err_handler_example();
void syslog_example();
void clone_example();

#include "spdlog/spdlog.h"

// [[Rcpp::depends(RcppSpdlog)]]

// [[Rcpp::export]]
void exampleTwo() {

    spdlog::info("Welcome to spdlog version {}.{}.{} !",
                 SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:>8} aligned, {:<8} aligned", "right", "left");

    // Runtime log levels
    spdlog::set_level(spdlog::level::info); // Set global log level to info
    spdlog::debug("This message should not be displayed!");
    spdlog::set_level(spdlog::level::trace); // Set specific logger's log level
    spdlog::debug("This message should be displayed..");

    // Customize msg format for all loggers
    spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
    spdlog::info("This an info message with custom format");
    spdlog::set_pattern("%+"); // back to default format

    try
    {
        stdout_logger_example();
        basic_example();
        rotating_example();
        daily_example();
        clone_example();
        async_example();
        binary_example();
        multi_sink_example();
        user_defined_example();
        err_handler_example();
        trace_example();

        // Flush all *registered* loggers using a worker thread every 3 seconds.
        // note: registered loggers *must* be thread safe for this to work correctly!
        spdlog::flush_every(std::chrono::seconds(3));

        // Apply some function on all registered loggers
        spdlog::apply_all([&](std::shared_ptr<spdlog::logger> l) { l->info("End of example."); });

        // Release all spdlog resources, and drop all loggers in the registry.
        // This is optional (only mandatory if using windows + async log).
        //spdlog::shutdown();
    }

    // Exceptions will only be thrown upon failed logger or sink construction (not during logging).
    catch (const spdlog::spdlog_ex &ex)
    {
        std::printf("Log initialization failed: %s\n", ex.what());
        return;
    }

    // added to this example file allow multiple runs of function
    spdlog::drop("console");
    spdlog::drop("file_logger");
    spdlog::drop("some_logger_name");
    spdlog::drop("daily_logger");
    spdlog::drop("async_file_logger");
}


#include "spdlog/sinks/stdout_color_sinks.h"
// or #include "spdlog/sinks/stdout_sinks.h" if no colors needed.
void stdout_logger_example()
{
    // Create color multi threaded logger.
    auto console = spdlog::stdout_color_mt("console");
    // or for stderr:
    // auto console = spdlog::stderr_color_mt("error-logger");
}

#include "spdlog/sinks/basic_file_sink.h"
void basic_example()
{
    // Create basic file logger (not rotated).
    auto my_logger = spdlog::basic_logger_mt("file_logger", "logs/basic-log.txt");
}

#include "spdlog/sinks/rotating_file_sink.h"
void rotating_example()
{
    // Create a file rotating logger with 5mb size max and 3 rotated files.
    auto rotating_logger =
        spdlog::rotating_logger_mt("some_logger_name", "logs/rotating.txt", 1048576 * 5, 3);
}

#include "spdlog/sinks/daily_file_sink.h"
void daily_example()
{
    // Create a daily logger - a new file is created every day on 2:30am.
    auto daily_logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);
}

// Clone a logger and give it new name.
// Useful for creating component/subsystem loggers from some "root" logger.
void clone_example()
{
    auto network_logger = spdlog::default_logger()->clone("network");
    network_logger->info("Logging network stuff..");
}

#include "spdlog/async.h"
void async_example()
{
    // Default thread pool settings can be modified *before* creating the async logger:
    // spdlog::init_thread_pool(32768, 1); // queue with max 32k items 1 backing thread.
    auto async_file =
        spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_log.txt");
    // alternatively:
    // auto async_file =
    //     spdlog::create_async<spdlog::sinks::basic_file_sink_mt>("async_file_logger",
    //     "logs/async_log.txt");

    for (int i = 1; i < 101; ++i)
    {
        async_file->info("Async message #{}", i);
    }
}

// Log binary data as hex.
// Many types of std::container<char> types can be used.
// Iterator ranges are supported too.
// Format flags:
// {:X} - print in uppercase.
// {:s} - don't separate each byte with space.
// {:p} - don't print the position on each line start.
// {:n} - don't split the output to lines.

#include "spdlog/fmt/bin_to_hex.h"
void binary_example()
{
    std::vector<char> buf;
    for (int i = 0; i < 80; i++)
    {
        buf.push_back(static_cast<char>(i & 0xff));
    }
    spdlog::info("Binary example: {}", spdlog::to_hex(buf));
    spdlog::info("Another binary example:{:n}",
                 spdlog::to_hex(std::begin(buf), std::begin(buf) + 10));
    // more examples:
    // logger->info("uppercase: {:X}", spdlog::to_hex(buf));
    // logger->info("uppercase, no delimiters: {:Xs}", spdlog::to_hex(buf));
    // logger->info("uppercase, no delimiters, no position info: {:Xsp}", spdlog::to_hex(buf));
}

// Compile time log levels.
// define SPDLOG_ACTIVE_LEVEL to required level (e.g. SPDLOG_LEVEL_TRACE)
void trace_example()
{
    // trace from default logger
    SPDLOG_TRACE("Some trace message.. {} ,{}", 1, 3.23);
    // debug from default logger
    SPDLOG_DEBUG("Some debug message.. {} ,{}", 1, 3.23);

    // trace from logger object
    auto logger = spdlog::get("file_logger");
    SPDLOG_LOGGER_TRACE(logger, "another trace message");
}

// A logger with multiple sinks (stdout and file) - each with a different format and log level.
void multi_sink_example()
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::warn);
    console_sink->set_pattern("[multi_sink_example] [%^%l%$] %v");

    auto file_sink =
        std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/multisink.txt", true);
    file_sink->set_level(spdlog::level::trace);

    spdlog::logger logger("multi_sink", {console_sink, file_sink});
    logger.set_level(spdlog::level::debug);
    logger.warn("this should appear in both console and file");
    logger.info("this message should not appear in the console, only in the file");
}

// User defined types logging by implementing operator<<
#include "spdlog/fmt/ostr.h" // must be included
struct my_type
{
    int i;
    template<typename OStream>
    friend OStream &operator<<(OStream &os, const my_type &c)
    {
        return os << "[my_type i=" << c.i << "]";
    }
};

void user_defined_example()
{
    spdlog::info("user defined type: {}", my_type{14});
}

// Custom error handler. Will be triggered on log failure.
void err_handler_example()
{
    // can be set globally or per logger(logger->set_error_handler(..))
    spdlog::set_error_handler([](const std::string &msg) {
         printf("*** Custom log error handler: %s ***\n", msg.c_str()); });
}

// syslog example (linux/osx/freebsd)
#ifndef _WIN32
#include "spdlog/sinks/syslog_sink.h"
void syslog_example()
{
    std::string ident = "spdlog-example";
    auto syslog_logger = spdlog::syslog_logger_mt("syslog", ident, LOG_PID);
    syslog_logger->warn("This is warning that will end up in syslog.");
}
#endif

// Android example.
#if defined(__ANDROID__)
#include "spdlog/sinks/android_sink.h"
void android_example()
{
    std::string tag = "spdlog-android";
    auto android_logger = spdlog::android_logger_mt("android", tag);
    android_logger->critical("Use \"adb shell logcat\" to view this message.");
}

#endif


/*** R
exampleTwo()
*/

```

We are not showing the output here; it can be compiled, linked, loaded and run just as above by simply passing the filename to `Rcpp::sourceCpp()`.
Note that is will create a few demonstration logfiles so you may want to run the example from a temporary directory.


## Third example: Colour

The next example highlights a colour 'sink' for the logger.
Again, do not use this as a starting point for your package as `R CMD check` will protest about use of `stdout`.

```c++

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <Rcpp.h>

// [[Rcpp::depends(RcppSpdlog)]]

// [[Rcpp::export]]
void exampleThree() {

  auto console = spdlog::stdout_color_mt("console");

  // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
  spdlog::set_pattern("[%H:%M:%S.%f] [%^%L%$] [thread %t] %v");
  spdlog::info("This an info message with custom format");
  //spdlog::set_pattern("%+"); // back to default format

  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);

  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");
  spdlog::info("{:<30}", "left aligned");


  // added to this example file allow multiple runs of different package functions
  spdlog::drop("console");

}

/*** R
exampleThree()
*/
```

When running this example in a terminal capable of displaying colour escape sequence, the logging levels are distinguished by colour.
This ranges from green ("info") to yellow ("warning") to red ("error") and white-on-red ("critical").
Not that in this vignette color from standard output does how not show (in the keep-it-simple-mode we are using here).

```sh
R> exampleThree()
[14:47:52.260692] [I] [thread 2502026] This an info message with custom format
[14:47:52.260715] [I] [thread 2502026] Welcome to spdlog!
[14:47:52.260732] [E] [thread 2502026] Some error message with arg: 1
[14:47:52.260734] [W] [thread 2502026] Easy padding in numbers like 00000012
[14:47:52.260736] [C] [thread 2502026] Support for int: 42;  hex: 2a;  oct: 52; bin: 101010
[14:47:52.260739] [I] [thread 2502026] Support for floats 1.23
[14:47:52.260741] [I] [thread 2502026] Positional args are supported too..
[14:47:52.260743] [I] [thread 2502026] left aligned
R>
```

## Fourth Example: Dedicated R Logger

The next example is suitable for use in R packages, and in fact included as an example in the package.
We include the source file [src/exampleRsink.cpp](https://github.com/eddelbuettel/rcppspdlog/blob/master/src/exampleRsink.cpp).

```c++
// this portmanteau include also defines the r_sink we use below, and which
// diverts all logging to R via the Rcpp::Rcout replacement for std::cout
#include <RcppSpdlog>
#include <spdlog/stopwatch.h>   		// also support stopwatch feature

//' spdlog Example using a sink for R
//'
//' A simple example invoking a derived R/Rcpp logger. Also demonstrates the
//' stopwatch feature. For more features see the 'spdlog' documnetation.
//'
//' Note that this no longer triggers R warnings thanks to excellent help by
//' Gabi Melman.
//' @return None
//' @examples
//' exampleRsink()
// [[Rcpp::export]]
void exampleRsink() {

    std::string logname = "fromR"; 							// fix a name for this logger
    auto sp = spdlog::get(logname);       					// retrieve existing one
    if (sp == nullptr) sp = spdlog::r_sink_mt(logname);   	// or create new one if needed
    spdlog::set_default_logger(sp);                         // and set as default

    spdlog::stopwatch sw;       							// instantiate a stop watch

    // change log pattern (changed from [%H:%M:%S %z] [%n] [%^---%L---%$] )
    spdlog::set_pattern("[%H:%M:%S.%f] [%n] [%^%L%$] [thread %t] %v");

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    spdlog::info("Elapsed time: {}", sw);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");
    spdlog::info("Elapsed time: {}", sw);

}

//' spdlog Logging Lever Setter
//'
//' A helper function to turn a logging level given as string
//' into the current logging level
//'
//' @param name A string with the logging level. Value understood are,
//' in decreasing verbosity \sQuote{trace}, \sQuote{debug}, \sQuote{info},
//' \sQuote{warning}, \sQuote{error}, \sQuote{critical}, and \sQuote{off}.
//' Unrecognised names are equivalent to \sQuote{off}.
//' @return Nothing is returned.
// [[Rcpp::export]]
void setLogLevel(const std::string &name) {
    spdlog::set_level(spdlog::level::from_str(name));
}

```

The example file contains three key aspects to highlight:
- use of the `r_sink_mt()` class for R-specific logger sink
- use of the very convenient `stopwatch` object
- use of logging levels

We highlight these below after first showing the relevant output:

```sh
R> exampleRsink()
[16:52:12.076751] [fromR] [I] [thread 2453030] Welcome to spdlog!
[16:52:12.076809] [fromR] [E] [thread 2453030] Some error message with arg: 1
[16:52:12.076823] [fromR] [I] [thread 2453030] Elapsed time: 9.6104e-05
[16:52:12.076833] [fromR] [W] [thread 2453030] Easy padding in numbers like 00000012
[16:52:12.076844] [fromR] [C] [thread 2453030] Support for int: 42;  hex: 2a;  oct: 52; bin: 101010
[16:52:12.076853] [fromR] [I] [thread 2453030] Support for floats 1.23
[16:52:12.076871] [fromR] [I] [thread 2453030] Positional args are supported too..
[16:52:12.076879] [fromR] [I] [thread 2453030] left aligned
[16:52:12.076892] [fromR] [I] [thread 2453030] Elapsed time: 0.000167057
R>
```

#### R-specific sink

[spdlog](https://github.com/gabime/spdlog) has the ability to derive and sub-class sinks for logger.
The [RcppSpdlog](https://github.com/eddelbuettel/rcppspdlog) package uses this feature to implement a sink using the Rcpp conduit `Rcpp::Rcout` instead of `std::cout` as it conveniently redirects to
the R output stream.
This class should be the default one for any R packages wanting to use [spdlog](https://github.com/gabime/spdlog)  while also passing `R CMD check`.

A second important aspect of the initial code in function `exampleRsink()` is how a named logging instance is requested.
If none is found, a new one is instantiated.
Next, this logger is made the default logger permitting convenient programmatic access via `spdlog::`.

#### Stopwatch

A powerful (recent) feature of the include [fmt](https://github.com/fmtlib/fmt) library is the automatic formatting of timestamps and interval.
As the code example shows, simply instantianting an object, here called `sw`, and referring to it later is all that takes.


#### Log-Level

A second utility function `setLogLevel()` is also provided.
Usage is simple: after calling it with a given level, only message equal to it or higher are shown as the next example shows.

```sh
R> setLogLevel("error")
R> exampleRsink()
[16:54:12.666261] [fromR] [E] [thread 2453030] Some error message with arg: 1
[16:54:12.666286] [fromR] [C] [thread 2453030] Support for int: 42;  hex: 2a;  oct: 52; bin: 101010
R>
```

By requestion level 'error', message of level 'info', 'warning' or 'debug' are suppressed but messages levels 'error' or 'critical' as shown as desired.

## Fifth Example: Initialization

Package desiring to use [RcppSpdlog](https://github.com/eddelbuettel/rcppspdlog) can initialize its facilities during startup.

For that we first define a setup function

```c++
// this portmanteau include also defines the r_sink we use below, and which
// diverts all logging to R via the Rcpp::Rcout replacement for std::cout
#include <RcppSpdlog>

//' Set a new default logger for R
//'
// [[Rcpp::export]]
void setDefault() {
    std::string logname = "fromR"; 							// fix a name for this logger
    auto sp = spdlog::get(logname);        					// retrieve existing one
    if (sp == nullptr) sp = spdlog::r_sink_mt(logname);   	// or create new one if needed
    sp->set_pattern("[%H:%M:%S.%f] [%^%L%$] %v");
    spdlog::set_default_logger(sp);
}
```

We can then call this function during startup:


```r
.onLoad <- function(libname, pkgname) {
    setDefault();
}
```

## Sixth Example: Compile-time Selection

Of course, [spdlog](https://github.com/gabime/spdlog) also supports a common
usage paradigm with loggers in which the decision of whether to log or not is
_compile-time_ rather than run time.  As this is typically implemented via
macros, usage is via upper-case macros as well.

The following example shows a function with three different logging-level
statements as well as a `#define` set such one and only one is
shown. Similarly, code can contain debug or trace or info or ... statements
which would _not_ appear in the actually loaded "production code" (or CRAN
version) if the compile-time logging level define is set high enough.

```c++
// this portmanteau include also defines the r_sink we use below, and which
// diverts all logging to R via the Rcpp::Rcout replacement for std::cout
#include <RcppSpdlog>

// A define such as this could also be set in src/Makevars via a -D flag
#define SPDLOG_LOG_LEVEL  SPDLOG_LEVEL_CRITICAL

// [[Rcpp::export]]
void demoInvisible() {
    Rcpp::Rcout << "Hello from demoInvisible, just to show we're being called...\n";

    // trace message via default logger
    SPDLOG_TRACE("Some trace message.. {} ,{}", 1, 3.23);
    // debug message via default logger
    SPDLOG_DEBUG("Some debug message.. {} ,{}", 1, 3.23);
    // debug message via default logger
    SPDLOG_CRITICAL("Some critical message.. {} ,{}", 1, 3.23);
}
```

When a piece of code with such compile-time defines is used, we see the
expected outcome. The following example uses default logger, and as the
preceding section showed this can be set up to be the custom R sink:

```r
R> Rcpp::sourceCpp("/tmp/rcppspdlog.cpp")  # plus a '// [[Rcpp:depends("RcppSpdlog")'
R> demoInvisible()
Hello from demoInvisible, just to show we're being called...
[08:44:48.198075] [fromR] [C] [thread 2453030] Some critical message.. 1 ,3.23
R>
```

## Conclusion

[spdlog](https://github.com/gabime/spdlog) and the included [fmt](https://github.com/fmtlib/fmt) are two very powerful and widely used C++ libraries.
The [RcppSpdlog](https://github.com/eddelbuettel/rcppspdlog) package adds to them to the set of packages R users can deploy.
It is our hope that the examples shown here are of interest to R users who are looking for effortless, performant and flexible logging solutions for their compiled R extension packages.
