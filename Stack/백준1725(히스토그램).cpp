#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int N;
long long inputArr[100'001];

struct histogram {
	int index;
	int height;
};

stack<histogram> s;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
	}
}

long long maxArea(int lastIndex) {
	long long preIndex = 0,preHeight=0, ret=0;
	//스택안의 값중 lastindex번째로 들어온 값보다 큰게 있다면
	while (!s.empty() && s.top().height>=inputArr[lastIndex]) {
		//stack의 top값 저장
		preIndex = s.top().index;
		preHeight= s.top().height;
		//pop을 하여 비교하려는 막대 이전 막대의 index구함
		s.pop();

		//pop했을때 스택이 비었다면 해당 막대가 제일 작은 막대이므로 시작점부터 lastindex까지가 거리
		if (s.empty()) ret = max(ret, preHeight*lastIndex);
		//스택이 안비었다면 pop한 막대로 만들수 있는 최대 넓이값의 가로길이는 이전 막대와 lastindex사이의 거리다.
		else ret = max(ret, (long long)preHeight * (lastIndex - s.top().index-1));
	}
	histogram h = { lastIndex, inputArr[lastIndex] };
	s.push(h);
	return ret;
}

void solution() {
	//이전 값,정답
	long long Ans=0;
	for (int i = 0; i < N; i++) {
		//이전 값이 없다면
		if (i == 0) {
			histogram h = {i, inputArr[i]};
			s.push(h);
		}
		//이전 값이 있다면
		else if(!s.empty()) {
			//이전값보다 입력값이 더 크면
			if (s.top().height<= inputArr[i]) {

				histogram h = {i, inputArr[i]};
				//스택에 푸시
				s.push(h);
			}
			//이전값보다 입력값이 더 작으면
			else {
				//해당 입력값까지의 제일 큰 값 넣어준다.
				Ans = max(Ans,maxArea(i));
			}
		}
	}
	//stack이 비어있지 않다면 0값을 넣어줘 남은 스택들끼리 연산하게 함.
	if (!s.empty()) {
		Ans = max(Ans, maxArea(N));

	}
	cout << Ans;
}

int main() {
	input();
	solution();
}