# Dante Project

This project is a C project that includes a maze generator and solver. The generator was created by [NielsOuvrard](https://github.com/NielsOuvrard) and the solver was created by [AdamLBS](https://github.com/AdamLBS).

## Maze Generator

The maze generator creates a random maze using Recursive Backtracking algorithm.
The maze can be generated with different sizes and complexities.

## Maze Solver

The maze solver uses the A* algorithm to find the shortest path from the starting point to the end point in the maze.

## Usage

To use the maze generator and solver, follow these steps:

1. Clone the repository: `git clone https://github.com/NielsOuvrard/dante.git`
2. Navigate to the project directory: `cd dante`
3. Compile the generator and solver: `make`
4. Generate a maze: `./generator/generator [width] [height] [perfect] > [maze_file]`
5. Solve the maze: `./solver/solver [maze_file]`

## Example

To generate a maze with a width of 10 and a height of 5 and solve it, run the following commands:
```bash
./generator/generator 10 5 > maze1.txt
./solver/solver maze1.txt
```
To generate a perfect maze with a width of 12 and a height of 20 and solve it, run the following commands:
```bash
./generator/generator 12 20 perfect > maze2.txt
./solver/solver maze2.txt
```

## File example

The maze file is a text file that contains the maze. The maze is represented by a grid of characters. The characters are either `*` or `X`. The `*` character represents an empty space and the `X` character represents a wall.
The starting point is at the top left corner of the maze and the end point is at the bottom right corner of the maze.

```
**X***XX**
**X*XXX***
X*X*****X*
**XX***XX*
*XXXX*XX**
******X***
XX*XX**X**
******X***
***X*XXXX*
**********
```

## Credits

- [NielsOuvrard](https://github.com/NielsOuvrard)
- [Adam Elaoumari](https://github.com/AdamLBS)
