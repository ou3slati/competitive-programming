//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
//#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

//template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int N,D,U,Q;
vi adj[100001];
int H[100001];
int A[200001],B[200001];
int X[50001],Y[50001],V[50001];
vpi vec;
int res[50000];


int main() {
	boost; IO();

	//FOR(i,0,100001) FOR(j,0,501) adj[i][j]=-1;

	

	cin>>N>>D>>U>>Q; 
	FOR(i,0,N) cin>>H[i];
	FOR(i,1,U+1) cin>>A[i]>>B[i];

	
	FOR(i,0,Q){
		int x,y,v; cin>>x>>y>>v;
		X[i]=x,Y[i]=y;
		if(v==0) res[i]=1e9;
		else vec.pb({v,i});
	}
	sort(all(vec));

	/*int ii=0;
	
	FOR(i,1,U+1){
		int u=A[i],v=B[i];

		bool f=false;
		FOR(j,0,sz(adj[u])) if(adj[u][j]==v){
			adj[u].erase(adj[u].begin()+j); 
			f=true;
			break;
		}
		FOR(j,0,sz(adj[v])) if(adj[v][j]==u){
			adj[v].erase(adj[v].begin()+j);
			break;
		}
		if(!f){
			adj[u].pb(v); adj[v].pb(u);
		}

		while(ii<sz(vec) && vec[ii].fi<=i){
			if(vec[ii].fi==i){
				int idx=vec[ii].se; // the index of the query
				int ans=INF;
				u=X[idx],v=Y[idx];

				vi a,b;
				FOR(j,0,sz(adj[u])) if(adj[u][j]!=-1) a.pb(H[adj[u][j]]);
				FOR(j,0,sz(adj[v])) if(adj[v][j]!=-1) b.pb(H[adj[v][j]]);
				//sort(all(a)); 
				sort(all(b));

				if(a.empty() || b.empty()){
					ans=1e9;
				}
				else{
					for(auto val: a){
						auto it=upper_bound(all(b),val)-b.begin();
						if(it!=sz(b)) ans=min(ans,abs(val-b[it]));
						if(it!=0){
							it--;
							ans=min(ans,abs(val-b[it]));
						}
					}
				}

				res[idx]=ans;
			}
			ii++;
		}
	}*/

	/*for(int i=0; i<Q; i++){ 	
		//int x=res[i]; cout << x << endl; cout.flush(); 
		cout << 5; cout << endl;
		cout.flush(); 
	}*/



	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
