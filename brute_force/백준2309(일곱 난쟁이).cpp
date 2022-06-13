#include<iostream>							//3
#include<vector>
#include<algorithm>
using namespace std;

int arr[10] = {0,};	//초기화
vector<int> ans;

void input() {
	for(int i=0;i<9;i++)
		cin >> arr[i];
}
void solution() {                           //무식한 풀이
	int sum = 0;
	for (int i = 0; i < 9; i++) {			//첫번째 난쟁이 정하기
		for (int j = i+1; j < 9; j++) {		//두번째 난쟁이 정하기
			for (int k = 0; k < 9; k++) {	
				if (k != i && k != j) {		
					sum += arr[k];			//두 값 제외한 값 다 더해주기
					ans.push_back(arr[k]);	//답 벡터에 push_back
				}

			}
			if (sum == 100) {				//다른 두 값 합이 100이면
				sort(ans.begin(), ans.end());//algorithm헤더의 sort함수로 정렬
				for (int elem : ans)
					cout << elem << '\n';		//ans벡터의 원소 출력
				return;
			}
			else {
				ans.clear();				//100이 아니면 ans벡터 초기화
				sum = 0;					//sum값도 초기화
			}
		}
	}
}

//void solution() {					//다른 풀이
//	int sum = 0,rem=0;
//	for (int i = 0; i < 9; i++)
//		sum += arr[i];
//	rem = sum - 100;				//다 더한값에서 100을 빼고 
//									//나머지 값 저장
//	for (int i = 0; i < 9; i++) {
//		for (int j = i+1; j < 9; j++) {
//			if (arr[i] + arr[j] == rem) {	//두개 더한값이 나머지값이 나오면 
//											//나머지 값들을 다 더해야하는데
//				arr[i] = 0;					//값에 0저장		
//				arr[j] = 0;
//				sort(arr, arr + 9);			//정렬
//				for (int elem : arr) {
//					if (elem != 0) {			//원소가 0이 아니면
//						cout << elem << '\n';	//출력
//					}
//				}
//				return;
//			}
//		}
//	}
//
//}

int main() {
	input();
	solution();
}


