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
        int key;
        cin>>key;
        sort(arr, arr + n);
        vector<int> sol;
        int i = 0, j = n - 1;
        while(i < j) {
            if(arr[i] + arr[j] == key) {
                sol.push_back(arr[i]);
                sol.push_back(arr[j]);
                break;
            }
            if(arr[i] + arr[j] > key) j--;
            else i++;
        }
        if(sol.empty())
          cout<<"No such element exist";
        else {
            for(auto it : sol) 
               cout<<it<<" ";
        }
        cout<<endl;
    }
}

