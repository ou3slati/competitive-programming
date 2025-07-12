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

int t[300001];
int pref[300001];
int memo[3000][3001];
int N,K;

int solve(int i, int r){
   if(!r) return 0;
   if(i==N) return -INF;
   if(memo[i][r]!=-1) return memo[i][r];
   int ans=solve(i,r-1);
   for(int j=i; j<N; j++){
      for(int k=j; k<N; k++){
         ans=max(ans,solve(k+1,r-1)+pref[k+1]-pref[j]);
      }
   }
   return memo[i][r]=ans;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   cin>>N>>K;
   pref[0]=0;
   int cnt=0;
   for(int i=0; i<N; i++){
      cin>>t[i];
      pref[i+1]=t[i];
      if(i) pref[i+1]+=pref[i];
      if(t[i]<0) cnt++;
   }

   if(cnt==0 ||(cnt==1 && K>1)){
      int res=0;
      for(int i=0; i<N; i++) if(t[i]>0) res+=t[i];
      cout << res << endl;
   }
   else if(cnt==1){
      int s=0,ss=0,sss=0;
      int idx=0;
      while(t[idx]>=0){s+=t[idx]; idx++;}
      sss+=t[idx]; idx++;
      while(idx<N && t[idx]>=0){ss+=t[idx]; idx++;}
      cout << max(max(s,ss),s+ss+sss) << endl;
   }
   else if(K==1){
      int s=0;
      int res=0;
      for(int i=0; i<N; i++){
         s+=t[i];
         res=max(res,s);
         if(s<=0) s=0;
      }
      cout << res << endl;
   }
   else if(N<=3005){
      int res=0;
      for(int i=0; i<N; i++) res=max(res,solve(i,K));
      cout << res << endl;
   }


   return 0;
}

