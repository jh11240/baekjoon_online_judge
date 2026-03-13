#pragma region Dynamic Programming
#include <iostream>
#include <vector>
using namespace std;

struct Shortcut{
    int start, len;
};
int dp[10'001];
vector<Shortcut> v[10'001];
int main()
{
    int N,D;
    cin>>N>>D;

    for(int i=0;i<N;i++)
    {
        int s,d,l;
        cin>>s>>d>>l;
        if(d>D) continue;
        if (d - s <= l) continue;
        v[d].push_back({s,l});
    }

    dp[0]=0;
    for(int i=1;i<=D;i++)
    {
        dp[i] = dp[i-1]+1;

        for(auto&s : v[i])
        {
            dp[i] = min(dp[i],dp[s.start]+ s.len);
        }
    }

    cout<<dp[D];

}
#pragma endregion

#pragma region DijkStra

#include<iostream>
#include<queue>
using namespace std;

const int INF = 1e9; // 충분히 큰 값으로 설정
//거리,지점
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//인덱스는 시작지점, 값은 도착지점,거리
vector<pair<int,int>> adj[10'001];
int dist[10'001];
void Dijkstra()
{
    fill(dist, dist + 10001, INF);
    dist[0]=0;
    pq.push(make_pair(0,0));

    while(!pq.empty())
    {
        int curDist= pq.top().first;
        int curLoc = pq.top().second;
        pq.pop();

        if(dist[curLoc]< curDist) continue;

        for(auto next : adj[curLoc])
        {
            int nextDist= curDist + next.second;
            int nextNode=next.first;
            if(nextDist<dist[nextNode])
            {
                dist[nextNode] = nextDist;
                pq.push(make_pair(nextDist,nextNode));
            }
        }
        
    }
}

int main()
{
    int N,D;
    cin>>N>>D;

    for(int i=0;i<N;i++)
    {
        int s,d,l;
        cin>>s>>d>>l;
        adj[s].push_back(make_pair(d,l));
    }
    //초기화
    for(int i=0;i<D;i++)
    {
        adj[i].push_back(make_pair(i+1,1));
    }
    Dijkstra();

    cout<<dist[D];
}

#pragma endregion