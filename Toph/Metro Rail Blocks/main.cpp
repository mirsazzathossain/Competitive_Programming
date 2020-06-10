#include<bits/stdc++.h>

using namespace std;

int arr[1000001];
int current = -1;

int main(){
    int n, a;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a;
        arr[a-1] = 1;

        while (arr[current+1] != 0){
            current++;
        }
        cout<<current+1<<endl;
    }

    return 0;
}