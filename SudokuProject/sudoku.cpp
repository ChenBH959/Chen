// sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "time.h"
#include "fstream"
using namespace std;

int main()
{
	ofstream outfile, fout;
	outfile.open("sudoku.txt");
	int a[9][9] = {
		{ 1,2,3,4,5,6,7,8,9 },
		{ 4,5,6,7,8,9,1,2,3 },
		{ 7,8,9,1,2,3,4,5,6 },
		{ 2,3,4,5,6,7,8,9,1 },
		{ 5,6,7,8,9,1,2,3,4 },
		{ 8,9,1,2,3,4,5,6,7 },
		{ 3,4,5,6,7,8,9,1,2 },
		{ 6,7,8,9,1,2,3,4,5 },
		{ 9,1,2,3,4,5,6,7,8 } };//只有8*7*6*5*4*3*2*1=40320种不同的排列方式 

	int n;
	cin >> n; 
	srand((int)time(0));
	for (int i = 0; i<n; i++) {
		int m;
		m = rand() % 1000 + 1;
		for (int i = 0; i<m; i++) {
			int x = 0, y = 0;
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			for (int i = 0; i<9; i++) {
				for (int j = 0; j<9; j++) {
					int l = 0;
					if (a[i][j] == x) {
						a[i][j] = y;
						l++;
					}
					if (l == 0 && a[i][j] == y) {
						a[i][j] = x;
						l = 0;
					}
				}
			}
		}
		int x, y;
		x = 4;
		y = a[0][0];
		for (int i = 0; i<9; i++) {
			for (int j = 0; j<9; j++) {
				int l = 0;
				if (a[i][j] == x) {
					a[i][j] = y;
					l++;
				}
				if (l == 0 && a[i][j] == y) {
					a[i][j] = x;
					l = 0;
				}
			}
		} 
		cout << endl << endl;
		for (int i = 0; i<9; i++) {
			for (int j = 0; j<9; j++) {
				outfile << a[i][j] << " ";
			}
			outfile << endl;
		}
		outfile << endl;
	}
    return 0;
}

