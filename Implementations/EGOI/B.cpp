#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
#define int ll
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
vi a,val;

struct node{
	int i, mn, lazy;
};

vector<node> t(MX*4);
node combine(node a, node b){
	node c;
	c.lazy=0;
	if(a.mn<=b.mn){
		c.mn=a.mn;
		c.i=a.i;
	}
	else{
		c.mn=b.mn;
		c.i=b.i;
	}
	return c; 
}

void push_down(int pos){
	int v=t[pos].lazy;
	t[pos*2].lazy+=v; 
	t[pos*2+1].lazy+=v; 
	t[pos*2].mn+=v; 
	t[pos*2+1].mn+=v; 

	t[pos].lazy=0;
}

void build(int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t[pos]={tl,val[tl],0};
		return; 
	}

	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);

	t[pos]=combine(t[pos*2],t[pos*2+1]);
}

void upd(int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return; 
	if(l==tl && r==tr){
		t[pos].mn+=v; 
		t[pos].lazy+=v; 
		return; 
	}

	push_down(pos);
	int tm=(tl+tr)/2;
	upd(l,min(r,tm),v,pos*2,tl,tm);
	upd(max(l,tm+1),r,v,pos*2+1,tm+1,tr);

	t[pos]=combine(t[pos*2],t[pos*2+1]);
}

node get(int l=0, int r=N-1,int pos=1, int tl=0, int tr=N-1){
	if(l>r) return node{-1,(int)2e9,0}; 
	if(l==tl && r==tr){
		return t[pos];
	}

	push_down(pos);
	int tm=(tl+tr)/2;
	return combine(get(l,min(r,tm),pos*2,tl,tm),
		get(max(l,tm+1),r,pos*2+1,tm+1,tr));

}

int32_t main(){
	IO();

	cin>>N; N*=2; a.resize(N); val.resize(N);
	FOR(i,0,N) cin>>a[i];

	vi vis(N+1,-1),nxt(N+1,-1);
	ROF(i,0,N){
		if(vis[a[i]]==-1) vis[a[i]]=i;
		else{
			val[i]=val[vis[a[i]]]=vis[a[i]]-i;
			nxt[i]=vis[a[i]];
			nxt[vis[a[i]]]=i;
		}
	}

	build();
	int rep=N/2;

	ll ans=0;
	while(rep--){
		node p=get();
		int l=p.i,x=p.mn;
		ans+=x; 
		int r=nxt[l]; if(l>r) swap(l,r);

		//cout << l << ' ' << r << ' ' << x << endl;

		upd(l,l,1e9); upd(r,r,1e9);
		
		upd(l,r,-1);

		FOR(i,0,l) if(nxt[i]>r) upd(i,i,-2);
		
	}
	cout << ans << endl;
	
}
