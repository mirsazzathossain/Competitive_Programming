#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> OneD;
typedef vector<vector<lli>> TwoD;

TwoD multiply(TwoD x, TwoD y, int m){
    TwoD temp;
    temp.resize(x.size(), OneD(y[0].size(), 0));

    for(int i=0; i<x.size(); i++){
        for(int j=0; j<y[0].size(); j++){
            for(int k=0; k<x[0].size(); k++){
                temp[i][j] += (x[i][k]*y[k][j])%m;
            }
        }
    }
    return temp;
}

TwoD power(TwoD a, lli exp, int m){
    if(exp==1) return a;

    TwoD temp = power(a, exp/2, m);
    temp = multiply(temp, temp, m);

    if(exp%2==1) temp = multiply(temp, a, m);

    return temp;
}

int fib(lli n, int a, int b, int m){
    TwoD temp = power({{1, 1}, {1, 0}}, n-1, m);
    return ((temp[0][0]*b)%m + (temp[0][1]*a)%m)%m;
}

int main(){
    int t, a, b, m, c;
    lli n;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>a>>b>>n>>m;
        c=1;
        for(int i=0; i<m; i++) c*=10;
        cout<<"Case "<<i<<": "<<fib(n, a, b, c)<<endl;
    }

    return 0;
}