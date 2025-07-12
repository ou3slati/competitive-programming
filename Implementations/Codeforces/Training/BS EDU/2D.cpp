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

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int32_t main(){
   boost;
   IO();
	
	int M,N; cin>>M>>N;
	int t[N],y[N],z[N];
	for(int i=0; i<N; i++) cin>>t[i]>>z[i]>>y[i];

	int ans=INF;
	int l=0,r=INF;
	while(l<=r){
		int m=(l+r)/2;
		int x=0;
		for(int i=0; i<N; i++){
			int val=m/((z[i]*t[i])+y[i]);
			int r=m%((z[i]*t[i])+y[i]);
			x+=val*z[i]+min(r/t[i],z[i]);
		}

		if(x>=M){
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}

	cout << ans << endl; 
	vi vec;
	int sum=0;
	for(int i=0; i<N; i++){
		int val=ans/((z[i]*t[i])+y[i]);
		int r=ans%((z[i]*t[i])+y[i]);
		vec.pb(val*z[i]+min(r/t[i],z[i])); 
		sum+=val*z[i]+min(r/t[i],z[i]);
	}
	int j=0;
	for(int i=0; i<sum-M;i++){
		if(vec[j]) vec[j]--;
		else i--;
		j++; j%=N;
	}
	for(auto x: vec) cout << x << ' '; cout << endl;	 

   return 0;
}

