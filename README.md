<h1> SIMPLE SHELL PROJECT </h1>

Simple shell project developed by Joaquín Domínguez and Felipe Sandim for Holberton School Uruguay.

## DESCRIPTION

The project is a very simple shell developed in C language.
A shell is a program that takes commands inputs written from the user's keyboard and passes them to the machine to execute them through the kernel. It also verifies if the command inputs from the user are correct.

### How to Install
Clone the below repository and compile the files into an executable using the GCC compiler.
```
https://github.com/joakG16/holbertonschool-simple_shell
```
       
## COMPILATION

Our very simple shell is compiled on Ubuntu 20.04 LTS with the following command:

    $ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## COMMANDS

In this project the commands are searched from the `/bin` directory, and there are two built-in implements.
Some of the commands that can run:

`/bin/ls` --> Used to list directory contents(EXAMPLE)

`env` --> Display the current environment 

`exit` --> Cause the shell to exit

## FILES & FUNCTIONS

`AUTHORS` --> Lists all individuals that have contributed content to the repository 

`main.h` --> The header file: includes the libraries and functions needed

`strfunc.c` --> All the string functions 

`shell.c` --> The body of our shell

`tokenizer.c` --> Tokenizes user's input

`execvec.c` --> Execute the required program

## TESTING

Our simple shell works like this in interactive mode:

    $ ./hsh
    #cisfun$ /bin/ls
    AUTHORS    hsh     man_1_simple_shell  shell.c    test         vgcore.17564                                                                       execvec.c  main.h  README.md   strfunc.c  tokenizer.c  vgcore.17697
    #cisfun$
    #cisfun$ exit
    $
      
But also in non-interactive mode:

    $ echo "/bin/ls" | ./hsh
    AUTHORS    hsh     man_1_simple_shell  shell.c    test         vgcore.17564                                                                       execvec.c  main.h  README.md   strfunc.c  tokenizer.c  vgcore.17697
    $

### Notes
Currently in development.

### To do List
Handle the `PATH`, add more functionality of the shell, such as cd command, and cover error in border cases

### Authors

* [**Joaquin Dominguez**](https://github.com/joakG16)
* [**Felipe Sandim**](https://github.com/m1dnas)
      
