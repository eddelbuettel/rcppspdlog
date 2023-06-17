
## R Accessor Functions for spdlog Logger

### Description

Several R-level functions can access the `spdlog` logging facilties. As
`spdlog` is a C++-level logging library, these are R function permit
concurrent logging from both R and C++.

### Usage

``` R
log_setup(name = "default", level = "warn")

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
```

### Arguments

|            |                                                                                        |
|------------|----------------------------------------------------------------------------------------|
| `name`     | A character variable with the logging instance name, default value is ‘default’.       |
| `level`    | A character variable with the default logging level, default value is ‘warn’.          |
| `filename` | A character variable with the logging filename if a file-based logger is instantiated. |
| `s`        | A character variable with the logging pattern, level or message.                       |

### Details

Several functions are provided:

`log_setup`  
Initializes a logger (which becomes the default logger).

`log_filesetup`  
Initializes a file-based logger (which becomes the default).

`log_drop`  
Removes logger (which in general should not be needed).

`log_set_pattern`  
Changes the default logging message pattern.

`log_set_level`  
Sets the logging level threshold.

`log_trace`  
Logs a trace-level message.

`log_debug`  
Logs a debug-level message.

`log_info`  
Logs a info-level message.

`log_warn`  
Logs a warn-level message.

`log_error`  
Logs a error-level message.

`log_critical`  
Logs a critical-level message.

Supported logging levels are, in order of increasing threshold values,
‘trace’, ‘debug’, ‘warn’, ‘info’, ‘warn’, ‘error’, and ‘critical’. A
message issued below the current threshold is not displayed whereas a
message at or above the current threshold is displayed. The default
level is ‘warn’.

### Value

Nothing is returned from these functions as they are invoked for their
side-effects.

### See Also

The logging pattern format is described in at the repo in the page
<https://github.com/gabime/spdlog/wiki/3.-Custom-formatting>.

### Examples

``` R
log_setup("demo")  # at default level 'warn'
log_info("this message is NOT seen")
log_set_level("debug")
log_info("this message is seen")
log_warn("as is this message")
```

