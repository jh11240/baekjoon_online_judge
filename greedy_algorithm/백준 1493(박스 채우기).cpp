#include<iostream>															//3
																			//일단 2d박스에 채운다고 가정하면 큰거 하나 넣고, 이제 나머지 박스를 넣을때 
																			//고려하는 부분은 채워진 박스 변* 총 크기 - 박스 변 의 크기를 가진 사각형 두개랑,

																			//3d로 채운다하면 직육면체 4개의 크기가 나옴 정사각형이므로 이 4 직육면체 안에만 들어감
																			//중간에 걸치긴 안됨.
																			//그래서 재귀함수로 일단 채울수 있는만큼 채우고 나머지 네개의 직육면체에 다음 큐브 채우기를 만들어봤으나
																			//큐브가 무한정하지않아서 직육면체가 네개 이상 나올수 있어서 접었다.
																			
																			//but, 채울수있는만큼 채우는방식이 아닌 하나씩 넣는걸 반복하면 된다.
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<pair<int,int>> v;
int ans = 0,fail=0;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

void input(int& length,int& width, int& height) {			//입력값 받는 함수
	int cnt=0,cube=0,amountCube=0;
	cin >> length >> width >> height;
	cin >> amountCube;
	for (int i = 0; i < amountCube; i++) {
		cin >> cnt >> cube;
		v.push_back(make_pair(pow(2,cnt),cube));
	}
	sort(v.begin(), v.end(),comp);
}

void solution(int length, int width, int height,int idx) {	//재귀함수 length, width, height, 몇번째 큐브인지
																//

	if (length == 0 || width == 0 || height == 0)
		return;
	for (int i = idx; i < v.size(); i++){												//또초보적인 실수함 i< queue.size()처럼 변하는 수 넣으면 안되지

		if (v[i].second != 0 && (length - v[i].first)>=0 && (width - v[i].first)>=0 && (height - v[i].first)>=0) {
			v[i].second--;																//i번째 큐브 갯수 채워넣었으므로 감소
			ans++;																		//답++
			solution(length , width, height-v[i].first,i);
			solution(length, width-v[i].first, v[i].first,i);
			solution(length - v[i].first, v[i].first, v[i].first,i);
			return;
		}
	}
	fail = 1;																			//만약 제대로 큐브가 들어왔다면 무조건 세모서리중 하나는 0이어야하므로
																						//빠져나왔다는것은 -1 출력
}
void print() {
	if (fail) cout << -1;
	else
		cout << ans;
}

int main() {
	int length=0, width = 0 , height = 0;
	input(length,width,height);
	solution(length, width, height,0);
	print();
}


//#include<iostream>														//두번째 방법 그냥 타겟 사각형에 몇개의 큐브가 들어가는지 
//																			//갯수만 고려하는 방법
//#include<algorithm>
//
//using namespace std;
//
//int a[20];
//
//int main() {
//	long long w = 0;
//	int t, length, width, height, cubeType = 0;
//	int cubeSize, cubeAmount, ans = 0;
//	cin >> length >> width >> height >> cubeType;
//	for (int i = 0; i < cubeType; i++) {
//		cin >> cubeSize >> cubeAmount;
//		a[cubeSize] += cubeAmount;
//	}
//	for (int i = 19; i >= 0; i--) {	//cubesize가 예를들어 1 2 이렇게 숫자가 들어오면 w=0이고 2큐브가 들어갈 갯수를 저장, 
//									//그다음 1큐브일 때 생각하면 2가 차있는 부분은 1로 치환해보면 (2*2*2)인 8을 곱해야 2짜리가 차지하는 갯수가 나온다, 
//									//그래서 그 두개를 빼면 2가 차지한 부분을 제외한 부분에 1로 가득채운 갯수가 나온다 이값과 1큐브갯수를 비교
//		w <<= 3;					//이미 공간 차지한 부분 8배하기	()
//		t = min((long long)a[i], (long long)(length >> i) * (width >> i) * (height >> i) - w);		//i길이의 큐브를 다쓴것과 , 
//																									//2^i길이의 큐브가 타겟큐브에 들어갈수 있는 갯수 - 이미 공간 차지한 부분
//		w += t;						//w에 새롭게 공간 차지한부분 넣기
//		ans += t;					//총 갯수
//	}
//	if (w == (long long)length * width * height)
//		cout << ans;
//	else
//		cout << -1;
//
//}

