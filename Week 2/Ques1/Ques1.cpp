#include <bits/stdc++.h>
using namespace std;

void findDuplicates(int arr[], int n, int key) {
    int l = 0, h = n - 1, mid;
    bool flag = 0;
    while(l <= h) {
        mid = (l + h) / 2;
        if(arr[mid] == key) {
            flag = 1;
            break;
        }
        else if(arr[mid] > key) h = mid - 1;
        else l = mid + 1;
    }
    if(flag) {
        int i = mid - 1, j = mid + 1;
        int c = 1;
        while(i >= 0) {
            if(arr[i] != key) break;
            c++; i--;
        }
        while(j < n) {
            if(arr[j] != key) break;
            c++; j++;
        }
        cout<<arr[mid]<<" - "<<c<<endl;
    }
    else cout<<"Key not present"<<endl;
}

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
        findDuplicates(arr, n, key);
    }
}