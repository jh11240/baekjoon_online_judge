#include<iostream>
#include<vector>
using namespace std;

vector<int> multiTap;
vector<int> plugs;

void input(int& holes, int& usedAmount) {
	int tempInput = 0;
	cin >> holes >> usedAmount;
	for (int i = 0; i < usedAmount; i++) {
		cin >> tempInput;
		plugs.push_back(tempInput);
	}
		multiTap.assign(holes,0);
	

}

void solution(int& holes,int& usedAmount) {
	int ans = 0;
	for (int i = 0; i < usedAmount; i++) {
		bool plugged= false;					//플러그에 꽂았나.
		for (int j = 0; j < holes; j++)			//멀티탭에꼽으려는 플러그가 있을 때 와 이거 순서 시방
		{
			if (multiTap[j] == plugs[i]) {
				plugged = true;
				break;
			}

		}
		
		if (plugged) continue;
		for (int j = 0; j < holes; j++) {		//멀티탭이 비어있을 때	
			if (multiTap[j] == 0) {
				multiTap[j] = plugs[i];
				plugged = true;
				break;
			}
		}
	
		if (plugged) continue;

		int lastNeed = -1;						//마지막으로 들어올 차례
		int index = -1;							//뺄 멀티탭 인덱스

		for (int j = 0; j < holes; j++) {		//이제 사용횟수 없거나 멀티탭중에 제일 뒤에 들어올 놈 빼야함
			int tmp = 0;
			for (int k = i + 1; k < usedAmount; k++) {	//k는 i+1부터 조사, 왜냐면 i일때는 line96에서 조사하기때문
				if (plugs[k] == multiTap[j])
					break;
				tmp++;
			}
			if (tmp > lastNeed) 
			{
				lastNeed = tmp;
				index = j;
			}
		}
		multiTap[index] = plugs[i];
		ans++;

	}
	cout << ans;
}

int main() {
	int holes = 0,usedAmount=0;
	input(holes,usedAmount);
	solution(holes,usedAmount);
}