#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//블록 정보값 #이랑 .입력용
char v[1001][1001];
//DFS방식으로 탐색하기 위함
bool visited[1001][1001];
//순서대로 총 테케 수, 행값, 열값, 시작 노드의 좌표X,Y, 제일 긴 로프 길이 저장용 변수
int N,tmpRow,tmpColumn,startX,startY,maxRopeLen;
//상하좌우값 표시 용이하도록
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//초기화하는 함수
void Init() {
	fill(&v[0][0], &v[tmpRow][tmpColumn], 'a');
	fill(&visited[0][0], &visited[tmpRow][tmpColumn], false);
	maxRopeLen = 0;
}

void Solution();

void Input() {
	char tmpBlockInfo=' ';
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmpColumn >> tmpRow;
		Init();
		for (int i = 0; i < tmpRow; i++) {
			for (int j = 0; j < tmpColumn; j++) {
				cin >> tmpBlockInfo;
				//free 블록이라면 startX에 저장
				if (tmpBlockInfo == '.') {
					startX = i;
					startY = j;
				}
				v[i][j] = tmpBlockInfo;
			}
		}
		Solution();
	}
}
//블록에서 블록까지 이어진 길은 무조건 하나이므로 백트래킹방식이 아님, dfs로 찾기
//-> 1번노드부터 4번노드까지 1.2.3.4 이렇게 이어졌다면 1.2.5.4 이렇게 다른방식으로 4갈순없다는 뜻


//(x,y)에서 안 가본 루트 중에 제일 긴 루트의 길이를 반환
int findLongestDiameter(int x,int y) {
	//방문했다면 0을 return
	if (visited[x][y]) return 0;
	visited[x][y] = true;
	//x,y에서 갈수 있는 루트중에 제일 긴값과 두번째로 긴값
	int tmpLongest = 0, tmpSecondLongest = 0;
	//상하좌우만 갈수있고 대각선은 못간다고 문제에서 못 박았다.
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		//x,y에서 nextX,nextY 까지 길이는 1이므로 1더해줌
		int tmp = 1;

		//다음 좌표가 벽이면 컨티뉴
		if (v[nextX][nextY] == '#')continue;
		//다음좌표가 범위를 넘어가면 컨티뉴
		if (nextX < 0 || nextY < 0 || nextX >= tmpRow || nextY >= tmpColumn) continue;
		//이미 방문한 좌표라면 컨티뉴
		if (visited[nextX][nextY]) continue;
		//nextX,nextY값에서 시작한 루트중에 제일 긴 거리값을 반환해서 tmp에 더해줌 
		tmp += findLongestDiameter(nextX, nextY);
		//이번 tmp값이 제일 길다면 
		if (tmp > tmpLongest) {
			//두번째로긴값에 제일 긴값 저장해주고
			tmpSecondLongest = tmpLongest;
			//제일 긴값 갱신
			tmpLongest = tmp;
		}
		//이번 tmp값이 두번째로 길다면 
		else if(tmp<=tmpLongest&& tmp>tmpSecondLongest) 
		{
			//두번째로 긴값으로 갱신
			tmpSecondLongest = tmp;
		}
	}
	
	//각 노드(x,y)에서 제일 긴값과 두번째로 긴값 갱신해서 답냄.
	maxRopeLen = max(maxRopeLen, tmpSecondLongest+tmpLongest );
	return tmpLongest;
}

void Solution() {
	findLongestDiameter(startX, startY);
	cout <<"Maximum rope length is " << maxRopeLen<<"." << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	Input();
}