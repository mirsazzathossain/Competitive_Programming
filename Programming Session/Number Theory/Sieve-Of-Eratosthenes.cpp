#include<bits/stdc++.h>


using namespace std;

int mark[1000002];

void sieve(int n){
    int limit = sqrt(n)+2;

    mark[1] = 1;
    for(int i=4; i<=n; i+=2) mark[i] = 1;

    for(int i=3; i<=limit; i+=2){
        if(!mark[i]){
            for(int j = i*i; j<=n; j += i*2){
                mark[j]=1;
            }
        }
    }
}

vector<int>prime;

void sieve_with_list(int n){
    int limit = sqrt(n)+2;

    mark[1] = 1;
    
    prime.push_back(2);

    for(int i=4; i<=n; i+=2) mark[i] = 1;

    for(int i=3; i<=n; i++){
        if(!mark[i]){
            prime.push_back(i);
            if(i<=limit){
                for(int j=i*i; j<=n; j+=i*2) mark[j] = 1; 
            }
        }
    }
}


int main(){
    sieve_with_list(100);

    for (int i = 0; i < prime.size(); i++){
        cout<<prime[i]<<endl;
    }
    

    return 0;
}