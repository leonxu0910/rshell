# Rshell

This is the Rshell project by Liang Xu and Patrick Porter for CS100 Fall 2017. Rshell is a command shell in C++ that takes in commands from the user and executes them. Rshell supports execution of many commands separated by connectors. This shell executes any command in bin that any normal terminal would. The Rshell supports the precedence (parantheses) operator as well as the test function and its equivalent ([]).

## Testing
To run testing files, change directory to tests and run the shell script.

## Known Bugs

- The cd command is not supported, as it is not in the bin folder.
- ~~No error message is output when a connector does not have a right child, but execution of commands continues.~~
- ~~It only supports single set of quote. Nested quotes are not supported yet.~~
- Only well formatted input will give a successful output (space before and after connectors, quote attaching to string).
- When using comments within a set of precedence operators, an error will occur because the end parantheses will be ignored.
