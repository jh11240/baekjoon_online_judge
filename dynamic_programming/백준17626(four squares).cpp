#include<iostream>
using namespace  std;
int dp[50001];
// 223 * 223 = squared num right under 50000
int square[223];
int N;



int main(){
    for(int i=1;i<50001;i++){
        dp[i]=i;
    }
    for(int i =1;i<224;i++){
        square[i]=i*i;
        dp[i*2]=1;
    }
    cin>>N;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=1;
    dp[5]=2;
    dp[6]=3;
    for(int i=2;i<224;i++){
        for(int j=1;j<50001;j++){
            if(j>=square[i])
            dp[j]= min (dp[j], dp[j-square[i]]+1);
        }
    }
    cout<<dp[N];
}