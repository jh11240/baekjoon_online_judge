#include<iostream>
#include<algorithm>
using namespace std;
//게임 횟수
int dp[1001];
int N;
int main(){
    cin>>N;

    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for(int i=4;i<1001;i++){
        dp[i] = min(dp[i-1]+1,dp[i-3]+1);
    }
    if(dp[N]%2 ==0) cout<<"CY";
    else cout<<"SK";

}