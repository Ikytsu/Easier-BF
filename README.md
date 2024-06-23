# Easier-BF

Easier-BF is a simplified compiled version of BrainF\*ck. While it remains compatible with vanilla BrainF\*ck, Easier-BF aims to streamline the language by removing some of the more complex aspects, such as intricate pointer management.

## Installation

### Building from Source

To build Easier-BF from source, you can use `make` in the parent directory by typing:

```
make
```

Alternatively, you can compile it manually with `g++` by navigating to the parent directory and typing:

```
g++ -o bin/ebf src/main.cpp src/load-config.cpp src/generate-c-code.cpp
```

While this example uses `g++`, other compilers can be used, but their usage is not documented at this time.

### Dependency
The program transpile the ebf code into C code in order to compile the ebf code, so you need to have gcc on your PATH, even with prebuilt bin.

### Installing Prebuilt Binaries

You can download prebuilt binaries from the releases section. This method does not require g++ but gcc like mentionned on Dependency section.

**Work in progress, does nothing really, wait for the actual real release**
