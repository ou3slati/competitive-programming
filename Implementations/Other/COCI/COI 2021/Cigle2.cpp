//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
const int MX = 5000 + 10;
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

#define left lft
#define right rgt

int N; 
vi a(MX);

int memo[MX][MX],left[MX],right[MX];
vi val(MX,0);


void precompute(){
	memset(left,-1,MX); 
	memset(right,-1,MX); 
	FOR(i,1,N-1){
		int x,y; 

		int l,r,cnt; 

		while(l<=r){
			x=0,y=0;
			FOR(j,0,i+1) x+=a[j];
			FOR(j,i+1,N) y+=a[j];
			l=0,r=N-1,cnt=0;
			
			while(x!=y){
				if(x>y){
					l++;
					if(l>r) break;
					x-=a[l];
				}
				else{
					r--;
					if(r<0) break;
					y-=a[r];
				}
			}

			l--; 
			r++;

			if(l>=0 && r<N && x==y){
				if(left[i]==-1) left[i]=l,right[i]=r;
				val[i]++;
			}

			l+=2;
			r-=2;
		}
		

		

	}
}

int solve(int l, int i){
	if(i==N) return 0;
	int &ind=memo[l][i];
	if(ind!=-1) return ind;

	int ans=solve(l,i+1);
	if(left[i]!=-1 && left[i]>=l){
		ckmax(ans,solve(i+1,right[i])+1);
	}

	return ind=ans; 
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N) cin>>a[i];

    precompute();

    /*int idx=4;
    cout << left[idx] << ' ' << right[idx] << endl;*/


    memset(memo,-1,sizeof(memo));
    cout << solve(0,0) << endl; 
    

    return 0;
}
//Change your approach 