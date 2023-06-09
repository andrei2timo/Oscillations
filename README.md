# Oscillations

This repository contains code for simulating and analyzing oscillations in physical systems. The code is written in C++ and provides a collection of classes and functions to model various oscillatory phenomena.

## Table of Contents

- [Oscillations](#oscillations)
  - [Table of Contents](#table-of-contents)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Examples](#examples)
  - [Contributing](#contributing)
  - [License](#license)

## Installation

To use this code, follow these steps:

1. Clone the repository to your local machine using the following command:

   ```shell
   git clone https://github.com/andrei2timo/Oscillations.git ```
2. Ensure that you have a C++ compiler installed on your system. This code has been tested with GCC and Clang.

3. Build the project by compiling the source files. You can use the provided Makefile by running the following command:
  ```shell
  make
  ```
4. Once the compilation is successful, you will find the compiled executable in the bin directory.

## Usage

The main functionality of this code revolves around simulating and analyzing oscillatory systems. The core classes and functions are located in the `src` directory.

To use the code, you can include the necessary headers and link against the compiled object files in your own C++ project. Here's an example of how to include the `Oscillator` class:

```cpp
#include "Oscillator.h"

int main() {
    // Create an instance of the Oscillator class and perform simulations or analyses
    Oscillator oscillator;
    // ...
    return 0;
}
```
Refer to the documentation within the source files for more details on the available classes and their respective functions.

## Examples

The `examples` directory contains sample code that demonstrates the usage of this library. You can explore these examples to get started and understand how to utilize the provided functionality.

To compile and run an example, navigate to the example's directory and use the provided Makefile or compile manually as described in the installation section.
