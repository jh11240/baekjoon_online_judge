#include<iostream>
#include<list>
#include<vector>

using namespace std;
int N;
list<char> passWord;
vector<string> testCases;
list<char>::iterator passWordCursor;

void input() {
	string abc;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> abc;
		testCases.push_back(abc);
	}
	//커서 초기화
	passWordCursor = passWord.end();
}
/// <summary>
/// index번째의 입력 문자열의 각 char형 원소를 분석해 passWordCursor을 움직이며 passWord 리스트에 적고 지우고 하기 
/// </summary>
/// <param name="index"></param>
void solvePassword(int index) {
	//password 리스트 초기화
	passWord.clear();
	passWordCursor = passWord.end();
	for (int i = 0; i < testCases[index].length(); i++) {
		//다음이 -면 커서 전값 지우기
		if (testCases[index][i] == '-') {
			//사이즈 없다면
			if (passWord.size() == 0) {
				continue;
			}
			//커서가 첫 값이라면 전값 없으므로
			if (passWordCursor == passWord.begin()) { 
				//패스
				continue;
			}
			passWordCursor=passWord.erase(--passWordCursor);
		}
		//다음 <일 때
		else if (testCases[index][i] == '<') {
			//사이즈 없다면
			if (passWord.size() == 0) {
				continue;
			}
			//커서 하나 옆이 첫 값이라면
			if (passWordCursor == passWord.begin()) {
				//패스
				continue;
			}
			passWordCursor--;
		}
		//다음 >일 때
		else if (testCases[index][i] == '>') {
			//사이즈 없다면
			if (passWord.size() == 0) {
				continue;
			}
			//커서 하나 옆이 첫 값이라면
			if (passWordCursor == passWord.end()) {
				//패스
				continue;
			}
			passWordCursor++;

		}
		//그냥 문자 입력시
		else {
			//passWord에 넣어주기
			passWord.insert(passWordCursor,testCases[index][i]);
			
		}
	}
	//출력하기
	for (auto iter = passWord.begin(); iter != passWord.end(); ++iter) {
		cout << *iter;
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		solvePassword(i);
		cout << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	solution();
}

