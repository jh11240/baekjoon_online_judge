// https://www.acmicpc.net/problem/14716

#include<iostream>

using namespace std;

int HSM[251][251];
bool visited[251][251];

int dx[8] = {-1,1,0,0,-1,1,-1,1};
int dy[8] = {0,0,-1,1,1,-1,-1,1};

void DFS(int curX,int curY,int M,int N)
{
    visited[curX][curY] =true;

    for(int i=0;i<8;i++)
    {
        int nextX =curX + dx[i];
        int nextY = curY + dy[i];

        if(nextX<0|| nextY <0 || nextX>= M || nextY >= N) continue;
        if(visited[nextX][nextY]) continue;
        if(HSM[nextX][nextY] == 0)  continue;
        DFS(nextX,nextY,M,N);
    }
}

int main()
{
    int M,N;
    cin>>M>>N;

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            int isLetter;
            cin>>isLetter;
            HSM[i][j] = isLetter;
        }
    }
    int letterCnt=0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j]) continue;
            if(HSM[i][j] ==0) continue;

            DFS(i,j,M,N);
            letterCnt++;
        }
    }
    cout<<letterCnt;
}