#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int N;
string inputStr;
int inputArr[27];
vector<char> inputStrS;
stack<double> ans;

void input() {
	cin >> N>>inputStr;
	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
	}
	//inputStr문자열을 char형으로 하나하나 뜯어봄
	for (int i = 0; i < inputStr.length(); i++) {
		//사칙연산 기호가 있다면
		if (inputStr[i]== '+' || inputStr[i] == '-' || inputStr[i] == '*' || inputStr[i] == '/')
		{
			inputStrS.push_back(inputStr[i]);
		}
		//알파벳이라면 'A'값을 빼준후 int형으로 형변환하여 넣어줌.
		else {
			inputStrS.push_back((int)(inputStr[i]-'A'));
		}
			
	}
}
//소수점 둘째자리 방법은 double형으로 선언해서 100곱한채로 계산한후 100 나눠버리면된다
void solution() {
	double tmp1 = 0, tmp2 = 0;
	for (int i = 0; i < inputStrS.size(); i++) {

		//연산기호라면 마지막 두 숫자 빼서 연산 후 결과 값 다시 넣음
		if (inputStrS[i] == '+')
		{
			tmp1 = ans.top();
			ans.pop();
			tmp2 = ans.top();
			ans.pop();
			ans.push(tmp2 + tmp1);
		}
		else if (inputStrS[i] == '-')
		{
			tmp1 = ans.top();
			ans.pop();
			tmp2 = ans.top();
			ans.pop();
			ans.push(tmp2 - tmp1);
		}
		else if (inputStrS[i] == '/')
		{
			tmp1 = ans.top();
			ans.pop();
			tmp2 = ans.top();
			ans.pop();
			ans.push(tmp2/tmp1);
		}
		else if (inputStrS[i] == '*')
		{
			tmp1 = ans.top();
			ans.pop();
			tmp2 = ans.top();
			ans.pop();
			ans.push(tmp1*tmp2);
		}

		//값이 숫자라면 스택에 푸시
		else {
			ans.push(inputArr[inputStrS[i]]);
		}

	}
	//소수점 몇번째 자리인지 고정시킨 후
	cout<<fixed;
	//소수점 밑 둘째자리까지 표시
	cout.precision(2);
	//반복문 빠져나왔다면 결과값만 남아있을 것이므로 
	cout << ans.top();
}

int main() {
	input();
	solution();
}

