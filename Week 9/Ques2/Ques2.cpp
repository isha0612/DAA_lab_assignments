#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    int val1 = a.second/ a.first;
    int val2 =  b.second/ b.first;
    return val1 > val2;
}

int main() {
    vector<pair<int, int>> fk;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin>>w>>v;
        fk.push_back({w, v});
    }
    int weight; cin>>weight;
    sort(fk.begin(), fk.end(), cmp);
    int currWeight = 0;
    double ans = 0.0;
    for(int i = 0; i < n; i++) {
        if(currWeight + fk[i].first <= weight) {
            currWeight += fk[i].first;
            ans += fk[i].second;
        }
        else {
            int remain = weight - currWeight;
           ans += (fk[i].second / (double(fk[i].first))) * double(remain);   
           break;
        }
    }
    cout<<ans;
}