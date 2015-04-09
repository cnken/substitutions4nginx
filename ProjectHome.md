# nginx\_substitutions\_filter #

_Note: this module is not distributed with the Nginx source. Installation instructions can be found [below](#Installation.md)._

_Note: This module has been moved to github: https://github.com/yaoweibin/ngx_http_substitutions_filter_module/_

## Description ##

`nginx_substitutions_filter` is a filter module which can do both regular expression and fixed string substitutions on response bodies. This module is quite different from the Nginx's native Substitution Module. It scans the output chains buffer and matches string line by line, just like Apache's [mod\_substitute](http://httpd.apache.org/docs/trunk/mod/mod_substitute.html).

## Example ##

```
location / {

    subs_filter_types text/html text/css text/xml;
    subs_filter st(\d*).example.com $1.example.com ir;
    subs_filter a.example.com s.example.com;

}
```
## Directives ##

  * [subs\_filter\_types](#subs_filter_types.md)
  * [subs\_filter](#subs_filter.md)

### subs\_filter\_types ###

`syntax:` _subs\_filter\_types mime-type `[`mime-types`]`_

`default:` _subs\_filter\_types text/html_

`context:` _http, server, location_

_subs\_filter\_types_ is used to specify which content types should be checked for _subs\_filter_. The default is only _text/html_.

This module just works with plain text. If the response is compressed, it can't uncompress the response and will ignore this response. This module can be compatible with gzip filter module. But it will not work with proxy compressed response. You can disable the compressed response like this:

proxy\_set\_header Accept-Encoding "";

### subs\_filter ###

`syntax:` _subs\_filter source\_str destination\_str `[`gior`]`_

`default:` _none_

`context:` _http, server, location_

_subs\_filter_ allows replacing source string(regular expression or fixed) in the nginx response with destination string. Substitution text may contain variables. More than one substitution rules per location is supported. The meaning of the third flags are:
  * _g_(default): Replace all the match strings.
  * _i_: Perform a case-insensitive match.
  * _o_: Just replace the first one.
  * _r_: The pattern is treated as a regular expression, default is fixed string.

## Installation ##

To install, get the source with subversion:

```
git clone git://github.com/yaoweibin/ngx_http_substitutions_filter_module.git
```
and then compile nginx with the following option:

```
./configure --add-module=/path/to/module
```
## Known issue ##

  * 

## CHANGES ##

Changes with nginx\_substitutions\_filter 0.6.0                                     2012-06-30

  * refactor this module

Changes with nginx\_substitutions\_filter 0.5.2                                     2010-08-11

  * do many optimizing for this module
  * fix a bug of buffer overlap
  * fix a segment fault bug when output chain return NGX\_AGAIN.
  * fix a bug about last buffer with no linefeed. This may cause segment fault. Thanks for Josef Fröhle

Changes with nginx\_substitutions\_filter 0.5                                       2010-04-15

  * refactor the source structure, create branches of dev
  * fix a bug of small chunk of buffers causing lose content
  * fix the bug of last\_buf and the nginx's compatibility above 0.8.25
  * fix a bug with unwanted capture config error in fix string substitution
  * add feature of regex captures

Changes with nginx\_substitutions\_filter 0.4                                       2009-12-23

  * fix many bugs

Changes with nginx\_substitutions\_filter 0.3                                       2009-02-04

  * Initial public release

## Reporting a bug ##

Questions/patches may be directed to Weibin Yao, yaoweibin@gmail.com.