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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC;cin>>TC;
   while(TC--){
      int t[11][11];

      for (int i=0; i<9; i++){
         for (int j=0; j<9;j++){
            char c; cin>>c;
            t[i][j]=c-'0';
         }
      }
      /* (int i=0; i<9; i++){
         for (int j=0; j<9;j++) cout << t[i][j];
         cout << endl;
      }*/
      int j=0;
      for (int i=0; i<9; i++){
         if(i==0) j=0;if(i==1) j=3;if(i==2) j=6;
      if(i==3) j=1;
      if(i==4) j=4;
      if(i==5) j=7;
      if(i==6) j=2;if(i==7) j=5;if(i==8) j=8;
         /*if(i>=0 && i<=2) for (int j=0; j<9; j+=3){if(t[i][j]==1)t[i][j]=2; else t[i][j]=1;}

         if(i>=3 && i<=5)for (int j=1; j<9; j+=3) {if(t[i][j]==1)t[i][j]=2; else t[i][j]=1;}

         if(i>=6 && i<=8)for (int j=2; j<9; j+=3) {if(t[i][j]==1)t[i][j]=2; else t[i][j]=1;}*/
         if(t[i][j]==1)t[i][j]=2; else t[i][j]=1;

      }
      //cout << endl;
      for (int i=0; i<9; i++){
         for (int j=0; j<9;j++) cout << t[i][j];
         cout << endl;
      }
   }

}

