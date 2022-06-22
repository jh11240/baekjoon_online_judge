#include<iostream>									//예를들어 111일 휴가 받았고, 20일중 9일 만 된다 싶을때 
													//원래 답은 111/20 *9 + 9지만,V%P로 해버리면 111/20+ 11이 되어버린다.

using namespace std;

void solution(const int& L, const int& P, const int& V) {	//각 L,P,V에 대해 답 구하고 출력 함수
	static int cnt = 1,ans=0;								//static으로 선언하여 반복호출때마다 cnt값 증가할수 있게.
	if (V % P > L)  ans =(( V / P )* L) + L;				//만약 V%P>L 일땐 V%P말고 L을 더해줌
													
	else
	ans = V / P * L + V % P;								//V%P<=L이면 L말고 V%P 더해준다.
	cout << "Case " << cnt << ": " << ans << '\n';
	cnt++;
}

void input(int& L, int& P, int& V) {						//P일 중 L일만큼 휴가를 사용가능, V일짜리 휴가 받음 
	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) return;
		solution(L, P, V);

	}


}


int main() {
	int L = 0, P = 0, V = 0;
	input(L, P, V);

}