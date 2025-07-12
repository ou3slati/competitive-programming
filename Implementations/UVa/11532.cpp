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
   int res=0;
   for (int i=0; i<sz(s); i++){
      res*=2;
      res+=s[i]-'0';
   }
   return res;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
      while(TC--){
         int p,q; cin>>p>>q;
         string res;
         for (int i=0; i<3*q; i++) res+='0';
         int r=p;
         for (int i=0; i<3*q&&r>0; i+=3){
            res[i]='1';
            if(r>1)res[i+2]='1';
            r-=2;
         }
         if(r>0) for (int i=0; i<r; i++) res.insert(0,"1");
         reverse(all(res));
         cout <<convert(res) << endl;
      }

}

