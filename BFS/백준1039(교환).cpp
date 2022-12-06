#include<iostream>
#include<string>
#include<queue>
#include<set>

using namespace std;
//N, K , K번 바꿨을때 최대수
string N;
int K = 0, maxNum = -1;
//문자열 방문 set
set<string> visited;
void Input() {
	cin >> N >> K;
}

void Solution() {
	//bfs에 쓰일 queue
	queue<string> q;
	//초기값 push
	q.push(N);
	while (!q.empty()) {
		int qSize = q.size();
		//횟수 만큼만 연산해야하므로 -1
		K--;
		//연산 해준 값이 다음 번 연산 때 또 나올수 있으므로 각 연산전에 초기화해줌
		visited.clear();
		for (int i = 0; i < qSize; i++) {
			//큐에 들어가있는 숫자 cur에 넣어줌
			string cur = q.front();
			q.pop();
			//k는 j보다 무조건 커야함 (조건) 수의 크기는 문자열의 길이
			for (int j = 0; j < N.length() - 1; j++) {
				for (int k = j + 1; k < N.length(); k++) {
					string tmp = cur;
					//바꿨을때 앞자리가 0이오면 안됨
					if (j == 0 && tmp[k] == '0') continue;
					//자릿수 바꿔줌
					swap(tmp[j], tmp[k]);
					//set에 자리를 바꿔준 값이 없다면
					if (visited.find(tmp) == visited.end()) {
						//set에 넣어줌
						visited.insert(tmp);
						//큐에 푸시
						q.push(tmp);
					}
				}
			}
		}
		//연산횟수를 다 써서 K==0일 때
		if (K == 0) {
			//큐에 담긴 값들이 연산끝났을때 가능한 수들이므로
			while (!q.empty()) {
				int cur = stoi(q.front());
				//제일큰값 탐색
				maxNum = maxNum > cur ? maxNum : cur;
				q.pop();
			}
			cout << maxNum;
			return;
		}
	}
	// 반복문을 빠져나온다면 연산을 다했는데 K가 남아있는 경우로 -1 출력
	cout << -1;
}
int main() {
	Input();
	Solution();
}