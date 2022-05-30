#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, c = 0, mxC = 0, i;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
       cin>>v[i];
    int median = v[n/2];
    sort(v.begin(), v.end());
    for(i = 0; i < n - 1; i++) {
        if(v[i] == v[i + 1])
           c++;
        else {
            mxC = max(mxC, c);
            c = 0;
        }
    }
    if(v[i] == v[i - 1])
        mxC++;
    if(mxC > (n / 2))
       cout<<"Yes";
    else 
       cout<<"No";
    cout<<endl<<median;
}