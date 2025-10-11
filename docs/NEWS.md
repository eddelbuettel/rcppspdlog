

# News for Package <span class="pkg">RcppSpdlog</span>

## Changes in RcppSpdlog version 0.0.23 (2025-10-11)

<ul>
<li>

Upgraded to upstream release spdlog 1.16.0 (including fmt 12.0)

</li>
<li>

The mkdocs-material documentation site is now generated via
<span class="pkg">altdoc</span>

</li>
</ul>

## Changes in RcppSpdlog version 0.0.22 (2025-05-09)

<ul>
<li>

Upgraded to upstream release spdlog 1.15.3 (including fmt 11.2.0)

</li>
</ul>

## Changes in RcppSpdlog version 0.0.21 (2025-03-30)

<ul>
<li>

Upgraded to upstream release spdlog 1.15.2 (including fmt 11.1.4)

</li>
</ul>

## Changes in RcppSpdlog version 0.0.20 (2025-02-01)

<ul>
<li>

New multi-threaded logging example (Young Geun Kim and Dirk via
<a href="https://github.com/eddelbuettel/rcppspdlog/issues/22">[#22](https://github.com/eddelbuettel/rcppspdlog/issues/22)</a>)

</li>
<li>

Upgraded to upstream release spdlog 1.15.1

</li>
</ul>

## Changes in RcppSpdlog version 0.0.19 (2024-11-10)

<ul>
<li>

Support use of <code>std::format</code> under C++20 via opt-in define
instead of <code>fmt</code> (Xanthos Xanthopoulos in
<a href="https://github.com/eddelbuettel/rcppspdlog/pull/19">[#19](https://github.com/eddelbuettel/rcppspdlog/issues/19)</a>)

</li>
<li>

An erroneous duplicate log=level documentation level was removed
(Contantinos Giachalis in
<a href="https://github.com/eddelbuettel/rcppspdlog/pull/20">[#20](https://github.com/eddelbuettel/rcppspdlog/issues/20)</a>)

</li>
<li>

Upgraded to upstream release spdlog 1.15.0 (Dirk in
<a href="https://github.com/eddelbuettel/rcppspdlog/pull/21">[#21](https://github.com/eddelbuettel/rcppspdlog/issues/21)</a>)

</li>
<li>

Partially revert / simplify <code>src/formatter.cpp</code> accomodating
both
<a href="https://github.com/eddelbuettel/rcppspdlog/pull/19">[#19](https://github.com/eddelbuettel/rcppspdlog/issues/19)</a> and
previous state (Dirk in
<a href="https://github.com/eddelbuettel/rcppspdlog/pull/21">[#21](https://github.com/eddelbuettel/rcppspdlog/issues/21)</a>)

</li>
</ul>

## Changes in RcppSpdlog version 0.0.18 (2024-09-10)

<ul>
<li>

Upgraded to upstream release spdlog 1.14.1

</li>
<li>

Minor packaging upgrades

</li>
<li>

Allow logging levels to be set via environment variable
<code>SPDLOG_LEVEL</code>

</li>
</ul>

## Changes in RcppSpdlog version 0.0.17 (2024-04-25)

<ul>
<li>

Minor continuous integration update

</li>
<li>

Upgraded to upstream release spdlog 1.14.0

</li>
</ul>

## Changes in RcppSpdlog version 0.0.16 (2024-01-12)

<ul>
<li>

Upgraded to upstream release spdlog 1.13.0

</li>
</ul>

## Changes in RcppSpdlog version 0.0.15 (2023-11-29)

<ul>
<li>

Correct default package help page slighly

</li>
<li>

<code>RcppExports.cpp</code> has been regenerated under an updated
<span class="pkg">Rcpp</span> to address a format string warning under
R-devel

</li>
</ul>

## Changes in RcppSpdlog version 0.0.14 (2023-07-09)

<ul>
<li>

Added new badge to README.md

</li>
<li>

Upgraded to upstream release spdlog 1.12.0

</li>
</ul>

## Changes in RcppSpdlog version 0.0.13 (2023-06-17)

<ul>
<li>

Minor tweak to <code>stopwatch</code> setup avoids pulling in
<span class="pkg">fmt</span>

</li>
<li>

No longer set a C++ compilation standard as the default choices by R are
sufficient for the package

</li>
<li>

Add convenience wrapper <code>log_init</code> omitting first argument to
<code>log_setup</code> while preserving the interface from the latter

</li>
<li>

Add convenience <code>setup</code> wrappers <code>init</code> and
<code>log</code> to API header file <code>spdl.h</code>

</li>
</ul>

## Changes in RcppSpdlog version 0.0.12 (2023-01-07)

<ul>
<li>

Addeed support for ‘stopwatch’ object allowing for simple timing (from
both C++ and R) via the logging framework.

</li>
<li>

The ‘spdlog’ logging pattern is documented via a reference.

</li>
</ul>

## Changes in RcppSpdlog version 0.0.11 (2022-12-13)

<ul>
<li>

Export the formatter at C level

</li>
<li>

Mention package <span class="pkg">spdl</span> in README.md

</li>
<li>

Support simple file-based logger

</li>
</ul>

## Changes in RcppSpdlog version 0.0.10 (2022-11-17)

<ul>
<li>

Support variadic templates with fmt::format

</li>
<li>

Add R formatting helper which converts arguments to character taking
advantage of variadic template logger: fmt logging from R

</li>
<li>

Expand vignette

</li>
</ul>

## Changes in RcppSpdlog version 0.0.9 (2022-11-04)

<ul>
<li>

Add both an R and an C++ interface to <code>spdlog</code>

</li>
<li>

Update GitHub Actions to checkout@v3

</li>
<li>

Add a shorter aliased namespace for C++

</li>
<li>

Upgraded to upstream release spdlog 1.11.0

</li>
</ul>

## Changes in RcppSpdlog version 0.0.8 (2022-04-04)

<ul>
<li>

Upgraded to upstream release spdlog 1.10.0

</li>
</ul>

## Changes in RcppSpdlog version 0.0.7 (2021-12-05)

<ul>
<li>

Upgraded to upstream bug fix releases spdlog 1.9.1 and 1.9.2

</li>
<li>

Travis artifacts and badges have been pruned

</li>
<li>

Vignette now uses <span class="pkg">simplermarkdown</span>

</li>
</ul>

## Changes in RcppSpdlog version 0.0.6 (2021-07-21)

<ul>
<li>

Upgraded to upstream release spdlog 1.9.0

</li>
</ul>

## Changes in RcppSpdlog version 0.0.5 (2020-12-11)

<ul>
<li>

Upgraded to upstream release spdlog 1.8.5 (and 1.8.4 and 1.8.3)

</li>
<li>

Small enhancements to DESCRIPTION files

</li>
</ul>

## Changes in RcppSpdlog version 0.0.4 (2020-12-11)

<ul>
<li>

Upgraded to upstream release spdlog 1.8.2

</li>
<li>

Added GitHub Actions CI using <code>run.sh</code> from
<a href="https://eddelbuettel.github.io/r-ci/">r-ci</a>

</li>
</ul>

## Changes in RcppSpdlog version 0.0.3 (2020-10-23)

<ul>
<li>

New function <code>setLogLevel</code> with R accessor in
<code>exampleRsink</code> example

</li>
<li>

Updated <code>exampleRsink</code> to use default logger instance

</li>
<li>

Upgraded to upstream release 1.8.1 which contains finalised upstream use
to switch to REprintf() if R compilation detected

</li>
<li>

Added new vignette with extensive usage examples, added compile-time
logging switch example

</li>
<li>

A package documentation website was added

</li>
</ul>

## Changes in RcppSpdlog version 0.0.2 (2020-09-17)

<ul>
<li>

Upgraded to upstream release 1.8.0

</li>
<li>

Switched Travis CI to using BSPM, also test on macOS

</li>
<li>

Added ‘stopwatch’ use to main R sink example

</li>
</ul>

## Changes in RcppSpdlog version 0.0.1 (2020-09-08)

<ul>
<li>

Initial release with added R/Rcpp logging sink example

</li>
</ul>