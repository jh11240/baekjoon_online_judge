#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
const long long INF = -1e18;
vector<pair<int,int>> adj[100];
//경로를 거꾸로 저장 (도착지점에서 각 노드에 도달할 수 있는지 판별용)
vector<int> reverseV[100];
bool visited[101];

//reverseV를 통해 도착지점에서 각 노드에 도달할 수 있는지 체크한다.
bool BFS(int N){
    queue<int> q;
    q.push(N-1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int p : reverseV[cur]){
            if(!visited[p]){
                visited[p]=true;
                q.push(p);
            }
        }
    }
    return visited[0];
}

int main(){
    int N,M;
    cin>>N>>M;
    //얻는 금품의 가치 
    long long dist[101];
    //이전 노드
    int prevNode[101];

    fill(prevNode,prevNode+101,101);
    fill(dist,dist+101,INF);
    fill(visited,visited+101,false);

    //처음 얻는 금품은 0으로 설정
    dist[0]=0;
    bool minusCycle=false;

    for(int i=0;i<M;i++){
        int A,B,C;
        cin>>A>>B>>C;
        adj[A-1].push_back(make_pair(B-1,C));
        reverseV[B-1].push_back(A-1);
    }

    //시작지점에서 도착지점을 못가는 경우 미리 체크
    if(!BFS(N)) {
        cout<<-1;
        return 0;
    }

    //N-1번 루프보다 한번 더 돌아서 싸이클 체크
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(auto& p : adj[j]){
                int nextNode=p.first, nextDist=p.second;
                if(dist[j]!=INF&& dist[nextNode] < dist[j]+nextDist){

                    prevNode[nextNode]=j;
                    dist[nextNode] = dist[j] + nextDist;
                    //사이클이 발생하고 사이클 노드에서 도착지점에 도달할 수 있다면
                    if (i == N - 1&& visited[nextNode])
                    {
                        minusCycle = true;
                    }
                }
            }
        }
    }

    if (minusCycle)
    {
        cout<<-1;
        return 0;
    }

    //역순 설정되어 있는 prevNode를 다시 원래대로 출력하기 위함
    int cur=N-1;
    vector<int> v;
    while(cur!=0){
        v.push_back(cur);
        cur=prevNode[cur];
    }
    cout<<1<<" ";
    for(int i=v.size()-1;i>=0;i--)
    //0번부터 저장되서 1씩 더해서 출력
    cout<<v[i]+1<<" ";
}

