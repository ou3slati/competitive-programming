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
   int p[11]={2,3,5,7,11,13,17,19,23,29,31};
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      int c[N];
      set <int> s;
      for (int j=0; j<N; j++){
         int x; cin>>x;
         for (int i=0; i<11; i++) if(x%p[i]==0){
            c[j]=i+1;
            s.insert(i+1);
            break;
         }
      }

      cout << s.size() << endl;

      int res[N]={0};
      int m=1;
      for (int i=0; i<N; i++) if(res[i]==0){
         for(int j=i; j<N; j++) if(c[i]==c[j]) res[j]=m;
         m++;
      }
      for (int i=0; i<N; i++)cout << res[i] << ' ';
      cout << endl;
   }

}

