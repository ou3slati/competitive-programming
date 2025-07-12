//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[8] = {-1, -1, -1, 0 ,0,1,1,1}, ny[8] = {0, 1, -1, 1,-1,1,0,-1}; //right left down up

template<class T> using V = vector<T>;
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

//right left down up
int op(int m){
	if(m==0) return 1;
	if(m==1) return 0;
	if(m==2) return 3;
	return 2;
}

bool check(int m, int mm){
	if(m==mm || m==op(mm)) return false;
	return true;
}


int main() {
	boost; IO();

	int N,t; cin>>N>>t;
	vi X(N),Y(N); 
	map<pi,bool> here;
	map<pi,int> mp;

	int ii=0,xx=2e9;
	FOR(i,0,N){
		cin>>X[i]>>Y[i]; 
		here[{X[i],Y[i]}]=true; 
		mp[{X[i],Y[i]}]=i;
		if(X[i]<xx){
			xx=X[i];
			ii=i;
		}
	}


	queue<int> q; q.push(ii);
	bool vis[N]; FOR(i,0,N) vis[i]=false;
	vis[ii]=true;

	vi res;
	while(!q.empty()){
		int idx=q.front();
		q.pop();
		res.pb(idx+1);
		int x=X[idx],y=Y[idx];

		FOR(m,0,8){
			int nwx=x+nx[m],nwy=y+ny[m];

			if(here.count({nwx,nwy})==true && !vis[mp[{nwx,nwy}]]){
				int ni=mp[{nwx,nwy}];
				vis[ni]=true;
				q.push(ni);
			}

			//Doesn't work?
			/*FOR(mm,0,4)if(check(m,mm)){
				nwx=nwx+nx[mm],nwy=nwy+ny[mm];
				if(here.count({nwx,nwy})==true && !vis[mp[{nwx,nwy}]]){
					int ni=mp[{nwx,nwy}];
					vis[ni]=true;
					q.push(ni);
				}
			}*/
		}
	}

	if(sz(res)<N) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for(auto x: res) cout << x << endl;

	}


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
