

# R Accessor Functions for spdlog Logger

[**Source code**](https://github.com/eddelbuettel/rcppspdlog/tree/master/R/#L)

## Description

Several R-level functions can access the <code>spdlog</code> logging
facilties. As <code>spdlog</code> is a C++-level logging library, these
are R function permit concurrent logging from both R and C++.

## Usage

<pre><code class='language-R'>log_setup(name = "default", level = "warn")

log_init(level = "warn")

log_filesetup(filename, name = "default", level = "warn")

log_drop(name)

log_set_pattern(s)

log_set_level(s)

log_trace(s)

log_debug(s)

log_info(s)

log_warn(s)

log_error(s)

log_critical(s)
</code></pre>

## Arguments

<table role="presentation">
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="name">name</code>
</td>
<td>
A character variable with the logging instance name, default value is
‘default’.
</td>
</tr>
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="level">level</code>
</td>
<td>
A character variable with the default logging level, default value is
‘warn’.
</td>
</tr>
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="filename">filename</code>
</td>
<td>
A character variable with the logging filename if a file-based logger is
instantiated.
</td>
</tr>
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="s">s</code>
</td>
<td>
A character variable with the logging pattern, level or message.
</td>
</tr>
</table>

## Details

Several functions are provided:

<dl>
<dt>
<code>log_setup</code>
</dt>
<dd>
Initializes a logger (which becomes the default logger).
</dd>
<dt>
<code>log_filesetup</code>
</dt>
<dd>
Initializes a file-based logger (which becomes the default).
</dd>
<dt>
<code>log_drop</code>
</dt>
<dd>
Removes logger (which in general should not be needed).
</dd>
<dt>
<code>log_set_pattern</code>
</dt>
<dd>
Changes the default logging message pattern.
</dd>
<dt>
<code>log_set_level</code>
</dt>
<dd>
Sets the logging level threshold.
</dd>
<dt>
<code>log_trace</code>
</dt>
<dd>
Logs a trace-level message.
</dd>
<dt>
<code>log_debug</code>
</dt>
<dd>
Logs a debug-level message.
</dd>
<dt>
<code>log_info</code>
</dt>
<dd>
Logs a info-level message.
</dd>
<dt>
<code>log_warn</code>
</dt>
<dd>
Logs a warn-level message.
</dd>
<dt>
<code>log_error</code>
</dt>
<dd>
Logs a error-level message.
</dd>
<dt>
<code>log_critical</code>
</dt>
<dd>
Logs a critical-level message.
</dd>
</dl>

Supported logging levels are, in order of increasing threshold values,
‘trace’, ‘debug’, ‘info’, ‘warn’, ‘error’, and ‘critical’. A message
issued below the current threshold is not displayed whereas a message at
or above the current threshold is displayed. The default level is
‘warn’.

## Value

Nothing is returned from these functions as they are invoked for their
side-effects.

## See Also

The logging pattern format is described in at the repo in the page
<a href="https://github.com/gabime/spdlog/wiki/3.-Custom-formatting">https://github.com/gabime/spdlog/wiki/3.-Custom-formatting</a>.

## Examples

``` r
library("RcppSpdlog")

log_setup("demo")  # at default level 'warn'
log_info("this message is NOT seen")
log_set_level("debug")
log_info("this message is seen")
```

    [2025-10-11 14:16:03.482] [demo] [Process: 358] [info] this message is seen

``` r
log_warn("as is this message")
```

    [2025-10-11 14:16:03.482] [demo] [Process: 358] [warning] as is this message
