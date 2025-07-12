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
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
	int N,S; cin>>N>>S;
	int dist[N+1];
	for (int i=1; i<=N; i++) cin>>dist[i];
	set <pi> s[101];

	int a,b;
	for (int i=0; i<S; i++){
      cin>>a>>b;
      s[b].insert({dist[a],a});
	}
	int Q; cin>>Q;
	for (int q=0; q<Q; q++){
      char c; cin>>c;
      if(c=='A'){
         cin>>a>>b;
         s[b].insert({dist[a],a});
      }
      if(c=='S'){
         cin>>a>>b;
         s[b].erase({dist[a],a});
      }
      if(c=='E'){
         cin>>a>>b;
         for (int i=0; i<100; i++) s[i].erase({dist[a],a});
         dist[a]=b;
      }
      if(c=='Q'){
         cin>>a;
         if(s[a].empty()) cout << -1 << endl;
         else{
            for (auto x:s[a]){cout << x.se << endl; break;}
         }
      }
	}

   return 0;
}

