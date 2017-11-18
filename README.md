# Rshell

This is the Rshell project by Liang Xu and Patrick Porter for CS100 Fall 2017. Rshell is a command shell in C++ that takes in commands from the user and executes them. Rshell supports execution of many commands separated by connectors. This shell executes any command in bin that any normal terminal would. The Rshell supports the precedence (parantheses) operator as well as the test function and its equivalent ([]).

## Testing
To run testing files, change directory to tests and run the shell script.

## Known Bugs

- Assign specification: The cd command is not supported, as it is not in the bin folder.
- ~~No error message is output when a connector does not have a right child, but execution of commands continues.~~
- Nested quotes do not work in some cases, such as the number of pairs of quotes is odd.
- ~~Only well formatted input will give a successful output (space before and after connectors, quote attaching to string).~~
- When using comments within a set of precedence operators, an error will occur because the end parantheses will be ignored.
- Echo "123"123 should return 123123, but it returns 123 123, with a space in between.
- Escape character such as \" does not work. echo \" does not output ".
- Echo parentheses doesn't output error which it should.
- Quote after a connector is not treated as an invalid command. Execution still continues. 
- pwd command with an argument will cause "ignoring non-option arguments" error. 
- Maybe a bug: Test command only supports at most two arguments, one flag (can be omitted) and one path. Test command outputs an error and returns (false) if no argument is present or number of argument is larger than two. 
