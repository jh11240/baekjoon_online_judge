#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

void Input() {

	int N=0,tmp=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			//우선순위큐가 비어있거나, 새로 입력받는 값이 pq.top값보다 클때
			if (pq.empty() || tmp > pq.top()) {
				//만약 pq의 사이즈가 N개일때는 pop해준다
				if (pq.size() == N)
					pq.pop();
				//N개가 아닐땐 push
				pq.push(tmp);
			}

		}
	}

	cout << pq.top();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}