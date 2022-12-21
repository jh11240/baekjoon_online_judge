///////////////////////////////////////////////////////map<char,int>를 이용한 풀이

// #include<iostream>
// #include<map>

// using namespace std;

// string nums[11];
// int N=0,maxAns=0;
// //중복 허용 안하는 map으로 선언
// map<char, int> digitNum;
// //숫자를 사용했는지
// bool used[10];

// void Input() {
// 	cin >> N;
// 	for (int i = 0; i < N; i++) {
// 		cin >> nums[i];
// 		//각 알파벳값 초기화
// 		for(char e: nums[i])
// 			//map에 -1로 넣어주기
// 			digitNum.insert({e,-1});
// 	}
	
// }

// void Backtracking(map<char, int>::iterator iter) {
// 	//각 백트래킹의 끝단계에서
// 	if (iter==digitNum.end()) {
// 		//각 재귀의 끝단계에서의 단어의 합
// 		int tmpSum = 0;
// 		//각 단어마다 
// 		for (int i = 0; i < N; i++) {
// 			int tmp = 0;
// 			//i번째 단어의 각 알파벳 e에 대해  
// 			for (char e : nums[i]) {
// 				//알파벳 e에 매핑된 숫자를 통해 단어를 숫자로 변경해준 후 더해준다.
// 				tmp= tmp*10+digitNum[e];
// 			}
// 			//각 단어를 수로 변경한 값인 tmp를 총합 tmpSum에 더해줌
// 			tmpSum += tmp;
// 		}
// 		//최대치의 답 갱신해줌
// 		maxAns = maxAns > tmpSum ? maxAns : tmpSum;
// 		return;
// 	}

// 	for (int i = 0; i <= 9; i++) {
// 		//i를 이미 다른 알파벳에 할당한 상황이라면 continue
// 		if (used[i]) continue;
// 		used[i] = true;
// 		//현재값 변경해줌.
// 		digitNum[iter->first] = i;
// 		Backtracking(++iter);
// 		//백트래킹 끝나면 iterator와 used배열 다시 초기화
// 		iter--;
// 		used[i] = false;
// 	}
// }

// void Solution() {
// 	if (digitNum.size() == 1) {
// 		digitNum[nums[0][0]] = 9;
// 		//각 재귀의 끝단계에서의 단어의 합
// 		int tmpSum = 0;
// 		//각 단어마다 
// 		for (int i = 0; i < N; i++) {
// 			int tmp = 0;
// 			for (char e : nums[i]) {
// 				//현재 각 문자에 해당된 숫자를 통해 단어를 숫자로 변경해준 후 더해준다.
// 				tmp = tmp * 10 + digitNum[e];
// 			}
// 			tmpSum += tmp;
// 		}
// 		cout << tmpSum;
// 		return;
// 	}
// 	Backtracking(digitNum.begin());
// 	cout << maxAns;
// }

// int main() {
// 	Input();
// 	Solution();
// }

///////////////////////////////////////////////////// map의 시간이 느려서 배열을 이용한 풀이
#include<iostream>
#include<map>

using namespace std;

string nums[11];
int N=0,alphabetAmount=0,maxAns=0;
int digitNumArr[26];
//숫자를 사용했는지
bool used[10];

void Input() {
	cin >> N;
	//알파벳 배열에 미리 -1값으로 넣어주기
	fill(digitNumArr, digitNumArr + 26, -1);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		for (char e : nums[i]) {
			//단어에 포함된 알파벳은 0을 넣어주기
			digitNumArr[e - 'A'] = 0;
		}
	}

}

//0부터 25까지 알파벳 전체 백트래킹
void Backtracking(int length) {
	//각 백트래킹의 끝단계에서
	if (length==26) {
		//각 재귀의 끝단계에서의 단어의 합
		int tmpSum = 0;
		//각 단어마다 
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (char e : nums[i]) {
				//현재 각 문자에 해당된 숫자를 통해 단어를 숫자로 변경해준 후 더해준다.
				tmp= tmp*10+digitNumArr[e-'A'];
			}
			tmpSum += tmp;
		}
		//최대치의 답 갱신해줌
		maxAns = maxAns > tmpSum ? maxAns : tmpSum;
		return;
	}
	//입력값에 포함되어있지 않은 알파벳이면
	if (digitNumArr[length] == -1) {
		//포함된값까지 증가시켜줌
		while (digitNumArr[length] == -1) {
			length++;
			//만약 이 부분에서 26넘어가면 오류출력하므로 여기서도 26인지 체크해줘야함
			if (length == 26) {
				//각 재귀의 끝단계에서의 단어의 합
				int tmpSum = 0;
				//각 단어마다 
				for (int i = 0; i < N; i++) {
					int tmp = 0;
					for (char e : nums[i]) {
						//현재 각 문자에 해당된 숫자를 통해 단어를 숫자로 변경해준 후 더해준다.
						tmp = tmp * 10 + digitNumArr[e - 'A'];
					}
					tmpSum += tmp;
				}
				//최대치의 답 갱신해줌
				maxAns = maxAns > tmpSum ? maxAns : tmpSum;
				return;
			}
		}
	}

	for (int i = 9; i >=0; i--) {
		if (used[i]) continue;
		used[i] = true;
		//현재length번째 알파벳에 해당하는 숫자 변경해줌.
		digitNumArr[length] = i;
		//
		Backtracking(length + 1);
		used[i] = false;
	}
}

void Solution() {
	Backtracking(0);
	cout << maxAns;
}

int main() {
	Input();
	Solution();
}