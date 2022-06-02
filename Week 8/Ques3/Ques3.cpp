#include<bits/stdc++.h>
using namespace std;
const int N = 7;
int parent[N], Rank[N];
vector<pair<int, pair<int, int>>> graph; 

void make(int v) {
    parent[v] = v;
    Rank[v] = 0;
}

int find(int v) {
    if(parent[v] == v)
       return parent[v];
    return find(parent[v]);
}

void Union(int x, int y) {
    int a = find(x), b = find(y);
    if(a == b) 
        return;
    if(Rank[a] < Rank[b])
      parent[a] = b;
    else if(Rank[a] > Rank[b])
      parent[b] = a;
    else {
        parent[b] = a;
        Rank[a] += 1;
    }
}

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
        graph.push_back({wt, {v1, v2}});
    }
    for(int i = 0; i < N; i++) {
        make(i);
    }
    sort(graph.begin(), graph.end(), greater<pair<int, pair<int, int>>>());
    int ans = 0;
    for(auto it : graph) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(find(u) == find(v)) continue;
        Union(u, v);
        ans += wt;
    }
    cout<<"Maximum spanning tree weight : "<<ans;
}