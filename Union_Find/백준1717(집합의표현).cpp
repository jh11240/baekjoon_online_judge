#include<iostream>

using namespace std;

int parent[1'000'001];

int GetParent(int a) {
	if (parent[a] == a) return a;
	else
		return parent[a] = GetParent(parent[a]);
}

void AddGroup(int a, int b) {

	//b의 root의 parent를 a 로 묶어버리기
	a = GetParent(a);
	b = GetParent(b);
	parent[b] = a;

}

bool IsSameGroup(int a, int b){
	a = GetParent(a);
	b = GetParent(b);


	return b== a;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int N,M;
	cin >> N;
	for (int i = 0; i < N+1; i++) {
		parent[i] = i;
	}
	int tmpWay, tmpA, tmpB;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmpWay >> tmpA >> tmpB;
		if (tmpWay) {
			if (IsSameGroup(tmpA, tmpB)) {
				cout << "yes" << "\n";
				continue;
			}
			cout << "no" << "\n";
			continue;
		}
		else {
			AddGroup(tmpA, tmpB);
		}
	}


}