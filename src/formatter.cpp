
// [[Rcpp::interfaces(r, cpp)]]

#include <RcppSpdlog>

#if defined(SPDLOG_USE_STD_FORMAT) && __cplusplus >= 202002L
#define NAMESPACE std
#else
#define NAMESPACE fmt
#endif

template<std::size_t... S>
NAMESPACE::format_args unpack_vector(const std::vector<std::string>& vec, std::index_sequence<S...>) {
    return NAMESPACE::make_format_args(vec[S]...);
}

template<std::size_t size>
NAMESPACE::format_args unpack_vector(const std::vector<std::string>& vec) {
    return unpack_vector(vec, std::make_index_sequence<size>());
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
    size_t n = v.size();
    switch (n) {
        case 0: return NAMESPACE::vformat(NAMESPACE::string_view(s), NAMESPACE::make_format_args());
        case 1: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<1>(v));
        case 2: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<2>(v));
        case 3: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<3>(v));
        case 4: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<4>(v));
        case 5: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<5>(v));
        case 6: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<6>(v));
        case 7: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<7>(v));
        case 8: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<8>(v));
        case 9: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<9>(v));
        case 10: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<10>(v));
        case 11: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<11>(v));
        case 12: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<12>(v));
        case 13: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<13>(v));
        case 14: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<14>(v));
        case 15: return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<15>(v));
        default: {
            Rcpp::warning("Only up to fifteen arguments support for now.");
            return NAMESPACE::vformat(NAMESPACE::string_view(s), unpack_vector<12>(v));
        }
    }
}
    
