# mkcmod
Make C module

This program is meant to ease the creation of C modules (pairs of header file and implementation/source file).

## Usage

```
mkcmod [OPTIONS]... NAME
```

### Options

 - `-g` - Do not put an include guard.
 - `-d` - Write an include guard in the `#ifndef ... #define ...` style (standard). Otherwise, use the `#pragma once` style (default). This option is ignored if the `-g` option is already present.

## License

![CC0 icon](https://mirrors.creativecommons.org/presskit/buttons/88x31/svg/cc-zero.svg)

This whole repository is licensed using the Creative Commons Zero v1.0 license. For more information, check out the [official web page](https://creativecommons.org/publicdomain/zero/1.0/) and/or the [Wikipedia page](https://en.wikipedia.org/wiki/Creative_Commons_license#Zero_/_public_domain).

[LICENSE file](LICENSE)
