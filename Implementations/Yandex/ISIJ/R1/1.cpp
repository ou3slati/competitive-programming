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

int32_t main(){
   boost;
   /*ofstream cout ("casting.out");
   ifstream cin ("casting.in");*/

   int T; cin>>T;
   int N,a,b,c; cin>>N>>a>>b>>c;
   if(T==2){
      cout << min(min(a,b),c);
   }
   else{
      if(a+b<=N||a+c<=N ||b+c<=N){cout << 0 << endl; return 0;}
      int t[3]={a,b,c};
      int res=INF;
      for(int i=0; i<3; i++) for(int j=i+1; j<3; j++){
         a=t[i],b=t[j];
         for(int k=0; k<3; k++) if(k!=i && j!=k) c=t[k];

         /*if(a+b+c<=N)res=0;
         else if(a+b>=N){
            res=min(res,max(a+b-N,c));
         }
         else{
            res=min(res,max((ll)0,c-(N-a-b)));
         }*/

         int x=a+b-N;
         int y=min(c-(b-x)-max((ll)0,c-b),c-(a-x)-max((ll)0,c-a));
         if(y<=0) res=0;
         else res=min(res,y);


      }
      cout << res << endl;

   }


   return 0;
}

