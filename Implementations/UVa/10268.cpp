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

int xx;
vi c;

void solve(string s){
   for (int i=0; i<sz(s); i++){
      int coef=1;
      int res=0;
      if(s[i]>='0'&&s[i]<='9'){
         if(i>0&&s[i-1]=='-') coef=-1;
         while(s[i]>='0'&&s[i]<='9'){
            res*=10; res+=s[i]-'0';
            i++;
         }
         i--;
      }
      else continue;
      c.pb(res*coef);
   }

}

int32_t main(){
   boost;
   cin>>xx;
   while(!cin.fail()){
      cin.ignore();
      string s; getline(cin,s);
      solve(s);
      reverse(all(c));
      //for (int i=0; i<sz(c); i++) cout << c[i] << ' ';
      //cout << endl;

      int n=1;
      int x=1;
      int res=0;
      for (int i=1; i<sz(c); i++){
         res+=c[i]*n*x;
         n++;
         x*=xx;
         //cout << x << endl;
      }
      cout << res << endl;

      c.clear();
      cin>>xx;
   }

}

