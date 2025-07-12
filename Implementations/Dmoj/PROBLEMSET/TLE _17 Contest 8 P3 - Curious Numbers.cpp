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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
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

vs vec;
string s;
vi pal;
unordered_map <int,bool> used;

void solve(int i){
   if(sz(s)==i){
      string res=s,sp=s;
      reverse(all(sp));
      vec.pb(res+sp);
      for(char c='0'; c<='9'; c++){
         vec.pb(res+c+sp);
      }
      return;
   }

   for(char c='0'; c<='9'; c++){
      if(s.empty()&&c=='0') continue;
      s+=c;
      solve(i);
      s.pop_back();
   }
}

int32_t main(){
   boost;
   for(int i=1; i<6;i++) solve(i);

   int Q,K; cin>>Q>>K;

   for(int i=0; i<10; i++) if(i%K==0)pal.pb(i);
   for(int i=0; i<sz(vec); i++){
      string s=vec[i];
      int x=0;
      for(int j=0; j<sz(s); j++){
         x*=10;
         x+=s[j]-'0';
      }
      if(x%K==0 && !used.count(x)){
         pal.pb(x);
         used[x]=1;
      }
   }

   sort(all(pal));

   while(Q--){
      int l,r; cin>>l>>r;
      auto it=lower_bound(all(pal),l), itr=upper_bound(all(pal),r);
      cout << itr-it << endl;
   }


   return 0;
}

