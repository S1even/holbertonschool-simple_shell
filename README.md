
![images (1)](https://github.com/user-attachments/assets/2694f49e-7352-4a09-bb36-4748fd186f07)

 ## Description
This project is a basic shell program developed in C. It offers basic features like command implementation and directory navigation.
## Screenshot

![images (2)](https://github.com/user-attachments/assets/323aa81e-7eaf-4048-9754-2ee3569ba87a)

## Flowchart
![images (3)](https://github.com/user-attachments/assets/64411039-bff2-49e3-89ac-cce3e7dca176)

## List of allowed functions and system calls+

- all functions from string.h
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Requirements
```
All the files will be compiled on Ubuntu 20.04 LTS using gcc
All files that contain code use the Betty style
No more than 5 functions per file

All the files will be compiled on Ubuntu 20.04 LTS using gcc
All your files should end with a new line
Your shell should not have any memory leaks
All your header files should be include guarded

The header files : shell.h
Allowed editors  : vi, vim, emacs

```


## Compilation

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Run locally
### Prerequisites
To run and install this program, make sure you use

- Operating system: Ubuntu 20.04 LTS
- Compiler Options: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### Installation
```
# clone the repository
git clone https://github.com/S1even/holbertonschool-simple_shell

# use the command cd for navigate in the project
cd holbertonschool-simple_shell

# need to compile the file with gcc
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# run the simple_shell project
./hsh
```


## The examples
```
♠ ls
AUTHORS  README.md  execute_command.c  find_command.c  free_argument.c  hsh  man_1_simple_shell  print_prompt.c  
read_command.c  shell.c  shell.h  token.c
♠
```
```
♠ pwd
/home/steven/holbertonschool-simple_shell
♠
```
```
♠ exit
steven@DESKTOP-19KG90P:~/holbertonschool-simple_shell$
```
## Files description

| Files | Description |
| :---------------: |:---------------:|
| [execute_command.c](https://github.com/S1even/holbertonschool-simple_shell/blob/main/execute_command.c) | Execute the command|
| [free_argument.c](https://github.com/S1even/holbertonschool-simple_shell/blob/main/free_argument.c) | The function frees the allocated memory |
|[print_prompt.c](https://github.com/S1even/holbertonschool-simple_shell/blob/main/print_prompt.c) | Print a custom prompt|
| [shell.c](https://github.com/S1even/holbertonschool-simple_shell/blob/main/shell.c) | Main File, loop of the prompt |
| [shell.h](https://github.com/S1even/holbertonschool-simple_shell/blob/main/shell.h) | Header file |
| [token.c](https://github.com/S1even/holbertonschool-simple_shell/blob/main/token.c) | Splits a command line into tokens|




## Man page
### This project include a man page
```
# display the Man page
$ man ./man_1_simple_shell
```
or you can check the  [Man page](https://github.com/S1even/holbertonschool-simple_shell/blob/main/man_1_simple_shell) of the simple Shell here.

## Authors 

- [Steven](https://github.com/S1even)
- [Dylan](https://github.com/Bruqui)
- [Benjamin](https://github.com/Benji021)


