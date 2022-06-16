#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ans;
    vector<pair<int, int>> as;
    int n; cin>>n;
    vector<int> v1(n), v2(n);
    for(int i = 0; i < n; i++) cin>>v1[i];
    for(int i = 0; i < n; i++) cin>>v2[i];
    for(int i = 0; i < n; i++) {
        as.push_back({v2[i], v1[i]});
    }
    sort(as.begin(), as.end());
    int curEnd = -1;
    for(int i = 0; i < n; i++) {
        if(as[i].second > curEnd) {
            ans.push_back(i + 1);
            curEnd = as[i].first;
        }
    }
    cout<<"No. of non-conflicting activities: "<<ans.size()<<endl;
    cout<<"List of selected activities: ";
    for(auto it : ans)
        cout<<it<<" ";
}
