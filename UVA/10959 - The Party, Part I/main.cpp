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
//Custom
typedef vector<vector<int> > vvi;
#define white 0
#define gray 1;
#define black 2;

vvi adj;
int level[1000];
int color[1000];

void bfs(){
    level[0] = 0;
    color[0] = gray;

    queue<int>q;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        int i;
        loop0(i, adj[u].size()){
            int v = adj[u][i];
            if(color[v] == white){
                color[v] = gray;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        color[u] = black;
    }
}


int main(){
    //fastio;
    //fstream fin("input.txt");
    //ofstream fout("output.txt");
    
    int t, P, D, i;
    sfi(t);

    while(t--){
        sfi(P); sfi(D);

        adj.resize(P);
        loop0(i, P){
            color[i] = white;
            level[i] = -1;
        }

        int u, v;
        while(D--){
            sfi(u); sfi(v);

            adj[u].pb(v);
            adj[v].pb(u);
        }


        bfs();
        loop1(i, P-1){
            pfi(level[i]);endl;
        }
        if(t != 0) endl;
        adj.clear();
    }
    
    
    return 0;
}