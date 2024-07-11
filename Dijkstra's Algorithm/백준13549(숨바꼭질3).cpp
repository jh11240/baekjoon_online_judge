#include<iostream>
#include<queue>

using namespace std;

int minDist[100'002];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int N, K;
	fill(&minDist[0], &minDist[100'002], 111'111);
	cin >> N >> K;
	
	minDist[N] = 0;
	pq.push(N);
	while (!pq.empty()) {
		int curNode = pq.top();
		pq.pop();

		if (curNode * 2 < 100'001 && minDist[curNode * 2] > minDist[curNode]) {
			pq.push(curNode * 2);
			minDist[curNode * 2] = minDist[curNode];
		}
		if (curNode+1 <100'001&& minDist[curNode + 1] > minDist[curNode] + 1) {
			pq.push(curNode + 1);
			minDist[curNode + 1] = minDist[curNode] + 1;
		}
		if (curNode > 0 && minDist[curNode - 1] > minDist[curNode] + 1) {
			pq.push(curNode - 1);
			minDist[curNode - 1] = minDist[curNode] + 1;
		}
	}

	cout << minDist[K];

}