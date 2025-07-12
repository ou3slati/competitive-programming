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

const int MX=2e5+10;
int N;
int h[MX],a[MX];
vi st(4*MX,0);

int mx(int l, int r, int pos, int tl, int tr){
	if(r<l) return 0;
	if(l==tl && r==tr) return st[pos];
	int tm=(tl+tr)/2;
	return max(mx(l,min(r,tm),pos*2,tl,tm),mx(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

void update(int i, int v, int pos, int l, int r){
	if(l>r) return;
	if(l==r){
		st[pos]=v;
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,v,pos*2,l,m);
	else update(i,v,pos*2+1,m+1,r);
	st[pos]=max(st[pos*2],st[pos*2+1]);
}

int32_t main(){
   boost;
   IO();

   cin>>N;
   for(int i=0; i<N; i++) cin>>h[i];
   for(int i=0; i<N; i++) cin>>a[i];

   int dp[N+1];
	for(int i=0; i<=N; i++) dp[i]=0;
	for(int i=0;i<N;i++){
		int x=mx(1,h[i]-1,1,1,N);
		dp[h[i]]=max(dp[h[i]],x+a[i]);
		update(h[i],dp[h[i]],1,1,N);
	}

	int ans=0;
	for(int i=1; i<=N; i++) ans=max(ans,dp[i]);
	cout << ans << endl;
	


   return 0;
}

