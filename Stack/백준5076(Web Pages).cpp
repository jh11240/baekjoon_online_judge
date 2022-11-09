#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool checkIfProperlyNested(string inputStr);
stack<string> s;

void input() {
	string inputStr;
	while (1) {
		////버퍼에 남아있는 엔터 제거
		//cin.ignore();
		getline(cin,inputStr);
		if (inputStr == "#") {
			return;
		}
		if (checkIfProperlyNested(inputStr)) cout << "legal" << '\n';
		else cout << "illegal" << '\n';

	}
}
/// <summary>
/// string형 매개변수인 inputStr의 태그가 적절한지 비교하는 함수
/// </summary>
/// <param name="inputStr"></param>
/// <returns>태그가 적절하다면 true , 적절하지 않다면 else</returns>
bool checkIfProperlyNested(string inputStr) {
	while (!s.empty()) {
		s.pop();
	}
	//문자열의 각 char형 원소마다 비교 실행
	for (int i = 0; i < inputStr.length(); i++) {
		string tmp = "";
		//원소가 <라면 태그 여는 값
		if (inputStr[i] == '<') {
			//태그 다음 값 조사
			i++;
			//<다음 값이 /라면
			if (inputStr[i] == '/') {
				i++;
				//> 값이 나올때까지
				while (inputStr[i] != '>') {
					//임시 string변수 tmp에 더해준다.
					tmp += inputStr[i++];
				}
				//반복문 끝났다면 tmp값에 < >사이에 해당하는 단어들어있다.
				//스택이 비어있다면 짝이 안맞으므로 false 리턴
				if (s.empty()) {
					return false;
				}
				//스택이 차있다면
				else {
					//스택의 top값이 tmp값과 같다면
					if (s.top() == tmp) {
						s.pop();
					}
					//일치하지 않다면 false리턴
					else {
						return false;
					}
				}
			}
			//< 다음에 /가 아니라 처음 여는 꺽쇠라면
			else {
				while (inputStr[i] != ' ' && inputStr[i] != '>') {
					tmp += inputStr[i++];
				}
				//빈칸이 있을 경우 
				if (inputStr[i] == ' ') {
					//다음칸이 /라면 패스
					if (inputStr[++i] == '/') {
						//>를 가리키도록 
						i++;
						continue;
					}
					//다음칸에 주소가 나온다면
					//닫는 꺽쇠나올때까지 i증가
					while (inputStr[i] != '>') {
						i++;
					}
				}
				//처음 여는 꺽쇠이므로 스택에 푸시
				s.push(tmp);
			}
		}
	}
	if (!s.empty()) return false;
	return true;
}
int main() {
	input();
}