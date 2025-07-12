//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;

int N;
int t[20][20];

int memo[(1)<<(16)];

int solve(int m){
	if(m==((1)<<(N))-1) return 0;
	if(memo[m]!=-INF) return memo[m];

	int ans=-2*INF;

	vi vec; int r;
	for(int i=0; i<N; i++) if(((m)&((1)<<(i)))==0) vec.pb(i);
	r=sz(vec);
	
	for(int i=1; i<((1)<<(r)); i++){
		vi chosen;
		for(int j=0; j<r; j++) if((i)&((1)<<(j))) chosen.pb(j);
		for(int j=0; j<sz(chosen); j++) chosen[j]=vec[chosen[j]];

		int nm=m;
		for(auto it: chosen){
			nm=((nm)|((1)<<(it)));
		}

		int x=0;
		for(int i=0; i<sz(chosen); i++) for(int j=i+1; j<sz(chosen); j++) x+=t[chosen[i]][chosen[j]];
		ans=max(ans,solve(nm)+x);
	}

	return memo[m]=ans; 
}


int32_t main(){
   boost;
   IO();

   for(int i=0; i<(1)<<(16); i++) memo[i]=-INF;
   cin>>N;
   for(int i=0; i<N; i++) for(int j=0; j<N;j++) cin>>t[i][j];

   cout << solve(0) << endl;
   

   return 0;
}

