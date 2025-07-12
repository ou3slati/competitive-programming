#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//---------------------------------------------------//

const int MX=3e5;
void ckmax(int &x, int y){x=max(x,y);}

int N,D; 
vi a(MX);

//--------------------------------------
const int INF=1e9;
vi t(MX*4,-INF);

void upd(int i, int v, int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t[pos]=v; 
		return; 
	}

	int tm=(tl+tr)/2;
	if(i<=tm) upd(i,v,pos*2,tl,tm);
	else upd(i,v,pos*2+1,tm+1,tr);

	t[pos]=max(t[pos*2],t[pos*2+1]);
}

int get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return -INF;
	if(l==tl && r==tr) return t[pos];

	int tm=(tl+tr)/2;
	return max(get(l,min(r,tm),pos*2,tl,tm),
		get(max(l,tm+1),r,pos*2+1,tm+1,tr));
}
//------------------------------

bool cmp(pi a, pi b){
	if(a.fi!=b.fi) return a.fi<b.fi; 
	return a.se>b.se;
}

int main() {
    IO();
    
    cin>>N>>D;
    FOR(i,0,N) cin>>a[i];

    map<int,vi>mp;
    FOR(i,0,N) mp[a[i]].pb(i);

   	vi dp(N,-INF);

   	int prev=-1;
   	for(auto it: mp){
   		sort(all(it.se));
   		for(int i: it.se){
   			dp[i]=0;
   			ckmax(dp[i],get(max(0,i-D),i));
   			upd(i,dp[i]);
   		}

   		vpi nw; 
   		for(int i: it.se) nw.eb(i,get(max(0,i-D),i)+1);

   		for(auto itt: nw){
   			int i=itt.fi,v=itt.se;
   			dp[i]=1;
   			ckmax(dp[i],v);
   			upd(i,dp[i]);
   		}


   		//cout << i  << ' ' << dp[i] << endl;
   	}
    
    int ans=0;
    FOR(i,0,N) ckmax(ans,dp[i]);
    cout << ans << endl;

    return 0;
}
//Change your approach 