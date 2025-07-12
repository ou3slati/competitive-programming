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

int res[11];
bool vis[11]={0};
vector <pair<char,int>> mv;

int ans=INF;
vector <pair<char,int>> vans;
int N; 

void solve(vi v, int nb){
	bool y=true;
	for(int i=0;i<N; i++) if(res[i]!=v[i]) y=false;
	if(y){
		if(nb<ans){
			ans=nb;
			vans.clear();
			for(auto x: mv) vans.pb(x);
		}

		return;
	}

	for(int i=0; i<N; i++)if(!vis[i]){

		vis[i]=true;

		int op=0;
		for(int j=0;j<N; j++) if(v[i]==res[j]) if(j>i) op=1;

		vi vv;
		if(op==0){
		 
		vv.pb(v[i]); 
		for(int j=0; j<N; j++) if(i!=j) vv.pb(v[j]);
		mv.pb({'F',i+1});
		solve(vv,nb+1);
		mv.pop_back();}

		else{
		vv.clear();
		for(int j=0; j<N; j++) if(i!=j) vv.pb(v[j]);
		vv.pb(v[i]);
	   mv.pb({'B',i+1});
		solve(vv,nb+1);
		mv.pop_back();}
		
		vis[i]=false;
		
	}
}

int32_t main(){
   boost;
   IO();
   

   cin>>N;
   vi v(N);
   for(int i=0; i<N;i++) cin>>v[i];
   for(int i=0; i<N;i++) cin>>res[i];
   
   solve(v,0);
   cout << ans << endl;
   for(auto x: vans)cout << x.fi <<  ' ' << x.se << endl;

	

   return 0;
}

