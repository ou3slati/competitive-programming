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

const int MX=2005;
int N,P,Q;
int W;
vi a;

int memo[MX][MX];

int bs(int i, int x){
	int ans;
	int l=i,r=N-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]-a[i]+1<=x){
			ans=m;
			l=m+1;
		}
		else r=m-1;
	}
	return ans;
}

int solve(int i, int r){
	if(i==N) return 0;
	if(memo[i][r]!=-1) return memo[i][r];
	int ans=INF;
	if(r) ans=solve(bs(i,W*2)+1,r-1);
	ans=min(ans,solve(bs(i,W)+1,r)+1);
	return memo[i][r]=ans;
}

int32_t main(){
   boost;
   IO();

   cin>>N>>P>>Q; a.resize(N);
   P=min(P,N); Q=min(Q,N);
   if(P+Q>N) P=N-Q;

   for(int i=0; i<N; i++) cin>>a[i]; sort(all(a));

   int ans;
   int l=1,r=INF;
	while(l<=r){
		memset(memo,-1,sizeof(memo));
		int m=(l+r)/2;
		W=m;
		if(solve(0,Q)<=P){
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}

	cout << ans << endl;

   return 0;
}

