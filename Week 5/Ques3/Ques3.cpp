#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin>>m;
    int a1[m];
    for(int i = 0; i < m; i++)
       cin>>a1[i];
    int n;
    cin>>n;
    int a2[n];
    for(int i = 0; i < n; i++)
       cin>>a2[i];
    int i = 0, j = 0;
    while(i < m && j < n) {
        if(a1[i] == a2[j]) {
            cout<<a1[i]<<" ";
            i++; j++;
        }
        else if(a1[i] < a2[j]) i++;
        else j++;
    }
}