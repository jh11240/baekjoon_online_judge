#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int N=0;
vector<pair<int, int>> v;
stack<pair<int,int>> s;

bool comp(pair<int,int> a, pair<int,int> b) {
	if (a.first != b.first) return a.first < b.first;
	//물론 a와 b의 위치가 같을일은 없지만 엄격하게 비교함수 작성해야하므로
	else return a.second < b.second;

}

void input() {
	int L = 0, H = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L >> H;
		v.push_back(make_pair(L, H));
	}
	sort(v.begin(), v.end(), comp);

}
/// <summary>
/// 입력값들을 stack안에 조건에 맞게 넣는 함수
/// </summary>
void roofStackManage() {
	int tmpIndex = 0, tmpHeight = 0, maxHeight = 0;
	//정렬된 입력값들 순서대로 스택에 넣고 빼는 작업
	for (int i = 0; i < v.size(); i++)
	{
		tmpHeight = v[i].second;
		tmpIndex = v[i].first;
		//맨 처음
		if (i == 0)
		{
			s.push(make_pair(tmpIndex, tmpHeight));
			continue;
		}

		//지금 막대가 스택의 top 막대보다 크다면 
		if (v[i].second >= s.top().second) {
			//한번도 밑으로 안꺾인 막대그래프면
			if (maxHeight == 0) {
				//그대로 push
				s.push(make_pair(v[i].first, v[i].second));
				continue;
			}
			//지금까지 제일 큰 높이보다 크다면
			else if (v[i].second >= maxHeight) {
				//해당 높이 값 다음 막대들 다 스택에서 pop
				while (s.top().second != maxHeight) {
					s.pop();
				}
				//maxHeight 갱신
				maxHeight = v[i].second;
				s.push(make_pair(v[i].first,v[i].second));
				continue;
			}
			//한번 꺾인 애면 지금 넣으려는갑보다 낮은 막대들 전부 pop
			while (s.top().second <= v[i].second) {
				s.pop();
			}
			//막대 넣기
			s.push(make_pair(v[i].first, v[i].second));
		}
		//지금 넣으려는 막대가 스택의 top 막대보다 작다면
		else {
			maxHeight = max(maxHeight,s.top().second);
			s.push(make_pair(v[i].first, v[i].second));
		}

	}
}

/// <summary>
/// stack안에 조건에 맞게 들어간 막대들을 통해 지붕 넓이 구하는 함수
/// </summary>
void calculateRoofArea() {
	int tmpIndex=0, tmpHeight=0,retArea=0;
	if (s.size() == 1) {
		cout << s.top().second;
		return;
	}
	while (!(s.size()==1)) {
		tmpIndex = s.top().first;
		tmpHeight= s.top().second;
		s.pop();

		//만약 해당 값보다 이전 값이 크다면 
		if (s.top().second >= tmpHeight) {
			retArea += (tmpIndex - s.top().first) * tmpHeight;
			//계산하고 스택 size가 1일땐 스택 top것도 계산해줘야함 마지막 막대는 무조건 작대기 하나.
			//(마지막 남은게 평평해지려면 평평해진 값 끝값 두개 들어가있어야해서 모순)
			if (s.size() == 1) {
				retArea += s.top().second;
			}
		}
		//만약 해당 값보다 이전 값이 작다면
		else {
			retArea += tmpHeight;
			retArea += (tmpIndex - s.top().first-1) * s.top().second;
			if (s.size() == 1) {
				retArea += s.top().second;
			}
		}
	}
	cout << retArea;
}


int main() {
	input();
	roofStackManage();
	calculateRoofArea();
}