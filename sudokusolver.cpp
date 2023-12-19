#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "sudokusolver.h"
#include "utility.h"

bool isVisited[10];

pair<int, int> nextEmpty(int board[9][9], int row, int col) {
	int indexNext = 82;
	for (int i = row * 9 + col + 1; i < 81; i++) {
		if (board[i / 9][i % 9] == 0) {
			indexNext = i;
			break;
		}
	}
	return { indexNext / 9, indexNext % 9 };
}

bool isLegal(int board[9][9], int row, int col, int n) {
	if (board[row][col] != 0)return false;
	int x = (col / 3) * 3;
	int y = (row / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == n || board[i][col] == n || board[y + i / 3][x + i % 3] == n) {
			return false;
		}
	}
	return true;
}

int solutionBoard[9][9];

void addToSol(int board[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			solutionBoard[i][j] = board[i][j];
		}
	}
}

vector<int> validNums(int board[9][9], int row, int col) {
	vector<int> ret;
	for (int i = 1; i < 10; i++) {
		if (isLegal(board, row, col, i)) {
			ret.push_back(i);
		}
	}
	return ret;
}

chrono::duration<double> times;
chrono::time_point<chrono::high_resolution_clock> stop_time;
chrono::time_point<chrono::high_resolution_clock> start_time;

bool cool = false;

void testTime() {
	stop_time = chrono::high_resolution_clock::now();
	times = stop_time - start_time;

	if (times.count() > 10)cool = true;

}

int recursion(int board[9][9], int x, int y) {
	int sum = 0;
	if (cool)return 0;
	if (x == 9) {
		addToSol(board);
		return 1;
	}
	if (board[x][y] != 0) {
		pair<int, int> p = nextEmpty(board, x, y);
		return recursion(board, p.first, p.second);
	}

	vector<int> legalMoves = validNums(board, x, y);

	for (auto& e : legalMoves) {
		testTime();
		board[x][y] = e;
		pair<int, int> p = nextEmpty(board, x, y);
		sum += recursion(board, p.first, p.second);
		board[x][y] = 0;
	}

	return sum;
}


pair<int, string> solutions(int board[9][9]) {
	start_time = chrono::high_resolution_clock::now();
	cool = false;
	int ret = recursion(board, 0, 0);
	string s = "";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			s += to_string(solutionBoard[i][j]);
		}
	}

	return { ret, s };
}
