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
    freopen("guard.in", "r", stdin); 
    freopen("guard.out", "w", stdout); 
#endif 
}

const int MX=22;
int N,Hm; 
int H[MX],W[MX],S[MX];
int memo[1<<20];


int solve(int m){
	int h=0,w=0;
	for(int i=0; i<N; i++) if((m)&((1)<<(i))) h+=H[i],w+=W[i];
	if(h>=Hm) return INF;
	if(memo[m]!=-1) return memo[m];

	int ans=-INF;
	for(int i=0; i<N; i++) if(!((m)&((1)<<(i))) && S[i]>=w){
		ans=max(ans,min(S[i]-w,solve((m)|((1)<<(i)))));
	}

	return memo[m]=ans;
}

int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));
   cin>>N>>Hm;
   for(int i=0; i<N; i++) cin>>H[i]>>W[i]>>S[i];

   int ans=solve(0);
	if(ans<0) cout <<"Mark is too tall" << endl;
	else cout << ans << endl;
	

   return 0;
}

