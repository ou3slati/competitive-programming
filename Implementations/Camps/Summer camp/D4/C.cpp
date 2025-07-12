//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;
int N;
vi t(MX*4,0);

void update(int i, int pos, int l, int r, int x){
	if(l==r) {
		t[pos]=x;
		return;
	}
	int m=(l+r)/2;
	if(i<=m){
		update(i,pos*2,l,m,x);
	}
	else update(i,pos*2+1,m+1,r,x);
	t[pos]=max(t[pos*2],t[pos*2+1]);
}

int query(int l, int r, int pos, int tl, int tr){
	if(l>r) return -INF;
	if(tl==l && tr==r) return t[pos];
	int tm=(tl+tr)/2;
	return max(query(l,min(r,tm),pos*2,tl,tm),query(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

int main(){
   boost;
   IO();

   cin>>N;
   int t[N+1];
   for(int i=1; i<=N; i++){
   	int x; cin>>x;
   	t[i]=x;
   	update(i,1,1,N,x);
   }

   for(int i=1; i<=N; i++){
   	if(i==N){cout << 0 << endl; return 0;}
   	int x=t[i];
   	int l=i,r=min(N,x+i);
   	int res=0;
   	while(l<=r){
   		int m=(l+r)/2;
   		//cout << query(i,m,1,1,N) << endl;
   		if(query(i,m,1,1,N)<=x){
   			res=max(res,m); 
   			l=m+1;
   		}
   		else r=m-1;
   	}
   	cout << res-i << ' ';
   	//cout << endl;
   }
	

   return 0;
}

