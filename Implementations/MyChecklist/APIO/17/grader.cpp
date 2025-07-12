//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#ifndef LOCAL
#include "koala.h"
#endif
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}

#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int N, W;
static int P[105];

static int maxQueries = 3200;
static int numQueries;

static void runGame(int F);
static void grader();

int main() {
    grader();
    return 0;
}


void playRound(int *B, int *R) {
    int i, j;

    int S = 0;
    for (i=0;i<N;++i) {
        if ( !(B[i] >= 0 && B[i] <= W) ) {
            printf("Invalid query.\n");
            exit(0);
        }
        S += B[i];
    }
    if (S > W) {
        printf("Invalid query.\n");
        exit(0);
    }

    numQueries++;
    if (numQueries > maxQueries) {
        printf("Too many queries.\n");
        exit(0);
    }

    int cache[2][205];
    int num[2][205];
    char taken[105][205];

    for (i=0;i<205;++i) {
        cache[1][i] = 0;
        num[1][i] = 0;
    }

    for (i=0;i<N;++i) {
        int v = B[i]+1;
        int ii = i&1;
        int o = ii^1;
        for (j=0;j<=W;++j) {
            cache[ii][j] = cache[o][j];
            num[ii][j] = num[o][j];
            taken[i][j] = 0;
        }
        for (j=W;j>=v;--j) {
            int h = cache[o][j-v] + P[i];
            int hn = num[o][j-v] + 1;
            if (h > cache[ii][j] || (h == cache[ii][j] && hn > num[ii][j])) {
                cache[ii][j] = h;
                num[ii][j] = hn;
                taken[i][j] = 1;
            } else {
                taken[i][j] = 0;
            }
        }
    }

    int cur = W;
    for (i=N-1;i>=0;--i) {
        R[i] = taken[i][cur] ? (B[i] + 1) : 0;
        cur -= R[i];
    }
}

int B[100],R[100];

int maxValue(int N, int W) {
    /*
    .for every 10 elements place 10 items
    .from those 10 elements, we won't choose more than 1 element (prooved)
    .if it was chosen, it is bigger than (10*11/2)==55
    .for all the elements chosen (<=10), put 10 on them
    .the chosen is the max
    */

  /*  vi chosen;
    for(int i=0; i<100; i+=10){
        FOR(j,0,N) B[i]=0;
        FOR(j,i,i+10) B[j]=10;
        playRound(B,R); 
        FOR(j,i,i+10) if(R[j]>10) chosen.pb(j);
    }

    FOR(i,0,N) B[i]=0;
    for(auto x: chosen) B[x]=10;
    playRound(B,R);
    for(auto x: chosen) if(B[x]>10) return x;
*/
    return 0;
}



static void runGame(int F) {
    int i;

    scanf("%d %d",&N,&W);
    for (i=0;i<N;++i) {
        //scanf("%d",&P[i]);
        P[i]=i+1;
    }

    numQueries = 0;
    if (F == 1) {
       // printf("%d\n", minValue(N, W));
    } else if (F == 2) {
        cout << maxValue(N, W) << endl;
    } else if (F == 3) {
       // printf("%d\n", greaterValue(N, W));
    } else if (F == 4) {
        /*int userP[105];
        allValues(N, W, userP);
        for (i=0;i<N;i++) {
            printf("%d ",userP[i]);
        }
        printf("\n");*/
    }
    printf("Made %d calls to playRound.\n", numQueries);
}

void grader() {
    int i;

    int F=2, G=1;
    //scanf("%d %d",&F,&G);

    for (i=0;i<G;i++) {
        runGame(F);
    }
}
