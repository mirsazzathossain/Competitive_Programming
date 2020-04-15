#include<bits/stdc++.h>


using namespace std;

int mark[1000002];

void sieve(int n){
    mark[1] = 1;
    for(int i=4; i<=n; i+=2) mark[i] = 1;

    int limit = sqrt(n+1);

    for(int i=3; i<=limit; i+=2){
        if(!mark[i]){
            for(int j=i*i; j<=n; j += i*2) mark[j] = 1;
        }
    }
}

int main(){
    sieve(100);

    for(int i=1; i<=100; i++){
        if(!mark[i]) cout<<i<<endl;
    }

    return 0;
}