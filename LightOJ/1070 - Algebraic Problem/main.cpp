#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<ull> OneD;
typedef vector<vector<ull>> TwoD;
ull mod = 1ULL << 63;

TwoD multiply(TwoD x, TwoD y){
    TwoD temp;
    temp.resize(x.size(), OneD(y[0].size(), 0));

    for(int i=0; i<x.size(); i++){
        for(int j=0; j<y[0].size(); j++){
            for(int k=0; k<x[0].size(); k++){
                temp[i][j] += (x[i][k]*y[k][j]);
            }
        }
    }
    return temp;
}

TwoD power(TwoD a, ull exp){  

    TwoD temp;
    temp.resize(a.size(), OneD(a[0].size(), 0));
    for(int i=0; i<a.size(); i++) temp[i][i]=1;

    TwoD power=a;
    while(exp){
        if(exp%2==1) temp=multiply(temp, power);
        power = multiply(power, power);
        exp/=2;
    }

    return temp;                             
}

ull fib(ull n, ull p, ull q){
    TwoD temp = power({{p, -q}, {1, 0}}, n-1);
    return ((temp[0][0]*p) + (temp[0][1]*2));
}

int main(){
    int t;
    ull n, p, q;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>p>>q>>n;
        if(n==0){
            cout<<"Case "<<i<<": "<<2<<endl;
            continue;
        }

        cout<<"Case "<<i<<": "<<fib(n, p, q)<<endl;
    }

    return 0;
}