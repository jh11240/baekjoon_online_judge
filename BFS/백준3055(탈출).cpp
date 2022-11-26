#include<iostream>
#include<queue>

using namespace std;
int height = 0, width = 0;
char TW[51][51];
queue<pair<int,int>> hedgehog;
bool visitedH[51][51];
queue<pair<int,int>> flood;
bool visitedF[51][51];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void BFS(int targetA, int targetB);

void input() {
	int targetA = 0, targetB = 0;
	cin >> height >> width;
	fill(&visitedH[0][0], &visitedH[50][50], false);
	fill(&visitedF[0][0], &visitedF[50][50], false);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> TW[i][j];
			if (TW[i][j] == '*') {
				flood.push({ i,j });
				visitedH[i][j] = true;
			}
			else if (TW[i][j] == 'S') {
				hedgehog.push({ i,j });
				visitedF[i][j] = true;
					
			}
			else if (TW[i][j] == 'D') {
				targetA = i;
				targetB = j;
			}
		}
	}
	BFS(targetA,targetB);
}

void BFS(int targetA,int targetB) {
	int level = 1;
	while (!hedgehog.empty()) {
		int hSize = hedgehog.size();
		int fSize = flood.size();
		for (int i = 0; i < fSize; i++) {
			pair<int,int> cur = flood.front();
			flood.pop();
			for (int j= 0; j < 4; j++) {
				int nextA = cur.first + dx[j];
				int nextB = cur.second + dy[j];
				if (nextA >= 0 && nextB >= 0 && nextA < height && nextB < width && TW[nextA][nextB] == '.'&& TW[nextA][nextB]!='S') {
					if (!visitedF[nextA][nextB]) {
						visitedF[nextA][nextB] = true;
						flood.push({ nextA,nextB });
					}
				}
			}
		}
		for (int i = 0; i < hSize; i++) {
			pair<int, int> cur = hedgehog.front();
			hedgehog.pop();

			for (int j = 0; j < 4; j++) {
				int nextA = cur.first + dx[j];
				int nextB = cur.second + dy[j];
				if (nextA ==targetA && nextB ==targetB && !visitedF[nextA][nextB]) {
					cout << level;
					return;
				}
				if (nextA >= 0 && nextB >= 0 && nextA < height && nextB < width && !visitedF[nextA][nextB] && TW[nextA][nextB] == '.') {
					if (!visitedH[nextA][nextB]) {
						visitedH[nextA][nextB] = true;
						hedgehog.push({ nextA,nextB });
					}
				}
			}
		}
		level++;
	}
	cout << "KAKTUS";

}

int main() {
	input();
}