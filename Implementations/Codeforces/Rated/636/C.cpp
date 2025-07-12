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
	int TC; cin>>TC;
	while(TC--){
      int N,k; cin>>N>>k;
      int t[N];
      for (int i=0;i<N; i++) cin>>t[i];
      multiset <int> s;
      vi vec;
      for (int i=0; i<N/2; i++){
         s.insert(t[i]+t[N-i-1]);
         vec.pb(min(t[i],t[N-i-1]));
      }
      sort(all(vec));
      /*for (int i=0; i<sz(vec); i++) cout << vec[i] << ' ';
      cout << endl;*/
      int res=INF;
      for (int i=2; i<=2*k; i++){
         int ans=0;
         int it=vec.end()-upper_bound(all(vec),i-1)+1;
         //cout << it << endl;
         if(i>k){
            int itr=lower_bound(all(vec),i-k)-vec.begin();
            //cout << itr << endl;
            //ans+=(max(itr,it))*2+N-max(itr,it);
            if(itr+it>=N/2) ans=N;
            else ans=it*2 + itr*2; + N/2-it-itr;
         }
         else ans=it*2+N/2-it;
         ans-=s.count(i);
         res=min(res,ans);

         //cout << res << endl;
      }
      cout << res << endl;
      cout << endl;

	}

   return 0;
}

