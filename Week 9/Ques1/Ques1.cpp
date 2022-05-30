#include<bits/stdc++.h>
using namespace std;
const int N = 6;
int dist[N][N];

void floyd() {
    for(int k = 1; k < N; k++) {
        for(int i = 1; i < N; i++) {
            for(int j = 1; j < N; j++) {
                int val = (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) ? INT_MAX : dist[i][k] + dist[k][j];
                dist[i][j] = min(dist[i][j], val);  
            }
        }
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            if(dist[i][j] == INT_MAX) 
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < n; i++) {
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
        dist[v1][v2] = wt;
    }
    floyd();
}