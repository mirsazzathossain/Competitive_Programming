#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> OneD;
typedef vector<vector<lli>> TwoD;



TwoD multiply(TwoD x, TwoD y, lli mod){
    TwoD temp;
    temp.resize(x.size(), OneD(y[0].size(), 0));

    for(int i=0; i<x.size(); i++){
        for(int j=0; j<y[0].size(); j++){
            temp[i][j] = 0;
            for(int k=0; k<x[0].size(); k++){
                temp[i][j] += x[i][k]*y[k][j]%mod;
            }
        }
    }

    return temp;
}

TwoD power(TwoD x, lli exp, lli mod){
    if(exp==1) return x;

    TwoD temp = power(x, exp/2, mod);
    temp = multiply(temp, temp, mod);

    if(exp%2==1) temp = multiply(temp, x, mod);
    return temp;
}

lli fib(lli n, lli mod){
    if(n==0 || n==1) return n;

    TwoD a = {{1,1},{1,0}};
    TwoD rslt = power(a, n-1, mod);

    return rslt[0][0]%mod;
}

lli power_two(int exp){
    if(exp==0) return 1;

    lli temp = power_two(exp/2);
    temp = temp*temp;

    if(exp%2==1) temp = temp*2;

    return temp;
}


int main(){

    
    lli a, b;

    while(cin>>a>>b){
        cout<<fib(a, power_two(b))<<endl;
    }

    return 0;
}