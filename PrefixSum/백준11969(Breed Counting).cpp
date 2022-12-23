///////////////////////////////////////////////////////by struct cowInfo

#include<iostream>
#include<vector>

using namespace std;

int N=0, Q=0;
int dx[3] = { 0,1,2 };

//각 입력값마다 1,2,3 몇개씩있는지 정보를 담을 구조체 
struct cowInfo{
	int Holsteins;
	int Guernseys;
	int Jerseys;
};

//구조체 연산자 오버로딩
cowInfo operator-(const cowInfo& c1, const cowInfo& c2) {
	cowInfo ret;
	ret.Holsteins = c1.Holsteins - c2.Holsteins;
	ret.Guernseys = c1.Guernseys - c2.Guernseys;
	ret.Jerseys = c1.Jerseys - c2.Jerseys;
	return ret;
}

//v[i]는 i번째일때 소 정보 
vector<cowInfo> v;

void Input() {
	cowInfo back={0,0,0};
	//tmp for N / tmp1,tmp2 for Q
	int tmp = 0,tmp1=0,tmp2=0;
	cin >> N >> Q;
	v.push_back(back);
	//입력값이 1,2,3인지에 따라 마지막 cowinfo에 증가시켜주고 벡터에 저장
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		back = v.back();
		if (tmp == 1) {
			back.Holsteins++;
			v.push_back(back);
		}
		else if (tmp == 2) {
			back.Guernseys++;
			v.push_back(back);
		}
		else {
			back.Jerseys++;
			v.push_back(back);
		}
	}
	//Q번간 a,b입력받아 각 a,b에 대해 답출력
	for (int i = 0; i < Q; i++) {
		cin >> tmp1 >> tmp2;
		//0~tmp2 값의 합부터 0~ (tmp1-1)값의 차가 답이된다.
		cowInfo ans=v[tmp2] - v[tmp1-1];
		cout << ans.Holsteins<< " " << ans.Guernseys << " " << ans.Jerseys << '\n';
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}

////////////////////////////////////////////// by array 