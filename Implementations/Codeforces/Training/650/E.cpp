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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int gcd(int a, int b){
   if(b==0) return a;
   return gcd(b,a%b);
}
int lcm(int a,int b){return (a*b)/gcd(a,b);}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N,KK; cin>>N>>KK; //K%=N;
      str s; cin>>s;
      vi vec;
      int t[26];
      for(int i=0; i<26; i++) t[i]=0;
      for(int i=0; i<N; i++) t[s[i]-'a']++;
      for(int i=0; i<26; i++) vec.pb(t[i]);
      //sort(rall(vec));
      //for(auto x:vec) cout << x << ' ';

      int res=1;
      for(int i=N; i>1; i--){
            int K=KK%i;
          int nb;
          if(K==0) nb=1;
          else nb=lcm(i,K)/K;


          //cout <<nb << endl;
          int nbc=i/nb;
          int cnt=0;
          for(int j=0; j<26; j++) cnt+=vec[j]/nb;
          //out << K << ' ' << nb << ' ' << nbc << ' ' << cnt <<endl;

          if(cnt>=nbc){res=i; break;}
      }
      cout << res << endl;
      cout << endl;
   }


   return 0;
}

