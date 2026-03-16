#include<iostream>									//3
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int arr[1001];											//점수대로 정렬후 며칠차에 어떤 과제를 하는게 좋은지 저장하는 배열
vector<pair<int,int>> v;
bool comp(pair<int, int> a, pair<int, int> b) {		//점수대로 정렬
	return a.second > b.second;
}

void input(int& maxDate) {										//입력함수 
	int amountH=0,tempD=0,tempW=0;
	cin >> amountH;
	for (int i = 0; i < amountH; i++) {
		cin >> tempD >> tempW;
		maxDate = tempD > maxDate ? tempD : maxDate;
		v.push_back(make_pair(tempD,tempW));
	}
}

void solution(const int& maxDate) {
	int ans = 0,idx=0;
	sort(v.begin(), v.end(),comp);										// 점수대로 정렬
	for (int i = 0; i < v.size();i++ ) {
		int day = v[i].first;											//v[i].first값을 day에 저장
		while (day>1 && arr[day] != 0 && arr[day]>=v[i].second) day--;	//만약 해당 날짜에 이미 다른 값이 저장되어있다면 그 앞날짜로 index를 옮겨준다.
																		//arr[day]>v[i].second에서 같을땐 생각을 안해서 틀림
		if(arr[day]<v[i].second) arr[day]= v[i].second;					//만약 arr[day]이 비어있다면 넣어준다.

																		// !조건을추가해야됨 비교했는데 더크면 교체.
	    
	}
	for(int i=1;i<=maxDate;i++)
		ans += arr[i];
	cout << ans;

}

int main() {
	int maxDate=0;
	input(maxDate);
	solution(maxDate);
}