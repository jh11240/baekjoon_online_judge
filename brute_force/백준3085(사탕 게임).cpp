#include<iostream>

using namespace std;

char** arr;

void input(int& row) {
	cin >> row;
	arr = new char*[row];
	for (int i = 0; i < row; i++) {
		arr[i] = new char[row];
	}
	for (int i = 0; i < row ; i++) {
		for (int j = 0; j < row; j++) {
			char temp;
			cin >> temp;
			arr[i][j]=temp;
		}
	}

}
int checkPair(const int& i,const int& j,const int& row) {	//arr[i][j]일 때, arr[i][j]값 바로 오른쪽값과 밑의 값 비교하는 함수	
													//이방식은 모든 값을 다 조사함.
													//변경 필요 바꾼값 두개를 대입하고 
													//해당 열이나 행을 조사
													//값 하나를 가져오면 그값과 오른쪽값과 바꾸고, 행 비교
													//그 값과 아랫값을 바꾸고, 열 비교
													//이방식 대로 하려면 바꾸면 바꾼 두값의 열,행 다 비교해서 총 세번식 비교해야함 
													//시간복잡도는 어차피 3곱해지는데 상수라 무시되므로 상관없다 귀찮을뿐
	int sum=0;
	
	if (i + 1 != row) {										//arr[i][j]값과 그 밑 값 바꾸깅
		swap(arr[i][j], arr[i + 1][j]);						//arr[i][j]값과 그 밑의 값 바꿀때 j열 조사
		for (int idx = 0; idx < row; idx++) {				
			int sumTemp = 1;
			int idxTemp = idx;
			while (idxTemp + 1 < row) {							//열+1이 row보다 작을때까지
				if (arr[idxTemp][j] == arr[idxTemp + 1][j]) {	//해당 열의 값과 그다음 열값 비교후
					sumTemp++;									//같으면 sumTemp+1,idx++반복
					idxTemp++;
				}
				else
					break;

			}
			sum= sum> sumTemp ? sum: sumTemp;
		}
		for (int idx = 0; idx < row; idx++) {				//arr[i][j]값과 그 밑의 값 바꿀 때 i행 조사
			int sumTemp = 1;
			int idxTemp = idx;
			while (idxTemp + 1 < row) {						//열+1이 row보다 작을때까지
				if (arr[i][idxTemp] == arr[i][idxTemp+1]) {	//해당 열의 값과 그다음 열값 비교후
					sumTemp++;								//같으면 sumTemp+1,idx++반복
					idxTemp++;
				}
				else
					break;

			}
			sum= sum> sumTemp ? sum: sumTemp;

		}
		for (int idx = 0; idx < row; idx++) {				//arr[i][j]값과 그 밑의 값 바꿀 때 i+1행 조사
			int sumTemp = 1;
			int idxTemp = idx;
			while (idxTemp + 1 < row) {								//열+1이 row보다 작을때까지
				if (arr[i+1][idxTemp] == arr[i+ 1][idxTemp+1]) {	//해당 열의 값과 그다음 열값 비교후
					sumTemp++;										//같으면 sumTemp+1,idx++반복
					idxTemp++;
				}
				else
					break;

			}
			sum= sum> sumTemp ? sum: sumTemp;

		}
		swap(arr[i][j], arr[i + 1][j]);					//다시 바꿔주기
	}
	if (j + 1 != row) {									//arr[i][j]값과 오른쪽 값 바꾸기
		swap(arr[i][j], arr[i][j + 1]);					//바꿔주기

		for (int idx = 0; idx < row; idx++) {			//i,j값과 오른쪽 값 바꿀 때, i행 조사
			int sumTemp = 1;							//임시 합 저장하는 변수
			int idxTemp = idx;
			while (idxTemp + 1 < row) {							//행+1 값이 끝이 아닐때까지
				if (arr[i][idxTemp] == arr[i][idxTemp + 1]) {	//만약 다음 행값과 같다면
					sumTemp++;									//임시 합+1
					idxTemp++;									
				}
				else
					break;
			}
				sum= sum> sumTemp ? sum: sumTemp;
			
		}
		for (int idx = 0; idx < row; idx++) {			//i,j값과 오른쪽 값 바꿀때, j열 조사
			int sumTemp = 1;							//임시 합 저장하는 변수
			int idxTemp = idx;
			while (idxTemp + 1 < row) {							//행+1 값이 끝이 아닐때까지
				if (arr[idxTemp][j] == arr[idxTemp + 1][j]) {	//만약 다음 행값과 같다면
					sumTemp++;									//임시 합+1
					idxTemp++;									//++
				}
				else
					break;
			}
				sum= sum> sumTemp ? sum: sumTemp;
			
			
		}
		for (int idx = 0; idx < row; idx++) {			//i,j값과 오른쪽 값 바꿀때, j+1열 조사
			int sumTemp = 1;							//임시 합 저장하는 변수
			int idxTemp = idx;
			while (idxTemp + 1 < row) {									//행+1 값이 끝이 아닐때까지
				if (arr[idxTemp][j + 1] == arr[idxTemp + 1][j + 1]) {	//만약 다음 행값과 같다면
					sumTemp++;											//임시 합+1
					idxTemp++;											//++
				}
				else
					break;
			}
				sum= sum> sumTemp ? sum: sumTemp;
			
		}

		swap(arr[i][j], arr[i][j + 1]);					//다시 바꿔주기
	}

	return sum;
}
void solution(int& row) {											//답 도출 함수
	int ans=0;														//답 변수
	for (int i = 0; i < row; i++) {									//사탕 한개 고른 후
		for (int j = 0; j < row; j++) {					
			ans=checkPair(i, j,row)>ans ? checkPair(i, j, row):ans;	//checkpair함수로 그 한 개랑 오른쪽 바꿨을 때랑
																	//밑에랑 바꿨을 때 제일 긴 수를 답 변수랑 비교,
																	//더 큰값 변수에 넣어줌
		}
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);					
	int row = 0;
	input(row);
	solution(row);

	delete[] arr;
}