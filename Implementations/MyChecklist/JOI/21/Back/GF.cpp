#include <bits/stdc++.h>
using namespace std; 
	
typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void ckmin(ll &x, ll y){x=min(x,y);}

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//--------------------------------------------------------------------

const int MX=5e3+10;
int N;
ll val[MX][MX]; 
vi a(MX);

vi t; 
void upd(int i){
	for(;i<sz(t); i+=i&-i) t[i]++;
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans; 
}

void compute(){
	FOR(l,1,N+1){
		vi b;
		FOR(i,1,N+1) if(a[i]>=l) b.pb(a[i]);
		int n=sz(b);

		vi order(N+1),nb(N+1,0);
		t.assign(N+1,0);
		ROF(i,0,n){
			order[b[i]]=i;
			nb[b[i]]=get(b[i]);
			upd(b[i]);
		}

		val[l][l]=order[l];
		FOR(r,l+1,N+1)
			val[l][r]=val[l][r-1]+order[r]-nb[r];
	}
}

int main(){
	IO();

	cin>>N;
	FOR(i,1,N+1) cin>>a[i];


	compute();
	
	ll dp[N+1];
	dp[0]=0;
	FOR(i,1,N+1){
		dp[i]=1e18;
		FOR(j,0,i) ckmin(dp[i],dp[j]+val[j+1][i]);
	}
	cout << dp[N] << endl;
}