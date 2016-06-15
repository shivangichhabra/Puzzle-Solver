/**
 * Solving the Jump-Peg Puzzle using Breadth first search
 * 
 *
 */
#include "JumpState.h"
#include "Jump_peg.h"
#include "Puzzle_solver.h"
#include "Puzzle.h"
#include <iostream>
#include <vector>

/**
*	 Main Program.
*/
int main(){
    Jump_peg *p= new Jump_peg();
    Puzzle_solver<JumpState> solution(p);
    solution.solve();
}
