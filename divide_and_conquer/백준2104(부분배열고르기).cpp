//#include<iostream>												//start 0이고 end 1일때 빙빙돔 mid가 0나와서
//#include<vector>												//solution(start,end)에서 mid값에서 왼쪽 오른쪽 조사를 한후
//#include<map>													//solution(start,mid), solution(mid,end), return 로 재귀를 돌렸는데,
//#include<algorithm>												//mid값이 중복되다보니 solution(0,1)에서 solution(0,0)->solution(0,1)로 무한루프에 빠진다 
//																//이방식은 그리디로 바로 다음값을 가지고 계산한값만 비교하기때문에 
//																//예를들어 9가 주어지고 3 3 3 5 7 7 3 4 1이런 식에서 7 7일때와 773일때 비교후
//																//77이 더크므로 3이 무시되고 774와 77을 비교하게된다
//using namespace std;
//vector<int> v;
//int ans=0;
//
//void input() {
//	int inputAmount = 0,temp=0;
//	cin >> inputAmount;
//	for (int i = 0; i < inputAmount; i++) {
//		cin >> temp;
//		v.push_back(temp);
//	}
//}
//
//void solution(int start, int end, int tempSum) {
//	if (start >= end) return;
//	int tempSumTemp=tempSum, minValTemp=1'000'001;
//	int mid = (start + end) / 2;
//	for (int i = mid; i <= end; i++) {						//mid부터 오른쪽으로 end값까지
//		if (v[i] <= minValTemp) {								//v[i]값이 최소값보다 작다면
//			ans = ans> max(v[i]*(tempSumTemp+v[i]), minValTemp*tempSumTemp)? ans: max(v[i] * (tempSumTemp + v[i]), minValTemp * tempSumTemp);	//두값중 큰값
//			if (v[i] * (v[i] + tempSumTemp) > minValTemp * tempSumTemp) {
//				minValTemp = v[i];
//				tempSumTemp += v[i];
//			}

//		}
//		else                                              //v[i]값이 최소값보다 크다면 
//		{
//			ans= ans>(minValTemp*(tempSumTemp+v[i]))? ans: (minValTemp *( tempSumTemp + v[i]));
//			tempSumTemp += v[i];

//		}       
//	
//	}
//	
//	for (int i = mid-1; i >= start; i--) {
//		if (mid == start) break;								//mid값이 start값이랑 같을때 예를들어 start =0 end=1일때
//		if (v[i] <= minValTemp) {								//v[i]값이 최소값보다 작다면
//			ans = ans > max(v[i] * (tempSumTemp + v[i]), minValTemp * tempSumTemp) ? ans : max(v[i] * (tempSumTemp + v[i]), minValTemp * tempSumTemp);	//두값중 큰값
//			if (v[i] * (v[i] + tempSumTemp) > minValTemp * tempSumTemp) {
//				minValTemp = v[i];
//				tempSumTemp += v[i];
//			}

//		}
//		else                                              //v[i]값이 최소값보다 크다면 
//		{
//			ans = ans > (minValTemp *( tempSumTemp + v[i])) ? ans : (minValTemp * (tempSumTemp + v[i]));
//			tempSumTemp += v[i];

//		}
//	
//	}
//	solution(start, mid, 0);
//	solution(mid+1, end, 0);
//	return;
//
//}
//
//int main(){
//	input();
//	solution(0, v.size() - 1, 0);
//	cout << ans;
//}

#include<iostream>									//https://devbelly.tistory.com/61 출처
#include<algorithm>

using namespace std;
int N;
long long arr[100'001], pSum[100'001];

long long solve(int lt,int rt) {
	if (lt == rt) return arr[lt] * arr[rt];						//만약 lt,rt값 같다면 mn*(pSum[rt]-pSum[l-1])값이 rt*rt값이 되므로 제곱값 리턴

	int mid = (lt + rt) / 2;									//평균값
	long long ret = max(solve(lt, mid), solve(mid +1, rt));		//반환값인 ret엔 mid를 기준으로 왼쪽과 오른쪽 조사해서 max값 return
																//조사할 구간중 왼쪽과 오른쪽을 나눠서 조사했으므로 
																//가운데 mid포함한 부분 이제 조사

	int l = mid;												//각 재귀에서 l은 mid값
	int r = mid + 1;											//각 재귀에서 r은 mid+1값
	long long mn = min(arr[l], arr[r]);							//mn값은 arr[l]과 arr[r]값중 더 적은 값
	ret = max(ret, (pSum[r] - pSum[l - 1]) * mn);				//ret값은 기존 ret값과 l~r값의 합*mn값 비교해서 더큰값

	while (lt < l || r < rt) {									//mid값인 l값이 범위 끝인 lt, mid+1값인 r값이 범위끝인 rt값을 넘지 않을때까지
		if (r < rt && (l == lt || arr[l - 1] < arr[r + 1])) {	//r이 rt값보다 작고, l값이 lt값과 같거나 왼쪽으로 한 칸 앞의 값이 
																//오른쪽으로 한 칸 뒤 값보다 작을때

			r+=1;												//r값 증가시키고
			mn = min(mn, arr[r]);								//mn값은 기존 mn값과 arr[r]값을 비교해서 더작은값
		}
		else													//아니면 왼쪽으로 진행하는 것이므로
		{
			l-=1;												//l값 감소시키고
			mn = min(arr[l], mn);								//mn값은 기존 mn값과 arr[l]값을 비교해서 더 작은값을 저장
		}	
		ret = max(ret, (pSum[r] - pSum[l - 1]) * mn);			//각 반복문마다 비교해서 ret값 저장
	}
	return ret;													//ret값 반환 
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		pSum[i] = pSum[i - 1] + arr[i];							//pSum[i]는 i번째까지의 합, solve에서 ret값 쉽게 구현하기 위함.
	}
	cout << solve(1, N);
}