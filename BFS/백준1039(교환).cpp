#include<iostream>
#include<string>
#include<queue>
#include<set>

using namespace std;
//N, K , K번 바꿨을때 최대수
string N;
int K=0,maxNum = -1;
set<string> visited;
void Input() {
	cin >> N >> K;
}

void Solution() {
	if (N.length() < K) {
		cout << -1;
		return;
	}
	queue<string> q;
	q.push(N);
	while (!q.empty()) {
		int qSize = q.size();
		K--;
		visited.clear();
		for (int i = 0; i < qSize; i++) {
			string cur = q.front();
			//visited.insert(cur);
			q.pop();
			for (int j = 0; j < N.length()-1; j++) {
				//i이전 값
				for (int k = j+1; k < N.length(); k++) {
					string tmp = cur;
					if (tmp[k] == 0) continue;
					swap(tmp[j], tmp[k]);
					if (visited.find(tmp) == visited.end()) {
						visited.insert(tmp);
						q.push(tmp);
					}
				}
			}
		}
		if (K == 0) {
			while(!q.empty()){
				int cur = stoi(q.front());
				maxNum = maxNum > cur ? maxNum : cur;
				q.pop();
			}
			cout << maxNum;
			return;
		}

	}
}
int main() {
	Input();
	Solution();
}