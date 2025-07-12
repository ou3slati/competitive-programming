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
	int N,H; cin>>N>>H;
	vector<pair<char,int>> v,vv;
	for (int i=0; i<N;i++){
      char a; int b; cin>>a>>b;
      v.pb({a,b});
	}
	for (int i=0; i<N;i++){
      char a; int b; cin>>a>>b;
      vv.pb({a,b});
	}
	int h1=H, h2=H;
	int res=0;
	for (int i=0; i<N; i++){
      if(v[i].fi=='A'){
         h2-=v[i].se;
         if(h2<=0){res=1; break;}
      }
      if(v[i].fi=='D'){
         if(vv[i].fi=='D'){
            h1-=v[i].se;
            if(h1<=0){res=2; break;}
         }
         else if(vv[i].fi=='A') vv[i].se=0;
      }
      if(vv[i].fi=='A'){
         h1-=vv[i].se;
         if(h1<=0){res=2; break;}
      }
      if(vv[i].fi=='D'){
         if(i==N-1 ||v[i+1].fi=='D'){
            h2-=vv[i].se;
            if(h2<=0){res=1; break;}
         }
         else if(i<N-1) v[i+1].se=0;
      }
	}

	if(res==0) cout << "TIE" << endl;
	else if(res==1) cout << "VICTORY" << endl;
	else cout << "DEFEAT" << endl;


   return 0;
}

