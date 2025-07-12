//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

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

const int MX=1e5;
int t[MX],s[MX],v[MX];
int N;
pi memo[MX];
int nxtt[MX];
vector<pi> vec;

int solve(int i){
   if(i==N) return 0;
   if(memo[i].fi!=-1) return memo[i].fi;
   int ans=solve(i+1);
   int ac=0;
   int j=nxtt[i];

   int x=solve(j)+v[vec[i].se];
   if(x>ans){
      ans=x; //nxt[i]=j;
      ac=1;
   }
   memo[i]={ans,ac};
   return memo[i].fi;
}

int32_t main(){
   boost;
   /*freopen("olympiad.in", "r", stdin);
   freopen("olympiad.out", "w", stdout);*/


	cin>>N;
   for(int i=0; i<N; i++) memo[i]={-1,-1};

	for(int i=0; i<N; i++){
      cin>>s[i]>>t[i]>>v[i];
      vec.pb({s[i],i});
	}
	sort(all(vec));

	for(int i=0; i<N; i++){
      int x=vec[i].fi+t[vec[i].se];
      if(x>vec[sz(vec)-1].fi){nxtt[i]=N; continue;}
      int l=1,r=N;
      while(l<r){
         int m=(l+r)/2;
         if(vec[m-1].fi>=x) r=m;
         else l=m+1;
      }
      nxtt[i]=l-1;
	}
	//for(int i=0; i<N; i++) cout << nxt[i] << ' '; cout << endl;


	cout << solve(0) << endl;


   int nb=0;
	for(int i=0; i<N;){
      if(memo[i].se==1){nb++;
         i=nxtt[i];}
      else i++;
	}
	cout << nb << endl;

   for(int i=0; i<N;){
      if(memo[i].se==1){cout << vec[i].se+1 << ' '; i=nxtt[i];}
      else i++;
	}


   return 0;
}

