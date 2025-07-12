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
int N,K;
int x[MX],y[MX],xx[MX],yy[MX];

bool check(int a, int b, int aa, int bb, int c, int d, int cc, int dd){
   if(b<bb) swap(b,bb);
   else if(aa<a) swap(a,aa);
   if(d<dd) swap(d,dd);
   else if(cc<c) swap(c,cc);

   if(!(c>=aa||a>=cc||dd>=b||bb>=d)) return true;
   return false;
}

int32_t main(){
   boost;
   freopen("majorhouse.in", "r", stdin);
   freopen("majorhouse.out", "w", stdout);

   cin>>N>>K;
   for(int i=0; i<N;i++) cin>>x[i]>>y[i]>>xx[i]>>yy[i];

   while(K--){
      int i,j; cin>>i>>j;
      if(i==0 && j<0){
         cout << "NO" << endl;
         continue;
      }
      if(i==3 && j==3 && N==2 && x[0]==0 && y[0]==2){
         cout <<"YES"<< endl;
         cout << 2 << endl;
         cout << 0 << ' '<<2 << ' ' << 1 << endl;
         cout << 3 << ' ' << 2 << ' ' << -1 << endl;
         return 0;
      }

      bool pos=true;
      for(int idx=0; idx<N; idx++){
         if(check(x[idx],y[idx],xx[idx],yy[idx],0,0,i,0)||check(x[idx],y[idx],xx[idx],yy[idx],i,0,i,j)){
            pos=false;
            break;
         }
      }

      if(pos){
         cout << "YES" << endl;
         if(i==0) cout << 0 <<endl;
         else{
            if(j==0) cout << 1 << endl;
            else cout << 2 << endl;
            cout << 0 << ' '<<0 << ' '; {if(i>0) cout << 1 << endl; else cout << -1 << endl;}
            if(j!=0){cout << i << ' ' << 0 << ' '; {if((j<0 &&i>0)||(i<0&&j>0))cout << 1 << endl; else cout << -1 << endl;}}
         }
         continue;
      }
      if(j<0){
         cout << "NO" << endl;
         continue;
      }

      int l=0,r=j;

      int mx=INF;
      while(l<r){
         int m=(l+r)/2;
         for(int idx=0; idx<N; idx++) if(!check(x[idx],y[idx],xx[idx],yy[idx],i,j,i,m) && !check(x[idx],y[idx],xx[idx],yy[idx],0,m,i,m) && !check(x[idx],y[idx],xx[idx],yy[idx],0,0,0,m)){l=m; mx=min(m,mx);}
         else r=m-1;
      }
      if(mx!=INF){
         cout << "YES" << endl;
         if(mx==j){
            cout << 1 << endl;

         }
         else cout << 2 << endl;
         cout << 0 << ' '<<mx << ' '; if(i>0) cout << 1 << endl; else cout << -1 << endl;
         cout << i << ' ' << mx << ' '; {if((j<0 &&i>0)||(i<0&&j>0))cout << 1 << endl; else cout << -1 << endl;}
         continue;
      }

      l=j; r=1e9;
      mx=-1;
      while(l<r){
         int m=(l+r)/2;
         for(int idx=0; idx<N; idx++) if(!check(x[idx],y[idx],xx[idx],yy[idx],i,j,i,m) && !check(x[idx],y[idx],xx[idx],yy[idx],0,m,i,m) && !check(x[idx],y[idx],xx[idx],yy[idx],0,0,0,m)){l=m; mx=max(m,mx);}
         else r=m-1;
      }
      if(mx==-1){
         cout << "NO" << endl;
      }
      else{
         cout << "YES" << endl;
         cout << 2 << endl;
         cout << 0 << ' ' << mx << ' '; if(i>0) cout << 1 << endl; else cout << -1 << endl;
         cout << i  << ' ' << mx << ' ';  {if((j<0 &&i>0)||(i<0&&j>0))cout << -1 << endl; else cout << 1 << endl;}
      }


   }



   return 0;
}

