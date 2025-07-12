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
   /*ofstream cout ("pobeda.out");
   ifstream cin ("pobeda.in");*/

   int N,K; cin>>N>>K;
   int t[N];
   bool all=true;
   for(int i=0; i<N; i++) {cin>>t[i]; if(t[i]>100) all=false;}
   sort(t,t+N);

   if(K==1){
      int res=0;
      for(int i=0; i<N; i++){
         int x=t[i];
         int nb=0;
         while(i<N && t[i]==x){
            nb++;
            i++;
         } i--;
         if(nb>=3) res++;
      }
      cout << res << endl;
   }
   else if(N<=100 && all){
      bool vis[101][101][101];
      int res=0;
      memset(vis,false,sizeof(vis));
      for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) for(int k=j+1; k<N; k++){
         int x=t[i],y=t[j],z=t[k];
         int tt[3]={x,y,z};
         if(ld(z)/x>K) continue;
         do{
            x=tt[0],y=tt[1],z=tt[2];
            if(!vis[x][y][z]){
               vis[x][y][z]=true;
               res++;
            }
         }while(next_permutation(tt,tt+3));
      }
      cout << res << endl;
   }
   else{
      int res=0;
      for(int i=0; i<N-2; i++){
         auto itr=upper_bound(t,t+N,t[i]*K)-t; itr--;
         int it=itr;
         if(it-i+1>=3){
            int NN=it-i;
            res+=(NN)*(NN-1)*6/2;
         }
      }
      cout << res << endl;
   }


   return 0;
}

