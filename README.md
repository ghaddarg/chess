## Intro

This is a quick test of the chess logic not an actual imlementation:

1. 
	Given the positions of a white bishop and a black pawn on the standard chess board, determine whether the bishop can capture the pawn in one move.

	The bishop has no restrictions in distance for each move, but is limited to diagonal movement.

2. 
	Given a position of a knight on the standard chessboard, find the number of different moves the knight can perform.

	The knight can move to a square that is two squares horizontally and one square vertically, or two squares vertically and one square horizontally away from it. The complete move therefore looks like the letter L. Check out the image below to see all valid moves for a knight piece that is placed on one of the central squares

## Example

1.
	For bishop = "a1" and pawn = "c3", the output should be solution(bishop, pawn) = true.

	For bishop = "h1" and pawn = "h3", the output should be solution(bishop, pawn) = false.

2.
	For cell = "a1", the output should be solution(cell) = 2.

	For cell = "c2", the output should be solution(cell) = 6.

## Chess Board

8: A B C D E F G H

7: A B C D E F G H

6: A B C D E F G H

5: A B C D E F G H

4: A B C D E F G H

3: A B C D E F G H

2: A B C D E F G H

1: A B C D E F G H

    