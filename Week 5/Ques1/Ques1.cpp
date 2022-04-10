#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<char> arr(n);
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        vector<int> res(26, 0);
        for(int i = 0; i < n; i++) {
            res[arr[i] - 'a'] += 1;
        }
        int max = 1;
        char c = '\0';
        for(int i = 0; i < 26; i++) {
            if(res[i] > max) {
                max = res[i];
                c = i + 'a';
            }
        }
        if(max != 1) {
            cout<<c<<" - "<<max<<endl;
        }
        else {
            cout<<"No duplicates found"<<endl;
        }
    }
}