#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

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

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;

      /*int res=0;
      string s; cin>>s;
      for (int i=0; i<sz(s); i++)
         if(s[i]=='L'){
            int nb=0;
            while(s[i]=='L'){nb++; i++;}
            i--;
            res=max(nb,res);
         }

      cout << res+1 << endl;*/

      int N; cin>>N;
      int t[N];
      for (int i=0; i<N; i++)cin>>t[i];
      for (int i=0; i<N; i++){
         int x; cin>>x;
         t[i]-=x;
      }
      sort(t,t+N);

      int res=0;
      for (int i=0; i<N; i++){
         if(t[i]>0) res+=N-1-i;
         else{
            int ss=1-t[i];
            auto it=lower_bound(t,t+N, ss)-t;
            int ind=it;
            res+=N-ind;
         }
      }
      cout << res << endl;




}

