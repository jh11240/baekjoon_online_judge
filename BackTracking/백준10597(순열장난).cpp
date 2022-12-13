#include<iostream>
#include<vector>
using namespace std;

bool visited[51];
//입력 문자열 
string inputArr="";
int maxNum = 0;
bool didPrinted = false;
void Input() {
	cin >> inputArr;
}

//끊어서 분리한 숫자를 저장할 벡터, 어디까지 끊었는지 offset
void Backtracking(vector<int>& v,int offset) {
	//끝까지 분리했다면 
	if (offset == inputArr.length()) {
		//만약 1부터 제일큰 숫자까지 비어있는 값이있다면 return;
		for (int i = 1; i <= maxNum; i++) {
			if (!visited[i]) return;
		}
		//다 차있다면 다 출력
		for (auto iter = v.begin(); iter != v.end(); ++iter) {
			cout << *iter << " ";
		}
		//출력시 didPrinted를 true로 
		didPrinted = true;
		return;
	}
	//offset부터 숫자하나 따오기
	int num = inputArr[offset] - '0';

	//0인 수는 없으므로 다시 전단계로 돌아가서 두개를 넣어야함
	if (num == 0) return;

	//숫자가 방문한적있따고  return 처리시 숫자 두개 따오는 과정을 스킵함 
	//해당 숫자가 방문한적 없는 숫자라면 
	if (!visited[num] && num!=0) 
	{
		//백트래킹함수에서 돌아왔을 때를 대비해 maxnum갱신하기전값 저장
		int tmpMaxNum = maxNum;
		//제일 큰수 저장
		maxNum = maxNum > num ? maxNum : num;
		//방문 처리
		visited[num] = true;
		//v에 넣어주기
		v.push_back(num);
		//백트래킹함수 다음 단계 실행
		Backtracking(v, offset + 1);
		//끝내고 돌아왔을때 출력한 상태라면 return
		if (didPrinted) return;
		//제일 큰 숫자 다시 되돌리기
		maxNum = tmpMaxNum;
		//num방문 취소 
		visited[num] = false;
		//들어갔던 num값 뺌
		v.pop_back();
	}
    //이제 두글자따야되는데 문자열원소가 2개 안 남았다면 return
	if (offset == inputArr.length() - 1) return;


	//두글자 따기
	int twoDigitNum = (inputArr[offset++] - '0') * 10 + inputArr[offset] - '0';

	//두자릿수가 50초과하거나한자리수와 두자리수 둘다 방문했다면 return해줌
	if (twoDigitNum>50 || visited[twoDigitNum]) return;

	int tmpMaxNum = maxNum;	
	//제일 큰수 저장
	maxNum = maxNum > twoDigitNum ? maxNum : twoDigitNum;
	//방문 처리
	visited[twoDigitNum] = true;
	//v에 넣어주기
	v.push_back(twoDigitNum);
	//백트래킹함수 다음 단계 실행
	Backtracking(v, offset + 1);
	//끝내고 돌아왔을때 출력한 상태라면 return
	if (didPrinted) return;
	//제일 큰 숫자 다시 되돌리기
	maxNum = tmpMaxNum;
	//num방문 취소 
	visited[twoDigitNum] = false;
	//들어갔던 num값 뺌
	v.pop_back();
}

void Solution() {
	vector<int> v;
	Backtracking(v,0);
}

int main() {
	Input();
	Solution();
}