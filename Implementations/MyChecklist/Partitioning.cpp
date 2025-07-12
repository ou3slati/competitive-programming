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

/*void IO(){
#ifndef ONLINE_JUDGE 
    freopen("partition.in", "r", stdin); 
    freopen("partition.out", "w", stdout); 
#endif 
}*/

int N,K;
int g[16][16];

int mx[16][16];

int memo[16][32];

int solve(int i, int r){
   if(i==N) return 0;
   if(r==0) return mx[i][N];
   //if(memo[i][r]!=-1) return memo[i][r];
   int ans=INF;
   for(int j=i+1; j<=N; j++) ans=min(ans,max(solve(j,r-1),mx[i][j]));
   return memo[i][r]=ans;

}


int32_t main(){
   boost;
   IO();

   for(int i=0; i<16; i++) for(int j=0; j<32; j++) memo[i][j]=-1;

   cin>>N>>K;
   for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>g[i][j];

   int ans=INF;

   for(int i=0; i< (1)<<((min(N-1,K))); i++){
      int nb=0;
      vi walls;
      for(int j=0; j<N; j++) if((i)&((1)<<(j))) nb++,walls.pb(j+1);
      walls.pb(N);
      //for(auto x: walls) cout << x << ' '; cout << endl;

      if(nb>=N) continue;

      int t[N][nb+1];
      for(int i=0; i<N; i++) for(int j=0; j<=nb; j++) t[i][j]=0;

      for(int j=0; j<N; j++){
         int k=0;
         int idx=0;
         while(1){

            t[j][idx]+=g[j][k];
            
            k++;
            if(k==N) break;
            if(k>=walls[idx]) idx++;

         }
      }

      /*for(int i=0; i<N; i++){
         for(int j=0; j<=nb; j++) cout << t[i][j] << ' ';
         cout << endl;
      } cout << endl;*/

      for(int c=0; c<=nb; c++){
         for(int r=1; r<N; r++) t[r][c]+=t[r-1][c];
      }

      for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) mx[i][j]=-1;

      for(int j=0; j<=N; j++) for(int k=j+1; k<=N; k++){
         int x=0;
         for(int l=0; l<=nb; l++){
            int minus=0; if(j) minus=t[j-1][l];
            x=max(x,t[k-1][l]-minus);
         }
         mx[j][k]=x;
      }

      /*for(int i=0; i<=N; i++){for(int j=0; j<=N; j++) cout << mx[i][j]<< ' '; cout << endl;}
      cout << endl;*/

      //cout << solve(0,min(N-1,K-nb)) << endl;
      ans=min(ans,solve(0,min(N-1,K-nb)));
   }
   cout << ans << endl;

   
	

   return 0;
}

