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

int32_t main(){
   boost;
   IO();

   int N,Q; cin>>N>>Q;
   int t[N],mn[N],mx[N];
   for(int i=0; i<N; i++) cin>>t[i];

   for(int i=N-1; i>=0; i--){
   	mx[i]=mn[i]=t[i];
   	if(i<N-1) mx[i]=max(mx[i],mx[i+1]);
   	if(i<N-1) mn[i]=min(mn[i],mn[i+1]);
   }

   while(Q--){
   	int x,e; cin>>x>>e;
   	int a=x-e,b=x+e;
   	int l=0,r=N-1;
   	int ans=0;
   	while(l<=r){
   		int m=(l+r)/2;
   		if(mn[m]>=a && mx[m]<=b) ans=max(ans,N-m),r=m-1;
   		else l=m+1;
   	}
   	cout << ans << endl;
   }
	

   return 0;
}

