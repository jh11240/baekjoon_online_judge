#pragma region DFS
#include<vector>
#include<iostream>

using namespace std;
bool visited[50'0001];
vector<int> adj[50'0001];

/// @brief curNode에 도달했을 때 거리가 dist다.
/// @param curNode 
/// @param dist 
void DFS(int curNode,int dist, long long& totalCnt)
{
    visited[curNode] = true;

    bool isLeaf=true;
    for(int elem: adj[curNode])
    {
        if(visited[elem]) continue;
        isLeaf=false;
        DFS(elem,dist+1,totalCnt);
    }
    if(isLeaf &&curNode != 1)totalCnt += dist;

}

int main()
{
    int N;
    cin>>N;

    fill(&visited[0],&visited[0]+N+1,false);

    for(int i=0;i<N-1;i++)
    {
        int node1,node2;
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    long long totalCnt=0;
    DFS(1,0,totalCnt);
    if(totalCnt %2 ==0)
     cout<<"No";
     else
     cout<<"Yes";
}

#pragma endregion



#pragma region BFS
#include<vector>
#include<set>
#include<queue>
#include<iostream>

using namespace std;

vector<int> adj[50'0001];
set<int> leafNode; //key는 leaftnode 번호
long long dist[50'0001];
void BFS()
{
    queue<int> q;
    q.push(1);
    dist[1]=0;

    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();
        bool isLeaf=true;
        for(int elem : adj[curNode])
        {
            if(dist[elem] != -1)
            continue;
            isLeaf=false;
            dist[elem] = dist[curNode]+1;
            q.push(elem);
        }
        if(isLeaf) leafNode.insert(curNode);
    }

}

int main()
{
    int N;
    cin>>N;

    fill(&dist[0],&dist[0]+N+1,-1);

    for(int i=0;i<N-1;i++)
    {
        int node1,node2;
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    BFS();
    long long totalCnt=0;
    for(set<int>::iterator iter = leafNode.begin();iter!= leafNode.end();++iter)
    {
        totalCnt += dist[*iter];
    }
    if(totalCnt %2 ==0)
     cout<<"No";
     else
     cout<<"Yes";
}

#pragma endregion