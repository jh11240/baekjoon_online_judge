#include<iostream>

using namespace std;
int N=0, S=0,currentSum=0,cnt=0;
int Num[21];
void Input() {
	cin >> N >> S;
	for(int i=0;i<N;i++){
		cin >> Num[i];
	}
}

void DFS(int cur) {
	//DFS의 끝노드 도달시 return
	if (cur == N) return;
	//현재 cur 인덱스의 값을 더했을 때, S가 나오면 cnt++
	if (currentSum + Num[cur] == S) cnt++;
	
	//현재값을 더하지않고 다음값으로 진행
	DFS(cur + 1);

	//돌아와서 현재값을 더하고 다음값으로 진행
	currentSum += Num[cur];
	DFS(cur + 1);
    //cur인덱스의 정점을 방문 완료 후 빼줘야함(다시 방문가능하도록) 
	currentSum -= Num[cur];
}

void Solution() {
	DFS(0);
	cout << cnt;
}

int main() {
	Input();
	Solution();
}