#include <iostream>
#include<vector>
using namespace std;
int dp[101][100'001];
vector<pair<int,int> >items; //idx에 해당하는 무게 , 가치

int Knapsack(int curIdx, int curWeight,int maxIdx,int maxWeight )
{
    int& ret = dp[curIdx][curWeight];
    if(ret != -1) return ret;

    if(curIdx == maxIdx)
    {
       return 0;
    }

    //현재 아이템 버렸을 때
    ret=Knapsack(curIdx+1, curWeight,maxIdx,maxWeight);


    //현재 아이템 챙겼을 때
    if(curWeight+ items[curIdx].first <= maxWeight)
        ret = max(ret,Knapsack(curIdx+1,curWeight+ items[curIdx].first, maxIdx,maxWeight)+items[curIdx].second );

    return ret;
}

int main()
{
    int N,C;
    cin >> N>>C;

    for(int i=0;i<N;i++)
    {
        int w,v;
        cin>>w>>v;
        items.push_back(make_pair(w,v));
    }
    for(int i=0;i<N;i++)
    {
        for(int j =0;j<=C;j++)
        {
            dp[i][j] =-1;
        }
    }
    int answer = Knapsack(0,0,N,C);

    cout<<answer;
}