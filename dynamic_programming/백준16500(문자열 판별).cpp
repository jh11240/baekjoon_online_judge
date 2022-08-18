//#include<iostream>	
//#include<vector>
//#include<string.h>
//#include<memory.h>
//
////처음에 시도방법은 cursor의 위치에서 부터 temp string형변수에 다음 string을 넣어준 후 S의 커서위치부터 temp변수 길이만큼 할당한 후 비교하는 방법인데
////중간에 temp변수가 s보다 커버리게되면 nullreference라 오류걸린다.
////다음 반례 s가 aab이고 a, ab가 들어오면 a를처리후 a가 맞으므로 a를 또 처리함 처리하자
////시간초과 남
//using namespace std;
//const int MAX = 100;
//
//vector<string> inputArr;
//string S;
//int amount = 0,ans=2;
//
//void input() {
//	string temp=" ";
//	cin >> S;
//	cin >> amount;
//
//	for (int i = 0; i < amount; i++) {
//		cin >> temp;
//		inputArr.push_back(temp);
//	}
//}
//
////S의 n-1번째 문자열까지 채워진 상태, s의 몇번째 문자부터 시작하는지 커서값
//void solution(int n,int cursor) {
//	if (ans == 1) return;
//	bool isThereAnswer = false;
//	
//	//n번째 문자열
//	string temp = "";
//	if (cursor==S.length()) {
//		ans = 1;
//		return;
//	}
//	else if (cursor > S.length()) {
//		ans = 0;
//		return;
//	}
//
//	for (int i = 0; i < amount; i++) {
//		if (ans == 1) return;
//		//초기화
//		temp = "";
//		for (int j = 0; j < inputArr[i].length(); j++)
//		{
//			if(cursor+j<S.length())
//			temp += S[cursor + j];
//		}
//		//만약 문자열중에 같은게 있을 때
//		if (!strcmp(temp.c_str(), inputArr[i].c_str())) {
//			isThereAnswer = true;
//			solution(n + 1, cursor + inputArr[i].length());
//			if (ans == 1) return;
//		}
//	}
//		//문자열중에 같은게 없을때는 0반환
//	if (ans!=1 && !isThereAnswer)
//		ans = 0;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	input();
//	solution(0,0);
//	cout << ans;
//}

#include<iostream>
#include<memory.h>

using namespace std;

//L이 S의 길이, 갯수 amount , dp배열
int L, amount, dp[101];
//S문자열, 입력문자열 받는 배열
string S,inputArr[101];

void input() {
	cin >> S >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> inputArr[i];
	}
	L = S.length();
	//dp -1로초기화
	memset(dp, -1, sizeof(dp));
}

//n번째 문자까지 매칭 시켰을 때 남은 문자들도 맞출 수 있는 지 bool형 반환 하는 함수
bool word(int n) {
	int& ret = dp[n];
	if (ret != -1) return ret;
	if (n == L) return ret = 1;

	ret = 0;

	for (int i = 0; i < amount; i++) {
		//S의 남은 길이보다 문자열값이 더 길면 패스해야함
		if (L < n + inputArr[i].length()) continue;
		//각 문자열과 S 비교했을때 같으면 true로 바뀌는 bool형 변수
		bool flag = true;
		//string의 []연산자를 써써 각 문자를 비교 이방식으로 하면 cursor가 필요없음
		for (int j = 0; j < inputArr[i].length(); j++) {
			if (S[n + j] != inputArr[i][j]) flag = false;
		}

		//|=을 이용해 만약 재귀중 return값이 1이 나온다면 ret= 1 아니면 0
		if (flag) ret |= word(n + inputArr[i].length());
		
	}
	return ret;


}

int main() {
	input();
	bool ans = word(0);
	cout << ans;
}