#pragma once

using namespace std;

pair<int, int> nextEmpty(int arr[9][9], int row, int col);
bool isLegal(int board[9][9], int row, int col, int n);
void addToSol(int board[9][9]);
vector<int> validNums(int board[9][9], int row, int col);
int recursion(int board[9][9], int x, int y);
pair<int, string> solutions(int board[9][9]);
