# Simple Shell ![BlueShell](https://github.com/juanesart/simple_shell/blob/master/img/Blue_Shell.png?raw=true)

Brief description: We get a line of characters from the prompt, checks if that line of the prompt starts with "/", that will define how the shell will look for the commands that are stored in the environment variables, after that comparisson we are going to be able to execute the functions that the commands perform.

## Table of Contents

    Authors
    How To Installation
    How To Use
    Commands
    Examples

### Authors

    Juan Arango - juanesart <2067@holbertonschool.com>
    Marcos Pimienta - MarcosPimienta <1676@holbertonschool.com>

## Installation

To use the shell it is necessary to install it by using the following commands from your terminal:

    git clone https://github.com/juanesart/simple_shell.git

This will create a new directory named "simple_shell", now move to the directory using:

    cd simple_shell/

Now you will be inside the simple_shell directory and you will see different files. These files are used to compile the shell. In order to compile it please use:

    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Congrats, now you have your shell installed on your system

## Use

In order to execute this shell just type from your terminal the command

    ./hsh

It will open a shell prompt and it will look like this

    #$ 

You are on the shell and it is waiting for you to type and execute a command. Next you will see a list of commands. it will show you how you can exit the shell. You can use either one of these commands:

    #$ exit
    
Or you can also do Ctrl + D And this will also terminate the simple shell.

### Some Commands

Here is a list of some commands you can use, there are many more, try to experiment with it.

    /bin/ls
    ls
    pwd

### Examples of use

*Let's take a look at these examples:*

    #$ -l
    #$ echo Hola Mundo
    #$ pwd
    #$ /bin/ls
