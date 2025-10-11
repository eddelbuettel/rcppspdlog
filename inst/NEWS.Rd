\name{NEWS}
\title{News for Package \pkg{RcppSpdlog}}
\newcommand{\ghpr}{\href{https://github.com/eddelbuettel/rcppspdlog/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/eddelbuettel/rcppspdlog/issues/#1}{##1}}

\section{Changes in RcppSpdlog version 0.0.23 (2025-10-11)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.16.0 (including fmt 12.0)
    \item The mkdocs-material documentation site is now generated via \pkg{altdoc}
   }
}

\section{Changes in RcppSpdlog version 0.0.22 (2025-05-09)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.15.3 (including fmt 11.2.0)
  }
}

\section{Changes in RcppSpdlog version 0.0.21 (2025-03-30)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.15.2 (including fmt 11.1.4)
  }
}

\section{Changes in RcppSpdlog version 0.0.20 (2025-02-01)}{
  \itemize{
    \item New multi-threaded logging example (Young Geun Kim and Dirk via \ghit{22})
    \item Upgraded to upstream release spdlog 1.15.1
  }
}

\section{Changes in RcppSpdlog version 0.0.19 (2024-11-10)}{
  \itemize{
    \item Support use of \code{std::format} under C++20 via opt-in define
    instead of \code{fmt} (Xanthos Xanthopoulos in \ghpr{19})
    \item An erroneous duplicate log=level documentation level was removed
    (Contantinos Giachalis in \ghpr{20})
    \item Upgraded to upstream release spdlog 1.15.0 (Dirk in \ghpr{21})
    \item Partially revert / simplify \code{src/formatter.cpp} accomodating
    both \ghpr{19} and previous state (Dirk in \ghpr{21})
  }
}

\section{Changes in RcppSpdlog version 0.0.18 (2024-09-10)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.14.1
    \item Minor packaging upgrades
    \item Allow logging levels to be set via environment variable
    \code{SPDLOG_LEVEL}
  }
}

\section{Changes in RcppSpdlog version 0.0.17 (2024-04-25)}{
  \itemize{
    \item Minor continuous integration update
    \item Upgraded to upstream release spdlog 1.14.0
  }
}

\section{Changes in RcppSpdlog version 0.0.16 (2024-01-12)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.13.0
  }
}

\section{Changes in RcppSpdlog version 0.0.15 (2023-11-29)}{
  \itemize{
    \item Correct default package help page slighly
    \item \code{RcppExports.cpp} has been regenerated under an updated
    \pkg{Rcpp} to address a format string warning under R-devel
  }
}

\section{Changes in RcppSpdlog version 0.0.14 (2023-07-09)}{
  \itemize{
    \item Added new badge to README.md
    \item Upgraded to upstream release spdlog 1.12.0
  }
}

\section{Changes in RcppSpdlog version 0.0.13 (2023-06-17)}{
  \itemize{
    \item Minor tweak to \code{stopwatch} setup avoids pulling in \pkg{fmt}
    \item No longer set a C++ compilation standard as the default choices by
    R are sufficient for the package
    \item Add convenience wrapper \code{log_init} omitting first argument to
    \code{log_setup} while preserving the interface from the latter
    \item Add convenience \code{setup} wrappers \code{init} and \code{log} to
    API header file \code{spdl.h}
  }
}

\section{Changes in RcppSpdlog version 0.0.12 (2023-01-07)}{
  \itemize{
    \item Addeed support for 'stopwatch' object allowing for simple timing
    (from both C++ and R) via the logging framework.
    \item The \sQuote{spdlog} logging pattern is documented via a reference.
  }
}

\section{Changes in RcppSpdlog version 0.0.11 (2022-12-13)}{
  \itemize{
    \item Export the formatter at C level
    \item Mention package \pkg{spdl} in README.md
    \item Support simple file-based logger
  }
}

\section{Changes in RcppSpdlog version 0.0.10 (2022-11-17)}{
  \itemize{
    \item Support variadic templates with fmt::format
    \item Add R formatting helper which converts arguments to character
    taking advantage of variadic template logger: fmt logging from R
    \item Expand vignette
  }
}

\section{Changes in RcppSpdlog version 0.0.9 (2022-11-04)}{
  \itemize{
    \item Add both an R and an C++ interface to \code{spdlog}
    \item Update GitHub Actions to checkout@v3
    \item Add a shorter aliased namespace for C++
    \item Upgraded to upstream release spdlog 1.11.0
  }
}

\section{Changes in RcppSpdlog version 0.0.8 (2022-04-04)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.10.0
  }
}

\section{Changes in RcppSpdlog version 0.0.7 (2021-12-05)}{
  \itemize{
    \item Upgraded to upstream bug fix releases spdlog 1.9.1 and 1.9.2
    \item Travis artifacts and badges have been pruned
    \item Vignette now uses \pkg{simplermarkdown}
  }
}

\section{Changes in RcppSpdlog version 0.0.6 (2021-07-21)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.9.0
  }
}

\section{Changes in RcppSpdlog version 0.0.5 (2020-12-11)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.8.5 (and 1.8.4 and 1.8.3)
    \item Small enhancements to DESCRIPTION files
  }
}

\section{Changes in RcppSpdlog version 0.0.4 (2020-12-11)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.8.2
    \item Added GitHub Actions CI using \code{run.sh} from
    \href{https://eddelbuettel.github.io/r-ci/}{r-ci}
  }
}

\section{Changes in RcppSpdlog version 0.0.3 (2020-10-23)}{
  \itemize{
    \item New function \code{setLogLevel} with R accessor in
    \code{exampleRsink} example
    \item Updated \code{exampleRsink} to use default logger instance
    \item Upgraded to upstream release 1.8.1 which contains finalised
    upstream use to switch to REprintf() if R compilation detected
    \item Added new vignette with extensive usage examples, added
    compile-time logging switch example
    \item A package documentation website was added
  }
}

\section{Changes in RcppSpdlog version 0.0.2 (2020-09-17)}{
  \itemize{
    \item Upgraded to upstream release 1.8.0
    \item Switched Travis CI to using BSPM, also test on macOS
    \item Added 'stopwatch' use to main R sink example
  }
}

\section{Changes in RcppSpdlog version 0.0.1 (2020-09-08)}{
  \itemize{
    \item Initial release with added R/Rcpp logging sink example
  }
}
