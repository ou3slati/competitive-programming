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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

vs t;

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N,k; cin>>N>>k;
      t.clear(); t.resize(k);
      string s; cin>>s;

      sort(all(s));
      string res;
      //cout << s << endl;
      for (int i=0; i<k; i++){
         t[i]+=s[i];
      }
      bool same=true;
      for (int i=1; i<k; i++) if(t[i]!=t[i-1]){same=false; break;}
      if(!same){cout << t[k-1] << endl; continue;}
      //for (int i=0; i<k; i++) cout << t[i] << endl;


      string st=s.substr(k,N-k);
      bool allsame=true; for (int i=1; i<sz(st); i++) if(st[i]!=st[i-1]){allsame=false; break;}

      if(allsame){
         res=t[0];
         for(int i=0; i<ceil((db)(N-k)/k); i++) res+=st[0];
      }
      else{
         res=t[0];
         res+=st;
      }
      cout << res << endl;
      //cout << endl;

   }


   return 0;
}

