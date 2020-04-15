#include<bits/stdc++.h>

using namespace std;

#define MAX 100000000
#define LIMIT 10000

int flag[MAX>>6];

#define ifc(i) (flag[i>>6]&(1<<((i>>1)&31)))
#define isc(i) (flag[i>>6]|=(1<<((i>>1)&31)))

void optimized_sieve(int n){
    isc(1);

    int limit = sqrt(n+1);
    for(int i=3; i<=limit; i+=2){
        if(!ifc(i)){
            for(int j=i*i; j<=n; j+=(i<<1)) isc(j);
        }
    }
}

vector<int>prime;
void prime_list(int n){
    prime.push_back(2);

    for(int i=3; i<=n; i+=2){
        if(!ifc(i)) prime.push_back(i);
    } 
}

int main(){
    //fstream fin("input.txt");
    //ofstream fout("output.txt");

    optimized_sieve(MAX);
    prime_list(MAX);

    for(int i=0; i<prime.size(); i+=100) printf("%d\n", prime[i]);
    
    return 0;
}