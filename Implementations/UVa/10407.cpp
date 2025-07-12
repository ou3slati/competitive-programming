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

int gcd(int a, int b){
   if(b==0) return a;
   return gcd(b,a%b);
}

int32_t main(){
   boost;
   int n; cin>>n;
   while(n){
      cin.ignore();
      vi vec; vec.pb(n);
      string s; getline(cin,s);
      for (int i=0; i<sz(s); i++){
         if(s[i]>='0' && s[i]<='9'){
            int x=0,c=1;
            if(i>0 && s[i-1]=='-') c=-1;
            while(s[i]>='0' && s[i]<='9' && i<sz(s)){
               x*=10;
               x+=s[i]-'0';
               i++;
            }
            if(x!=0) vec.pb(x*c);
         }
      }

      sort(all(vec));
      if(sz(vec)>2){
         for (int i=1; i<sz(vec); i++) vec[i]-=vec[0];
         int res=vec[1];
         for (int i=2; i<sz(vec); i++) res=gcd(res,vec[i]);
         cout << res << endl;
      }
      else{
         cout << vec[1]-vec[0] << endl;
      }
      cin>>n;
   }

}

