#include<iostream>
#include<stack>

using namespace std;
string inputStr;
stack<char> s;

void input() {
	cin >> inputStr;

}
void solution() {
	for (int i = 0; i < inputStr.length(); i++) {
		//'+'나 '-'가 들어왔을 때, 
		if (inputStr[i] == '+' || inputStr[i] == '-') {
			// 비어있을때까지 혹은 '(' 나 ')' 나오기 전까지 순서대로 top부터 밑까지 다 출력
			while (!s.empty() && s.top()!='('&& s.top()!=')') {
				cout << s.top();
				s.pop();
			}
			//출력후 들어온 값 넣어주기
			s.push(inputStr[i]);
		}
		//*이나 /들어왔을 때
		else if (inputStr[i] == '*' || inputStr[i] == '/') {
			//스택 비어있다면 그냥 push
			if (s.empty()) {
				s.push(inputStr[i]);

			}
			//+나 -,'(',')' 들어있을 때도 그냥 push
			else if (s.top() == '+' || s.top() == '-' ||s.top()=='(') {
				s.push(inputStr[i]);
			}
			//*나 / 들어오면 전에 들어있던 값 넣어줌
			else {
				cout << s.top();
				s.pop();
				s.push(inputStr[i]);
			}
		}
		// '('들어오면 그냥 push
		else if (inputStr[i] == '(') {
			s.push('(');
		}
		//')'들어오면 스택안은 어차피 정렬되있을 것이므로 stack의 top()값이 '('나올때까지 top부터 순서대로 출력. 
		else if (inputStr[i] == ')') {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			cout << inputStr[i];
		}
	}
	//마지막에 스택 남은것 처리
	while (!s.empty()&&s.top()!='('&&s.top()!=')') {
		cout << s.top();
		s.pop();
	}
}

int main() {
	input();
	solution();
}
