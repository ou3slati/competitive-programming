//Never stop trying
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

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int N,K;
int memo[12][((1)<<(12))][100];

int solve(int i, int m, int r){
   //cout << i << ' ' << m << ' ' << r << endl;
   if(i==N && r==0) return 1;
   if(r<0) return 0;
   if(i==N) return 0;

   if(memo[i][m][r]!=-1) return memo[i][m][r];

   vi vec; 
   for(int j=0; j<N; j++) if((m)&((1)<<(j))) vec.pb(j);
   //for(auto x: vec) cout << x << ' '; cout <<endl;

   int ans=0;
   for(int idx=0; idx<N; idx++) if(!((m)&((1)<<(idx)))){
      int nb=0;
      for(auto x: vec) if(idx<x) nb++;
      ans+=solve(i+1,((m)|((1)<<(idx))),r-nb);
   }
   return memo[i][m][r]=ans;

}

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
      cin>>N>>K;
      for(int i=0; i<N; i++) for(int j=0; j<(1<<(N)); j++) for(int k=0; k<=K; k++) 
         memo[i][j][k]=-1;
      cout << solve(0,0,K) << endl;
   }

   

   return 0;
}

