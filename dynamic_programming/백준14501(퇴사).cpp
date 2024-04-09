#include<iostream>
#include<vector>
using namespace std;

int dp[17];
vector<pair<int,int>> v;

int main(){
    int N,t,p;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>t>>p;
        v.push_back(make_pair(t,p));
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+v[i].first; j <= N; j++) {
            dp[j] = max(dp[j],v[i].second+dp[i]);
        }
    }
    cout<<dp[N];
}