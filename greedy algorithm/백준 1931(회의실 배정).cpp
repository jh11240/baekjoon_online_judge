#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> v;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;

}

void input(int& amount) {
	int sTime=0, eTime = 0;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> sTime >> eTime;
		v.push_back(make_pair(sTime, eTime));
	}
}
	
void solution(const int& amount) {															//답 도출함수
	int currentSecond = 0, ans = 1;                                                         //두번째값만 비교
	sort(v.begin(), v.end(),comp);															//정렬
	currentSecond = v[0].second;
	for (int i=1;i<v.size();i++)
	{
		
		if (v[i].first >= currentSecond) {
			ans++;
			currentSecond = v[i].second;	
		}
	}

	cout << ans;
}

int main() {
	int amount = 0;
	input(amount);
	solution(amount);
}