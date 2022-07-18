//#include<iostream>												//3 
//																//아 1일때 *출력으로해서 이거 어떻게 각 재귀에서 줄바꿈이랑 처리를 하지 고민했었다.
//																//그냥 배열로 생각
//using namespace std;
//
//void input(int& amount) {
//	cin >> amount;
//}
//
//void solution(int x, int y, int length) {	//출처 https://cryptosalamander.tistory.com/38
//											//비어있는 좌표를 다적어보면 빈 좌표 / 해당 사각형 길이를 3으로 나눴을때
//											// 1이나온다는 공통점이있다는걸 활용한풀이
//	if ((x / length) % 3 == 1 && (y / length) % 3 == 1) {
//		cout << " ";
//	}
//	else
//	{
//		if (length / 3 == 0)
//			cout << "*";
//		else
//			solution(x, y, length / 3);
//	}
//		
//
//}
//	
//
//int main() {
//	int amount = 0;
//	input(amount);
//	for (int i = 0; i < amount; i++) {
//		for (int j = 0; j < amount; j++) {
//			solution(i, j, amount);
//		}
//		cout << '\n';
//	}
//}

#include<iostream>                                  //이건 내 방식 배열에 다때려넣기

using namespace std;

char arr[2188][2188];

void input(int& inputN) {
	cin >> inputN;
}
void init(const int& inputN) {
	for (int i = 0; i < inputN; i++) {
		for (size_t j = 0; j < inputN; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void solution(int x, int y, int length) {
	if (length == 3) {
		arr[x][y] = '*';
		arr[x][y + 1] = '*';
		arr[x][y + 2] = '*';
		arr[x + 1][y] = '*';
		arr[x + 2][y] = '*';
		arr[x + 1][y + 2] = '*';
		arr[x + 2][y + 2] = '*';
		arr[x + 2][y + 1] = '*';
	}
	else {
		solution(x, y, length / 3);
		solution(x, y+ length / 3, length / 3);
		solution(x, y+2* length / 3, length / 3);
		solution(x+ length / 3, y, length / 3);
		solution(x+ length / 3, y+2* length / 3, length / 3);
		solution(x+ 2*length / 3, y, length / 3);
		solution(x+ 2*length / 3, y+ length / 3, length / 3);
		solution(x+ 2*length / 3, y+2* length / 3, length / 3);
	}

}
void print(const int& amount) {
	for (int i = 0; i < amount;i++) {
		for (int j = 0; j < amount; j++) {
			cout<<arr[i][j];
		}
		cout << '\n';
	}
}

int main() {
	int amount;
	input(amount);
	init(amount);
	solution(0, 0, amount);
	print(amount);

}