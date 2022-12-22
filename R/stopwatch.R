##' @rdname log_setup
print.stopwatch <- function(x, ...) {
    cat(RcppSpdlog::format_stopwatch(x), "\n")
    invisible(x)
}

##' @rdname log_setup
format.stopwatch <- function(x, ...) {
    xx <- RcppSpdlog::format_stopwatch(x)
    names(xx) <- names(x)
    xx
}
