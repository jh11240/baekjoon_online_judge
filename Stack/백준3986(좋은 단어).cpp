#include<iostream>
#include<stack>
using namespace std;
int N;
string inputStr[101];
stack<char> s;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inputStr[i];
	}
}
/// <summary>
/// index번째의 단어를 조사
/// </summary>
/// <param name="입력 string배열의 index"></param>
/// <returns>좋은 단어라면 1 아니라면 0</returns>
int checkStr(int index) {
	//스택 초기화
	while (!s.empty()) {
		s.pop();
	}
	//해당 index의 문자열의 각 문자를 조사
	for (int i = 0; i < inputStr[index].length(); i++) {
		//스택 비어있다면 i번째 문자 푸시
		if (s.empty())
			s.push(inputStr[index][i]);
		//스택의 top과 i번째 문자를 비교해서 같다면 스택 pop해줌
		else if (s.top() == inputStr[index][i])
		{
			s.pop();
		}
		//다르다면 스택에 i번째 문자 푸시
		else
			s.push(inputStr[index][i]);
	}
	//반복문 끝나고 스택 비어있다면 좋은 단어이므로 1
	if (s.empty()) return 1;
	//스택에 뭔가 차있다면 나쁜단어이므로 0 
	else return 0;
}

void solution() {
	int Ans = 0;
	for (int i = 0; i < N; i++) {
		Ans+=checkStr(i);
	}
	cout << Ans;
	
}

int main() {
	input();
	solution();
}