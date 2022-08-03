<h1> SIMPLE SHELL PROJECT </h1>

Simple shell project developed by Joaquín Domínguez and Felipe Sandim for Holberton School Uruguay.

## DESCRIPTION

The project is a very simple shell developed in C language.
A shell is a program that takes commands inputs written from the user's keyboard and passes them to the machine to execute them through the kernel. It also verifies if the command inputs from the user are correct.

## PROTOTYPE

    int main(int ac, char **av, char **env);
       
## COMPILATION

Our very simple shell is compiled on Ubuntu 20.04 LTS with the following command:

    $ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## COMMANDS

In this project the commands are searched from the `/bin` directory, and there are two built-in implements.
Some of the commands that can run:

`/bin/ls` --> Used to list directory contents

`env` --> Display the current environment 

`exit` --> Cause the shell to exit

## FILES & FUNCTIONS

`AUTHORS` --> Lists all individuals that have contributed content to the repository 

`main.h` --> The header file: includes the libraries and functions needed

`strfunc.c` --> All the string functions 

`shell.c` --> The main program

`tokenizer.c` -->

`execvec.c` -->

## TESTING

Our simple shell works like this in interactive mode:

    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $
      
But also in non-interactive mode:

    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $cat test_ls_2
    /bin/ls
    /bin/ls
    $      
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $
      
