

# spdlog Example using a sink for R

[**Source code**](https://github.com/eddelbuettel/rcppspdlog/tree/master/R/#L)

## Description

A simple example invoking a derived R/Rcpp logger. Also demonstrates the
stopwatch feature. For more features see the ‘spdlog’ documnetation.

## Usage

<pre><code class='language-R'>exampleRsink()
</code></pre>

## Details

Note that this no longer triggers R warnings thanks to excellent help by
Gabi Melman.

## Value

None

## Examples

``` r
library("RcppSpdlog")

exampleRsink()
```

    [14:16:01.129698] [fromR] [I] [thread 216] Welcome to spdlog!
    [14:16:01.129751] [fromR] [E] [thread 216] Some error message with arg: 1
    [14:16:01.129754] [fromR] [I] [thread 216] Elapsed time: 5.9513e-05
    [14:16:01.129756] [fromR] [W] [thread 216] Easy padding in numbers like 00000012
    [14:16:01.129758] [fromR] [C] [thread 216] Support for int: 42;  hex: 2a;  oct: 52; bin: 101010
    [14:16:01.129760] [fromR] [I] [thread 216] Support for floats 1.23
    [14:16:01.129761] [fromR] [I] [thread 216] Positional args are supported too..
    [14:16:01.129763] [fromR] [I] [thread 216] left aligned                  
    [14:16:01.129764] [fromR] [I] [thread 216] Elapsed time: 7.0283e-05
