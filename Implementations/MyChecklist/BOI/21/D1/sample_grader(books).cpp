/*
SAMPLE GRADER for task BOOKS

USAGE:
place together with your solution and books.h in the same directory, then:
g++ <flags> sample_grader.cpp <solution_file>
e.g.:
g++ -std=c++17 sample_grader.cpp books.cpp

INPUT/OUTPUT:
The sample grader expects on standard input two lines. The first line should
contain the four integers N, K, A and S. The second line should contain a list
of N integers, the sequence of difficulties x_1 x_2 ... x_N which has to be
strictly increasing. Then, the grader writes to standard output a protocol of
all grader functions called by your program.
At the end, the grader prints your verdict.
*/


//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


void __attribute__((noreturn)) __attribute__((format(printf, 1, 2))) result(const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(0);
}

namespace
{
    int N, K, S, sUsed;
    long long A;
    vector<long long> seq;
}

void impossible()
{
    result("Impossible (not checked): %d book(s) skimmed", sUsed);
    exit(0);
}

long long skim(int pos)
{
    printf("skim(%d): ", pos);
	if (pos<1 || pos>N) result("Invalid skim");
    printf("%lld\n", seq[pos]);
	sUsed++;
	if (sUsed>S) result("Out of books to skim");
    return seq[pos];
}

void answer(vector<int> v)
{
    printf("answer({");
    for(int i = 0; i < (int) v.size(); ++i)
    {
        printf("%d", v[i]);
        if(i + 1 != (int) v.size()) printf(", ");
    }
    printf("})\n");

	if ((int) v.size() != K) result("Invalid answer");
   	ll sum = 0;
	for(auto x: v) {
		if (x<1 || x>N) result("Invalid answer");
		sum += seq[x];
	}	
	if (sum < A || 2*A<sum) result("Wrong answer");

	result("Correct: %d book(s) skimmed", sUsed);
    exit(0);
}

void solve(int N, int K, ll A, int S) {
    V<ll> a(N+1);
    FOR(i,1,N+1) a[i]=skim(i);


    ll cur=0;

    int l=-1,r;
    FOR(i,1,N+1){
        cur+=a[i];
        if(i<K) continue;

        if(cur>=A && cur<=2*A){
            l=i-K+1,r=i; 
            break;
        }
        cur-=a[i-K+1];
    }
    if(l==-1) impossible();
    else{
        vi ans;
        FOR(i,l,r+1) ans.pb(i);
        answer(ans);
    }

}


int main()
{
    IO();
    if(scanf("%d %d %lld %d", &N, &K, &A, &S) != 4)
        result("Invalid input");

    seq.resize(N + 1);
    for(int i = 1; i <= N; ++i) {
    	if(scanf("%lld", &(seq[i])) != 1) result("Invalid input");
		if(i>1 && seq[i]<=seq[i-1]) result("Invalid input");
   	}

    solve(N, K, A, S);

    result("No answer");
}
