#include<iostream>							//3
#include<vector>							//원래 하려던 건 값을 정렬한 후에 index 0부터 비교를해서 차이가 일정하면 패스하고 차이가 달라지면 거기에 기지국을 세우고
											//기지국이 너무많아지면 다시 비교후 저장된 차이값에 +1만큼해서 기지국 또 세우고 이런식으로 접근했는데 
											//+1만큼 세웠을때 차이가 불규칙하며  어떻게 비교를 해야할지 몰라서 
											// 하지만 정렬을 한후 각값의 차이만큼 또 정렬을 하게된다면 차이가 적은 값부터 정렬이될텐데
											//그럼 차이가 제일작은순으로 센서-기지국 값만큼 더해주면 답이된다. 
											//기지국에서 센서들을 할당을 하는데 센서들에게 수신을 받는값은 센서-기지국 만큼이므로
											//센서의 간격은 총 n-1개인데 기지국이 n-1개의 간격을 k개로 나눴을 때 버려지는 간격이 k-1개이므로 
											//우리가 사용하는 간격의 갯수는 총 n-1 - (k-1) = n-k이다.
#include<algorithm>
using namespace std;

vector<int> inputN;
vector<int> differ;

void input(int& sensors, int& manages) {
	int temp=0;
	cin >> sensors >> manages;

	for (int i = 0; i < sensors; i++) {
		cin >> temp;
		inputN.push_back(temp);
	}
}

void solution(int& sensors, int& manages) {
	int ans = 0;
	sort(inputN.begin(),inputN.end());					//들어온 값 정렬
	for (int i = 1; i < inputN.size(); i++) {		
		differ.push_back(inputN[i] - inputN[i - 1]);	//differ 벡터에 정렬된 두 값 차이 다 push
	}
	sort(differ.begin(), differ.end());					//각 차이를 또 정렬한 후
	for (int i = 0; i < sensors - manages; i++) {		//0부터 sensors- manages까지 값을 다 더한것이 답.
		ans += differ[i];
	}

	cout << ans;

}

int main() {
	int sensors = 0, manages = 0;
	input(sensors,manages);
	solution(sensors,manages);
}