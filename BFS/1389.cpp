#pragma region BFS 풀이
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adj[101]; // 인접 리스트
int dist[101];        // 시작점으로부터의 거리를 저장

int BFS(int Start)
{
    //초기화해주기
    memset(dist,-1,sizeof(dist));
    queue<int> q;

    dist[Start] =0;
    q.push(Start);
    int total_Bacon=0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : adj[cur])
        {
            if(dist[next]!=-1) continue;
            dist[next] = dist[cur]+1;
            total_Bacon+= dist[next];
            q.push(next);
        }
    }
    return total_Bacon;
}

int main()
{
    int N,M;
    
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int min_Bacon=1e9;
    int min_BaconIdx=0;

    for(int i=1;i<=N;i++)
    {
        int cur_Bacon= BFS(i);
        if(cur_Bacon<min_Bacon)
        {
            min_Bacon=cur_Bacon;
            min_BaconIdx=i;
        }
    }

    cout<< min_BaconIdx;
    return 0;

}
#pragma endregion

#pragma region 플로이드 와샬 풀이 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dist[101][101];        // 시작점으로부터의 거리를 저장

/// @brief 플로이드와샬
/// @param N 인원수
void FW(int N)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                dist[i][j] = dist[i][k] + dist[k][j];
            }
    }
}

int main()
{
    int N,M;
    
    cin>>N>>M;

    //초기화
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j] = 1e9;
        }
    }

    for(int i=0;i<M;i++)
    {
        int a=0,b=0;
        cin>>a>>b;

        dist[a][b]=1;
        dist[b][a]=1;
    }

    FW(N);

    int min_Bacon=1e9;
    int min_BaconIdx=0;

    for(int i=1;i<=N;i++)
    {
        int cur_Bacon = 0;
        for(int j=1;j<=N;j++)
        {
            cur_Bacon += dist[i][j];
        }
        if(min_Bacon>cur_Bacon)
        {
            min_Bacon = cur_Bacon;
            min_BaconIdx = i;
        }
    }

    cout<< min_BaconIdx;
    return 0;

}
#pragma endregion