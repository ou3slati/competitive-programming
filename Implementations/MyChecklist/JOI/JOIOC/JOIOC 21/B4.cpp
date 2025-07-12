#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

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


//----------

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

//------------

vi lft(MX);
void precompute(){
	vi st; 
	FOR(i,0,N){
		while(sz(st) && a[st.back()]<a[i]) st.pop_back();
		if(sz(st)) lft[i]=st.back()+1;
		else lft[i]=0;	

		st.pb(i);
	}
}

int main() {
    IO();
    
    cin>>N>>D;
    FOR(i,0,N) cin>>a[i];

    precompute();

    vi dp(N,1);
    FOR(i,0,N){
    	ckmax(dp[i],get(lft[i],i-1)+1);
    	upd(i,dp[i]);
    }
    
    int ans=0;
    FOR(i,0,N) ckmax(ans,dp[i]);
    cout << ans << endl;

    return 0;
}
//Change your approach 