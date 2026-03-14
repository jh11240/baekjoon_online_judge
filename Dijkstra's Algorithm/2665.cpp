// https://www.acmicpc.net/problem/2665

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int rooms[51][51];
int dist[51][51];
int dx[4]={-1,1,0,0};
int dy[4] = {0,0,-1,1};
const int INF = 1e9;

//거리,지점
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

void Dijkstra(int startX,int startY,int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        dist[i][j] = INF;
    }

    pq.push(make_pair(0,make_pair(startX,startY)));

    dist[startX][startY]=0;

    while(!pq.empty())
    {
        pair<int,int> curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if(dist[curNode.first][curNode.second] > curDist) continue;

        for(int i=0;i<4;i++)
        {
            int nextX = curNode.first+dx[i];
            int nextY = curNode.second+dy[i];
            pair<int,int> nextNode= make_pair(nextX,nextY);
            if(nextX<0||nextY<0 ||nextX>=n || nextY>=n) continue;
            int nextDist=0;
            //검은 방
            if(rooms[nextX][nextY] ==0)
            {
                nextDist = 1;
            }

            if(dist[nextX][nextY] > curDist + nextDist)
            {
                dist[nextX][nextY] = curDist+nextDist;
                pq.push(make_pair(dist[nextX][nextY],nextNode));
            } 
        }
    }

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string line;
        cin >> line;
        for(int j=0;j<n;j++)
        {
            rooms[i][j] = line[j]-'0';
        }
    }
    Dijkstra(0,0,n);

    int way = dist[n-1][n-1];
    cout<<way;

}