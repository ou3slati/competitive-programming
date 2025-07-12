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
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

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


bool check(int l, int r, int ll, int rr){
	if(ll<l){
		swap(l,ll); swap(r,rr);
	}
	if(!(ll>r || rr<l)) return true;
	return false;
}

int main() {
	boost; IO();

	int N; cin>>N;
	vi a(N),b(N); 
	FOR(i,0,N){
		cin>>a[i]>>b[i];
		if(b[i]==1 || (a[i]!=-1 && b[i]!=-1 && a[i]>=b[i]) ){
			cout << "No" << endl;
			return 0;
		}
	}

	int nb=0;//the ones that have (-1,-1)
	FOR(i,0,N){
		if(a[i]==-1 && b[i]==-1){ //!!!!!!!
			nb++;
			continue;
		}
		//assign minimum interval if not assigned
		//check if there's an obligation
		//if yes check everything is good

		int l=a[i],r=b[i];
		if(a[i]==-1) l=b[i]-1; 
		else if(b[i]==-1) r=a[i]+1;

		int ln=r-l; //b[k]-a[k]
		FOR(j,0,N) if(j!=i && a[j]!=-1 && b[j]!=-1){
			if(check(a[j],b[j],l,r)){
				ln=b[j]-a[j]; break;
			}
		}
		//ln is now an obligation

		if(a[i]!=-1 && b[i]!=-1 && ln!=r-l){
			cout << "No" << endl;
			return 0;
		}

		if(a[i]==-1) l=b[i]-ln;
		else if(b[i]==-1) r=a[i]+ln;
		

		FOR(j,0,N) if(j!=i && a[j]!=-1 && b[j]!=-1){
			if(check(a[j],b[j],l,r) && b[j]-a[j]!=r-l){
				cout << "No" << endl;
				return 0;
			}
		}

		a[i]=l; b[i]=r;
		if(a[i]<=0 || b[i]>2*N){
			cout << "No" << endl;
			return 0;
		}
	}

	bool taken[2*N+1]; FOR(i,1,2*N+1) taken[i]=false;
	int vis[2*N+1]; FOR(i,1,2*N+1) vis[i]=-1;
	int free=0; 

	FOR(i,0,N) if(a[i]!=-1 && b[i]-a[i]>1){
		assert(b[i]!=-1);
		FOR(j,a[i],b[i]+1) vis[j]=b[i]-a[i];
		taken[a[i]]=true; taken[b[i]]=true;
	}
	FOR(i,1,N*2+1)if(!taken[i]){
		if(vis[i]!=-1){
			if(i+vis[i]<=2*N && !taken[i+vis[i]] && (vis[i+vis[i]]==-1 ||vis[i+vis[i]]==vis[i])){nb--; taken[i+vis[i]]=true;}
			else if(i-vis[i]>=1 && !taken[i-vis[i]] && (vis[i-vis[i]]==-1 ||vis[i-vis[i]]==vis[i])){nb--;}
		}
		if(i<2*N && vis[i+1]==-1){
			nb--;
			taken[i+1]=true;
		}
	}

	if(nb>0){
		cout << "No" << endl;
		return 0;
		
	}

	/*bool y=true;
	FOR(i,0,N) FOR(j,0,N){
		if(a[i]==b[j] || a[i]==b[i] || a[j]==b[i] || a[j]==b[j]) y=false;
	}
	if(!y){
		cout << "No" << endl;
		return 0;
	}*/


	cout << "Yes" << endl;



	return 0;
}

/*
only one person at each floor
b[i]>a[i]
1<=a[i],b[i]<=N*2

*/

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
