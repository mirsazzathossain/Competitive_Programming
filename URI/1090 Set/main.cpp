#include<bits/stdc++.h>

using namespace std;

int two(int circle[3], int square[3], int tri[3]){
    int cnt = 0;

    int mn = circle[0]/3; circle[0] %= 3; cnt += mn;
    mn = circle[1]/3; circle[1] %= 3; cnt += mn;
    mn = circle[2]/3; circle[2] %= 3; cnt += mn;

    mn = square[0]/3; square[0] %= 3; cnt += mn;
    mn = square[1]/3; square[1] %= 3; cnt += mn;
    mn = square[2]/3; square[2] %= 3; cnt += mn;

    mn = tri[0]/3; tri[0] %= 3; cnt += mn;
    mn = tri[1]/3; tri[1] %= 3; cnt += mn;
    mn = tri[2]/3; tri[2] %= 3; cnt += mn;

    return cnt;
}

int one(int circle[3], int square[3], int tri[3]){
    int cnt = 0;

    int mn = min(min(circle[0], circle[1]), circle[2]);
    circle[0] -= mn; circle[1] -= mn; circle[2] -= mn;
    cnt += mn;

    mn = min(min(tri[0], tri[1]), tri[2]);
    tri[0] -= mn; tri[1] -= mn; tri[2] -= mn;
    cnt += mn;

    mn = min(min(square[0], square[1]), square[2]);
    square[0] -= mn; square[1] -= mn; square[2] -= mn;
    cnt += mn;

    return cnt;
}

int three(int circle[3], int square[3], int tri[3]){
    int cnt = 0;

    int mn = min(min(circle[0], square[0]), tri[0]);
    circle[0] -= mn; square[0] -= mn; tri[0] -= mn;
    cnt += mn;

    mn = min(min(circle[1], square[1]), tri[1]);
    circle[1] -= mn; square[1] -= mn; tri[1] -= mn;
    cnt += mn;

    mn = min(min(circle[2], square[2]), tri[2]);
    circle[2] -= mn; square[2] -= mn; tri[2] -= mn;
    cnt += mn;

    return cnt;
}

int four(int circle[3], int square[3], int tri[3]){
    int cnt = 0;

    int mn = min(min(circle[0], square[1]), tri[2]);
    circle[0] -= mn; square[1] -= mn; tri[2] -= mn;
    cnt += mn;

    mn = min(min(circle[0], square[2]), tri[1]);
    circle[0] -= mn; square[2] -= mn; tri[1] -= mn;
    cnt += mn;

    mn = min(min(circle[1], square[0]), tri[2]);
    circle[1] -= mn; square[0] -= mn; tri[2] -= mn;
    cnt += mn;

    mn = min(min(circle[1], square[2]), tri[0]);
    circle[1] -= mn; square[2] -= mn; tri[0] -= mn;
    cnt += mn;

    mn = min(min(circle[2], square[1]), tri[0]);
    circle[2] -= mn; square[1] -= mn; tri[0] -= mn;
    cnt += mn;


    mn = min(min(circle[2], square[0]), tri[1]);
    circle[2] -= mn; square[0] -= mn; tri[1] -= mn;
    cnt += mn;

    return cnt;
}

string permute[24] = {"1234", "1243", "1324", "1342", "1423",
                      "1432", "2134", "2143", "2314", "2341",
                      "2413", "2431", "3124", "3142", "3214",
                      "3241", "3412", "3421", "4123", "4132", 
                      "4213", "4231", "4312", "4321"};



int check(int circle[3], int square[3], int tri[3]){
    
    int prev = -1;
    int curr = -1;
    int arr1[3]; int arr2[3]; int arr3[3];

    for(int i=0; i<24; i++){
        for(int j=0; j<3; j++){arr1[j] = circle[j]; arr2[j] = square[j]; arr3[j] = tri[j];}

        curr = 0;
        for(int j=0; j<4; j++){
            if(permute[i][j] == '1') curr += one(arr1, arr2, arr3);
            else if(permute[i][j] == '2') curr += two(arr1, arr2, arr3);
            else if(permute[i][j] == '3') curr += three(arr1, arr2, arr3);
            else if(permute[i][j] == '4') curr += four(arr1, arr2, arr3);
        }
        prev = max(prev, curr);
    }
    return prev;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //ofstream fout("output.txt");
    int n;
    string num, shape;
    int circle[3], tri[3],square[3];


    while(cin>>n && n){
        for(int i=0; i<3; i++){
            circle[i] = 0;
            tri[i] = 0;
            square[i] = 0;
        }

        for(int i=0; i<n; i++){
            cin>>num>>shape;
            if(num == "um"){
                if(shape == "circulo") circle[0]++;
                else if(shape == "quadrado") square[0]++;
                else tri[0]++;
            }
            else if(num == "dois"){
                if(shape == "circulos") circle[1]++;
                else if(shape == "quadrados") square[1]++;
                else tri[1]++;
            }
            else{
                if(shape == "circulos") circle[2]++;
                else if(shape == "quadrados") square[2]++;
                else tri[2]++;
            }
        }

        int sum = 0;
        sum += check(circle, square, tri);

        cout<<sum<<endl;
    }


    return 0;
}