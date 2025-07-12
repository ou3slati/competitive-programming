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

   int N,d,m; cin>>N>>d>>m;
   int a[N];
   vi t1,t2;

   int sum=0;
   for(int i=0; i<N; i++){
   	cin>>a[i];
   	if(a[i]>m) t1.pb(a[i]);
   	else{t2.pb(a[i]);sum+=a[i];}
	}
	if(t1.empty()){cout << sum << endl; return 0;}

	sort(rall(t1)); sort(all(t2));
	for(int i=1; i<sz(t2); i++) t2[i]+=t2[i-1];

	int sum2=0;
	int ans=0;

	for(int i=0; i<sz(t1); i++){
		sum2+=t1[i];
		int x=i+1;

		if(d*(x-1)<sz(t1)-x || d*(x-1)+x+1>N) continue;

		int eliminate=d*(x-1)-sz(t1)+x;

		int rm=0; if(eliminate>0 && !t2.empty()) rm=t2[eliminate-1];
		ans=max(ans,sum2+sum-rm);

	}
	cout << ans << endl;


	

   return 0;
}

// when he chooses x type 1
// eliminates d*(x-1) other elements (including nb-x type 1) 
// !!!!! if(d*(x-1)<nb-x) not possible
// if(d*(x-1)+1>N) not pos