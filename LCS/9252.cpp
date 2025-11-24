#if 1
#pragma warning (disable : 4996)
//#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 1000

using namespace std;

int map[MAX + 1][MAX + 1];
pair<int, int> direction[MAX + 1][MAX + 1];
string input1, input2;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	for (int i = 0; i <= MAX; i++) {
		map[i][0] = 0;
		map[0][i] = 0;
		direction[i][0] = { 0, 0 };
		direction[0][i] = { 0, 0 };
	}

	cin >> input1;
	cin >> input2;
	int size1 = input1.size();
	int size2 = input2.size();
	direction[0][0] = { 0, 0 };
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (input1[i] == input2[j]) {
				map[i + 1][j + 1] = map[i][j] + 1;
				direction[i + 1][j + 1] = {1, 1};
			}
			else if (map[i][j + 1] >= map[i + 1][j]) {
				map[i + 1][j + 1] = map[i][j + 1];
				direction[i + 1][j + 1] = { 1, 0 };
			}
			else {
				map[i + 1][j + 1] = map[i + 1][j];
				direction[i + 1][j + 1] = { 0, 1 };
			}
			//cout << "(" << direction[i+1][j+1].first << " " << direction[i+1][j+1].second << ")" << " ";
		}
		//cout << endl;
	}
	int a = size1;
	int b = size2;
	string result;
	while (!(direction[a][b].first == 0 && direction[a][b].second == 0)) {
		if (direction[a][b].first == 1 && direction[a][b].second == 1) {
			//cout << a << " " << b << endl;
			result.push_back(input1[a-1]);
		}
		int tmpa = a - direction[a][b].first;
		int tmpb = b - direction[a][b].second;
		a = tmpa;
		b = tmpb;
	}
	reverse(result.begin(), result.end());
	cout << map[size1][size2] << endl;
	cout << result;
	return 0;
}
#endif