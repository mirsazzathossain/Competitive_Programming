#include<bits/stdc++.h>

using namespace std;

//Inputs
#define sfi(x) scanf("%d", &x)
#define sfl(x) scanf("%ld", &x)
#define sfd(x) scanf("%lf", &x)
#define sfc(x) scanf("%c", &x)
#define sfs(x) getline(cin, x);
#define in(x) cin>>x;
//Outputs
#define pfi(x) printf("%d", x)
#define pfl(x) printf("%ld", x)
#define pfd(x) printf("%lf", x)
#define pfc(x) printf("%c", x)
#define out(x) cout<<x
#define endl printf("\n")
#define pcase(i) printf("Case %d: ", i)
//Loops
#define loop0(i, n) for(i=0; i<n; i++)
#define loop1(i, n) for(i=1; i<=n; i++)
#define loopab(i, a, b) for(i=a; i<=b; i++)
#define loopr0(i, n) for(i=n-1; i>=0; i--)
#define loopr1(i, n) for(i=n; i>=1; i--)
#define looprab(i, a, b) for(i=b; i>=a; i--)
#define iterate(it, x) for(it=x.begin(); it!=x.end(); it++)
//Fast Input Output
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
//Data Types
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef set<int> si;
typedef set<long long> sll;
typedef set<double> sd;
typedef set<string> ss;
typedef pair<int, int> pii;
typedef map<int, int> mpii;
typedef map<string, int> mpsi;
//Keywords
#define pb push_back
#define ins insert
//Useful Functions
#define sort(x) sort(x.begin(), x.end());
#define sortr(x, a, b) sort(x.begin()+a, x.end()+b+1);
#define sortd(x) sort(x.begin(), x.end(), greater<int>());
#define rev(x) reverse(x.begin(), x.end());
#define revr(x, a, b) reverse(x.begin()+a, x.end()+b+1);
//Constants
const int MOD = 1000000007;
const int MAX = 1000005;
const double PI = acos(-1.0);

#define boom 0
#define safe 1
#define visited 2
int mp[1000][1000];
int level[1000][1000];

int fx[] = {0, 0, -1, 1};
int fy[] = {-1, 1, 0, 0};


void bfs(int R, int C, pii src){
    level[src.first][src.second] = 0;
    mp[src.first][src.second] = visited;

    queue<pii>q;
    q.push(src);

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        int i;
        loop0(i, 4){
            int nx = u.first + fx[i];
            int ny = u.second + fy[i];

            if(nx >= 0 && nx < R && ny >= 0 && ny < C && mp[nx][ny] == safe){
                level[nx][ny] = level[u.first][u.second] + 1;
                mp[nx][ny] = visited;
                q.push(pii(nx, ny));
            }
        }
    }

}



int main(){
    //fastio;
    //fstream fin("input.txt");
    //ofstream fout("output.txt");
    
    int R, C, row;
    while(cin>>R>>C){
        if(R == 0 && C == 0) break;
        int i, j;
        loop0(i, 1000){
            loop0(j, 1000){
                mp[i][j] = safe;
                level[i][j] = INT_MIN;
            }
        }

        sfi(row);
        int rowNo, numBoom, colNo;

        while(row--){
            sfi(rowNo);sfi(numBoom);
            while(numBoom--){
                sfi(colNo);
                mp[rowNo][colNo] = boom;
            }
        }
        
        int sx, sy, ex, ey;
        sfi(sx); sfi(sy);
        sfi(ex); sfi(ey);
        bfs(R, C, pii(sx, sy));
        pfi(level[ex][ey]);endl;

    }
    
    
    return 0;
}