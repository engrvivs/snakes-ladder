# snakes-ladder

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
