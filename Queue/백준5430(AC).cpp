#include<iostream>
#include<deque>

using namespace std;

int T;
deque<int> q;
string cmd="", num="";


//커맨드에 D가 안나올수도있다
void printAnswer() {
	//초기화 안했다
	bool isDequeBack = true;
	int qNum=0;
	q.clear();
	//num에적힌 수배열 큐에 넣기
	for (int i = 0; i < num.length(); i++) {
		//[이나 ]이면 패스
		if (num[i] == '[' ) {
			continue;
		}
		//,가 나오면 지금까지의 수 큐에 푸시
		else if (num[i] == ','){
			q.push_back(qNum);
			qNum = 0;
		}
		else if (num[i] == ']') {
			//큐가 비었어도 R을 시행한다면 에러가 아니다.
			if (qNum == 0) continue;
			q.push_back(qNum);
			qNum = 0;
		}
		//숫자라면 백의자리나 천의 자리일수 있으므로, 
		else {
			qNum=qNum * 10 + (num[i] - '0');
		}
	}
	//명령 실행
	for (int i = 0; i < cmd.length(); i++) {
		//R이나올때마다 deque의 방향 전환
		if (cmd[i] == 'R') {
			isDequeBack = !isDequeBack;
		}
		else if (q.empty()) {
			cout << "error" << '\n';
			return;
		}
		//dequeBack이면 큐가 정방향 (0번원소가 첫번째 원소)
		else if(isDequeBack) {
			q.pop_front();
		}
		//dequeBack=false면 큐의 방향이 반대(0번원소가 마지막 원소)
		else {
			q.pop_back();
		}
	}
	if (q.empty()) {
		cout << "[" << "]" << '\n';
		return;
	}
	//답 출력 부분
	cout << "[";
	int size = q.size();
	//마지막 하나 전까지 쉼표 출력후
	for (int i = 0; i < size-1; i++) {
		if (isDequeBack) {
			cout << q.front() << ",";
			q.pop_front();
		}
		else {
			cout << q.back() << ",";
			q.pop_back();
		}
	}
	//마지막일때 수 출력하고 ] 출력
	if (isDequeBack) {
		cout << q.front() << "]" << '\n';
	}
	else {
		cout << q.back() << "]" << '\n';
	}
}

void input() {
	cin >> T;
	int tmp=0;
	for (int i = 0; i < T; i++) {
		cin >> cmd >> tmp>>num;
		printAnswer();
	}
}

int main() {
	input();
}