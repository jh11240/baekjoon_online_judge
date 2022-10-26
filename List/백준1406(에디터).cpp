#include<iostream>
#include<list>
#include<vector>

using namespace std;

//입력 문자열
list<char> editor;
//명령어 갯수
int M;
//명령어 문자열
vector <char> inputArr;
//입력문자열 커서
list<char>::iterator Cursor;

void input() {
	//각각 L,P,B정하는 변수, P 다음에 들어올 변수
	char tmp = ' ', tmpXy = ' ';
	//처음에 입력받을 문자열
	string inputStr = "";
	cin >> inputStr;
	//입력받은 문자열 editor리스트에 넣어줌
	for (int i = 0; i < inputStr.length(); i++) {
		editor.push_back(inputStr[i]);
	}
	cin >> M;
	//inputArr에 L,P,B 함수 넣는과정
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		inputArr.push_back(tmp);
		//P라면 그다음 원소 넣어줌
		if (tmp == 'P') {
			cin >> tmpXy;
			inputArr.push_back(tmpXy);
		}
	}
	//커서 
	Cursor=editor.end();
}

void solution() {
	//inputArr.size()가 아니라 그냥 M으로 했더니 P들어왔을때 i++을 해줘서 처리하는 과정에서 i를 소모해 연산이 씹힌다. 
	for (int i = 0; i < inputArr.size(); i++) {
		if (inputArr[i] == 'L') {
			//맨앞이면 무시
			if (Cursor == editor.begin()) continue;
			else Cursor--;
		}
		else if (inputArr[i] =='D') {
			//맨뒤면 무시
			if (Cursor == editor.end()) {
				continue;
			}
			else Cursor++;
		}
		else if (inputArr[i] == 'B') {
			if (Cursor == editor.begin()) continue;
			else
			{
				//editor.erase하면 들어간 iterator위치가 자동으로 바뀌는거로생각했었는데 
				//다시 찾아보니 지우고 다음 iterator를 반환하는거였다.
				Cursor=editor.erase(--Cursor);
			}
		}
		else {
			//P 다음 값 찾기위해
			i++;
			editor.insert(Cursor,inputArr[i]);
			
			}
	}
	for (auto iter = editor.begin(); iter != editor.end(); ++iter) {
		cout << *iter;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	solution();
}