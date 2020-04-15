#include<bits/stdc++.h>


using namespace std;



int main(){

    //Cut bits from 3 to 9 bit position of A and from a new integer
    int A = 19881; //00000000 00000000 01001101 10101001
    int B = 0;     //00000000 00000000 00000000 00000000

    int number_of_one = (9-3)+1;
    for(int i=0; i<number_of_one; i++){
        B = (B << 1) | 1;
    }

    B = B << 3; //00000000 00000000 00000011 11111000
    B = A & B;  //00000000 00000000 00000001 10101000
    B = B >> 3; //00000000 00000000 00000000 00110101

    cout<<B<<endl;

    //Same bit pattern as A except it has all bits 0 within 4th to 23rd position.
    B = 0;
    for(int i=0; i<4; i++){
        B = (B << 1) | 1;
    }

    //B = 00000000 00000000 00000000 00001111
    B = A & B; //00000000 00000000 00000000 00001001
    cout<<B<<endl;

    //Same bit pattern as A except it has all bits 1 within 9th and 30th position.
    B = 0;

    number_of_one = (30-9)+1;
    for (int i = 0; i < number_of_one; i++){
        B = (B << 1) | 1;
    }

    B = B << 9; //01111111 11111111 11111111 00000000
    B = A | B;  //01111111 11111111 11111111 10101001

    cout<<B<<endl;

    //Same bit pattern as A except it has all bits inverted within positions 2nd and 20th.
    B = 0;
    number_of_one = (20-2)+1;
    for (int i = 0; i < number_of_one; i++){
        B = (B << 1) | 1;
    }

    B = B << 2; //00000000 00011111 11111111 11111100
    B = A ^ B;  //00000000 00011111 10110010 01010101

    cout<<B<<endl;

    //Totally inverted bit pattern.
    B = 0;

    for (int i = 0; i < 32; i++){
        B = (B << 1) | 1;
    }

    B = A ^ B;

    cout<<B<<endl;


    return 0;
}