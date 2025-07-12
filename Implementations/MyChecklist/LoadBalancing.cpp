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
void IO2(){
#ifndef ONLINE_JUDGE 
    freopen("balancing.in", "r", stdin); 
    freopen("balancing.out", "w", stdout); 
#endif 
}

const int MX=1e6+10;
int N;
vpi vec;
vi bit(MX,0),bit2(MX,0);

int lsb(int i){return i&-i;}
void update(int idx, int v){
	while(idx<MX){
		bit[idx]+=v;
		idx+=lsb(idx);
	}}
void update2(int idx, int v){
	while(idx<MX){
		bit2[idx]+=v;
		idx+=lsb(idx);
	}}
int getSum(int idx){
	int ans=0;
	while(idx){
		ans+=bit[idx];
		idx-=lsb(idx);
	}
	return ans;
}
int getSum2(int idx){
	int ans=0;
	while(idx){
		ans+=bit2[idx];
		idx-=lsb(idx);
	}
	return ans;
}

int32_t main(){
   boost;
   IO2();
	
	cin>>N;
	for(int i=0; i<N; i++){
		int x,y; cin>>x>>y;
		vec.pb({x,y});
		update2(y,1);
	}

	sort(all(vec));

	int l=1,r=100000;
	while(l<=r){
		int m=(l+r)/2;
		int a=getSum(m),b=getSum(MX-1)-getSum(m),c=getSum2(m),d=getSum2(MX-1)-getSum2(m),
		ans=min(ans,max(max(a,b),max(c,d)));
		if(max(a,c)<max(b,d)) l=m+1;
		else r=m-1;
	}

	int ans=INF;
	for(int i=0; i<N; i++){
		int x=vec[i].fi,y=vec[i].se;
		update(y,1);
		update2(y,-1);

		l=1,r=1000000;
		while(l<=r){
			int m=(l+r)/2;
			int a=getSum(m),b=getSum(MX-1)-getSum(m),
			c=getSum2(m),d=getSum2(MX-1)-getSum2(m);

			//cout << a  << ' ' << b << ' ' << ' ' << c << ' ' << d << endl;
			ans=min(ans,max(max(a,b),max(c,d)));
			if(max(a,c)<max(b,d)) l=m+1;
			else r=m-1;

		}
	}
	cout << ans << endl; 	



   return 0;
}

