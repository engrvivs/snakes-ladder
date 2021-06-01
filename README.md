# snakes-ladder

Develop Status: [![Lines Of Code](https://tokei.rs/b1/github/XAMPPRocky/tokei?category=code)](https://github.com/engrvivs/snakes-ladder) ![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/engrvivs/snakes-ladder) [![Build Status](https://travis-ci.com/engrvivs/snakes-ladder.svg?branch=main)](https://travis-ci.com/engrvivs/snakes-ladder)

## Notes

- CMake version SHOULD be newer than compiler and libraries!
  - helper modules and Find*.cmake files
- extern
  - git submodules
  - control over version of (upgradable) dependencies
- .gitignore
  - must have `*build*/`, so that `build` folders can be created in `src` folders

## References

- [Phil Nash, "Test Driven C++", CppCon, 2020](https://www.youtube.com/watch?v=N2gTxeIHMP0)
- [Henry Schreiner, An Introduction to Modern CMake (3.4+)](https://cliutils.gitlab.io/modern-cmake/)
- [Catch2/docs, "Why do my tests take so long to compile?"](https://github.com/catchorg/Catch2/blob/devel/docs/slow-compiles.md#short-answer)
- [C++ Weekly With Jason Turner - Ep 79 - Travis CI](https://youtu.be/3ulKzD2cmSw)

### Badges

- [XAMPPRocky, Tokei - Badges](https://github.com/XAMPPRocky/tokei#excluding-folders)
- [Shields IO, "GitHub code size in bytes"](https://shields.io/category/size)
  - [GitHub REST API Reference, "List repository languages"](https://docs.github.com/en/rest/reference/repos#list-repository-languages)
- [Travis CI, "Embedding Status Images"](https://docs.travis-ci.com/user/status-images/)
