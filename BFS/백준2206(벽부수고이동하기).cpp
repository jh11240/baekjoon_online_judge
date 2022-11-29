#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int height = 0, width = 0;
int map[1001][1001];
bool visited[2][1001][1001];

void input() {
	char tmp=0;
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}
}


void solution() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0][0] = true;
	int level = 1;
	while (!q.empty()) {
		int qSize = q.size();
		bool reach = false;
		for (int i = 0; i < qSize; i++) {
			bool crash;
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			if (r == height - 1 && c == width - 1) {
				reach = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nextR = r + dx[i];
				int nextC = c + dy[i]; 
				if (nextR < 0 && nextC < 0 && nextR >= height && nextC >= width) continue;
				if (visited[crash][nextR][nextC]) continue;
				//벽이 있다면
				if (map[nextR][nextC]) {
					if (crash) continue;
					visited[1]
				}
			}
		}
	}

}

int main() {

}