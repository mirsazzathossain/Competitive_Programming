#include<bits/stdc++.h>

using namespace std;

int mark[1000002];

void sieve(int n){
    int limit = sqrt(n);

    mark[1] = 1;

    for(int i=4; i<=n; i+=2) mark[i] = 1;

    for(int i=3; i<=limit; i+=2){
        if(!mark[i]){
            for(int j=i*i; j<=n; j+=i*2) mark[j] = 1;
        }
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //fstream fin("input.txt");
    //ofstream fout("output.txt");

    sieve(1000001);
    int t, x;
    cin>>t;

    while(t--){
        cin>>x;

        if(!mark[x]) cout<<x<<" is a prime number."<<endl;
        else cout<<x<<" is not a prime number."<<endl;
    }

    return 0;
}