#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    multiset<pair<int,int>> s;
    vector<int> v1(n);
    vector<int> v2(n);
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>v2[i];
    }
    for(int i = 0; i < n; i++) {
        s.insert({v1[i], 1});
        s.insert({v2[i], -1});
        ans.push_back(i + 1);
        int t = 0;
        for(auto it : s) {
            t += it.second;
            if(t > 1) {
                s.erase(s.find({v1[i], 1}));
                s.erase(s.find({v2[i], -1}));
                ans.pop_back();
                break;
            }
        }
    }
    cout<<"No. of non-conflicting activities: "<<ans.size()<<endl;
    cout<<"List of selected activities: ";
    for(auto it : ans)
        cout<<it<<" ";
}