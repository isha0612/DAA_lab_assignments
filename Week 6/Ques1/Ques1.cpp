#include <bits/stdc++.h>
using namespace std;
const int N = 6;
vector<int> graph[N];
vector<bool> visited(N);

bool dfs(int source, int destination) {
    if(source == destination) return true;
    visited[source] = true;
    for(auto child : graph[source]) {
        if(!visited[child]) {
            visited[child] = true;
            bool ans = dfs(child, destination);
            if(ans) return ans;
        }
    }
    return false;
}

int main() {
    int m;
    cin>>m;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i = 1; i <= 5; i++) {
        cout<<i<<"->";
        for(auto x : graph[i]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    int source, destination;
    cin>>source>>destination;
    if(dfs(source, destination)) 
       cout<<"Yes path exists";
    else
       cout<<"No path exits";
}