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


int a,b,c,d,e;
int t[5];
bool pos;

void solve(int val,int m){
   if(val==23 &&m==(1<<5)-1){
      pos=true;
      return;
   }
   if(m==(1<<5)-1) return;

   for (int j=0; j<5; j++) if((m&(1<<j))==0){
      solve(val*t[j],m|(1<<j));
      solve(val-t[j],m|(1<<j));
      solve(val+t[j],m|(1<<j));
   }
   return;
}

int32_t main(){
   boost;
   cin>>a>>b>>c>>d>>e;
   while(a||b||c||d||e){
      t[0]=a;t[1]=b;t[2]=c;t[3]=d;t[4]=e;
      pos=false;
      for (int i=0; i<5 && !pos; i++) solve(t[i],1<<i);
      if(pos) cout << "Possible"<< endl;
      else cout << "Impossible"<< endl;
      cin>>a>>b>>c>>d>>e;
   }

}

