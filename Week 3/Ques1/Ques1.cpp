#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    int c = 0, s = 0;
    for(int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = arr[i];
        while(j >= 0 && temp < arr[j]) {
            c++;
            s++;
            arr[j + 1] = arr[j];
            j--;
        }
        s++;
        arr[j + 1] = temp;
    }
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"comparsions = "<<c<<endl;
    cout<<"shifts = "<<s<<endl;
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
        insertionSort(arr, n);
    }
}