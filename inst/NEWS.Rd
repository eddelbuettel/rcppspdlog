\name{NEWS}
\title{News for Package \pkg{RcppSpdlog}}
\newcommand{\ghpr}{\href{https://github.com/eddelbuettel/rcppspdlog/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/eddelbuettel/rcppspdlog/issues/#1}{##1}}

\section{Changes in RcppSpdlog version 0.0.5 (2020-12-11)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.8.5 (and 1.8.4 and 1.8.3)
    \item Small enhancements to DESCRIPTION files
  }
}

\section{Changes in RcppSpdlog version 0.0.4 (2020-12-11)}{
  \itemize{
    \item Upgraded to upstream release spdlog 1.8.2
    \item Added GitHub Actions CI using \code{run.sh} from r-ci
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
