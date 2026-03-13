#include<iostream>
using namespace std;
char field[251][251];
bool visited[251][251];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

/// @brief curX,curY부터 뻗어나가면서 양이랑 늑대 갯수 구하기
/// @return first는 양 갯수, second는 늑대 갯수
pair<int,int> DFS(int curX,int curY,int R,int C)
{   
    visited[curX][curY] = true;
    pair<int,int> ret = make_pair(0,0);

    if(field[curX][curY] == 'o') 
        ret.first=1;
    else if(field[curX][curY] == 'v')
        ret.second=1;

    for(int i=0;i<4;i++)
    {
        int nextX = curX + dx[i];
        int nextY = curY + dy[i];

        if(nextX<0||nextY<0 || nextX>=R || nextY >= C)
        continue;
        if(visited[nextX][nextY] ) continue;
        if(field[nextX][nextY] == '#') continue;
        
        pair<int,int> tmp = DFS(nextX,nextY,R,C);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }
    return ret;
}

int main()
{
    int R,C;
    cin>>R>>C;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            char tmp;
            cin>>tmp;
            field[i][j] = tmp;
        }
    }

    int sheepCnt=0,wolfCnt=0;

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(visited[i][j] ) continue;
            pair<int,int> result = DFS(i,j,R,C);
            if(result.first> result.second)
                sheepCnt += result.first;
            else
                wolfCnt +=result.second;
        }
    }
    cout<<sheepCnt<<" "<<wolfCnt;
}