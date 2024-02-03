/*
Implementations for core functions for Game of Life assignment in CPSC 223 fall 2024

Author: Alan Weide
Modified by: Jairus Rhoades
Changelog:

1/29: 
- Implementing is_alive, should_die

1/31: 
- implementing num_living_neighbors

1/1: 
- fixed up lots of problems with num_living_neighbors 
- finished rest of functions outlined.

 */

#include "life.h"
#include <stdio.h>
#include <stdbool.h>

bool is_alive(int field[ROWS][COLS], size_t i, size_t j)
{
    /*
    TODO: Implement this function. This line here only so starter code compiles
    */
   //would take care of both cells that are currently alive
   // or currently dead. 
   return field[i][j] == 1;
}


bool should_Die(int field[ROWS][COLS], size_t i, size_t j)
{
    // returns cell is DEAD, case management is done in get_next_state
    return field[i][j] == 0;
}

unsigned int num_living_neighbors(int field[ROWS][COLS], size_t i, size_t j)
{
    int num_living = 0;
    for(int di = -1; di <= 1; di++){
        for(int dj = -1; dj <= 1; dj++){ // taking 3x3 matrix around each cell and seeing if they are in bounds
            int row_val = i + di;        // and their state. If they are out of bounds or are the cell 
            int col_val = j + dj; // not using 
            if (row_val != i || col_val != j) {
                if((row_val >= 0 && row_val < ROWS) && (col_val >= 0 && col_val < COLS)){
                    // printf("checked: (%i, %i) | %d\n", row_val, col_val, is_alive(field, row_val, col_val));
                    if(is_alive(field, row_val, col_val)){
                    //    printf("\t alive at %d, %d !\n", row_val, col_val);  // testing
                        num_living++;
                    }
                }
            }
            
        }
    }
    return num_living;
    // edge cases: corner has only three neighbors
    // edge cells have five neighbors
    // all other cells have 8 neighbors 

    // int count = 0;

    // //putting the actual field array with each cell does not work. Must 
    // // place just field into num_living_neighbors 
    // //top three cells
    // // take

    // int p = 0;

    // int q = 0;

    // for ((p = i - 1) ; (p = i + 1); p ++)
    // {
    //     for ((q = j-1) ; (q = j + 1) ; q ++)
    //     {

    //     if (p  >= ROWS || q >= ROWS || p == i || q == j)
    //             {
    //                 return field[i][j] = DEAD;
    //             }

    //     else if (is_alive(field, p, q))
    //     {
    //         count += 1;
    //     }
    //     }
    // }
    //past attempts: 
    // if (i > 0) {
    //     if (is_alive(field, i, j)) {count += 1}; // one up
    //     if (j > 0 && is_alive(field[i-1][j-1])) { count += 1}; // top left
    //     if (j < COLS -1 && is_alive(field[i-1][j+1])) {count +=1}; // top right

    // }


    // // laterals to cell

    // if (j > 0 && is_alive(field[i][j-1])) {count += 1}; // left
    // if (j < COLS - 1 && is_alive(field[i][j+1])) {count += 1}; // right


    // //bottom three cells

    // if (i < ROWS - 1) {
    //     if (is_alive(field[i+1][j])) {count += 1}; //one down
    //     if (j > 0 && is_alive(field[i+1][j-1])) {count += 1};
    //     if (j < COLS - 1 && is_alive(field[i+1][j+1])) {count += 1};
    // }







    // stopping recursion
    // if (i >= ROWS) { 
    //     return;
    // }
    // if (j >= COLS) {
    //     num_living_neighbors(int field[ROWS][COLS]); 

    //     return;
    // }
    // if (is_alive(field[i][j])) {
    // int alive_count = 0;
    //     {
    //         alive_count += 1  ;
    //     }
    
}



    





int get_next_state(int field[ROWS][COLS], size_t i, size_t j)
{
    /*
    TODO: Implement this function. This line here only so starter code compiles
    */
    if (is_alive(field, i, j)) {
        //cell neighbor assesment
        if (num_living_neighbors(field, i, j) > 3 || num_living_neighbors(field, i, j) < 2) {
            // printf("%d living neighbors at %ld, %ld \n" , num_living_neighbors(field,i, j), i, j);
            return 0;
        } 
        else{
            return 1;
        }
        
    }
    //cell is dead, so skip straight to seeing if cell should live.
    // all other cases not considered leaves the cell dead. 
    else {
        if((num_living_neighbors(field, i, j) == 3)){
            return 1;
            // printf("%d living neighbors at %ld, %ld \n" , num_living_neighbors(field,i, j), i, j);

        }
        else{
            return 0;
        }
    }
}

void compute_next_gen(int cur_field[ROWS][COLS], int next_field[ROWS][COLS])
{
//apply get_next_state to field[i][j]. 

    for (int i = 0; i < ROWS; i++) {
        for ( int j = 0 ; j < COLS ; j++) {
            next_field[i][j] = get_next_state(cur_field, i, j); 
        }
    }
}
