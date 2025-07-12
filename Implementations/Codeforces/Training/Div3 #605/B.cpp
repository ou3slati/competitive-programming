#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

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

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int t; cin >>t;
   while(t--){
      string s; cin>>s;
      int t[4]={0};
      for (int i=0; i<sz(s); i++){
         if(s[i]=='R') t[0]++;
         else if (s[i]=='L') t[1]++;
         else if (s[i]=='U') t[2]++;
         else t[3]++;
      }
      t[0]=min(t[0],t[1]);
      t[1]=t[0];
      t[2]=min(t[2],t[3]);
      t[3]=t[2];

      if((!t[0] &&!t[1]) && (t[2] && t[3]) ){cout <<2<< endl<<"UD" <<endl; continue;}
      if((t[0] &&t[1]) && (!t[2] && !t[3])) {cout <<2<< endl<<"RL" <<endl; continue;}

      cout << t[0]+t[1]+t[2]+t[3] << endl;
      for (int i=0; i<t[0]; i++) cout <<'R';
      for (int i=0; i<t[2]; i++) cout <<'U';
      for (int i=0; i<t[1]; i++) cout <<'L';
      for (int i=0; i<t[3]; i++) cout <<'D';
      cout << endl;
   }


}
