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
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      int t[N];
      int mx=0;
      for (int i=0; i<N; i++){
         cin>>t[i];
         mx=max(mx,t[i]);
      }
      int res=1;
      for (int c=1; c<=mx; c++){
         int i=-1,j=N;
         int nb=0;
         while(1){
            i++; j--;
            while(i<N && t[i]!=c) i++;
            while(j>=0&&t[j]!=c) j--;

            if(i<j) nb++;
            else break;

            int m[20]={0};
            int xx=0;
            for (int p=i+1; p<j; p++){
               m[t[p]]++;
               xx=max(xx,m[t[p]]);
            }
            /*cout << i << ' ' << j << endl;
            cout << nb << ' '<<xx << endl;*/
            res=max(res,nb*2+xx);
         }

      }
      cout << res << endl;
      //cout << endl;
   }

}

