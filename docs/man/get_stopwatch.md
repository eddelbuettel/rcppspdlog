

# R Accessor Functions for spdlog Stopwatch

[**Source code**](https://github.com/eddelbuettel/rcppspdlog/tree/master/R/#L)

## Description

A set of functions provides access to the <code>spdlog</code> stopwatch
facilty. As <code>stopwatch</code> object is a simple container around a
C++ <code>std::chrono</code> object which (essentially) reports
elapsed-time since creation. The object is exported to R via an external
pointer permitting use from both R and C++.

## Usage

<pre><code class='language-R'>get_stopwatch()

elapsed_stopwatch(sw)

format_stopwatch(sw)

# S3 method for class 'stopwatch'
print(x, ...)

# S3 method for class 'stopwatch'
format(x, ...)
</code></pre>

## Arguments

<table role="presentation">
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="sw">sw</code>
</td>
<td>
An S3 object of type <code>stopwatch</code>.
</td>
</tr>
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="x">x</code>
</td>
<td>
An S3 object of type <code>stopwatch</code>.
</td>
</tr>
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="...">…</code>
</td>
<td>
Dotted argument required by generic, unused here.
</td>
</tr>
</table>

## Details

Several functions are provided:

<dl>
<dt>
<code>get_stopwatch</code>
</dt>
<dd>
Returns a stopwatch object (as an S3 object).
</dd>
<dt>
<code>elapsed_stopwatch</code>
</dt>
<dd>
Returns elapsed time for stopwatch in seconds.
</dd>
<dt>
<code>format_stopwatch</code>
</dt>
<dd>
Returns elapsed time for stopwatch as character variable.
</dd>
</dl>

The <code>stopwatch</code> object has <code>print</code> and
<code>format</code> methods.

## Value

The desired object is returned: respectively, a stopwatch object as an
external pointer in an S3 class, the elapsed time in seconds as a
double, or formatted as a character variable.

## Examples

``` r
library("RcppSpdlog")

w <- get_stopwatch()
Sys.sleep(0.2)
elapsed_stopwatch(w)
```

    [1] 0.2009362

``` r
format_stopwatch(w)
```

    [1] "0.201288"
