#include <iostream>
using namespace std;
/*
* Kyle Harvey
* CSC 340.05
* 915139815
*/
bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

// Allows players to make a move 
// Determines whether move was invalid or occupied 
void makeAMove(char board[][3], char current_player) {
	//Checks each players input
	while (true) {
		cout << "Enter a row (0,1,2) for player " << current_player << ":";
		int n;
		cin >> n;
		int m;
		cout << "Enter a column (0,1,2)for player " << current_player << ":";
		cin >> m;
		if (n < 0 || n > 2 || m < 0 || m > 2) {
			cout << "Invalid Move\n";
		}
		// Makes sure if the space is already taken
		else {
			if (board[n][m] != 'X' && board[n][m] != 'O') {
				board[n][m] = current_player;
				break;
			}
			else {
				cout << "This cell is already occupied. Try a different cell\n";
			}
		}
	}
}

// Determines whether a player has won
bool isWon(char current_player, char board[][3]) {
	//Run the loop to check the rows
    
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player)
			return true;
		if (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)
			return true;
	}
	//Loop for columns of the board.
	if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player)
		return true;
	if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)
		return true;
	return false;
}

// Displays the board set up.
void displayBoard(char board[][3]) {
	//top
	cout << "_______\n";
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << "|";

		}
		//bottem
		cout << endl;
		cout << "_______\n";

	}
}

// Determines whether players came to a Draw
bool isDraw(char board[][3]) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 'X' || board[i][j] == 'O')
				count++;
		}
	}
	if (count != 9)
		return false;
	if (!isWon('X', board) && !isWon('O', board))
		return true;
}


int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}






