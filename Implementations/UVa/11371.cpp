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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   string s;
   while(cin>>s){
      string str=s,str2=s;
      sort(all(str2)); sort(str.rbegin(),str.rend());
      int nb=0,i=0;
      while(str2[i]=='0'){
         nb++; i++;
      }

      for (int x=0; x<nb; x++) str2.insert(i+1,"0");
      str2.erase(0,nb);

      int a=0,b=0;
      for (int i=0; i<sz(s); i++){
         a*=10; b*=10;
         a+=str[i]-'0'; b+=str2[i]-'0';
      }
      cout << a << " - "<<b << " = "<<a-b<<" = "<< "9 * "<<(a-b)/9 << endl;
   }

}

