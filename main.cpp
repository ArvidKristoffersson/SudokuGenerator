#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "utility.h"
#include "sudokusolver.h"


using namespace std;

int main() {
	cout << "Welcome to Sudoku Generator" << endl << "----------------------------------" << endl;
	cout << "type difficulty (1-10): ";
	int difficulty; cin >> difficulty;
	

	cout << difficulty << endl;
	

	int board[9][9];

	ofstream outFile;

	long long n = string_to_ll("arvid kristoffersson");

	srand(n);

	int q = 0;
	outFile.open("svår22.0.txt");
	for (int i = 0; i < 5000; i++) {
		cout << i << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				board[i][j] = 0;
			}
		}		

		for (int j = 0; j < 22; j++) {
			int coordinate = rand() % 81;
			int number = rand() % 9;
			if (!isLegal(board, coordinate / 9, coordinate % 9, number + 1) ){
				j--;
				continue;
			}
			board[coordinate / 9][coordinate % 9] = number+1;
		}

		pair<int, string> p = solutions(board);
		if (p.first < 2 && p.first > 0) {
			q++;
			cout << i << endl;
			cout << p.first << endl;
			cout << p.second << endl;
			string f = p.second;
			outFile << p.second << endl;
			outFile << p.first << endl;
			for (int i = 0; i < 9; i++) {
				outFile << "----";
			}
			outFile << endl;

			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					outFile << "| " << f[i*9 + j] << " ";
				}
				outFile << "|" << endl;
				for (int i = 0; i < 9; i++) {
					outFile << "----";
				}
				outFile << endl;
			}

			outFile << endl;

			for (int i = 0; i < 9; i++) {
				outFile << "----";
			}
			outFile << endl;

			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					outFile << "| " << (board[i][j] == 0 ? " " : to_string(board[i][j]) ) << " ";
				}
				outFile << "|" << endl;
				for (int i = 0; i < 9; i++) {
					outFile << "----";
				}
				outFile << endl;
			}

			outFile << endl;

			
		}
		
	}

	outFile.close();

	cout << q << endl;



	return 0;
}
