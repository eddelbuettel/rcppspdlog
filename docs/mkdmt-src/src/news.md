<div class="container">
<div role="main">
<h3 id="version-0.0.22-2025-05-09">Version 0.0.22 (2025-05-09)</h3>
<ul>
<li><p>Upgraded to upstream release spdlog 1.15.3 (including fmt
11.2.0)</p></li>
</ul>
<h3 id="version-0.0.21-2025-03-30">Version 0.0.21 (2025-03-30)</h3>
<ul>
<li><p>Upgraded to upstream release spdlog 1.15.2 (including fmt
11.1.4)</p></li>
</ul>
<h3 id="version-0.0.20-2025-02-01">Version 0.0.20 (2025-02-01)</h3>
<ul>
<li><p>New multi-threaded logging example (Young Geun Kim and Dirk via
<a
href="https://github.com/eddelbuettel/rcppspdlog/issues/22">#22</a>)</p></li>
<li><p>Upgraded to upstream release spdlog 1.15.1</p></li>
</ul>
<h3 id="version-0.0.19-2024-11-10">Version 0.0.19 (2024-11-10)</h3>
<ul>
<li><p>Support use of <code>std::format</code> under C++20 via opt-in
define instead of <code>fmt</code> (Xanthos Xanthopoulos in <a
href="https://github.com/eddelbuettel/rcppspdlog/pull/19">#19</a>)</p></li>
<li><p>An erroneous duplicate log=level documentation level was removed
(Contantinos Giachalis in <a
href="https://github.com/eddelbuettel/rcppspdlog/pull/20">#20</a>)</p></li>
<li><p>Upgraded to upstream release spdlog 1.15.0 (Dirk in <a
href="https://github.com/eddelbuettel/rcppspdlog/pull/21">#21</a>)</p></li>
<li><p>Partially revert / simplify <code>src/formatter.cpp</code>
accomodating both <a
href="https://github.com/eddelbuettel/rcppspdlog/pull/19">#19</a> and
previous state (Dirk in <a
href="https://github.com/eddelbuettel/rcppspdlog/pull/21">#21</a>)</p></li>
</ul>
<h3 id="version-0.0.18-2024-09-10">Version 0.0.18 (2024-09-10)</h3>
<ul>
<li><p>Upgraded to upstream release spdlog 1.14.1</p></li>
<li><p>Minor packaging upgrades</p></li>
<li><p>Allow logging levels to be set via environment variable
<code>SPDLOG_LEVEL</code></p></li>
</ul>
<h3 id="version-0.0.17-2024-04-25">Version 0.0.17 (2024-04-25)</h3>
<ul>
<li><p>Minor continuous integration update</p></li>
<li><p>Upgraded to upstream release spdlog 1.14.0</p></li>
</ul>
<h3 id="version-0.0.16-2024-01-12">Version 0.0.16 (2024-01-12)</h3>
<ul>
<li><p>Upgraded to upstream release spdlog 1.13.0</p></li>
</ul>
<h3 id="version-0.0.15-2023-11-29">Version 0.0.15 (2023-11-29)</h3>
<ul>
<li><p>Correct default package help page slighly</p></li>
<li><p><code>RcppExports.cpp</code> has been regenerated under an
updated <code>Rcpp</code> to address a format string warning under
R-devel</p></li>
</ul>
<h3 id="version-0.0.14-2023-07-09">Version 0.0.14 (2023-07-09)</h3>
<ul>
<li><p>Added new badge to README.md</p></li>
<li><p>Upgraded to upstream release spdlog 1.12.0</p></li>
</ul>
<h3 id="version-0.0.13-2023-06-17">Version 0.0.13 (2023-06-17)</h3>
<ul>
<li><p>Minor tweak to <code>stopwatch</code> setup avoids pulling in
<code>fmt</code></p></li>
<li><p>No longer set a C++ compilation standard as the default choices
by R are sufficient for the package</p></li>
<li><p>Add convenience wrapper <code>log_init</code> omitting first
argument to <code>log_setup</code> while preserving the interface from
the latter</p></li>
<li><p>Add convenience <code>setup</code> wrappers <code>init</code> and
<code>log</code> to API header file <code>spdl.h</code></p></li>
</ul>
<h3 id="version-0.0.12-2023-01-07">Version 0.0.12 (2023-01-07)</h3>
<ul>
<li><p>Addeed support for 'stopwatch' object allowing for simple timing
(from both C++ and R) via the logging framework.</p></li>
<li><p>The ‘spdlog’ logging pattern is documented via a
reference.</p></li>
</ul>
<h3 id="version-0.0.11-2022-12-13">Version 0.0.11 (2022-12-13)</h3>
<ul>
<li><p>Export the formatter at C level</p></li>
<li><p>Mention package <code>spdl</code> in README.md</p></li>
<li><p>Support simple file-based logger</p></li>
</ul>
<h3 id="version-0.0.10-2022-11-17">Version 0.0.10 (2022-11-17)</h3>
<ul>
<li><p>Support variadic templates with fmt::format</p></li>
<li><p>Add R formatting helper which converts arguments to character
taking advantage of variadic template logger: fmt logging from
R</p></li>
<li><p>Expand vignette</p></li>
</ul>
<h3 id="version-0.0.9-2022-11-04">Version 0.0.9 (2022-11-04)</h3>
<ul>
<li><p>Add both an R and an C++ interface to
<code>spdlog</code></p></li>
<li><p>Update GitHub Actions to checkout@v3</p></li>
<li><p>Add a shorter aliased namespace for C++</p></li>
<li><p>Upgraded to upstream release spdlog 1.11.0</p></li>
</ul>
<h3 id="version-0.0.8-2022-04-04">Version 0.0.8 (2022-04-04)</h3>
<ul>
<li><p>Upgraded to upstream release spdlog 1.10.0</p></li>
</ul>
<h3 id="version-0.0.7-2021-12-05">Version 0.0.7 (2021-12-05)</h3>
<ul>
<li><p>Upgraded to upstream bug fix releases spdlog 1.9.1 and
1.9.2</p></li>
<li><p>Travis artifacts and badges have been pruned</p></li>
<li><p>Vignette now uses <code>simplermarkdown</code></p></li>
</ul>
<h3 id="version-0.0.6-2021-07-21">Version 0.0.6 (2021-07-21)</h3>
<ul>
<li><p>Upgraded to upstream release spdlog 1.9.0</p></li>
</ul>
<h3 id="version-0.0.5-2020-12-11">Version 0.0.5 (2020-12-11)</h3>
<ul>
<li><p>Upgraded to upstream release spdlog 1.8.5 (and 1.8.4 and
1.8.3)</p></li>
<li><p>Small enhancements to DESCRIPTION files</p></li>
</ul>
<h3 id="version-0.0.4-2020-12-11">Version 0.0.4 (2020-12-11)</h3>
<ul>
<li><p>Upgraded to upstream release spdlog 1.8.2</p></li>
<li><p>Added GitHub Actions CI using <code>run.sh</code> from <a
href="https://eddelbuettel.github.io/r-ci/">r-ci</a></p></li>
</ul>
<h3 id="version-0.0.3-2020-10-23">Version 0.0.3 (2020-10-23)</h3>
<ul>
<li><p>New function <code>setLogLevel</code> with R accessor in
<code>exampleRsink</code> example</p></li>
<li><p>Updated <code>exampleRsink</code> to use default logger
instance</p></li>
<li><p>Upgraded to upstream release 1.8.1 which contains finalised
upstream use to switch to REprintf() if R compilation detected</p></li>
<li><p>Added new vignette with extensive usage examples, added
compile-time logging switch example</p></li>
<li><p>A package documentation website was added</p></li>
</ul>
<h3 id="version-0.0.2-2020-09-17">Version 0.0.2 (2020-09-17)</h3>
<ul>
<li><p>Upgraded to upstream release 1.8.0</p></li>
<li><p>Switched Travis CI to using BSPM, also test on macOS</p></li>
<li><p>Added 'stopwatch' use to main R sink example</p></li>
</ul>
<h3 id="version-0.0.1-2020-09-08">Version 0.0.1 (2020-09-08)</h3>
<ul>
<li><p>Initial release with added R/Rcpp logging sink example</p></li>
</ul>
</div>
</div>
