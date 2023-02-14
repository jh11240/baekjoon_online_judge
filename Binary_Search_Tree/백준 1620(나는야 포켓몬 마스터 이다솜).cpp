#include<iostream>
#include<unordered_map>

using namespace std;
//string값을 key로 int를 value로
unordered_map<string, int> pocketmonsStrToInt;
//int값을 key로 string값을 value로
unordered_map<int, string> pocketmonsIntToStr;
void Input() {
	//포켓몬 마릿수, 질문 갯수
	int pocketmons=0, questions=0;
	//입력받을 값
	string inputPocketmonStr="";
	cin >> pocketmons >> questions;

	//포켓몬 이름을 입력받아 map에 (이름, 번호) 이어줌 
	for (int i = 1; i <= pocketmons; i++) {
		cin >> inputPocketmonStr;
		pocketmonsStrToInt[inputPocketmonStr] = i;
		pocketmonsIntToStr[i] = inputPocketmonStr;
	}
	
	for (int j = 0; j < questions; j++) {
		int inputPocketmonNum = 0;
		//string값으로 우선 질문을 입력 받고
		cin >> inputPocketmonStr;
		//포켓몬 번호가 입력값이라면 
		if (isdigit(inputPocketmonStr[0])) {
			//해당 번호를 string에서 int값으로 변환해서 inputPocketNum에 넣어줌
			for (int k = 0; k < inputPocketmonStr.length(); k++) {
				inputPocketmonNum= inputPocketmonNum * 10 + inputPocketmonStr[k]-'0';
			}
		}
		//만약 입력값이 숫자라면 0이아닐것이므로(문제 조건때문에) int값에 대응되는 str값출력
		if (inputPocketmonNum) cout << pocketmonsIntToStr[inputPocketmonNum]<<'\n';
		//입력값 문자라면 str값에 대응되는 int값 출력
		else cout << pocketmonsStrToInt[inputPocketmonStr]<<'\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}