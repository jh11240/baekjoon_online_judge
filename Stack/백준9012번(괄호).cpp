#include<iostream>
#include<vector>

using namespace std;

int N;
vector<string> s;

void input() {
	string ps = "";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ps;
		s.push_back(ps);
	}
}

bool checkParenthesis(int index) {
	int cnt=0;
	for (int i = 0; i < s[index].length(); i++) {
		if (s[index][i] == '(')
			cnt++;
		else {
			//닫는 괄호가 들어왔을 때cnt가 0이거나 음수가 들어오면 안됨
			if (cnt <= 0)
				return false;
			cnt--;
		}
	}
	if (cnt == 0) return true;
	else return false;

}

void solution() {
	for (int i = 0; i < N; i++) {
		if (checkParenthesis(i)) {
			cout << "YES" << '\n';
		}
		else
			cout << "NO" << '\n';
	}
}

int main() {
	input();
	solution();
}