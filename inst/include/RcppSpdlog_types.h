
#pragma once

#include <Rcpp/Lightest>
#include <spdlog/stopwatch.h>   		// also support stopwatch feature

template <typename T> Rcpp::XPtr<T> make_xptr(T* p) {
    return Rcpp::XPtr<T>(p);
}
