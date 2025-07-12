#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int A,B,C; cin>>A>>B>>C;
      int t[A][B][C];

      for (int a=0; a<A; a++)
         for (int b=0; b<B; b++)
            for (int c=0; c<C; c++){
               cin>>t[a][b][c];
               int &i=t[a][b][c];

               if(b>0) i+=t[a][b-1][c];
               if(a>0) i+=t[a-1][b][c];
               if(a>0&&b>0) i-=t[a-1][b-1][c];

               if(c>0) i+=t[a][b][c-1];
               if(a>0 && c>0) i-=t[a-1][b][c-1];
               if(b>0&&c>0) i-=t[a][b-1][c-1];
               if(a>0&&b>0&&c>0) i+=t[a-1][b-1][c-1];
            }

      int res=(-1)*(pow(2,31)*20*20*20);

      for (int a=0; a<A; a++)
         for (int b=0; b<B; b++)
            for (int c=0; c<C; c++)
               for (int i=a; i<A; i++)
                  for (int j=b; j<B; j++)
                     for (int k=c; k<C; k++){
                        int x=t[i][j][k];
                        if(a>0) x-=t[a-1][j][k];
                        if(b>0) x-=t[i][b-1][k];
                        if(a>0 &&b>0) x+=t[a-1][b-1][k];

                        if(c>0)x-=t[i][j][c-1];
                        if(a>0 && c>0) x+=t[a-1][j][c-1];
                        if(b>0&&c>0) x+=t[i][b-1][c-1];
                        if(a>0 &&b>0&&c>0) x-=t[a-1][b-1][c-1];

                        res=max(res,x);
                     }

      cout << res << endl;
      if(TC)cout << endl;
   }
}


