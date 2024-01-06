#pragma region using BFS to get components and use bell-man Fords for each components
// #include<iostream>
// #include<vector>
// #include<queue>
// #include<set>
// #include<algorithm>

// using namespace std;
// //도로 저장용 도시 i,j사이 거리 k일때, adj[i]={j,k}
// vector<pair<int,int>> adj[501];
// //도시 컴퍼넌트를 구성하는 도시 원소들
// set<int> componentElem;
// //최단거리 
// long long dist[501];
// //방문 배열
// bool visited[501];
// long long INF=1e18;
// void Solution();

// //각 반복마다 초기화
// void Init(){
//     for(int i=0;i<501;i++){
//         adj[i].clear();
//     }
//     fill(dist,dist+501,INF);
//     fill(visited,visited+501,false);   
//     componentElem.clear();
// }

// //각 컴퍼넌트 순회해서 set에 구성요소 넣고 사이즈 반환 
// int BFS(int sN){
//     int size=0;
//     queue<int> q;
//     int cur=sN;
//     q.push(cur);
//     while(!q.empty()){
//         size++;
//         int cur = q.front();
//         componentElem.insert(cur);
//         q.pop();
//         for (auto &elem : adj[cur])
//         {
//             int nextNode=elem.first;
//             if (!visited[nextNode])
//             {
//                 visited[nextNode] = true;
//                 q.push(nextNode);
//             }
//         }
//     }
//     return size;
// }

// //테스트케이스 수 입력받고 그만큼 실행
// void Input(){
//     int N;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         Init();
//         Solution();
//     }

// }

// // 도시를 BFS함수를 통해 컴퍼넌트별로 나누고 모든 컴포넌트에 대해서 싸이클 체크
// void Solution(){

//     // 도시, 길, 웜홀 갯수
//     int N, M, W;
//     cin >> N >> M >> W;
//     // 시작도시, 끝도시, 걸리는 시간/ 줄어드는 시간
//     int S, E, T;
//     for (int i = 0; i < M; i++)
//     {
//         cin >> S >> E >> T;
//         // 양방향그래프
//         adj[S - 1].push_back(make_pair(E - 1, T));
//         adj[E - 1].push_back(make_pair(S - 1, T));
//     }
//     // 웜홀일 때, 감소하므로 -T
//     for (int i = 0; i < W; i++)
//     {
//         cin >> S >> E >> T;
//         adj[S - 1].push_back(make_pair(E - 1, -T));
//     }

//     //도시 컴퍼넌트마다 벨만포드 돌려야하므로 모든 도시에 대해서 반복
//     for (int i = 0; i < N; i++)
//     {
//         //visited[i]가 true이면 방문한 도시이다. 이미 조사한 컴퍼넌트에 속한 도시이므로 continue
//         if (visited[i]) continue;
//         //현재 컴퍼넌트의 원소들 받아올 set 초기화
//         componentElem.clear();

//         int startNode = i;
//         //시작 도시 방문배열이랑 dist 0으로 초기화
//         visited[startNode]=true;
//         dist[startNode]=0;
//         //BFS함수를 통해 현재 컴퍼넌트의 원소들 set에 insert한 후, 순회한 원소들 visited true로 체크함
//         int comSize=BFS(startNode);

//         // 싸이클 여부 확인용 변수
//         bool minusCycle = false;

//         // cycle 체킹용으로 N+1번 루프 (웜홀로 인해 다른 컴퍼넌트에 영향미칠 수도 있으므로 한번 더 체크 해야함)
//         for (int i = 0; i < comSize+1; i++)
//         {
//             //컴퍼넌트의 노드 거쳤을 때의 최단경로 갱신
//             for (auto iter=componentElem.begin();iter!=componentElem.end();++iter)
//             {
//                 //각 원소와 연결된 도시들에 대해 벨만포드 진행
//                 for (auto &elem : adj[*iter])
//                 {
//                     int nextNode = elem.first, nextDist = elem.second;
//                     if (dist[*iter]!=INF && dist[nextNode] > dist[*iter] + nextDist)
//                     {
//                         dist[nextNode] = dist[*iter] + nextDist;
//                         if (i == comSize )
//                             minusCycle = true;
//                     }
//                 }
//             }
//         }
//         //싸이클 생기면 YES 출력
//         if (minusCycle)
//         {
//             cout << "YES\n";
//             return;
//         }
//     }
//     cout << "NO\n";
// }

// int main()
// {
//     Input();
// }
#pragma endregion

#pragma region using virtual City to check Cycle in all components
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;
//도로 저장용 도시 i,j사이 거리 k일때, adj[i]={j,k}
vector<pair<int,int>> adj[501];
//최단거리 
long long dist[501];

long long INF=1e18;
void Solution();

//각 반복마다 초기화
void Init(){
    for(int i=0;i<501;i++){
        adj[i].clear();
    }
    fill(dist,dist+501,INF);
}

//테스트케이스 수 입력받고 그만큼 실행
void Input(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        Init();
        Solution();
    }

}

// 도시를 BFS함수를 통해 컴퍼넌트별로 나누고 모든 컴포넌트에 대해서 싸이클 체크
void Solution(){

    // 도시, 길, 웜홀 갯수
    int N, M, W;
    cin >> N >> M >> W;
    // 시작도시, 끝도시, 걸리는 시간/ 줄어드는 시간
    int S, E, T;
    for (int i = 0; i < M; i++)
    {
        cin >> S >> E >> T;
        // 양방향그래프
        adj[S - 1].push_back(make_pair(E - 1, T));
        adj[E - 1].push_back(make_pair(S - 1, T));
    }
    // 웜홀일 때, 감소하므로 -T
    for (int i = 0; i < W; i++)
    {
        cin >> S >> E >> T;
        adj[S - 1].push_back(make_pair(E - 1, -T));
    }

    //가상의 N번째 도시를 생성 후, 모든 도시에 단방향 간선을 이음(비용은 0이든 1이든 상관없음)
    for(int i=0;i<N;i++){
        adj[N].push_back(make_pair(i,1));
    }
    
    //N번째 도시부터 시작
    dist[N]=0;
    bool isCycle=false;
    //벨만포드 적용
    for(int  i=0; i<N+1;i++){
        for(int j=0;j<N+1;j++){
            for(auto& elem : adj[j]){
                int nextNode=elem.first,nextDist=elem.second;
                if(dist[j]!=INF&& dist[nextNode] > dist[j]+nextDist){
                    dist[nextNode]=dist[j]+nextDist;
                    if(i==N) isCycle=true;
                }
            }
        }
    }
    if(isCycle) cout<<"YES\n";
    else cout << "NO\n";
}

int main()
{
    Input();
}
#pragma endregion