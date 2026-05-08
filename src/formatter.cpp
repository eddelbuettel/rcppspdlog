
// [[Rcpp::interfaces(r, cpp)]]

#include <RcppSpdlog>

constexpr int max_args = 15;            // Arbitrary but 'smallish'

template<class... Args>
std::string forward_to_format(const std::string s,
                              const std::vector<std::string>& v,
                              const Args... args) {
    if (v.size() == sizeof...(args)) {
#if defined(SPDLOG_USE_STD_FORMAT) && __cplusplus >= 202002L
        // As of 2026-02 we do _not_ set SPDLOG_USE_STD_FORMAT so this section is unused
        return std::vformat(std::string_view(s), std::make_format_args(args...));
#elif __cplusplus >= 202002L
        // This section is now the default under C++20 or later
        return fmt::format(fmt::runtime(s), args...);
#else
        // Fallback
        return fmt::format(s, args...);
#endif
    }
    if constexpr(sizeof...(args) < max_args) {
        return forward_to_format(s, v, args..., v[sizeof...(args)]);
    }
    return std::string(""); // not reached
}

//' Simple Pass-Through Formatter to \code{fmt::format()}
//'
//' The C-level interface of R does not make it easy to pass \code{...}  arguments.
//' This helper function assumes it has already been called with \code{format()}
//' on each argument (as a wrapper can do) so it just spreads out the class to
//' \code{fmt::format{}} which, being C++, uses variadic templates to receive the
//' arguments. The main motivation for this function to able to format string as
//' use by the \sQuote{fmtlib::fmt} library included in \sQuote{spdlog} to write
//' similar debug strings in both R and C++. This function permits R calls with
//' multiple arguments of different types which (by being formatted on the R side)
//' are handled as strings (whereas C++ logging has access to the templating logic).
//'
//' @param s A character variable with a format string for \sQuote{fmtlib::fmt}
//' @param v A character vector with the logging string arguments.
//' @return A single (formatted) string
//' @seealso https://github.com/fmtlib/fmt
// [[Rcpp::export]]
std::string formatter(const std::string s, std::vector<std::string> v) {
    if (v.size() > max_args)
        Rcpp::warning("Only up to " + std::to_string(max_args) + " arguments support for now.");
    return forward_to_format(s, v);
}
