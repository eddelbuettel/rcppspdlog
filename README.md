
## RcppSpdlog: Bundling of spdlog for use from R and Rcpp


### About

The [spdlog](https://github.com/gabime/spdlog) library is a widely-used and
very capable header-only C++ library for logging.  This package includes it
as an R package to permit other R package use via a simple `LinkingTo:
RcppSpdlog` as described in [Section 1.1.3 of
WRE](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Package-Dependencies).

### Example

A simple first example:

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

This logs the hour, minute, second, microsecond followed by a one-char code
for info, error, warning or critical followed by the thread id and the actual
loggable message. The code, apart from the included headers and more, is
simply

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

Many other customizations are possible, see the [spdlog wiki](https://github.com/gabime/spdlog/wiki).

### Use in R Packages and Warnings

Both [spdlog](https://github.com/gabime/spdlog) and the embedded
[fmt](https://github.com/fmtlib/fmt) use `stdout` and `stderr` in ways that
make it non-trivial to replace them with R input/output as required by
[Section 1.3.1 (and others) of
WRE](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Checking-packages). Hence,
this library is best used _during debugging_ but not in released code as CRAN
may reject packages containing it due to these warnings.

### Author

Gabi Melman is the main author of [spdlog](https://github.com/gabime/spdlog).

Victor Zverovich is the main author of the embedded [fmt](https://github.com/fmtlib/fmt) library.

Dirk Eddelbuettel is author of this package and the R integration.

### License

[spdlog](https://github.com/gabime/spdlog) and
[fmt](https://github.com/fmtlib/fmt) are under the MIT license.

RcppSpdlog is released under the GNU GPL, version 2 or later, just like R and Rcpp.
