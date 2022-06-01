#include<bits/stdc++.h>
using namespace std;
const int N = 7;
vector<pair<int, int>> graph[N];

int prim(int source) {
    vector<bool> vis(N, 0);
    set<pair<int, int>> s;
    s.insert({0, source});
    int ans = 0;
    while(!s.empty()) {
        auto node = *s.begin();
        s.erase(s.begin());
        int v = node.second;
        int wt = node.first;
        if(vis[v]) continue;
        ans += wt;
        vis[v] = 1;
        for(auto child : graph[v]) {
            int child_v = child.first;
            int child_wt = child.second;
            if(!vis[child_v]) {
                s.insert({child_wt, child_v});
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2, wt});
        graph[v2].push_back({v1, wt});
    }
    int source;
    cin>>source;
    cout<<"Minimum spanning tree weight : "<<prim(source);
}