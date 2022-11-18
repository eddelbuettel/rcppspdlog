
## Simple Pass-Through Formatter to `fmt::format()`

### Description

The C-level interface of R does not make it easy to pass `...`
arguments. This helper function assumes it has already been called with
`format()` on each argument (as a wrapper can do) so it just spreads out
the class to `fmt::format{}` which, being C++, uses variadic templates
to receive the arguments. The main motivation for this function to able
to format string as use by the ‘fmtlib::fmt’ library included in
‘spdlog’ to write similar debug strings in both R and C++. This function
permits R calls with multiple arguments of different types which (by
being formatted on the R side) are handled as strings (whereas C++
logging has access to the templating logic).

### Usage

``` R
formatter(s, v)
```

### Arguments

|     |                                                             |
|-----|-------------------------------------------------------------|
| `s` | A character variable with a format string for ‘fmtlib::fmt’ |
| `v` | A character vector with the logging string arguments.       |

### Value

A single (formatted) string

### See Also

https://github.com/fmtlib/fmt

