# Simple Shell

## Overview

This is a simple shell program written in C that provides a basic command-line interface. The shell supports various functionalities such as executing commands, managing environment variables, and printing the environment.

## Features

- **Command Execution:** Allows the user to execute commands provided through the command line.
- **Built-in Commands:** Supports built-in commands such as `exit`, `env`, `setenv`, and `unsetenv`.
- **Environment Variables:** Provides functions to handle environment variables, including setting, unsetting, and printing.
- **Path Resolution:** Resolves the full path of the command using the `PATH` environment variable.
- **Error Handling:** Includes error handling for various scenarios, such as command not found and invalid input.

## Usage

1. **Compilation:** Compile the program using a C compiler, for example:
   ```bash
   gcc -o simple_shell simple_shell.c
   ```

2. **Execution:** Run the compiled program:
   ```bash
   ./simple_shell
   ```

3. **Command Input:** Enter commands in the shell prompt, and press Enter to execute.

## Built-in Commands

- **exit:** Exits the shell.
- **env:** Displays the current environment variables.
- **setenv:** Sets a new environment variable or modifies an existing one.
  ```bash
  setenv VARIABLE VALUE
  ```
- **unsetenv:** Unsets (removes) an environment variable.
  ```bash
  unsetenv VARIABLE
  ```

## Path Resolution

The shell resolves the full path of the entered command using the `PATH` environment variable. If the command is not found in the current directory, the shell searches through the directories specified in the `PATH` variable.

## Error Handling

The shell provides informative error messages for various scenarios, such as command not found, invalid input for `setenv` and `unsetenv`, and general execution errors.

## Examples

1. **Execute Command:**
   ```bash
   $ ls
   ```

2. **Set Environment Variable:**
   ```bash
   $ setenv MY_VARIABLE my_value
   ```

3. **Unset Environment Variable:**
   ```bash
   $ unsetenv MY_VARIABLE
   ```

4. **Exit the Shell:**
   ```bash
   $ exit
   ```

## Notes

- The shell supports basic functionalities and may not cover all edge cases or advanced features found in fully-featured shells.
- This implementation focuses on simplicity, usage flexibility and ease of understanding.

Program is fully scalable and customizable to suit per case needs.
