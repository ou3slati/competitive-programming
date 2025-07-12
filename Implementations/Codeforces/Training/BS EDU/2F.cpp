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

bool check(str a, str b){
	int i=0;
	for(auto x: b){
		while(i<sz(a) && a[i]!=x) i++;
		i++;
	}
	return i<=sz(a);
}

int32_t main(){
   boost;
   IO();

   str t,p; cin>>t>>p;
   int N=sz(t);

   int a[N];
   for(int i=0; i<N; i++){
   	int x; cin>>x; a[i]=x-1;
   }

   int l=0,r=N-1;
   int ans;
   while(l<=r){
   	int m=(l+r)/2;

   	bool deleted[N]; for(int i=0; i<N; i++) deleted[i]=false;
   	for(int i=0; i<m; i++) deleted[a[i]]=true;
   	str cur;
   	for(int i=0;i<N; i++) if(!deleted[i]) cur+=t[i];

   	if(check(cur,p)){
   		ans=m; 
   		l=m+1;
   	}
   	else r=m-1;
   }

   cout << ans << endl;
	

   return 0;
}

