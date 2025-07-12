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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int op(char c){
   if(c>='0' && c<='9') return c-'0';
   return c-'A'+10;
}

int32_t main(){
   boost;
   string s;
   while(cin>>s){
      int N=sz(s);
      int dist[N][N];
      memset(dist,0,sizeof(dist));
      for(int i=0; i<N; i++) dist[i][0]=1;

      int ans=0;
      for(int i=0; i<N-1; i++)
         for(int j=0; j<N; j++){
            if(s[i]!='?' && j!=op(s[i])-1) continue;
            for(int k=0; k<N; k++){
               if(abs(k-j)<=1 || (s[i+1]!='?' && k!=op(s[i+1])-1)) continue;
               dist[k][i+1]+=dist[j][i];
            }
         }

      for(int i=0; i<N; i++) ans+=dist[i][N-1];
      cout << ans << endl;
      //cout << endl;
   }

   return 0;
}

