#include<iostream>
#include<vector>

using namespace std;

int pensioners=0, channels=0, initChannel=0,channelChangedNum=0;
vector<int> adj;
vector<bool> visited;

void input() {
	int fromNode = 0, toNode = 0;
	cin >> pensioners >> channels >> initChannel;
	adj.resize(channels+1);
	visited.resize(channels+1);
	fill(visited.begin(), visited.end(), false);
	
	for (int i = 0; i < pensioners; i++) {
		cin >> toNode >> fromNode;
		//한 노드가 가리키는노드는 무조건 하나이므로 
		if (adj[fromNode] == 0)
			adj[fromNode] = (toNode);
		//이미 입력된 노드면 무시한다.
		else
			continue;
	}
}

void dfs(int Node) {
	//해당 노드에서 연결된게 없으면 채널 모두가 만족
	if (adj[Node]==0) return;
	//만약 방문한 채널이 아니라면
	if (!visited[adj[Node]]) {
		//방문 체크
		visited[adj[Node]] = true;
		//싸이클이 아닌경우
		if (channelChangedNum != -1) {
			//채널 바꾼 수 +1
			channelChangedNum++;
			//다음 노드값 dfs함수 시행
			dfs(adj[Node]);
		}
	}
	//방문한 채널을 또 방문하면 무조건 싸이클이므로 
	else {
		//싸이클일땐 -1로 저장
		channelChangedNum = -1;
	}
}

void solution() {
	dfs(initChannel);
	cout << channelChangedNum;
}

int main() {
	input();
	solution();

}