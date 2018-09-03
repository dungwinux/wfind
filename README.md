# wfind

wfind is a library providing the function to look for files
whose contents match the specified regular expression (regex).

The library is in `lib/`, and a simple program which has the same name that uses this library is `main.cpp`.

## Build

### Requirement

- C++ Version:

  - Recommended: C++ 17
  - Minimum: C++ 11

- Tested compiler:

  - GNU C++ Compiler (Version 6 or later)
  - MS Visual C++ Compiler

> Older versions of `g++` and other C++ compilers are yet to be tested, the build might fail.

> In MinGW-w64 g++ 8.1.0, due to a [bug](http://sourceforge.net/p/mingw-w64/bugs/737/), you can't compile `<filesystem>` library. It is recommended to use other version (7.3.0) on Windows.

### Command

```bash
make
```

This will compile `main.cpp` and link `wfind.cpp`.

> By default, the GNU C++ Compiler is chosen to compile. To use specific compiler, see below.

#### GNU C++ Compiler

```bash
make gcc
```

#### MS Visual C++ Compiler

```bash
make vc
```

### Clean

```bash
make clean
```

## Run

```bash
./wfind [regex] [directory]
```

- regex : The regular expression to be used to find in files
- directory : (Optional) Directory that contains the files to look up for

> If the directory is omitted, the location is set to current working directory.

## Install (GNU/Linux)

```bash
make install
```

## Example

(There are prepared files for this example in `example/`)

Run the following command:

```bash
./wfind '\bbooks\b' example/
```

You should see something like this as part of the output:

```bash
Looking up directory: "example/"
Regex: "\bbooks\b"
"example/file3"
"example/file1"
wfind: 2 file(s) found.
```

## License

This work is licensed under [The Unlicense](http://unlicense.org/), meaning it is dedicated to the Public Domain.
