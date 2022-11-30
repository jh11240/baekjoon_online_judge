//////////////////////////////////////////////////////////////////////////////////////////////////
//																	함수포인터 사용안하고 일일이 적은 케이스
//#include<iostream>
//#include<queue>
//
//using namespace std;
//int soobin = 0, brother = 0;
////false로 초기화됨
//bool visited[100'001];
//void input() {
//	cin >> soobin >> brother;
//
//}
//
//void solution() {
//	if (soobin == brother) { cout << 0; return; }
//	queue<int> q;
//	q.push(soobin);
//	visited[soobin] = true;
//	int level = 1;
//	for (; !q.empty(); level++) {
//		int qSize = q.size();
//		for (int i = 0; i < qSize; i++) {
//			int cur = q.front();
//			q.pop();
//			int nextA = cur + 1;
//			int nextB = cur - 1;
//			int nextC = 2 * cur;
//			if (nextA == brother) {
//				cout << level;
//				return;
//			}
//			if (nextB == brother) {
//				cout << level;
//				return;
//			}
//			if (nextC == brother) {
//				cout << level;
//				return;
//			}
//
//			if (nextA >= 0 && nextA <= 100'000) {
//				if (!visited[nextA]) {
//					visited[nextA] = true;
//					q.push(nextA);
//				}
//			}
//			if (nextB >= 0 && nextB <= 100'000) {
//				if (!visited[nextB]) {
//					visited[nextB] = true;
//					q.push(nextB);
//				}
//			}
//			if (nextC >= 0 && nextC <= 100'000) {
//				if (!visited[nextC]) {
//					visited[nextC] = true;
//					q.push(nextC);
//				}
//			}
//
//		}
//
//	}
//
//
//}
//
//int main() {
//	input();
//	solution();
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////															함수포인터 사용한 방법
#include<iostream>
#include<functional>
#include<queue>

using namespace std;
int soobin = 0, brother = 0;
//false로 초기화됨
bool visited[100'001];
//람다식으로 간단하게 구현
const function<int(int)> f[3] = {
	[](int n) {return n + 1; },
	[](int n) {return n - 1; },
	[](int n) {return 2 * n; }
};

void input() {
	cin >> soobin >> brother;

}

void solution() {
	if (soobin == brother) { cout << 0; return; }
	queue<int> q;
	q.push(soobin);
	visited[soobin] = true;
	int level = 1;
	for (; !q.empty(); level++) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < 3; i++) {
				//함수 배열에서 가져와 씀
				int nextC = f[i](cur);

				if (nextC == brother) {
					cout << level;
					return;
				}

				if (nextC >= 0 && nextC <= 100'000) {
					if (!visited[nextC]) {
						visited[nextC] = true;
						q.push(nextC);
					}
				}

			}
		}

	}


}

int main() {
	input();
	solution();
}