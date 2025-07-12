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

int N;
int t[2000];
vi bit(2005,0);

int lsb(int i){return i&-i;}
void update(int idx, int v){
   /*if(v==1 && getSum(idx)-getSum(idx-1)>1) return;
   else if(v==-1)
   while(idx<2005){
      bit[idx]+=v;
      idx=lsb(idx);
   }*/
}


int MEX(){
   vi vec;
   for(int i=0; i<N; i++) vec.pb(t[i]);
   sort(all(vec));
   int nxt=0;
   for(int i=0; i<N; i++){
      if(vec[i]!=nxt) return nxt;
      else {while(i<N && vec[i]==nxt) i++; i--;}
      nxt++;
   }
   return vec[sz(vec)-1]+1;

   /*int l=1,r=2004;
   while(l<r){
      int m=(l+r)/2;
      if(getSum(m))
   }
   return l-1;*/
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
   cin>>N;
   int tt[N];
   for(int i=0; i<N; i++){cin>>t[i]; tt[i]=t[i]; update(t[i]+1,1);}

   vi vec;

   for(int i=0; i<N; i++){
      if(t[i]==i) continue;
      if(MEX()==i){update(t[i]+1,-1);t[i]=i; update(t[i]+1,1); vec.pb(i+1);}
      else{
         //int x=MEX();
         //cout << x << endl;
         for(int j=i+1; j<N; j++) if(t[j]==i){
            vec.pb(j+1);
            update(t[j]+1,-1);
            t[j]=MEX();
            update(t[j]+1,1);
         }
         update(t[i]+1,-1);
         t[i]=i;
         update(t[i]+1,1);
         vec.pb(i+1);
      }
      //for(int i=0; i<N; i++) cout << t[i] << ' '; cout << endl;
   }

   cout << sz(vec) << endl;
   for(auto x: vec) cout << x << ' ';
   cout << endl;
   //cout << endl;


   /*for(int i=0; i<N; i++) t[i]=tt[i];
   for(auto x: vec){
      t[x-1]=MEX();
      for(int i=0; i<N; i++) cout << t[i] << ' '; cout << endl;
   }*/

   }


   return 0;
}

