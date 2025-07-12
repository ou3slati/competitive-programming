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
vi st(MX*4,0);

void update(int i, int pos, int tl, int tr, int v){
	if(tl==tr){
		st[pos]=v;
		return;
	}

	int tm=(tl+tr)/2;
	if(i<=tm) update(i,pos*2,tl,tm,v);
	
	else update(i,pos*2+1,tm+1,tr,v);
	st[pos]=min(st[pos*2],st[pos*2+1]);
}

int query(int l, int r, int pos, int tl, int tr){
	if(l>r) return INF;
	if(tl==l && tr==r){
		return st[pos];
	}
	int tm=(tl+tr)/2;
	return min(query(l,min(tm,r),pos*2,tl,tm),query(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

int32_t main(){
   boost;
   //IO();

   int Q;
   cin>>N>>Q;
   for(int i=1; i<=N;i++){
   	int x; cin>>x;
   	update(i,1,1,N,x);
   }

   while(Q--){
   	int l,r; cin>>l>>r;
   	cout << query(l,r,1,1,N) << endl;
   }
	

   return 0;
}

