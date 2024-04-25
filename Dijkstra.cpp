#include<bits/stdc++.h>
using namespace std;

int n, m, b, e;
const int INF=1e9;
vector<pair<int,int>> v[1001];

void input(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> b >> e;
    for(int i=0;i<m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
}

void output(int k,int arr[]){
    if(k!=arr[k]) return output(arr[k],arr);
    cout << k << " ";
}

void Dijkstra(int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int path[n+1];
    bool check[n+1]={false};
    int trace[n+1]={0};
    fill(path+1,path+n+1,INF);
    trace[k]=k;
    q.push({0,k});
    while(!q.empty()){
        int u=q.top().second;
        int w=q.top().first;
        q.pop();
        if(check[u]) continue;
        else{
            check[u]=true;
            for(auto x : v[u]){
                if(w+x.second<path[x.first]){
                    trace[x.first]=u;
                    path[x.first]=w+x.second;
                    q.push({path[x.first],x.first});
                }
            }
        }
    }
    cout << path[e] << " ";
    output(e,trace);
}

int main(){
    input();
    Dijkstra(b);
}