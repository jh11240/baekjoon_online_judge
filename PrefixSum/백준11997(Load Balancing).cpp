#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;
//set을 통해 처음 좌표들을 중복없이 오름차순으로 정렬하기
set<int> xSet, ySet;
//set에 들어온 좌표들을 HashMap을 통해서 좌표들을 순서대로 압축한다.
unordered_map<int, int> xHash, yHash;
//압축 전 100만까지의 좌표들
int beforeCompX[1001];
int beforeCompY[1001];
//압축후 좌표를 저장할 배열
int afterComp[1001][1001];
//0,0 부터 (i,j)좌표까지 
int howManyCows[1001][1001];
int minCowSum = 1'000'001;

int main() {
	int N=0, cowX=0, cowY=0,X[1001],Y[1001],xCnt=0,yCnt=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		cin >> Y[i];
		//set에 좌표들을 넣어 중복을 제거한후 오름차순 정렬
		xSet.insert(X[i]);
		ySet.insert(Y[i]);
	}
	//hashmap에 set의 좌표들을 넣어 0뷰터 순서대로 압축시켜준다. 
	for (int i : xSet) {
		xHash[i] = xCnt++;
	}
	for (int i : ySet) {
		yHash[i] = yCnt++;
	}
	//hashmap을 통해 압축을 한 좌표들을 afterComp에 대입시킨후 소가 있다는 표시로 ++을 해줌
	for (int i = 0; i < N; i++) {
		afterComp[xHash[X[i]]][yHash[Y[i]]]++;
	}
	//모든 압축 후의 좌표에 대해 누적 소 갯수값을 다 저장  
	for (int i = 0; i < xCnt; i++) {
		for (int j = 0; j < yCnt; j++) {
			howManyCows[i + 1][j + 1] = howManyCows[i + 1][j] + howManyCows[i][j + 1] - howManyCows[i][j] + afterComp[i][j];
		}
	}

	//0,0부터 xCnt-1,yCnt-1값까지 모든 좌표에 가로 세로 선 두개를 그어서 각 사분면의 제일큰 소의 갯수를 비교해본다.
	for (int i = 0; i <= xCnt; i++) {
		for (int j = 0; j <= yCnt; j++) {
			int tmpMaxPartialCowSum = 1'000'001;
			tmpMaxPartialCowSum = max(howManyCows[i][j],howManyCows[xCnt][j]-howManyCows[i][j]);
			tmpMaxPartialCowSum = max(tmpMaxPartialCowSum, howManyCows[i][yCnt]-howManyCows[i][j]);
			tmpMaxPartialCowSum = max(tmpMaxPartialCowSum, 
				howManyCows[xCnt][yCnt] - howManyCows[xCnt][j] - howManyCows[i][yCnt] + howManyCows[i][j]);
			//위의 식을 거쳐 tmpMaxPartialCowSum에 i,j일때의 각 사분면의 제일 큰 소의 갯수가 저장됨.
			//minCowSum을 갱신
			minCowSum = min(tmpMaxPartialCowSum,minCowSum);
		}
	}
	cout << minCowSum;
}