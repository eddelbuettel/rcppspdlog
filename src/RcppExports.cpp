// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// exampleRsink
void exampleRsink();
RcppExport SEXP _RcppSpdlog_exampleRsink() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    exampleRsink();
    return R_NilValue;
END_RCPP
}
// setLogLevel
void setLogLevel(const std::string& name);
RcppExport SEXP _RcppSpdlog_setLogLevel(SEXP nameSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type name(nameSEXP);
    setLogLevel(name);
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RcppSpdlog_exampleRsink", (DL_FUNC) &_RcppSpdlog_exampleRsink, 0},
    {"_RcppSpdlog_setLogLevel", (DL_FUNC) &_RcppSpdlog_setLogLevel, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_RcppSpdlog(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
