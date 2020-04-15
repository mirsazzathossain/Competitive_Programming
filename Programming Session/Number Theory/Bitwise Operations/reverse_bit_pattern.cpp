#include<bits/stdc++.h>

using namespace std;

// O(N)
int reverse_simple(int number){
    int reversed_int = 0;

    for(int i=0; i<32; i++){
        if(number & (1 << i)){
            reversed_int = reversed_int | (1 << (31 - i));
        }
    }

    return reversed_int;
}

// O(log N)
int reverse_standard(int number){
    int reversed_int = number, count = sizeof(number) * 8 - 1;
    
    number = number >> 1;
    while(number){
        reversed_int = reversed_int << 1;
        reversed_int = reversed_int | (number & 1);
        number = number >> 1;
        count--;
    }

    reversed_int = reversed_int << count;
    return reversed_int;
}

// O(1)
/* Wee can generate look up table using functions above.
    0 reverse is 0
    1 reverse is 128
    2 reverse is 64
    3 reverse is 192
    4 reverse is 32
    5 reverse is 160
    .
    .
    .
    250 reverse is 95
    251 reverse is 223
    252 reverse is 63
    253 reverse is 191
    254 reverse is 127
    255 reverse is 255

    int is 32 bit so (2^32 - 1) which is very large number
    for a Look up table. So we will split 32 bits into four
    8 bits and find the inverse of those 8 bits using table.
    And then stack them together. Now (2^8 - 1) = 255 we can 
    make it easily. (00000000)2 = (0)10 and (11111111) = (255)10 
    so the range is 0 - 255.

    We will use macro to generate the table.
*/

// macros to generate the lookup table (at compile-time)
#define R2(n) n,	 n + 2*64,	 n + 1*64,	 n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
#define REVERSE_BITS R6(0), R6(2), R6(1), R6(3)

// lookup-table to store the reverse of each index of the table
// The macro REVERSE_BITS generates the table
unsigned int lookup[256] = { REVERSE_BITS };

// Function to reverse bits of n
int reverse(int n){

	// assuming 32-bit(4 byte) integer, break the integer into 8-bit chunks
	// Note mask used 0xff is 11111111 in binary

	// Split, Reverse and Rearrange each chunk

	int reverse = lookup[n & 0xff] << 24 |  // consider first 8 bits
		lookup[(n >>  8) & 0xff] << 16 |	// consider next 8 bits
		lookup[(n >> 16) & 0xff] << 8 | 	// consider next 8 bits
		lookup[(n >> 24) & 0xff];   		// consider last 8 bits

	return reverse;
}


int main(){

    int n = 1691315356;
 
	cout << n << " in binary is " << bitset<32>(n) << endl;
	cout << "On reversing bits " << bitset<32>(reverse(n)) << endl;

    return 0;
}