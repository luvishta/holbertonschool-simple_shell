# Simple Shell  
  
## Description  
  
The objective of this lab project is to develop our own simple shell using C language.  
  
A shell is a command interpreter used by users to communicate with the operating system.The shell `hsh` will read commands from the user, execute them, and display the result.  
  
In this project we will learn how to use shells, create processes and run programs in Linux.

  
## How to Compile  
  
To compile the shell you should use the following command:  
    
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh    
  
## How to Run 
  
Then compile the program and start:  
    
./hsh  
  
You can type commands:    
($) ls  
($) pwd  
($) echo Hello  
```  
  
In order to finish the execution of the shell type:  
  
($) exit   
  
Our shell also works in non-interactive mode:  
  
echo "/bin/ls" | ./hsh    
  
## Features  
  
The shell can do the following things:  
  
- execute commands;  
- execute commands through their absolute path;  
- run in interactive mode;  
- run in non-interactive mode;  
- deal with errors;  
- exit with `exit` command.

## Project Requirements

[[what to do]] for the development of this project were as follows:

- Developed in C language
- Compiled using GCC
- Uses Betty code style
- No memory leaks
- Uses only allowed system calls
- complete [[exercises]]

## Project files
0-main.c
_get_env.c
execute.c
path.c
read_line.c
strdup.c

## Authors
luvishta Tengur
Saagarikha Ramsurrun-Balisson

## Holberton repository
https://github.com/luvishta/holbertonschool-simple_shell.git
