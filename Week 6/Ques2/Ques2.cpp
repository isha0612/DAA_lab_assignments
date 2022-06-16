#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<int> g[], int color[], int src) {
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        for(auto it : g[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node])
               return false;
        }
    }
    return true;
}

bool isBipartite(vector<int> g[], int n) {
    int color[n];
    memset(color, -1, sizeof(color));
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            if(!bfs(g, color, i))
              return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> g[n];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(isBipartite(g, n))
       cout<<"Yes Bipartite";
    else
       cout<<"Not Bipartite";
}