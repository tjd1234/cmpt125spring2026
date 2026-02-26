// Memory.h

#pragma once  // prevent multiple inclusion

const int MEM_ROWS = 10;
const int MEM_COLS = MEM_ROWS;
const int MEM_SIZE = MEM_ROWS * MEM_COLS;

char mem[MEM_SIZE];

//
// Prints the current state of mem, as described in the assignment.
//
void print_memory();

//
// Allocates a new block of memory of size num_bytes, as described in the
// assignment.
//
int allocate_first_fit(int num_bytes);

//
// Deallocates a block of memory whose first byte is at block_index, as
// described in the assignment.
//
bool deallocate(int block_index);
