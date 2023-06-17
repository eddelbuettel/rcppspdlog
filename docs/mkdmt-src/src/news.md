<section id="NEWS" class="container">
<h2>News for Package <code>RcppSpdlog</code></h2>
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
<li><p>Upgraded to upstream releases spdlog 1.11.0</p></li>
</ul>
<h3 id="version-0.0.8-2022-04-04">Version 0.0.8 (2022-04-04)</h3>
<ul>
<li><p>Upgraded to upstream releases spdlog 1.10.0</p></li>
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
</section>
