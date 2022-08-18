#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>

using namespace std;
//물품의 수
const int N = 101;
//버틸수 있는 무게
const int K = 100'001;
int dp[K][N], inputN = 0, inputK = 0,W[N],V[N];
//무게,가치
vector<pair<int, int>> v;

void input() {
	int  temp1 = 0, temp2 = 0;
	cin >> inputN >> inputK;

	for (int i = 0; i < inputN; i++) {
		cin >> temp1 >> temp2;
		//cin >> W[N] >> V[N];
		v.push_back(make_pair(temp1,temp2));
	}
	memset(dp, -1, sizeof(dp));
}

//현재 타겟무게가 targetweight일때, n번째부터 끝까지 중에서 최대 가치
int solution(int targetWeight, int n) {
	//dp 참조
	int& ret = dp[targetWeight][n];
	//ret이 이미 저장되어있다면 return;
	if (ret != -1) return ret;
	// 끝을 넘어가면 최대가치는 0
	if (n == inputN) {
		ret = 0;
		return ret; 
	}

	ret = solution(targetWeight, n + 1);

	//max함수의 left는 n번째물품을 포함했을때, right는 n번째 물품을 포함 안했을 때
	//targetweight가 inputK를 넘는지 확인하
	if(targetWeight+v[n].first <= inputK) ret = max(solution(targetWeight+v[n].first , n + 1 )+ v[n].second , ret);

	return ret;
}

int main() {
	input();
	int ans=solution(0,0);
	cout << ans;
}