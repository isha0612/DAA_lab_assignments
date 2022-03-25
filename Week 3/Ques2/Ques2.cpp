#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    int small, s = 0, c = 0;
    for(int i = 0; i < n - 1; i++) {
        small = i;
        for(int j = i + 1; j < n; j++) {
            c++;
            if(arr[i] > arr[j]) {
                small = j;
            }
        }
        s++;
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
    for(int i = 0; i < n; i++) 
      cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"comparsions = "<<c<<endl;
    cout<<"swaps = "<<s<<endl;
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
        selectionSort(arr, n);
    }
}