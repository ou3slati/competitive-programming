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

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

void ckmax(int &x, int y){x=max(x,y);}

//---------


const int MX=1e6+10;
int N; 
vi a;

vi t(MX,0);
void upd(int i){
	i++;

	for(;i<MX; i+=i&-i) t[i]++;
}
int get(int i){
	i++;

	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans; 
}

int query(int l, int r){
	l++; r++;
	return get(r)-get(l-1);
}


int main(){
	IO();

	cin>>N; N*=2; a.resize(N); 
	FOR(i,0,N) cin>>a[i];

	vi vis(N+1,-1),nxt(N+1,-1);
	ROF(i,0,N){
		if(vis[a[i]]==-1) vis[a[i]]=i;
		else{
			nxt[i]=vis[a[i]];
			nxt[vis[a[i]]]=i;
		}
	}

	ll ans=0;
	FOR(i,0,N) if(nxt[i]<i){
		ans+=i-nxt[i]-query(nxt[i],i); 
		upd(i); upd(nxt[i]);
	}
	cout << ans << endl;
	
}
