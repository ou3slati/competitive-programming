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

   vi c;
   vi vec;

   string s;
   getline(cin,s);

   while(!cin.fail()){
      for (int i=0; i<sz(s); i++) {
         if(s[i]<='9'&&s[i]>='0'){
            int x=0;
            while(s[i]<='9'&&s[i]>='0'){
               x*=10; x+=s[i]-'0';
               i++;
            }
            i--;
            c.pb(x);
         }
         else if(s[i]=='-'&&s[i+1]<='9'&&s[i+1]>='0'){
            int x=0;
            i++;
            while(s[i]<='9'&&s[i]>='0'){
               x*=10; x+=s[i]-'0';
               i++;
            }
            i--;
            c.pb(x*(-1));
         }
      }

      string ss; getline(cin,ss);
      for (int i=0; i<sz(ss); i++) {
         if(ss[i]<='9'&&ss[i]>='0'){
            int x=0;
            while(ss[i]<='9'&&ss[i]>='0'){
               x*=10; x+=ss[i]-'0';
               i++;
            }
            i--;
            vec.pb(x);
         }
         else if(ss[i]=='-'&&ss[i+1]<='9'&&ss[i+1]>='0'){
            int x=0;
            i++;
            while(ss[i]<='9'&&ss[i]>='0'){
               x*=10; x+=ss[i]-'0';
               i++;
            }
            i--;
            vec.pb(x*(-1));
         }
      }
      reverse(all(c));
      //for (int i=0; i<sz(c); i++) cout << c[i];
      for (int i=0; i<sz(vec); i++){
         int xx=vec[i];
         //cout << xx << endl;
         int x=1;
         int res=0;
         for (int j=0; j<sz(c); j++){
            res+=c[j]*x;
            x*=xx;
         }
         cout << res;
         if(i!=sz(vec)-1) cout << ' ';
      }
      cout << endl;
      c.clear(); vec.clear();
      getline(cin,s);
   }
}

