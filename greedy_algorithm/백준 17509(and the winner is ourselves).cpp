#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> times;			//더하는 건지 몰랐다.

void input(){
	int T = 0, V = 0;
	for (int i = 0; i < 11; i++) {
		cin >> T >> V;
		times.push_back(make_pair(T, V));
	}
	sort(times.begin(), times.end());		//algorithm헤더의 sort에선 페어는 first부터 비교
}
void solution() {
	int timeSum = 0,ans=0;					//시간 누적합, 답
	for (pair<int, int> i : times) {		//벡터의 모든 pair에서
		timeSum += i.first;					//시간 누적해서합해주고
		ans += timeSum + 20 * i.second;		//시간 누적합과 오차 시간 더해준다
	}
	cout << ans;
}


int main() {
	input();
	solution();

}