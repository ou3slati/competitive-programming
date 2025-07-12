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
vi t(MX*4,0);
int N,Q;

void update(int l, int r, int pos, int tl, int tr, int x){
	if(l>r) return;
	if(l==tl && r==tr){
		t[pos]+=x; 
		return;
	}
	int tm=(tr+tl)/2;
	update(l,min(r,tm),pos*2,tl,tm,x); 
	update(max(tm+1,l),r,pos*2+1,tm+1,tr,x);
}

int query(int i, int pos, int tl, int tr){
	if(tl==tr){
		return t[pos];
	}
	int tm=(tl+tr)/2;
	if(i<=tm) return t[pos]+query(i,pos*2,tl,tm);
	return t[pos]+query(i,pos*2+1,tm+1,tr);
}

int32_t main(){
   boost;
   //IO();

   cin>>N>>Q;
   for(int i=1; i<=N; i++){
   	int x; cin>>x;
   	update(i,i,1,1,N,x);
   }

   while(Q--){
   	int op; cin>>op;
   	if(op==1){
   		int l,r,x; cin>>l>>r>>x;
   		update(l,r,1,1,N,x);
   	}
   	else{
   		int idx; cin>>idx;
   		cout << query(idx, 1, 1, N) << endl;
   	}
   }
	

   return 0;
}

