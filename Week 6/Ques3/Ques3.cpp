#include <bits/stdc++.h>
using namespace std;
const int N = 6;
vector<int> graph[N];
vector<bool> vis(N, 0);
vector<bool> recS(N, 0);

bool dfs(int v) {
    vis[v] = true;
    recS[v] = true;
    for(auto child : graph[v]) {
        if(!vis[child]) {
            if(dfs(child)) 
              return true;
        }
        else if(recS[child])
           return true;
    }
    recS[v] = false;
    return false;
}

bool isCycle() {
    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            if(dfs(i))
               return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    }
    if(isCycle())
      cout<<"YES CYCLE EXISTS";
    else
      cout<<"NO CYCLE EXISTS";
}
