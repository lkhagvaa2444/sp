# Homework 8: Understanding xv6

## Introduction
This homework focuses on exploring the xv6 operating system, understanding its core components, and making simple modifications.

## Part 1: Reading Assignment

### Summary of Chapters 1-3
- **Chapter 1: Overview**: Provides an introduction to xv6, including its structure and functionality.
- **Chapter 2: System Calls**: Discusses how system calls are implemented in xv6.
- **Chapter 3: Traps**: Explains traps, interrupts, and how xv6 handles them.

### Insights from the "Tour of xv6"
- xv6's simplicity makes it an excellent educational tool.
- The modular structure of xv6 aids in understanding the OS components.

## Part 2: Code Exploration

### Summary of Key Files

#### `kernel/proc.c`
- Manages processes including creation, scheduling, and termination.

#### `kernel/trap.c`
- Handles traps and interrupts, ensuring smooth process execution.

#### `kernel/syscall.c`
- Implements system calls, allowing user programs to interact with the kernel.

### Points of Confusion and Questions
1. **Process Scheduling**: How does xv6 determine the order of process execution?
2. **Interrupt Handling**: What is the mechanism for prioritizing different types of interrupts?
3. **System Call Implementation**: How are new system calls added to xv6?
4. **Process States**: What are the different states a process can be in, and how does xv6 manage these states?
5. **Memory Management**: How does xv6 allocate and deallocate memory for processes?

## Part 3: Practical Task

### Building and Running xv6
1. Cloned the xv6 repository from GitHub.
2. Built and ran xv6 using QEMU.
3. Modified `kernel/hello.c` to print a custom message.

### Code Modification
```c
#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  printf("Hello, xv6!\n");
  printf("This is a custom boot message.\n");
  exit(0);
}
