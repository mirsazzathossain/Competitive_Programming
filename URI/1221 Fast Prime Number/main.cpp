#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bigMod(ll base, int power, ll number){
    if(power == 0) return 1;

    ll x = bigMod(base, (power>>1), number)%number;
    x = (x * x) % number;

    if(power & 1) x = ((base % number) * x) % number;

    return x;
}

bool millerRabin(int d, int r, ll number){
    //Generating random number from 2 to number-2
    ll a = 2 + rand() % (number-4);
    
    //phi = (2^r) * d
    //For 1st iteration r = 0
    ll exp = bigMod(a, d, number);

    //If 1st term of a^(2^i)*d [where i = 0, 1, ... r-1] is 1 or -1 
    //finaly we will get 1 so it probably can be a prime
    if(exp == 1 || exp == number - 1){
        return true;
    }

    for(int i=1; i<r; i++){
        exp = (exp*exp) % number;

        //Previous terms was not 1 or -1 but square root of unity is
        //1 so number can't be prime
        //For prime x^2 % p = 1 if and only if x = 1 or -1
        if(exp == 1) return false;

        //This term is -1 so next term surely will be 1
        //Thus number probably be a prime
        if(exp == number-1) return true;
    }


    //Did not follwed any of the previous rules so it must be a composite
    return false;
}


bool isPrime(ll number){
    //Define results for 1 to 4
    if(number <= 1 || number == 4) return false;
    if(number <= 3) return true;

    //Only consider odd number
    if(number > 2 && ((number & 1) == 0)) return false;

    //(p-1) = (2^r)*d
    int d = number - 1;
    int r = 0;
    while((d & 1) == 0){
        d = d >> 1;
        r++;
    }

    //Iterating 20 times
    for(int i=0; i<20; i++){
        if(!millerRabin(d, r, number)) return false;
    }

    return true;
}





int main()
{

    int t;
    cin>>t;
    ll a;
    for(int i=0; i<t; i++){
        cin>>a;
        
       if(isPrime(a)){
            cout<<"Prime"<<endl;
        }
        
        else{
            cout<<"Not Prime"<<endl;
        }
        
    }

    return 0;
}
