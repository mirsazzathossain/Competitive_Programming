#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	
	int t,a,b;
    scanf("%d",&t);
    
    while(t--){
        scanf("%d%d",&a,&b);
        
        
        if(a>b) swap(a, b);
        
        int n = __gcd(a,b);
        
        int cnt = 0;
        
        for(int i=1; i<=sqrt(n); i++){
            if (n%i==0) { 
                if (n/i == i) 
                    cnt += 1; 
                else
                    cnt += 2; 
            }
        }
        
        printf("%d\n",cnt);
    }

	return 0;
}