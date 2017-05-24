# Introduction

# How to run

# Design decisions

### Using MVC

### Board Model
    There are a few ways to conceptualize and store the position of pawns. 
Firstly, I decided to store the position of the pawns in a board rather than the
pawns themselves because a few critical functions would take a computational hit
(checking if a move is possible would be O(pawns) rather than O(1)). Storing the
Since the board is fixed in size, there aren't any memory management concerns.
There was a tradoff in representing the board as a cube vs a 3x8 grid which came
to wasting a few spaces of memory (center of each ring) vs code readability.