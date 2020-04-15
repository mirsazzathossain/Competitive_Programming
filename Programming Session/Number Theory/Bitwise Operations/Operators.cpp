#include<bits/stdc++.h>

using namespace std;

// Left Shift
// Find (N / P) where P is (2^x) some power of two
int divide(int number, int x){
    return number >> x;
}

// Right Shift
// Find (N * P) where P is (2^x) some power of two
int multiply(int number, int x){
    return number << x;
}

// Find (N % P) where P is (2^x) some power of two
int modulo(int number, int P){
    return number & P-1;
}

// Logical AND
int AND(int a, int b){
    return a & b;
}

// Logical OR
int OR(int a, int b){
    return a | b;
}

// Logical XOR
int XOR(int a, int b){
    return a ^ b;
}

// Logical NOT
int NOT(int a){
    return ~a;
}

int main(){

    int a = 35, b = 7, x = 3, p = 8;

    cout<<divide(a, x)<<endl;
    cout<<multiply(a, x)<<endl;
    cout<<modulo(a, p)<<endl;
    cout<<AND(a, b)<<endl;
    cout<<OR(a, b)<<endl;
    cout<<XOR(a, b)<<endl;
    cout<<NOT(a)<<endl;

    return 0;
}