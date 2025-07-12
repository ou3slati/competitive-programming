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
//#define int ll
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

int main(){
   boost;
	/*freopen("river.in", "r", stdin);
   freopen("river.out", "w", stdout);*/
   int R,CC,A,B,C,D; cin>>R>>CC>>A>>B>>C>>D;
   swap(R,CC); swap(A,B); swap(C,D);

   int g[R][CC];
   for(int i=0; i<R; i++) for(int j=0; j<CC; j++) cin>>g[i][j];

   for(int i=0; i<R; i++) for(int j=0; j<CC; j++){
      if(i) g[i][j]+=g[i-1][j];
      if(j) g[i][j]+=g[i][j-1];
      if(i&&j) g[i][j]-=g[i-1][j-1];
   }
   int mx=-1,a,b,c,d;
   for(int i=0; i<R-A+1; i++) for(int j=0; j<CC-B+1; j++){
      int ii=i+A-1, jj=j+B-1;
      int x=0;
      x+=g[ii][jj];
      if(i) x-=g[i-1][jj];
      if(j) x-=g[ii][j-1];
      if(i&&j) x+=g[i-1][j-1];

      for(int k=i+1; k<=ii-1-C+1; k++) for(int l=j+1; l<=jj-1-D+1; l++){
         int kk=k+C-1,ll=l+D-1;
         int ans=0;
         ans+=g[kk][ll];
         if(k) ans-=g[k-1][ll];
         if(l) ans-=g[kk][l-1];
         if(k&&l) ans+=g[k-1][l-1];
         ans=x-ans;

         if(ans>mx){
            mx=ans;
            a=i+1,b=j+1,c=k+1,d=l+1;
         }
      }
   }
   //cout << mx << endl;
   cout << b << ' ' << a << endl << d << ' ' << c << endl;


   return 0;
}

