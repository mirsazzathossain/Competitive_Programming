#include<bits/stdc++.h>

using namespace std;

#define MAX 100000000
#define LIMIT 10000

int mark[(MAX>>5)+2];

#define Check(i) (mark[i>>5]&(1<<(i&31)))
#define Set(i) (mark[i>>5] |= (1<<(i&31)))

void sieve(int n){
    Set(1);
    for(int i=4; i<=n; i+=2) Set(i);

    int limit = sqrt(n+1);
    for(int i=3; i<=limit; i+=2){
        if(!Check(i)){
            for(int j = i*i; j<=n; j+=(i<<1)) Set(j);
        }
    }
}

//Some more optimization.
//Kepping only odd values 1 in 0th place 3 in 1th place and so on...
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

    optimized_sieve(MAX);
    prime_list(MAX);

    for(int i=0; i<prime.size(); i+=100) printf("%d\n", prime[i]);
    
    return 0;
}