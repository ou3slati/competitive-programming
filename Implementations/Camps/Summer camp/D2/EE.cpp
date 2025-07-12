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
    freopen("outputt.txt", "w", stdout); 
#endif 
}

const int MX=210;

int32_t main(){
   boost;
   IO();

   int N,K; cin>>N>>K;
   int cnt[MX];
   for(int i=0; i<MX;i++) cnt[i]=0;

   set <pair<pi,int>> s;

   for(int i=0; i<N; i++){
   	int l,r; cin>>l>>r; l--; r--;
   	for(int j=l; j<=r; j++) cnt[j]++;
   	s.insert({{l,r},i+1});
   }
   
   N=MX;
   int todo[N];
   for(int i=0; i<N; i++){
		if(cnt[i]>K) todo[i]=cnt[i]-K;
		else todo[i]=0;
	}


	vi res;
   while(1){
	   	bool y=false;
	   	for(int i=0; i<N;i++) if(todo[i]>0){
	   		y=true; break;
	   	}
	   	if(!y) break;

	   	int mx=0,idxx=-1;
	   	pi pp;
	   	for(auto x: s){
	   		int nb=0;
	   		int idx=x.se;
	   		for(int i=x.fi.fi; i<=x.fi.se; i++) if(todo[i]>0) nb++;
	   		if(nb>mx){
	   			mx=nb; pp=x.fi; idxx=idx;
	   		}
	   	}

	   	s.erase(s.find({pp,idxx}));
		for(int i=pp.fi; i<=pp.se; i++) if(todo[i]>0){
	   		todo[i]--;
	   	}
	   	res.pb(idxx);
   }
   cout << sz(res) << endl;
   for(auto x: res) cout << x << ' '; cout << endl;
	

   return 0;
}

