#include<iostream>
#include<queue>

using namespace std;

int	floorB = 0, heightB = 0, widthB = 0;

char building[31][31][31];
bool visited[31][31][31];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};

struct room {
	int floor;
	int height;
	int width;
};

//층, 행. 렬
void BFS(int initX,int initY,int initZ) {
	queue<room> q;
	visited[initX][initY][initZ] = true;
	q.push({ initX, initY, initZ });
	int level = 1;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			room tmp = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nextA = tmp.floor + dx[i];
				int nextB = tmp.height + dy[i];
				int nextC = tmp.width + dz[i];
				if (building[nextA][nextB][nextC] == 'E') {
					cout<<"Escaped in "<< level<<" minute(s)."<<'\n';
					return;
				}
				if (nextA >= 0 && nextB >= 0 && nextC >= 0 && nextA < floorB && nextB < heightB && nextC < widthB && building[nextA][nextB][nextC]=='.') {
					if (!visited[nextA][nextB][nextC]) {
						visited[nextA][nextB][nextC] = true;
						q.push({ nextA,nextB,nextC });
					}

				}
			}
		}
		level++;

	}
	cout << "Trapped!"<<'\n';
}

void input() {
	char cube = ' ';
	int initX = 0, initY = 0, initZ = 0;
	while (1) {
		cin >> floorB >> heightB >> widthB;
		if (floorB == 0 && heightB == 0 && widthB == 0) return;

		fill(&visited[0][0][0], &visited[floorB][heightB][widthB], false);
		for (int i = 0; i < floorB; i++) {
			for (int j = 0; j < heightB; j++) {
				for (int k = 0; k < widthB; k++) {
					cin >> cube;
					if (cube == 'S') {
						initX = i;
						initY = j;
						initZ = k;
					}
					building[i][j][k] = cube;
				}
			}
		}
		BFS(initX, initY, initZ);
	}

}

int main() {
	input();
}