
## spdlog Logging Lever Setter

### Description

A helper function to turn a logging level given as string into the
current logging level

### Usage

    setLogLevel(name)

### Arguments

| Argument | Description                                                                                                                                                                                     |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `name`   | A string with the logging level. Value understood are, in decreasing verbosity ‘trace’, ‘debug’, ‘info’, ‘warning’, ‘error’, ‘critical’, and ‘off’. Unrecognised names are equivalent to ‘off’. |

### Value

Nothing is returned.

