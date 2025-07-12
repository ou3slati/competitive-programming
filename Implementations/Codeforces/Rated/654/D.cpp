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
   int TC; cin>>TC;
   while(TC--){
      int N,K; cin>>N>>K;
      int t[N][N];
      for(int i=0; i<N; i++) for(int j=0; j<N; j++) t[i][j]=0;

      if(K<N){cout << 0 << endl;
         for(int i=0; i<K; i++) t[i][0]=1;
         for(int i=0; i<N; i++){for(int j=0; j<N; j++) cout << t[i][j]; cout << endl;}
      continue;}

      K-=N;
      for(int i=0; i<N; i++) if(t[i][i]!=1) t[i][i]=1;
      for(int i=N-1; i>=0 && K; i--) if(t[i][i]!=1){t[i][i]=1; K--;}

      for(int i=1; i<N; i++){
         //t[N-i-1][N-1]=1; K--;
         for(int j=i; j<N && K; j++){
            if(t[j-i][i]!=1){t[j-i][j]=1;
            K--;}
         }
         //t[N-1][N-1-i]=1; K--;
         for(int j=i; j<N && K; j++){
            if(t[j][j-i]!=1){t[j][j-i]=1;
            K--;}
         }
      }
      int res=0;
      int mx=0,mn=INF;
      for(int i=0; i<N; i++){
         int s=0;
         for(int j=0; j<N; j++) s+=t[i][j];
         mx=max(mx,s); mn=min(mn,s);
      }
      res+=(mx-mn)*(mx-mn);
      mx=0; mn=INF;
      for(int i=0; i<N; i++){
         int s=0;
         for(int j=0; j<N; j++) s+=t[j][i];
         mx=max(mx,s); mn=min(mn,s);
      }
      res+=(mx-mn)*(mx-mn);
      cout << res << endl;
      for(int i=0; i<N; i++){for(int j=0; j<N; j++) cout << t[i][j]; cout << endl;}
      //cout << endl;
   }

   return 0;
}

