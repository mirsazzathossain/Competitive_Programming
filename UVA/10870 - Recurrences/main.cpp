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
                temp[i][j] = temp[i][j]%mod;
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

TwoD constract_M(OneD d){
    TwoD temp;
    temp.resize(d.size(), OneD(d.size(), 0));

    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp[0].size(); j++){
            if(i==0) temp[i][j] = d[j];
            else if(i-j == 1){
                temp[i][j] = 1;
            }
            else temp[i][j] = 0;
        }
    }

    return temp;
}

lli fib(lli n, lli mod, OneD d, OneD f){

    TwoD a = constract_M(d);
    TwoD rslt = power(a, n-d.size(), mod);

    lli ans = 0;

    for(int i=0; i<f.size(); i++){
        ans += (f[f.size()-i-1]*rslt[0][i])%mod;
        ans = ans%mod;
    }

    return ans;
}


int main(){
    lli d, n, m;
    while (true){
        cin>>d>>n>>m;
        if(d==0 && n==0 && m==0) break;

        OneD b, f;
        b.resize(d); f.resize(d);

        for(int i=0; i<d; i++){
            cin>>b[i];
        }

        for(int i=0; i<d; i++){
            cin>>f[i];
        }

        if(d>=n) cout<<f[n-1]%m<<endl;
        else cout<<fib(n, m, b, f)<<endl;
    }
    

    return 0;
}