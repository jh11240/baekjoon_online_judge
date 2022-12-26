#include<iostream>

using namespace std;
string inputStr="";
//각 순서당 알파벳이 몇개씩 들어있는지 체크 
//510만*4 바이트정도-> 2백만 바이트 정도라 ㄱㄴ
int	alphabetsInEachQuery[200'001][27];

void Input() {
	int q=0,l=0,r=0,inputStrLen=0;
	char alphabet = 'a';
	cin >> inputStr;
	//반복문마다 계속 length함수 호출하는거 싫어서 미리 할당해놓음
	inputStrLen = inputStr.length();
	
	for (int i = 0; i < inputStrLen; i++) {
		for (int j = 0; j < 26; j++) {
			//alphabetsineachquery[i+1]은 i번째까지의 알파벳 갯수 합 
			alphabetsInEachQuery[i + 1][j] = alphabetsInEachQuery[i][j] + (j == inputStr[i] - 'a');

		}
	}
	cin >> q ;
	for (int i = 0; i < q; i++) {
		cin >> alphabet >> l >> r;
		cout << alphabetsInEachQuery[r + 1][alphabet - 'a'] - alphabetsInEachQuery[l][alphabet - 'a'] << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}