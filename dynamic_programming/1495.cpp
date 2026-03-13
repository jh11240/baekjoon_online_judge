#include <iostream>

using namespace std;
int v[101];
int dp[101][1001];   //인덱스, 볼륨
int Solve(int curIdx, int curVol,int maxVol,int maxIdx)
{
    if(curVol<0 || curVol>maxVol) return -2;

    if(curIdx == maxIdx) return curVol;

    int& ret = dp[curIdx][curVol];
    if(ret!= -1) return ret;

    int case1 = Solve(curIdx+1,curVol + v[curIdx],maxVol,maxIdx);
    int case2= Solve(curIdx+1,curVol - v[curIdx],maxVol,maxIdx );

    return ret= max(case1, case2);

}

int main()
{
    int N,S,M;
    cin>>N>>S>>M;

    for(int i=0;i<N;i++)
    {
        cin>>v[i];
    }
    // 초기화: 안전하게 전체 크기를 2중 루프로 초기화
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 1000; j++) {
            dp[i][j] = -1;
        }
    }
    int result = Solve(0,S,M,N);
   if(result<=-2) cout<<-1;

   else cout<<result;

}