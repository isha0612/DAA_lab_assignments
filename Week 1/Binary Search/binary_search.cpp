#include <iostream>
using namespace std;
int main() {
    fstream input, output;
    input.open("binary_search_input.txt");
    output.open("binary_search_output.txt");
    if(!input) {
        cout<<"File not found";
        exit(0);
    }
    int t;
    input>>t;
    while(t--) {
        int n, key;
        input>>n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            input>>arr[i];
        }
        input>>key;
        
    }
}