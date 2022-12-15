#include<iostream>
#include<vector>
//for string.compare()
#include<string>

using namespace std;
int N=0;
vector<char> num;
bool didPrinted = false;

void Input() {
	cin >> N;
}

/// <summary>
/// N이 좋은 수열인지 판단하는 함수
/// </summary>
/// <param name="판단할 숫자 (N)"></param>
/// <param name="어디부터 판단할건지 (offset)"></param>
/// <returns>N이 좋은 수열이면 true, 나쁜 수열이면 false </returns>
bool isGoodNum(vector<char>& num,int offset) {
	if (offset == N) return true;
	for (int i = 1; i <= N; i++) {
		//인접수열에서 앞수열, 뒷수열
		string front = "", back = "";
		if ((N-offset) < i*2) break;
		for (int j = offset; j < offset + i; j++) {
			front += num[j];
		}
		for (int j = offset + i; j < offset + 2 * i; j++) {
			back += num[j];
		}
		if (!front.compare(back)) return false;
	}
	if (!isGoodNum(num, offset + 1)) return false;
	//반복문빠져나오면 true
	return true;
}


void MakeNum(vector<char>& totNum,int length) {

	if (length == N) {
		if (isGoodNum(totNum, 0)) {
			for (auto iter = totNum.begin(); iter != totNum.end(); ++iter) {
				char ans = *iter;
				cout << ans;
			}
			didPrinted = true;
			return;
		}
		else 
			return;
	}
	for (int i = 1; i <= 3; i++) {
		totNum.push_back(i);
		MakeNum(totNum, length + 1);
		if (didPrinted) return;
		totNum.pop_back();
	}


}

void Solution() {
	MakeNum(num, 0);

}

int main() {
	Input();
	Solution();
}