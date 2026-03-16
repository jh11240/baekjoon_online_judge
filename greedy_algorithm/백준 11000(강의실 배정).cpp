//                                  
//#include<iostream>				                                                 //used를 이용해 한번 본 부분은 스킵하며 하려했는데 시간초과난다													//3
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<pair<int, int>> v;															//입력값 벡터
//vector<int> used;																	//각 입력값에 대해 썼는지 안썼는지
//
//void input() {
//	int sTime = 0, eTime = 0, amount = 0;
//	cin >> amount;
//	for (int i = 0; i < amount; i++) {
//		cin >> sTime >> eTime;
//		v.push_back(make_pair(sTime, eTime));
//		used.push_back(0);
//	}
//}
//
//void solution() {																	//답 도출함수
//	sort(v.begin(), v.end());														//정렬
//	int currentfirst = 0, currentsecond = 0, ans = 0;								//지금 v.first값,v.second값,강의실 수
//	for (int i = 0; i < v.size(); i++) {
//		if (used[i] > 0) continue;													//s와 t가 같은 값은 안들어오니 한번 들으면 들은 시간대는 체크
//		used[i] ++;
//		ans++;
//		currentsecond = v[i].second;												//각 i값에서 반복 (혹시 맨처음값부터 시작한게 답이 아닐수도 있으므로) 
//
//		for (int j = i+1; j < v.size(); j++) {
//
//			if (used[j] > 0) continue;
//
//																					first값이 새로운 값으로 넘어왓다는 뜻이므로
//			if (v[j].first < currentsecond)	continue;								//currentsecond값나올때까지 스킵
//				
//			used[j]++;
//			currentsecond = v[j].second;											//이제 v[j].first가 currentsecond값보다 같거나 크므로
//		}
//	
//	}
//	cout << ans;
//}
//
//int main() {
//	input();
//	solution();
//}

#include<iostream>                      //우선순위 큐를 이용해 시간초과 안나게
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;

void input() {
	 int sTime = 0, eTime = 0, amount = 0;
	 cin >> amount;
	 for (int i = 0; i < amount; i++) {
		 cin >> sTime >> eTime;
		 v.push_back(make_pair(sTime, eTime));
	 }
	 sort(v.begin(), v.end());
	 pq.push(v[0].second);
}
void solution() {
	 for (int i = 1; i < v.size(); i++) {
		 if (v[i].first >= pq.top()) {
			 pq.pop();
			 pq.push(v[i].second);
		 }
		 else
			 pq.push(v[i].second);
	 }

	 cout << pq.size();
}

int main() {
	input();
	solution();
}