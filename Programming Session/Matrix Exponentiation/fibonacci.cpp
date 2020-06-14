#include<bits/stdc++.h>

using namespace std;

typedef vector<int> OneD;
typedef vector<vector<int>> TwoD;

TwoD multiply(TwoD x, TwoD y){
    TwoD temp;
    temp.resize(2);
    temp[0].resize(2);
    temp[1].resize(2);

    //Multiply
    temp[0][0] = (x[0][0]*y[0][0])+(x[0][1]*y[1][0]);
    temp[0][1] = (x[0][0]*y[0][1])+(x[0][1]*y[1][1]);
    temp[1][0] = (y[0][0]*x[1][0])+(y[1][0]*x[1][1]);
    temp[1][1] = (y[0][1]*x[1][0])+(x[1][1]*y[1][1]);

    return temp;
}


TwoD multiply_dynamic(TwoD x, TwoD y){
    TwoD temp;

    //matrix.resize(row_count, vector<int>(column_count, initialization_value ))
    temp.resize(x.size(), OneD(y[0].size(), 0));

    for(int i=0; i<x.size(); i++){
        for(int j=0; j<y[0].size(); j++){
            for(int k=0; k<x[0].size(); k++){
                temp[i][j] += x[i][k]*y[k][j];
            }
        }
    }

    return temp;
}

TwoD power(TwoD x, int exp){
    if(exp==1) return x;

    TwoD temp = power(x, exp/2);
    temp = multiply_dynamic(temp, temp);

    if(exp%2==1) temp = multiply_dynamic(temp, x);
    return temp;
}

int fib(int n){
    if(n==0 || n==1) return n;

    TwoD a = {{1,1},{1,0}};
    TwoD rslt = power(a, n-1);

    return (rslt[0][0]);
}


int main(){

    
    int n;
    while(true){
        cin>>n;
        cout<<fib(n)<<endl;
    }



    return 0;
}