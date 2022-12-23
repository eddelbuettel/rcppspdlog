##' @rdname get_stopwatch
print.stopwatch <- function(x, ...) {
    cat(RcppSpdlog::format_stopwatch(x), "\n")
    invisible(x)
}

##' @rdname get_stopwatch
format.stopwatch <- function(x, ...) {
    xx <- RcppSpdlog::format_stopwatch(x)
    names(xx) <- names(x)
    xx
}
