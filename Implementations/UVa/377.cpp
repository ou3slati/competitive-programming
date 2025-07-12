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

int convert(string s){
   int num=0;
   for (int i=0; i<sz(s); i++){
      num*=4;
      if(s[i]=='U') num++;
      else if(s[i]=='C')  num+=2;
      else if(s[i]=='D') num+=3;
   }
   return num;
}

int32_t main(){
   boost;

   int TC; cin>>TC;
   cout << "COWCULATIONS OUTPUT"<<endl;
   while(TC--){
      string n,m; cin>>n>>m;
      int x=convert(n),y=convert(m);
      for (int i=0; i<3; i++){
         char c; cin>>c;
         if(c=='A') y+=x;
         else if(c=='R') y/=4;
         else if(c=='L') y*=4;
      }
      string res; cin>>res;
      int z=convert(res);

      if(z==y) cout <<"YES"<< endl;
      else cout << "NO"<< endl;
   }
   cout << "END OF OUTPUT"<<endl;

}

