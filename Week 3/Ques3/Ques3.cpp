#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++)
          cin>>arr[i];
        sort(arr, arr + n);
        int i;
        while(i < n - 1) {
            if(arr[i] == arr[i + 1]) {
                cout<<"YES"<<endl;
                break;
            }
            i++;
        }
        if(i == n - 1) cout<<"NO"<<endl;
    }
}