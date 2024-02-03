/*
Driver for Game of Life assignment in CPSC 223 Fall 2023

Author: Jairus Rhoades

changelog:
-1/31: fixed up a whole bunch of tasks involved with 
up to print initial with Chase and Kenny at Office Hours, removed SIZE.

-1/1: implemented and fixed num_living_neighbors !!!! Did the 
"scan 3x3 grid around cell" for loop. 

-1/2: implemented get_next_state and compute_next_gen, fixed up main.c
how I used cur_state. Initially used 3D array, way too much memory usage
used for loop to implement.  

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "life.h"
#include "helpers.h"


int main(int argc, char *argv[]) {

    /*
     * TODO: Accept two command-line arguments, which will appear in the
     * following order:
     * time_steps:
     *      a positive integer describing how many "generations" the simulation
     *      will run for.
     
     * init:
     *      a string consisting of the characters '0' and '1', of length ROWS * COLS,
     *      representing the initial state for this run of Game of Life.
     */

//TIMESTEPS:
    unsigned int time_steps = atoi (argv[1]); // atoi converts to integers
    if (time_steps == 0)
    {
        fprintf(stderr, "ERROR: time steps must be positive. \n");
        return 1; //error code
    }
//INIT: 
     char *init_state = argv[2]; 
    size_t init_length = strlen(init_state); 
    //printf("init_length is: %ld ", init_length); //str header file provided
    if (init_length != ROWS * COLS) { //check 
        fprintf(stderr, "ERROR: Field must contain exactly %d characters, but has length %zu.\n", ROWS * COLS, init_length);
        return 1; 
    
    }

    

    //Declaring an 2D array init 
    /*
     * TODO: Create a new statically-allocated array of size ROWS x COLS
     */
    
    int field[ROWS][COLS];
        for (int i = 0 ; i < ROWS ; i ++) {
            for (int j = 0 ; j < COLS ; j ++) {
                char cell = init_state[i * COLS + j];
                if (cell == '1') {
                    field[i][j] = 1; // alive
                
                } else {
                    field[i][j] = 0 ; // DEAD
                }
            }
        }
        

    /*
     * TODO: Print the initial values held in the field
     */

    print_initial(field); // using field,


    /*
     * TODO: Run the game time_steps times, printing the field at the end of
     * each step
     */

    int cur_field[ROWS][COLS];
    int next_field[ROWS][COLS];

    for (int steps = 1; steps <= time_steps; steps ++) {

    // Copy the current state to cur_field
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cur_field[i][j] = field[i][j];
        }
    }

    // Initialize next_field to zero.
    // Is this necessary, given that compute_next_gen recomputes everything?
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            next_field[i][j] = 0;
        }
    }

    // Compute the next generation based on cur_field, storing it in next_field
    compute_next_gen(cur_field, next_field);
    print_generation(next_field, steps);

    // Copy next_field back to field (or cur_field) for the next iteration
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            field[i][j] = next_field[i][j];
        }
    }
    }
        

    

    // int generations[time_steps][ROWS][COLS];
    // compute_next_gen(field, generations[1]);
    // print_generation(generations[1], 1);

    // for (int i = 2 ; i <= time_steps; i++){
    //     compute_next_gen(generations[i - 1], generations[i]);
    //     print_generation(generations[i], i);
    // }

    //making a function that takes in the amount of neighbors that are alive in a cell
    //On this cell, check if it is alive. 
    //On this cell, run num_alive_neighbors.
    //If the cell is alive and run_alive_neighbors returns
        //more than three neighbors , then set cell to false 
        //less than two, then set cell to false
    //If the cell is dead and run_alive_neighbors returns
        //more than three neighbors, run should_die on cell
        //three neighbors, run is_alive on cell
        //less than three neighbors, run should_die on cell.
    //iterate on all cells until i and j have reached ROWS-1, COLS-1.

  


    

   
    
    




    /*
     * Print "Done." then exit.
     */
    printf("Done.\n");
    return 0;
}
