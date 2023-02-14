/////////////////////////////////////////////////////// using 2 set

#include<iostream>
#include<unordered_set>

using namespace std;
unordered_set <int> groupA;
unordered_set<int> groupB;
int groupASize,groupBsize;

void Input() {
	int inputSetElem=0;
	cin >> groupASize>>groupBsize;
    //A 원소들 Set에 넣어줌
	for (int i = 0; i < groupASize; i++) {
		cin >> inputSetElem;
		groupA.insert(inputSetElem);
	}
    //B원소들 set에 넣어줌
	for (int i = 0; i < groupBsize; i++) {
		cin >> inputSetElem;
		groupB.insert(inputSetElem);
	}
}

void Solution() {
	int Ans = 0;
    //A의 원소중 B와 겹치는거 탐색
	for (int elem : groupA) {
		if (groupB.find(elem) == groupB.end()) {
			Ans++;
		}
	}
    //B의 원소 중 A와 겹치는거 탐색
	for (int elem : groupB) {
		if (groupA.find(elem) == groupA.end()) {
			Ans++;
		}
	}
	cout << Ans;
}

int main(){
	Input();
	Solution();
}

////////////////////////////////////////////////////// using 1 set
#include<iostream>
#include<unordered_set>

using namespace std;
unordered_set <int> groupA;
int groupASize,groupBSize,commonElemsAmount;

void Input() {
	int inputSetElem=0;
	cin >> groupASize>>groupBSize;
	//그룹 A값을 다 groupA에 넣고
	for (int i = 0; i < groupASize; i++) {
		cin >> inputSetElem;
		groupA.insert(inputSetElem);
	}
	//B의 원소들을 그룹A에서 탐색후 공통원소라면 commonElemsAmount값 증가
	for (int i = 0; i < groupBSize; i++) {
		cin >> inputSetElem;
		if (groupA.find(inputSetElem) != groupA.end()) {
			commonElemsAmount++;
		}
	}

}

void Solution() {
	//총 사이즈에서 공통값 2배 빼면 답
	int Ans = groupASize+groupBSize-2 * commonElemsAmount;
	cout << Ans;
}

int main(){
	Input();
	Solution();
}