#include<iostream>
#include <queue>
#include<algorithm>

using namespace std;

int map[1001][1001];    //기존 맵
int dist[1001][1001];   //계산된 거리

int dx[4] ={-1,1,0,0};
int dy[4] ={0,0,-1,1};
/// @brief startX,startY에서 bfs로 최단거리 측정후 dist에 기록
void BFS(int startX, int startY, int n, int m)
{
    queue<pair<int, int>> q;

    q.push(make_pair(startX, startY));
    dist[startX][startY] = 0;

    while (!q.empty())
    {
            pair<int, int> curNode = q.front();
            q.pop();
            
            
            for (int i = 0; i < 4; i++)
            {
                int nextX = curNode.first + dx[i];
                int nextY = curNode.second + dy[i];

                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                    continue;
                if (dist[nextX][nextY] != -1)
                    continue;
                if(map[nextX][nextY] == 0) continue;    //갈수없는 땅
                dist[nextX][nextY] = dist[curNode.first][curNode.second] +1;    //이전 경로 +1
                q.push(make_pair(nextX,nextY));
            }
        }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,startPointX,startPointY;
    cin>>n>>m;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int val;
            cin>>val;
            map[i][j]=val;
            if(val ==2)
                {startPointX=i; startPointY =j;}
            else if(val ==0)
                dist[i][j]=0;
            else
                dist[i][j]=-1;
        }
    }


    BFS(startPointX,startPointY,n,m);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}