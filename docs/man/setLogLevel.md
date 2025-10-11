

# spdlog Logging Lever Setter

## Description

A helper function to turn a logging level given as string into the
current logging level

## Usage

<pre><code class='language-R'>setLogLevel(name)
</code></pre>

## Arguments

<table role="presentation">
<tr>
<td style="white-space: nowrap; font-family: monospace; vertical-align: top">
<code id="name">name</code>
</td>
<td>
A string with the logging level. Value understood are, in decreasing
verbosity ‘trace’, ‘debug’, ‘info’, ‘warning’, ‘error’, ‘critical’, and
‘off’. Unrecognised names are equivalent to ‘off’.
</td>
</tr>
</table>

## Value

Nothing is returned.
