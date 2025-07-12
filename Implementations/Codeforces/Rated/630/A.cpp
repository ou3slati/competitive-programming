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
      int N; cin >>N;
      vi  s[N];
      for (int i=0; i<N; i++) {
         int x; cin>>x;
         for (int j=2; j*j<=x; j++){
            while(x%j==0){
               s[i].pb(j);
               x/=j;
            }
         }
         if(x>1) s[i].pb(x);
      }
      for (int i=0; i<N; i++) sort(all(s[i]));
      /*for (int i=0; i<N; i++){
         for (auto x:s[i]) cout << x << ' ';
         cout << endl;
      }
      cout << endl;*/

      int c[N]; for (int i=0; i<N; i++) c[i]=0;
      int m=0;
      for (int i=0; i<N; i++){

       if(c[i]==0){  //if(c[i]!=0) continue;
         m++;
         //cout <<m << endl;
         c[i]=m;
         int mx=0;
         int xx=-1;
         for(int o=0; i<sz(s[i]);o++){
            int x=s[i][o];
            //cout << x << endl;
            int nb=0;
            for(int j=0; j<N; j++) if(lower_bound(all(s[j]),x)!=s[j].end()&&i!=j&& c[j]!=0) nb++; //cout << j<< ' ';
            if(nb>mx){
               mx=nb;
               xx=x;
            }
            //cout << mx << endl;
         }
         if(xx!=-1){
            for(int j=0; j<N; j++) if(lower_bound(all(s[j]),xx)!=s[j].end() &&i!=j&& c[j]!=0) c[j]=m;
         }
       }

       for (int i=0; i<N; i++) cout << c[i]<< ' ';
       cout << endl;
      }
      /*cout <<m << endl;
      for (int i=0; i<N; i++) cout << c[i] << ' ';*/
      cout << endl << endl;

   }

}

