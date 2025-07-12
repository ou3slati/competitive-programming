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

int power(int n, int k){
   int res=1;
   for (int i=0; i<k; i++) res*=n;
   return res;
}

int32_t main(){
   boost;
   int sv[33000]={0};
   sv[1]=1;
   for (int i=2; i<33000; i++) if(!sv[i]){
      sv[i]=i;
      for (int j=i*i; j<33000; j+=i) sv[j]=i;
   }

   string s; getline(cin,s);
   while(s!="0"){
      vi vec;
      for (int i=0; i<sz(s); i++){
         if(s[i]>='0'&&s[i]<='9'){
            int x=0;
            while(s[i]>='0'&&s[i]<='9'){
               x*=10; x+=s[i]-'0';
               i++;
            }
            i--;
            vec.pb(x);
         }
      }
      int N=1;
      for (int i=0; i<sz(vec); i+=2){
         N*=power(vec[i],vec[i+1]);
      }
      N--;
      vi f;
      while(N!=1){
         f.pb(sv[N]);
         N/=sv[N];
      }
      sort(f.rbegin(),f.rend());
      vpi res;
      for (int i=0; i<sz(f); i++){
         int x=f[i]; int p=0;
         while(i<sz(f)&&f[i]==x ){i++; p++;}
         i--;
         res.pb({x,p});
      }
      for (int i=0; i<sz(res); i++){
         if(i!=0)cout << ' ';
         cout << res[i].fi << ' '<< res[i].se;
      }
      cout << endl;
      getline(cin,s);
   }
}

