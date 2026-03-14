//https://www.acmicpc.net/problem/14938

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int item[101];

//index가 시작점, value의 first는 도착점, second는 길이
vector<pair<int,int>> adj[101];

//거리, 지점
priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
int dist[101];
const int INF = 1e9;

int Dijkstra(int start,int n,int m)
{
    //초기화
    fill(&dist[0],&dist[0]+101,INF);
    
    //1, 다익스트라로 다 처리
    pq.push(make_pair(0,start));
    dist[start] =0;

    while(!pq.empty())
    {
        int curDist =pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        for(auto& next: adj[curNode])
        {
            int nextNode= next.first;
            int nextDist= next.second;
            
            if(dist[nextNode]>nextDist +dist[curNode] )
            {
                dist[nextNode] = nextDist + dist[curNode];
                pq.push(make_pair(dist[nextNode],nextNode));
            }

        }
    }
    int maxItem=0;
    //2. 각 노드 지점 dist로 보면서 못가는 곳 짤
    for(int i=1;i<=n;i++)
    {
        if(dist[i]<=m)
            maxItem += item[i];
    }

    return maxItem;
}

int main()
{
    int n,m,r;
    cin>>n>>m>>r;

    for(int i=1;i<=n;i++)
    {
        cin>>item[i];
    }

    for(int i=0;i<r;i++)
    {
        int s,d,l;
        cin>>s>>d>>l;
        adj[s].push_back(make_pair(d,l));
        adj[d].push_back(make_pair(s,l));
    }

    int maxItem=0;
    for(int i=1;i<=n;i++)
    {
        int itemCnt = Dijkstra(i,n,m);
        maxItem = maxItem>itemCnt? maxItem:itemCnt;
    }
}