#include<iostream>
#include<vector>
using namespace std;
const long long INF=1e18;
int main(){
    int N,M;
    long long dist[500];
    scanf("%d %d",&N,&M);
    vector<pair<int,int>> adj[500];
    for(int i=0;i<M;i++){
        int A,B,C;
        scanf("%d %d %d", &A,&B,&C);
        //index 
        adj[A-1].push_back(make_pair(B-1,C));
    }
    bool minusCycle = false;
    //도시마다 INF로 초기화
    fill(dist,dist+N,INF);
    dist[0]=0;
    //정점이 N개일때 각 간선은 한번씩만 돌게 되므로 루프는 N-1개만 돔, N인이유는 마지막에 싸이클 확인용 
    for(int i=0;i<N;i++){
        //N-1번 루프에 걸쳐서 각 정점이 i+1개의 정점을 거쳐오는 최단경로 갱신
        for(int j=0;j<N;j++){
            for(auto &p: adj[j]){
                int nextNode= p.first, nextDist=p.second;
                if(dist[j]!=INF && dist[nextNode]>dist[j]+nextDist){
                    dist[nextNode]=dist[j]+nextDist;
                    //마지막에 갱신되는건 싸이클 발생한것.(싸이클 발생해 최단거리가 더 내려가서 갱신된것이므로)
                    if(i==N-1) minusCycle=true;
                }          
            }
        }
    }
    if(minusCycle) cout<<-1;
    else
    for(int i=1;i<N;i++){
        printf("%lld\n",dist[i]!=INF ? dist[i]:-1);
    }
}
