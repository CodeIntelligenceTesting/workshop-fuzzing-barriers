# Fuzzing Barrier Examples

This repository contains a collection of small examples that demonstrate different kinds of code barriers that stop the fuzzer from exploring certain branches in the code. Some ideas and solutions for helping the fuzzer overcome those barriers are provided as well.

Structure:

- `<name>{.cpp,.h}` contains the example code to be tested

## Collection

* assert_statements
* checksum
* complex_conditions
* exit_statements
* hardware_dependencies
* hashing
* initialization
* statefulness

## Building

All examples can be built and run with CI Fuzz:

```sh
cifuzz run <name>_fuzztest
```

For example, to build the `assert_statements` example, run:

```sh
cifuzz run assert_statements_fuzztest
```
