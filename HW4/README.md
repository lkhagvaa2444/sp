# Multi-threaded Deposit and Withdrawal Program

This program demonstrates multi-threading in C with a simple deposit and withdrawal scenario. There are two versions of the program:

1. **race.c**: This version does not use mutex, causing a race condition.
2. **norace.c**: This version uses mutex to prevent race condition.

## Compilation and Execution

You can compile each version using the following commands:

```bash
gcc -o race race.c -lpthread
gcc -o norace norace.c -lpthread
