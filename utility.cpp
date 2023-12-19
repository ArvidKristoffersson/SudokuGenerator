#include <iostream>
#include "utility.h"

void print_sudoku_board(int board[9][9]) {
	for (int i = 0; i < 9; i++) {
		cout << "----";
	}
	cout << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
		for (int i = 0; i < 9; i++) {
			cout << "----";
		}
		cout << endl;
	}
	return;
}

long long string_to_ll(string str) {
	long long ret = 0;
	int i = 0;

	for (char& e : str) {
		long long c = e - 'a';
		ret += (c << i);
		i++;
	}

	return ret;
}
