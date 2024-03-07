## Introduction

The ft_ls project at 42 Coding School was a challenging yet rewarding milestone in my journey to mastering system programming in C. This assignment tasked me with recreating the Unix 'ls' command with several of its options. This project allowed me to explore filesystem operations, directory traversals, and file metadata handling in depth. Developing my own version of the 'ls' command taught me the complexities of interacting with the operating system's file system. It honed my skills in data sorting, formatting output, and managing memory. Overall, this project was beneficial in solidifying my understanding of Unix system programming and prepared me for more advanced system-level projects.

## Description of the Key Features

* Basic Listing: Mimics the default behavior of the Unix 'ls' command, listing the files and directories in the current directory.
* Long Format (-l): Displays detailed information about each file, including permissions, number of links, owner, group, size, and last modification date.
* Recursive Listing (-R): Recursively lists subdirectories.
* Sorting by Modification Time (-t): Sorts files by modification time, displaying the most recently modified files first.
* Reverse Sorting (-r): Reverses the order of the file listing.
* Hidden Files (-a): Includes files that start with a dot (.) in the listing, which are typically hidden in Unix systems.
* Error Handling: Gracefully handles errors such as insufficient permissions or non-existent files and displays appropriate error messages.

## Bonus Options:

* -G (Color Output): Displays files and directories with different colors based on their type and permissions.
* -1 (Single Column Output): Lists files in a single column.
* -d (Directory Listing): Lists directories themselves, not their contents.
* -S (Sort by Size): Sorts files by size, with the largest files listed first.
* -s (Display File Size): Displays the size of each file in blocks.

## Usage

To use the ft_ls program, first clone the repository and compile the source code using the make command:

```bash
https://github.com/spushkin/ft_ls.git
cd ft_ls
make
```
Once compiled, you can run the program with various options to list files and directories:

```bash
./ft_ls {optional argument}
```
