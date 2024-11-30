
# Special Z80 AsseMbly lANguage

This project provides a basic assembly compiler written in C++ for Z80 MPU that processes assembly code and converts it into machine-readable bytecode. Below is an overview of the core functionality and usage.
## Features

- Initialize Memory: Prepares a vector to simulate device memory of varying sizes.
- Error Handling: Provides detailed error messages with line and file references.
- Label Management: Handles labels for jump and branching instructions.
- Preprocessor: Includes functionality for macros and variables.
- File Operations: Loads assembly code from files and saves compiled bytecode.


## Run Locally
Copy the SZAMAN/SZAMAN.cpp file. Include it inside your code. If you do not wish to use built-in main function, simply delete it. And that's it!
## Usage

#### From console
```bash
./SZAMAN -i input.z80 -o output.bin
```

Code presented above will assemble code from file input.z80 into machine code, which will be saved to output.bin

Additional options are available:
- -m can be used to set memory limit of target device. Allowed values: 1k, 2k, 4k, 8k, 16k, 32k, 64k. Default is 64k.
- -s is used to set position in memory where the result code will begin. Default is 0.
- -showbadcode will cause error messages to also display erroneous code.
- -alwaysbeginat0 forces bytecode to start at address 0, even if it was moved by .org

#### From C++ code
```c++
std::string inputPath = "input.z80";
std::string outputPath = "output.bin";
std::string memory = "16k";
std::string startingPos = "0";
bool showBadCode = true;
bool alwaysBeginAt0 = false;

run(inputPath, outputPath, memory, startingPos, showBadCode, alwaysBeginAt0);
```

Code presented above will assemble code from file input.z80 into machine code, which will be saved to output.bin. Memory of the target device is specified as 16k and error messages are set to also display erroneous code with them.

## Error and Warning Codes

This section contains descriptions of possible error and warning codes. It is not guaranteed to be a complete list.

#### Errors:
- 001: Base was not specified for the encountered number.
- 002: Unknown instruction.
- 003: Unknown label.
- 006: Redefinition of label.
- 012: Preprocessor instruction was detected in forbidden location.
- 016: Redefinition of define.
- 017: Redefinition of macro.
- 019: .org preprocessor instruction got value that exceeds maximum possible address.
- 021: Expected number, got something else instead.
- 022: Base was not specified for the encountered number.
- 023: Expected decimal number, got something else instead.
- 024: Expected binary number, got something else instead.
- 025: Expected hexadecimal number, got something else instead.
- 044: .org preprocessor instruction would overwrite some other code.
- 054: Variable declaration without specified size.
- 055: Attempting to delete variable that does not exist.
- 404: Can not include specified file.
- 405: Attempted to include the same file multiple times.
- 998: Specified variable name contains name of other macro, define or variable.
- 999: Specified macro name contains name of other macro, define or variable.

#### Warnings:
- 001: Memory of the target device not specified.
- 002: Bytecode starting position not specified.
- 004: Label contains forbidden character.
## License

This project is licensed under the terms of the MIT license. Check the LICENSE file for details.

