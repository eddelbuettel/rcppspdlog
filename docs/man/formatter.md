

# Simple Pass-Through Formatter to <code>fmt::format()</code>

## Description

The C-level interface of R does not make it easy to pass <code>…</code>
arguments. This helper function assumes it has already been called with
<code>format()</code> on each argument (as a wrapper can do) so it just
spreads out the class to <code>fmt::format{}</code> which, being C++,
uses variadic templates to receive the arguments. The main motivation
for this function to able to format string as use by the ‘fmtlib::fmt’
library included in ‘spdlog’ to write similar debug strings in both R
and C++. This function permits R calls with multiple arguments of
different types which (by being formatted on the R side) are handled as
strings (whereas C++ logging has access to the templating logic).

## Usage

<pre><code class='language-R'>formatter(s, v)
</code></pre>

## Arguments

<table role="presentation">
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="s">s</code>
</td>
<td>
A character variable with a format string for ‘fmtlib::fmt’
</td>
</tr>
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="v">v</code>
</td>
<td>
A character vector with the logging string arguments.
</td>
</tr>
</table>

## Value

A single (formatted) string

## See Also

https://github.com/fmtlib/fmt
