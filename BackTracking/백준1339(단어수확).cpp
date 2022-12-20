#include<iostream>
#include<map>

using namespace std;

string nums[11];
int N=0,maxAns=0;
//중복 허용 안하는 map으로 선언
map<char, int> digitNum;
//숫자를 사용했는지
bool used[10];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		//각 알파벳값 초기화
		for(char e: nums[i])
			//map에 -1로 넣어주기
			digitNum.insert({e,-1});
	}
	
}

void Backtracking(map<char, int>::iterator iter, int length) {
	//각 백트래킹의 끝단계에서
	if (iter==digitNum.end()) {
		//각 재귀의 끝단계에서의 단어의 합
		int tmpSum = 0;
		//각 단어마다 
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (char e : nums[i]) {
				//현재 각 문자에 해당된 숫자를 통해 단어를 숫자로 변경해준 후 더해준다.
				tmp= tmp*10+digitNum[e];
			}
			tmpSum += tmp;
		}
		//최대치의 답 갱신해줌
		maxAns = maxAns > tmpSum ? maxAns : tmpSum;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (used[i]) continue;
		used[i] = true;
		//현재값 변경해줌.
		digitNum[iter->first] = i;
		Backtracking(++iter, length + 1);
		iter--;
		used[i] = false;
	}
}

void Solution() {
	if (digitNum.size() == 1) {
		digitNum[nums[0][0]] = 9;
		//각 재귀의 끝단계에서의 단어의 합
		int tmpSum = 0;
		//각 단어마다 
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (char e : nums[i]) {
				//현재 각 문자에 해당된 숫자를 통해 단어를 숫자로 변경해준 후 더해준다.
				tmp = tmp * 10 + digitNum[e];
			}
			tmpSum += tmp;
		}
		cout << tmpSum;
		return;
	}
	Backtracking(digitNum.begin(), 0);
	cout << maxAns;
}

int main() {
	Input();
	Solution();
}