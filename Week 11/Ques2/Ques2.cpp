#include<bits/stdc++.h>
using namespace std;

void search(vector<vector<int>> &ans, vector<int> &temp, int target, int idx, vector<int> &arr) {
    if(target < 0)
        return;
    if(target == 0) {
        ans.push_back(temp);
        return;
    }
    for(int i = idx; i < arr.size(); i++) {
        temp.push_back(arr[i]);
        search(ans, temp, target - arr[i], i, arr);
        temp.pop_back();
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
       cin>>arr[i];
    int target;
    cin>>target;
    vector<vector<int>> ans;
    vector<int> temp;
    search(ans, temp, target, 0, arr);
    cout<<ans.size();
}