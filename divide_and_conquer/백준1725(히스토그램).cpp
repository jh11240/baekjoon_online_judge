#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> v;							//각 네모 길이 저장하는 벡터

void input(int& amount) {							//입력값 받는 함수
	int temp = 0;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> temp;
		v.push_back(temp);
	}
}

long long solution(int lt,int rt) {					//재귀해서 가장 큰 사각형값 return하는 함수
	if (lt == rt) return v[lt];						//만약 범위같을땐 밑변1에 높이 lt인 사각형이므로 return v[lt]
	int mid = (lt + rt) / 2;						//중간값 
	int l = mid,r=mid+1;							//l은 중간값 r은 중간값 +1
		
	long long minH = min(v[l],v[r]);				//minH값은 최소 변길이. 

	long long ret = max(solution(lt, mid), solution(mid + 1, rt));	//재귀로 이전 값들의 최대 사각형넓이값 불러옴

	ret = max(ret, (r - l+1) * minH);								//이미 지나온 재귀값들의 최대값과 지금 l, r값에 해당하는 사각형 넓이 값 비교
	while (lt < l || r < rt) {										//l이 lt값(경계값)보다 크고, r이 rt값(경계값)보다 작을 때
		if (r < rt && (l == lt || v[l - 1] < v[r + 1])) {			//오른쪽으로 진행할 때,
			r++;
			minH = min( v[r], minH);
		}
		else {														//왼쪽으로 진행할 때,
			l--;
			minH = min(v[l], minH);

		}
		ret = max(ret, (r - l+1) * minH);							//각각 진행할때마다 ret값 갱신
	}

	return ret;


	
}

int main() {
	int amount;
	input(amount);
	cout << solution(0, amount-1);
}