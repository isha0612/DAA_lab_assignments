#include<bits/stdc++.h>
using namespace std;
const int N = 6;
vector<pair<int, int>> graph[N];

void dijkstra(int source) {
    vector<bool> vis(N, 0);
    vector<int> dis(N, INT_MAX);
    dis[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while(!s.empty()) {
        auto node = *s.begin();
        s.erase(s.begin());
        int v = node.second;
        int wt = node.first;
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto child : graph[v]) {
            int child_v = child.first;
            int child_wt = child.second;
            if(dis[v] + child_wt < dis[child_v]) {
                dis[child_v] = dis[v] + child_wt;
                s.insert({dis[child_v], child_v});
            }
        }
    }
    for(int i = 1; i < dis.size(); i++) {
        cout<<i<<" : "<<dis[i]<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2, wt});
    }
    int source;
    cin>>source;
    dijkstra(source);
}