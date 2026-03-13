#pragma region BFS
#include<iostream>
#include<queue>
using namespace std;
char battleField[101][101];
bool visited[101][101];
int dx[4]={-1,1,0,0};
int dy[4] = {0,0,-1,1};

int BFS(int startX, int startY, int M, int N)
{
    char side = battleField[startX][startY];
    int armyCnt=0;
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;
    while (!q.empty())
    {
        int qSize = q.size();
        armyCnt+=qSize;
        for (int i = 0; i < qSize; i++)
        {
            pair<int, int> curNode = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int nextX = curNode.first + dx[j];
                int nextY = curNode.second + dy[j];

                if (nextX < 0 || nextY < 0 || nextX >= M || nextY >= N)
                    continue;
                if (visited[nextX][nextY])
                    continue;
                if (battleField[nextX][nextY] != side)
                    continue; // 팀다르면 건너뛰기
                visited[nextX][nextY] = true;
                q.push(make_pair(nextX,nextY));
            }
        }
    }
    return armyCnt;
}
int main()
{
    int N,M;
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            char side;
            cin>>side;
            battleField[i][j] = side;
        }
    }
    int sideW=0,sideB=0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j])
            continue;
            int num = BFS(i,j,M,N);
            num = num*num;
            if(battleField[i][j] == 'W')
                sideW+= num;
            else 
                sideB += num;
        }
    }

    cout<<sideW<<" "<<sideB;
}
#pragma endregion

#pragma region DFS

#include<iostream>
using namespace std;
char battleField[101][101];
bool visited[101][101];
int dx[4]={-1,1,0,0};
int dy[4] = {0,0,-1,1};

int DFS(int curX, int curY, int M, int N,int idx)
{
    char side = battleField[curX][curY];
    int armyCnt=1;      //현재 노드에 들어왔으니까 1
    visited[curX][curY] = true;

    for(int i=0;i<4;i++)
    {
        int nextX = curX+dx[i];
        int nextY = curY+ dy[i];

        if(nextX<0 ||nextY<0 ||nextX>=M ||nextY>=N) continue;
        if(battleField[nextX][nextY] != side) continue;
    if(visited[nextX][nextY]) continue;
        armyCnt+= DFS(nextX,nextY,M,N,idx+1);
    }

    return armyCnt;
}
int main()
{
    int N,M;
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            char side;
            cin>>side;
            battleField[i][j] = side;
        }
    }
    int sideW=0,sideB=0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j])
            continue;
            int num = DFS(i,j,M,N,0);
            num = num*num;
            if(battleField[i][j] == 'W')
                sideW+= num;
            else 
                sideB += num;
        }
    }

    cout<<sideW<<" "<<sideB;
}

#pragma endregion