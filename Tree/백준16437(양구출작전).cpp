#include<iostream>
#include<vector>
using namespace std;
struct info {
	char wolfOrSheep;
	//~10억
	int amount;
	int parent;
};
//각 노드의 정보담은 벡터 ~12만
vector<info> islandInfo;
//각 노드의 연결 정보 담은 벡터 ~12만 * 12만
vector<vector<int> > v;
//각 노드의 방문여부 탐색 ~12만
vector<bool> visited; 

void Input() {
	int N = 0, amount = 0,parent=0;
	char wOS='S';
	info tmpInfo;
	cin >> N;
	v.resize(N + 2);
	visited.resize(N + 2,false);
	islandInfo.resize(N + 2);
	for (int i = 2; i <= N; i++) {
		cin >> wOS>>amount>>parent;
		tmpInfo = { wOS,amount,parent};
		islandInfo[i]=tmpInfo;
		v[i].push_back(parent);
		v[parent].push_back(i);
	}
}
//재귀를 통해 리프값부터 가져오기 시작함
long long FindLeaves(int Node) {
	long long sheepRemaining = 0;
	visited[Node] = true;
	for (int elem : v[Node]) {
		if (visited[elem]) continue;
		sheepRemaining+=FindLeaves(elem);
	}
	//이전단계로 돌아가기전
	//해당 노드가 양이 있는 노드라면 
	if (islandInfo[Node].wolfOrSheep == 'S') {
		//sheepRemaining값에 양 값 저장해준 후,
		sheepRemaining += islandInfo[Node].amount;
		//해당 노드의 양 갯수를 0으로
		islandInfo[Node].amount = 0;
	}
	//해당 노드가 늑대가 있는 노드라면
	else {
		//양갯수가 늑대보다 많다면
		if (sheepRemaining > islandInfo[Node].amount) {
			//sheepRemainig변수에서 늑대갯수 빼줌
			sheepRemaining -= islandInfo[Node].amount;
			//늑대 갯수 제거
			islandInfo[Node].amount = 0;
		}
		//늑대가 더 많다면
		else {
			//해당 노드의 늑대 갯수에서 sheepRemaining값 만큼 빼줌
			islandInfo[Node].amount -= sheepRemaining;
			// 남은양갯수가 0이므로 sheepRemaining은 0
			sheepRemaining = 0;
		}
	}
	//sheepRemaining변수 return
	return sheepRemaining;
	
}
void Solution() {
	long long ans = 0;
	cout<<FindLeaves(1);
}

int main() {
	Input();
	Solution();
}