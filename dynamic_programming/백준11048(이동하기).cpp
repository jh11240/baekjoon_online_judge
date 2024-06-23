#include<iostream>
using namespace std;
int N,M,tmpNum;
int dp[1002][1002];
int candy[1002][1002];
int Dp(int r, int c){
    if(r<0 || c <0) return 0;
    int* ret= &dp[r][c];
    if(*ret!=-1) return *ret;

    *ret=0;
    *ret=max(Dp(r-1,c),max( Dp(r,c-1), Dp(r-1,c-1)))+candy[r][c];
    return *ret; 
}

int main(){
    fill(&dp[0][0], &dp[1000][1001],-1);
    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmpNum;
            candy[i][j]=tmpNum;
        }
    }
    cout<<dp[N][M];
}