	#include<iostream>
	#include<algorithm>
	#include<vector>

	using namespace std;
	int N, K, D;

	//세 가지 값 입력받을 구조체
	struct inputS {
		int startBox;
		int endBox;
		int rule;
	};

	vector<inputS> v;

	//입력함수
	void input() {
		inputS iS;
		cin >> N >> K >> D;
		int temp1, temp2, temp3;
		for (int i = 0; i < K; i++) {
			cin >> temp1 >> temp2 >> temp3;
			iS = { temp1,temp2,temp3 };
			v.push_back(iS);
		}
	}
	/// <summary>
	/// 들어온 mid값이 마지막이라고 했을 때, 도토리가 남거나 같으면 false를 return해서 high값을 조절,
	/// 도토리 부족하면 true를 return해 low값을 조정 
	/// </summary>
	/// <param name="mid"></param>
	/// <returns></returns>
	bool checkIfLastAcornBox(int mid) {
		long long tmpSum = 0,tmp=0;
		for (int i = 0; i < K; i++) {
			//이 부분을 빼먹을시 규칙의 끝번호가 마지막 상자보다 크다면 해당 규칙에선 넣을 수 있는 상자의 갯수가 더 크게 나온다.
			tmp = min(v[i].endBox, mid);
			//tmp가 첫 상자의 번호보다 작으면 tmpSum에 음수를 더해줘서 이상한 값이 조건에 안 걸리고 답으로 나옴!
			if (tmp >= v[i].startBox) {
				tmpSum += ((tmp - v[i].startBox) / v[i].rule) + 1;

			}
			//총 도토리 갯수보다 넣을 도토리 갯수가 많아지면 false return해서 high값 조절
			if (tmpSum >= D) return false;
		}
		//반복문 다 통과했다면 true를 return해서 low값 조절
		return true;
	
	}
	// 위에서 음수 조건체크못해서 나온 수와 제일 가까운 박스 찾는 함수 (그냥 삽질)
	///// <summary>
	///// 매개로 들어온 num값보다 작은 박스 번호 중 num과 제일 가까운 box return
	///// </summary>
	///// <param name="num"></param>
	///// <returns></returns>
	//long long nearestNumberBox(long long num) {
	//	long long ret = 0, tmp = 0;;
	//	for (int i = 0; i < K; i++) {
	//		// 해당 규칙에서 num보다 작은 상자 구하고 
	//		if (num >= v[i].startBox) {
	//			tmp = v[i].startBox + ((num - v[i].startBox) / v[i].rule) * v[i].rule;
	//			//num과의 차이가 ret이 더 작다면 ret유지, tmp가 더 작다면 ret=tmp로 갱신
	//			ret = (num - ret) >= (num - tmp) ? tmp : ret;
	//		}
	//	}
	//	return ret;
	//}

	void solution() {
		int low=0, high=1'000'000'001, mid=0;
		while (low + 1 < high) {
			mid = (low + high) / 2;
			((checkIfLastAcornBox(mid)) ? low : high) = mid;
		}
		cout<<high;
	
	}

	int main() {
		input();
		solution();
	}