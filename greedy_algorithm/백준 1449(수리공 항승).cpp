//#include<iostream>            //처음에 내가 풀었던 방식
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<int> holeLocation;
//
//void input(int& holeAmount, int& tapeLength) {						//입력값 받는 함수
//	int holes=0;													
//	cin >> holeAmount >> tapeLength;
//	for (int i = 0; i < holeAmount; i++) {
//		cin >> holes;
//		holeLocation.push_back(holes);
//	}
//
//
//}
//
//void solution(int& holeAmount, int& tapeLength) {					//답 도출 함수
//	sort(holeLocation.begin(),holeLocation.end());					//구멍위치 정렬
//	int tapeEndPosition=holeLocation[0]+tapeLength-1, tapeCnt=1;	//tapeEndPoisition은 테이프가 끝나는 위치로 설정, 
//																	//구멍위치에서 테이프의 길이-1만큼 떨어진곳(한 구멍당 1의 길이이므로)
//	for (int i : holeLocation) {									//각 구멍위치에서
//		if (i > tapeEndPosition) {									//테이프의 마지막 위치보다 큰 구멍위치면
//			tapeEndPosition = i+tapeLength-1;						//tapeEndPosition을 그 위치에서 테이프길이-1만큼 떨어진곳으로 갱신
//			tapeCnt++;												//테이프 갯수++
//		}
//	}
//	cout << tapeCnt;
//}
//
//int main() {
//	int holeAmount = 0, tapeLength = 0;
//	input(holeAmount,tapeLength);
//	solution(holeAmount, tapeLength);
//}

//다른 방식
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> locations;

int main() {
	int N = 0, L = 0,input=0,lastHole=0,tapes=0;	//구멍갯수,테이프길이,입력값받을 임시변수,마지막구멍위치,테이프갯수
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> input;
		locations.push_back(input);

	}
	sort(locations.begin(), locations.end());		//구멍위치 정렬
	lastHole = locations[0];						//마지막 구멍위치 정해주고
	
	for (int i = 1; i < N; i++) {					//각 구멍위치에서
		if (L <= locations[i] - lastHole) {			//테이프길이가 해당 구멍위치-마지막 구멍보다 크거나 같을 때
			lastHole = locations[i];				//마지막 구멍위치는 해당 구멍위치로 정해주고 
			tapes++;								//테이프 ++
		}
	}
	cout << tapes+1;								//마지막 테이프갯수는 세어지지 않으므로
													//출처 https://beginnerdeveloper-lit.tistory.com/117
}