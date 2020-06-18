#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> OneD;
typedef vector<vector<lli>> TwoD;



TwoD multiply(TwoD x, TwoD y, lli m){
    TwoD temp;
    temp.resize(x.size(), OneD(y[0].size(), 0));

    for(int i=0; i<x.size(); i++){
        for(int j=0; j<y[0].size(); j++){
            for(int k=0; k<x[0].size(); k++){
                temp[i][j] += (x[i][k]%m*y[k][j]%m)%m;
            }
            temp[i][j]%m;
        }
    }
    return temp;
}

TwoD power(TwoD a, lli exp, lli m){
    TwoD temp;
    temp.resize(a.size(), OneD(a[0].size(), 0));
    for(int i=0; i<a.size(); i++) temp[i][i]=1;

    TwoD power=a;
    while(exp){
        if(exp%2==1) temp=multiply(temp, power, m);
        power = multiply(power, power, m);
        exp/=2;
    }

    return temp;                             
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t, a[3], b[3], c[3], f[3], g[3], m, q, n;
    
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>a[1]>>b[1]>>c[1];
        cin>>a[2]>>b[2]>>c[2];
        cin>>f[0]>>f[1]>>f[2];
        cin>>g[0]>>g[1]>>g[2];
        cin>>m;
        cin>>q;
        TwoD M = {{a[1], b[1],  0,    0,    0,  c[1]},
                  { 1,    0,    0,    0,    0,   0  },
                  { 0,    1,    0,    0,    0,   0  },
                  { 0,    0,   c[2], a[2], b[2], 0  },
                  { 0,    0,    0,    1,    0,   0  },
                  { 0,    0,    0,    0,    1,   0  }};
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            cin>>n;
            if(n<=2){
                cout<<f[n]%m<<" "<<g[n]%m<<endl;
                continue;
            }
            TwoD rslt = power(M, n-2, m);
            cout<<((rslt[0][0]*f[2])%m+(rslt[0][1]*f[1])%m+(rslt[0][2]*f[0])%m+(rslt[0][3]*g[2])%m+(rslt[0][4]*g[1])%m+(rslt[0][5]*g[0])%m)%m<<" ";
            cout<<((rslt[3][0]*f[2])%m+(rslt[3][1]*f[1])%m+(rslt[3][2]*f[0])%m+(rslt[3][3]*g[2])%m+(rslt[3][4]*g[1])%m+(rslt[3][5]*g[0])%m)%m<<endl;
        }
    }

    return 0;
}