#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> OneD;
typedef vector<vector<lli>> TwoD;

int mod = 10007;

TwoD multiply(TwoD x, TwoD y){
    TwoD temp;
    temp.resize(x.size(), OneD(y[0].size(), 0));

    for(int i=0; i<x.size(); i++){
        for(int j=0; j<y[0].size(); j++){
            for(int k=0; k<x[0].size(); k++){
                temp[i][j] += (x[i][k]*y[k][j])%mod;
            }
        }
    }
    return temp;
}

TwoD power(TwoD a, lli exp){
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

int fib(lli n, int a, int b, int c){
    TwoD temp = power({{a, 0, b, 1}, 
                       {1, 0, 0, 0},
                       {0, 1, 0, 0},
                       {0, 0, 0, 1}}, n-2);
    return (temp[0][3]*c)%mod;
}

int main(){
    int t, a, b, c;
    lli n;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>n>>a>>b>>c;
        cout<<"Case "<<i<<": "<<fib(n, a, b, c)<<endl;
    }

    return 0;
}