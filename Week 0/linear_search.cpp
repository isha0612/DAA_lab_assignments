#include <iostream>
#include <fstream>
using namespace std;
int main() {
    fstream input, output;
    input.open("linear_search_input.txt");
    output.open("linear_search_output.txt");
    if(!input) {
        cout<<"Can't open file";
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
        int j;
        for(j = 0; j < n; j++) {
            if(arr[j] == key) {
                output<<"Present "<<j+1<<'\n';
                break;
            }
        }
        if(j == n) {
            output<<"Not Present "<<j<<"\n";
        }
    }

}