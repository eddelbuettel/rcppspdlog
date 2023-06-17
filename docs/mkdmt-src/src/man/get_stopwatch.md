
## R Accessor Functions for spdlog Stopwatch

### Description

A set of functions provides access to the `spdlog` stopwatch facilty. As
`stopwatch` object is a simple container around a C++ `std::chrono`
object which (essentially) reports elapsed-time since creation. The
object is exported to R via an external pointer permitting use from both
R and C++.

### Usage

``` R
get_stopwatch()

elapsed_stopwatch(sw)

format_stopwatch(sw)

## S3 method for class 'stopwatch'
print(x, ...)

## S3 method for class 'stopwatch'
format(x, ...)
```

### Arguments

|       |                                                   |
|-------|---------------------------------------------------|
| `sw`  | An S3 object of type `stopwatch`.                 |
| `x`   | An S3 object of type `stopwatch`.                 |
| `...` | Dotted argument required by generic, unused here. |

### Details

Several functions are provided:

`get_stopwatch`  
Returns a stopwatch object (as an S3 object).

`elapsed_stopwatch`  
Returns elapsed time for stopwatch in seconds.

`format_stopwatch`  
Returns elapsed time for stopwatch as character variable.

The `stopwatch` object has `print` and `format` methods.

### Value

The desired object is returned: respectively, a stopwatch object as an
external pointer in an S3 class, the elapsed time in seconds as a
double, or formatted as a character variable.

### Examples

``` R
w <- get_stopwatch()
Sys.sleep(0.2)
elapsed_stopwatch(w)
format_stopwatch(w)
```

