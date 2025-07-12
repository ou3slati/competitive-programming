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
const ll INF = 1e9;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO2(){
#ifndef ONLINE_JUDGE 
    freopen("marathon.in", "r", stdin); 
    freopen("marathon.out", "w", stdout); 
#endif 
}

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+100;
int N,Q;
int cord[MX][2];

vector<ll> ft(MX,0);
vi st(MX*4+5,-INF);

int dist(int i, int j){
	return abs(cord[i][0]-cord[j][0])+abs(cord[i][1]-cord[j][1]);
}

int lsb(int i){return (i)&(-i);}
void update(int idx, int v){
	while(idx<MX){
		ft[idx]+=v;
		idx+=lsb(idx);}}
ll sum(int idx){
	ll ans=0;
	while(idx>0){
		ans+=ft[idx];
		idx-=lsb(idx);
	}
	return ans;}


void update2(int i, int pos, int tl, int tr, int v){
	if(tl==tr){
		st[pos]=v;
		return;
	}
	int tm=(tl+tr)/2;
	if(i<=tm) update2(i,pos*2,tl,tm,v);
	else update2(i,pos*2+1,tm+1,tr,v);

	st[pos]=max(st[pos*2],st[pos*2+1]);
}

int mx(int l, int r, int pos, int tl, int tr){
	if(l>r) return -INF;
	if(tl==l && tr==r) return st[pos];
	int tm=(tl+tr)/2;
	return max(mx(l,min(r,tm),pos*2,tl,tm),mx(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

int32_t main(){
   boost;
   IO2();

   cin>>N>>Q;
   for(int i=1; i<=N; i++) cin>>cord[i][0]>>cord[i][1];

   for(int i=1; i<N; i++) update(i,dist(i,i+1));
   for(int i=1; i<=N-2; i++) update2(i,1,1,N-2,dist(i,i+1)+dist(i+1,i+2)-dist(i,i+2));

   while(Q--){
   	char T; cin>>T;
   	if(T=='U'){
   		int i,x,y; cin>>i>>x>>y;
   		int old2,old;

        if(i>1) old=dist(i-1,i);
   		if(i<N) old2=dist(i,i+1);
   		

   		cord[i][0]=x; cord[i][1]=y;

   		if(i>1) update(i-1,dist(i-1,i)-old);
   		if(i<N) update(i,dist(i,i+1)-old2);

   		if(i>2) update2(i-2,1,1,N-2,dist(i-2,i-1)+dist(i-1,i)-dist(i-2,i));
        if(i>1) update2(i-1,1,1,N-2,dist(i-1,i)+dist(i,i+1)-dist(i-1,i+1));
   		if(i<=N-2) update2(i,1,1,N-2,dist(i,i+1)+dist(i+1,i+2)-dist(i,i+2));
   	}
   	else{
   		int i,j; cin>>i>>j;
   		if(i==j) cout << 0 << endl;
   		else if(i==j-1) cout << dist(i,i+1) << endl;
   		else cout << sum(j-1)-sum(i-1)-mx(i,j-2,1,1,N-2) << endl;
   	}
   }
	

   return 0;
}

