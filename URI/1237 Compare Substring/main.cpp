#include<bits/stdc++.h>

using namespace std;

string s1, s2;


int lcs(int m, int n, int cnt){

    if(m == 0 || n == 0) return cnt;

    if(s1[m-1] == s2[n-1]) cnt = lcs(m-1, n-1, cnt+1);

    cnt = max(cnt, max(lcs(m, n-1, 0), lcs(m-1, n, 0)));

    return cnt;
}


int main(){

    while(getline(cin, s1)){
        getline(cin, s2);

        cout<<lcs(s1.length(), s2.length(), 0)<<endl;
    }

    return 0;
}