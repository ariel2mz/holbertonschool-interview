#ifndef SANDPILES_H
#define SANDPILES_H

/* Function prototype */
static void print_grido(int grid[3][3]);
static void print_grid(int grid[3][3]);
int is_unstable(int grid[3][3]);
void topple(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
#endif /* SANDPILES_H */