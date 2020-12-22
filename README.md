MONTY - PROJECT FOR AKNOWLEDGE THE LOGIC BEHIND COMPILERS AND INTERPRETERS

Monty Pythons flying circus

Deep in this topic resides the logic and well understanding to create
programming languages from scratch. And so, compilers and interpreters 
for any existing language.

Byte codes are data fiels, such as scripts, with very basic commands like:
push, pall, div, add, mul, sub, and so on.

A string with key words conducts to functions that execute the operations
given by the user in the form of these bytecodes with .m extension.

There is a subjacent stack storing the input file and decomposing it to the
main program, for it to process the commands, handle errors and give the
proper output for the user.

BASIC USAGE:

Compile and execute the .c files, for example [->$ gcc -Werror -Wextra -Wall -pedantic *.c -o monty]
then you execute like this [->$ ./monty byte_code_file.m]
That's it.

Be sure that you know the codes:

push
pall
pint
pop
swap
add
nop
sub
div
mul
mod
pchar
pstr

guess what they do? 

just try to do it this way:

command argument(s), ...

comments are allowed with #

# Just like in Python (one line comments only)
