#include<iostream>
#include<set>
using  namespace std;
int N;
string inputStr;
int targetNum;
set<int> wrongNum;

bool CheckContainsWrongNum(int n) {
	int Mod = 0;
	if (n == 0) {
		if (wrongNum.find(0) != wrongNum.end()) {
			return true;
		}
		return false;
	}
	while (n) {
		Mod = n % 10;
		if (wrongNum.find(Mod) != wrongNum.end()) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int GetDigitCnt(int n) {
	int cnt=0;
	if (n == 0) return 1;
	while (n) {
		cnt++;
		n /= 10;
	}
	return cnt;
}

int main() {
	cin >> inputStr;
	cin >> N;
	int tmpWrongNum;
	int minDiff = 500'001;
	int minDiffNum = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmpWrongNum;
		wrongNum.insert(tmpWrongNum);
	}

	for (int i = 0; i < inputStr.length(); i++) {
		targetNum *= 10;
		targetNum += inputStr[i] - '0';
	}

	for (int i = 0; i < 1'000'001; i++) {
		if (CheckContainsWrongNum(i)) continue;
		if (minDiff > abs(i - targetNum)) {
			minDiff = abs(i - targetNum);
			minDiffNum = i;
		}
	}

	cout << min(minDiff + GetDigitCnt(minDiffNum), abs(targetNum - 100));
}