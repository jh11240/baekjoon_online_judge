#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> v;
bool comp(pair<int, int>a, pair<int, int>b) {			//tastiness가 더 큰순대로 비교, tastiness가 같다면 시간이 더 적은순대로 나열
	if (a.second != b.second)
		return a.second > b.second;
	else
		return a.first < b.first;

}

void input(int& L, int& N,long long& Rf,long long& Rb) {			//입력받는 함수
	int Xi = 0, Ci = 0;
	cin >> L >> N >> Rf >> Rb;
	for (int i = 0; i < N; i++) {
		cin >> Xi >> Ci;
		v.push_back(make_pair(Xi, Ci));
	}


}
void solution(const int& L,const int& N,const long long& Rf,const long long& Rb) {
	long long ans = 0, curRestDistance = 0;;								//답, 쉰장소
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < N; i++) {
		if (curRestDistance < v[i].first) {
			long long differDistance = v[i].first - curRestDistance;		//전에 쉰 장소에서 베시가 존 기다리므로 
			long long differSecond = differDistance* Rf - differDistance* Rb;		//제일 tastiness가 높은 곳에 도달 했을 때, 그 둘의 시간 차이
			ans += differSecond * v[i].second;
			curRestDistance = v[i].first;
		}
	}
	cout << ans;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	int L = 0, N = 0;
	long long Rf = 0, Rb = 0;

	input(L,N,Rf,Rb);
	solution(L,N,Rf,Rb);
}