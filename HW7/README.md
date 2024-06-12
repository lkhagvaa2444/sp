# Homework 7: Understanding mini-riscv-os

## Overview

This repository contains my solutions and report for Homework 7: Understanding mini-riscv-os.

## Contents

- `report.md`: Detailed report of the assignment.
- `modified_files/`: Directory containing modified mini-riscv-os files.

## Instructions to Run mini-riscv-os

1. **Clone the mini-riscv-os Repository**:
    ```sh
    git clone https://github.com/riscv2os/riscv2os
    cd riscv2os/mini-riscv-os
    ```

2. **Apply the Modifications**:
    - Replace the contents of `start.c` with the modified version provided in the `modified_files` directory.

3. **Build and Run mini-riscv-os**:
    - Follow the instructions provided in the [mini-riscv-os README](https://github.com/riscv2os/riscv2os/tree/master/mini-riscv-os) to build and run the OS.

4. **Observe the Custom Boot Message**:
    - You should see the custom boot message after running the OS.

## Report

### Introduction
This homework focuses on exploring the mini-riscv-os operating system, understanding its core components, and making simple modifications.

### Part 1: Reading Assignment

#### Summary of the Book
- The book provides an in-depth overview of mini-riscv-os, detailing the initialization process, trap handling, and UART communication.
- Key concepts such as bootstrapping, memory management, and interrupt handling are explained with accompanying code examples.

### Part 2: Code Exploration

#### Summary of Key Files

##### `entry.S`
- Contains assembly code for initial bootstrapping and setting up the execution environment.

##### `start.c`
- Handles system initialization, including setting up the stack, UART, and enabling interrupts.

##### `trap.c`
- Manages traps and interrupts, ensuring proper handling of system events.

##### `uart.c`
- Implements the UART driver for serial communication, allowing for input and output operations.

#### Points of Confusion and Questions
1. **Bootstrap Process**: How does the code in `entry.S` transition from assembly to C?
2. **Stack Initialization**: What is the significance of setting up the stack in `start.c`?
3. **Trap Vector Table**: How is the trap vector table configured and used in `trap.c`?
4. **Interrupt Prioritization**: How does the system prioritize different types of interrupts?
5. **UART Communication**: What are the specific roles of the functions in `uart.c`?

### Part 3: Practical Task

#### Building and Running mini-riscv-os
1. Cloned the mini-riscv-os repository from GitHub.
2. Built and ran mini-riscv-os following the provided instructions.
3. Modified `start.c` to print a custom message.

#### Code Modification
```c
#include "uart.h"

void start() {
  uart_init();
  uart_puts("Hello, mini-riscv-os!\n");
  uart_puts("This is a custom boot message.\n");
  while (1) {
    asm volatile ("wfi");
  }
}
