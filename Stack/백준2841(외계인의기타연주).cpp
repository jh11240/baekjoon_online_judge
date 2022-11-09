// #include<iostream>
// #include<stack>

// using namespace std;
// int N = 0,P=0,Ans=0;
// stack<int> First;
// stack<int> Second;
// stack<int> Third;
// stack<int> Fourth;
// stack<int> Fifth;
// stack<int> Sixth;




// void FirstString(int fret) {
// 	if (First.empty()) {
// 		First.push(fret);
// 		Ans++;
// 	}
// 	else {
// 		//1번 노래 스택이 비어있지않고, 프렛 스택의 top이 이번에 누를 프렛보다 작을때까지 pop
// 		while (!First.empty() && First.top()>fret) {
// 			First.pop();
// 			//손가락 떼었으므로 답 ++
// 			Ans++;

// 		}
// 		//만약 같은 프렛이 있다면 스택 변동 x, 손가락 이동횟수 변동x
// 		if (!First.empty() && fret == First.top()) {
// 			return;
// 		}
// 		//스택이 비었거나 스택의 top이 작다면 이번값 push
// 		else {
// 			First.push(fret);
// 			Ans++;
// 			return;
// 		}
// 	}
// }
// void SecondString(int fret) {
// 	if (Second.empty()) {
// 		Second.push(fret);
// 		Ans++;
// 	}
// 	else {
// 		//2번 노래 스택이 비어있지않고, 프렛 스택의 top이 이번에 누를 프렛보다 작을때까지 pop
// 		while (!Second.empty() && Second.top() > fret) {
// 			Second.pop();
// 			//손가락 떼었으므로 답 ++
// 			Ans++;

// 		}
// 		//만약 같은 프렛이 있다면 스택 변동 x, 손가락 이동횟수 변동x
// 		if (!Second.empty() && fret == Second.top()) {
// 			return;
// 		}
// 		//스택이 비었거나 스택의 top이 작다면 이번값 push
// 		else {
// 			Second.push(fret);
// 			Ans++;
// 			return;
// 		}
// 	}
// }
// void ThirdString(int fret) {
// 	if (Third.empty()) {
// 		Third.push(fret);
// 		Ans++;
// 	}
// 	else {
// 		//3번 노래 스택이 비어있지않고, 프렛 스택의 top이 이번에 누를 프렛보다 작을때까지 pop
// 		while (!Third.empty() && Third.top() > fret) {
// 			Third.pop();
// 			//손가락 떼었으므로 답 ++
// 			Ans++;

// 		}
// 		//만약 같은 프렛이 있다면 스택 변동 x, 손가락 이동횟수 변동x
// 		if (!Third.empty() && fret == Third.top()) {
// 			return;
// 		}
// 		//스택이 비었거나 스택의 top이 작다면 이번값 push
// 		else {
// 			Third.push(fret);
// 			Ans++;
// 			return;
// 		}
// 	}
// }
// void FourthString(int fret) {
// 	if (Fourth.empty()) {
// 		Fourth.push(fret);
// 		Ans++;
// 	}
// 	else {
// 		//4번 노래 스택이 비어있지않고, 프렛 스택의 top이 이번에 누를 프렛보다 작을때까지 pop
// 		while (!Fourth.empty() && Fourth.top() > fret) {
// 			Fourth.pop();
// 			//손가락 떼었으므로 답 ++
// 			Ans++;

// 		}
// 		//만약 같은 프렛이 있다면 스택 변동 x, 손가락 이동횟수 변동x
// 		if (!Fourth.empty() && fret == Fourth.top()) {
// 			return;
// 		}
// 		//스택이 비었거나 스택의 top이 작다면 이번값 push
// 		else {
// 			Fourth.push(fret);
// 			Ans++;
// 			return;
// 		}
// 	}
// }
// void FifthString(int fret) {
// 	if (Fifth.empty()) {
// 		Fifth.push(fret);
// 		Ans++;
// 	}
// 	else {
// 		//5번 노래 스택이 비어있지않고, 프렛 스택의 top이 이번에 누를 프렛보다 작을때까지 pop
// 		while (!Fifth.empty() && Fifth.top() > fret) {
// 			Fifth.pop();
// 			//손가락 떼었으므로 답 ++
// 			Ans++;

// 		}
// 		//만약 같은 프렛이 있다면 스택 변동 x, 손가락 이동횟수 변동x
// 		if (!Fifth.empty() && fret == Fifth.top()) {
// 			return;
// 		}
// 		//스택이 비었거나 스택의 top이 작다면 이번값 push
// 		else {
// 			Fifth.push(fret);
// 			Ans++;
// 			return;
// 		}

// 	}
// }
// void SixthString(int fret) {
// 	if (Sixth.empty()) {
// 		Sixth.push(fret);
// 		Ans++;

// 	}
// 	else {
// 		//6번 노래 스택이 비어있지않고, 프렛 스택의 top이 이번에 누를 프렛보다 작을때까지 pop
// 		while (!Sixth.empty() && Sixth.top() > fret) {
// 			Sixth.pop();
// 			//손가락 떼었으므로 답 ++
// 			Ans++;

// 		}
// 		//만약 같은 프렛이 있다면 스택 변동 x, 손가락 이동횟수 변동x
// 		if (!Sixth.empty() && fret == Sixth.top()) {
// 			return;
// 		}
// 		//스택이 비었거나 스택의 top이 작다면 이번값 push
// 		else {
// 			Sixth.push(fret);
// 			Ans++;
// 			return;
// 		}
// 	}
// }


// void input() {
// 	int string = 0, fret = 0;
// 	cin >> N >> P;
// 	for (int i = 0; i < N; i++) {
// 		cin >> string >> fret;
// 		switch (string) {
// 		case 1:
// 			FirstString(fret);
// 			break;
// 		case 2:
// 			SecondString(fret);
// 			break;
// 		case 3:
// 			ThirdString(fret);
// 			break;
// 		case 4:
// 			FourthString(fret);
// 			break;
// 		case 5:
// 			FifthString(fret);
// 			break;
// 		case 6:
// 			SixthString(fret);
// 			break;

// 		}
// 	}
// 	cout << Ans;
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(NULL);
// 	input();
// }



////////////////////////////////////////////////////////////////
// 스택포인터를 이용해 함수 하나로만 구현한 방법
#include<iostream>
#include<stack>

using namespace std;
int N = 0,P=0,Ans=0;
stack<int> First;
stack<int> Second;
stack<int> Third;
stack<int> Fourth;
stack<int> Fifth;
stack<int> Sixth;
stack<int>* S;

void String(int string, int fret) {
	switch (string) {
	case 1:
		S = &First;
		break;
	case 2:
		S = &Second;
		break;
	case 3:
		S = &Third;
		break;
	case 4:
		S = &Fourth;
		break;
	case 5:
		S = &Fifth;
		break;
	case 6:
		S = &Sixth;
		break;
	}
	if (S->empty()) {
		S->push(fret);
		Ans++;

	}
	else {
		//6번 노래 스택이 비어있지않고, 프렛 스택의 top이 이번에 누를 프렛보다 작을때까지 pop
		while (!S->empty() && S->top() > fret) {
			S->pop();
			//손가락 떼었으므로 답 ++
			Ans++;

		}
		//만약 같은 프렛이 있다면 스택 변동 x, 손가락 이동횟수 변동x
		if (!S->empty() && fret == S->top()) {
			return;
		}
		//스택이 비었거나 스택의 top이 작다면 이번값 push
		else {
			S->push(fret);
			Ans++;
			return;
		}
	}
	
}


void input() {
	int string = 0, fret = 0;
	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		cin >> string >> fret;
		String(string, fret);
	}
	cout << Ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	input();
}