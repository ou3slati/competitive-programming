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

int X[1000],Y[1000],S[1000];

int dist(int i, int j){
	return abs(X[i]-X[j])*abs(X[i]-X[j])+abs(Y[i]-Y[j])*abs(Y[i]-Y[j]);
}

int32_t main(){
   boost;
   //IO();


   int N; cin>>N;
   
   for(int i=0; i<N; i++) cin>>X[i]>>Y[i]>>S[i];

   int ans[N];
   for(int i=0; i<N; i++){//Defender
   	vector<pair<ld,int>> vec;
   	for(int j=0; j<N; j++) if(i!=j){
   		ld inf=(ld)S[j]/(ld)dist(i,j);
   		if(inf>S[i]) vec.pb({inf,j});
   	}
   	sort(rall(vec));

   	//for(auto x: vec) cout << x.fi << ' ' << x.se+1<< endl;
   	if(vec.empty()){
   		ans[i]=-2;
   	}
   	else if(sz(vec)>1 && vec[0].fi==vec[1].fi){
   		ans[i]=-3;
   	}
   	else ans[i]=vec[0].se;
   }

   int ans2[N];
   for(int i=0; i<N; i++){
   	if(ans[i]>=0){
	   	int x=i;
	   	while(ans[x]>=0){
	   		x=ans[x];
	   	}
	   	ans2[i]=x+1;
	   }
	   else ans2[i]=ans[i];
   }
	
	for(int i=0; i<N; i++){
		if(ans2[i]==-2) cout << "K" << endl;
		else if(ans2[i]==-3) cout << "D" << endl;
		else cout << ans2[i] << endl;
	}

   return 0;
}

