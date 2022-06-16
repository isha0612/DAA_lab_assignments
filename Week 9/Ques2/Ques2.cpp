#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    double val1 = (double)a.second/ a.first;
    double val2 = (double)b.second/ b.first;
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
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(fk[i].first <= weight) {
            weight -= fk[i].first;
            ans += fk[i].second;
        }
        else {
            ans += ((double)fk[i].second / fk[i].first) * weight;
            break;
        }
    }
    cout<<ans;
}