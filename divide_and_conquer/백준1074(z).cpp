//#include<iostream>						//3  첫번째 방법
//											//길이가 length일때 length사각형 몇개 지나왔는지 벡터에 저장하고 또 쪼개서 해당사각형을 네개로 나눴을때
//											// 그 점이 어느구역에 있는 지 체크해서 나중에 저장한 length* 갯수를 다 더해서 지나온 칸을 계산한다.
//											//하지만 해당 점을 구역을 네개로 쪼갰을때 몇,몇이라고 넘겨줘야할질 모르겟어서 막혔다.
//
//#include<vector>
//#include<math.h>
//using namespace std;
//
//vector<vector<int>> v;
//vector<int> temp;
//vector<int> cnt;					        //first에 length second에 해당 length사각형 몇개 지나왔는지 저장하려 햇으나 그냥 넓이 자체를 넣어주는거로 변경
//
//void input(int& amount,int& r,int& c)
//{
//	int tempInput=0;
//	cin >> amount;
//	for (int i = 0; i < amount; i++) {
//		temp.clear();
//		for (int j = 0; j < amount; j++) {
//			temp.push_back(i);
//		}
//		v.push_back(temp);
//	}
//	cin >> r >> c;
//
//
//}
//void solution(int r,int c,int length ) {
//	
//	if (length == 1) return;									//length가 0이면 return;
//
//	if (r < length / 2 && c < (length / 2)) {					//r,c가 1사분면
//		solution(r % (length / 2), c % (length / 2), length / 2);
//	}
//	else if (r<length / 2 && c >=(length / 2)) {					//r,c가 2사분면
//		cnt.push_back((length / 2) * (length / 2) * 1);			//해당 점이 2사분면에있다면 1사분면에 해당하는 넓이 cnt벡터에 넣어준다.
//		solution(r % (length / 2), c % (length / 2), length / 2);
//	}
//	else if (r >= length / 2 && c < (length / 2)) {				//r,c가 3사분면
//		cnt.push_back((length / 2) * (length / 2) * 2);			//해당 점이 3사분면에 있다면 1,2사분면에 해당하는 넓이 cnt벡터에 넣어준다
//		solution(r % (length / 2), c % (length / 2), length / 2);
//	}
//	else if (r >= length / 2 && c >= (length / 2)) {				//r,c가 4사분면
//		cnt.push_back((length / 2) * (length / 2) * 3);			//해당 점이 4사분면에 있다면 1,2,3사분면에 해당하는 넓이 cnt벡터에 넣어준다	
//		solution(r % (length / 2), c % (length / 2), length / 2);
//	}
//
//}
//void printAns() {
//	int ans = 0;
//	for (int elem : cnt) {
//		ans += elem;
//	}
//	cout << ans;
//}
//
//int main() {
//	int amount=0,r=0,c=0;
//	input(amount,r,c);
//	int length = pow(2, amount);
//	solution(r, c, length);
//	printAns();
//}

#include<iostream>										//두번째 방법
#include<vector>

using namespace std;

vector<vector<int>> v;
vector<int> temp;
int amount = 0, r = 0, c = 0,ans=0;

void input()											//입력값 받는 함수
{
	int tempInput = 0;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		temp.clear();
		for (int j = 0; j < amount; j++) {
			temp.push_back(i);
		}
		v.push_back(temp);
	}
	cin >> r >> c;
}

void solution(int y, int x, int length ) {				//몇개 지나왔는지 구하는 재귀함수

	if (y == r && x == c) {								//만약 y와 x가 쪼개지다가 r행 c열과 같아지면 ans출력후 return
														//함수 다끝나고 ans출력하면 r행 c열 다음 부분도 다 ans에 계산해버려서 답 달라짐
		cout << ans;
		return;
	}

	if ((y <= r && r < y + length) && (x <= c && c < x + length)) {	//r행 c열이 변이 y+length, x+length인 사각형 안에 있을 때, 4등분으로 재귀
		solution(y, x, length / 2);									
		solution(y, x + length / 2, length / 2);
		solution(y + length / 2, x, length / 2);
		solution(y + length / 2, x + length / 2, length / 2);

	}
	else
	{
		ans += length * length;										//만약 사분면안에 r,c가 없다면 해당 사분면 넓이 더해주기

	}
		
}
int main() {
	input();
	solution(0, 0, 1 << amount);									//pow함수 안쓰고도 비트연산자를 통해 2^n승 넣어줄 수 있다.

}