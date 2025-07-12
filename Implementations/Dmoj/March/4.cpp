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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

map <int,vi> BIT;
int N,Q;

set <int> waitlist;
map <int,int> mp;
int cnt;

int LSB(int i){
   return i&(-i);
}

int getSum(int idx, int i){
   if(!mp.count(idx)) return 0;
   idx=mp[idx];
   int ans=0;
   while(i>0){
      ans+=BIT[idx][i];
      i-=LSB(i);
   }
   return ans;
}

void update(int idx, int i, int v){
   if(!mp.count(idx)){
      if(waitlist.empty()){
         mp[idx]=cnt++;
         BIT[mp[idx]].assign(N+1,0);
      }
      else{
         auto it=waitlist.begin();
         mp[idx]=*it;
         waitlist.erase(*it);
      }
   }

   int idxx=idx;
   idx=mp[idx];

   while(i<=N){
      BIT[idx][i]+=v;
      i+=LSB(i);
   }

   if(getSum(idxx,N)==0){
      waitlist.insert(idx);
      mp.erase(idxx);
   }
}

int32_t main(){
   boost;

   cin>>N>>Q;
   int t[N+1]={0};

   cnt=0;
   for(int i=1; i<=N; i++) update(0,i,1);

	while(Q--){
      int op; cin>>op;
      if(op==1){
         int x; cin>>x;
         update(t[x],x,-1);
         t[x]++;
         update(t[x],x,1);

      }
      if(op==2){
         int x; cin>>x;
         update(t[x],x,-1);
         t[x]--;
         update(t[x],x,1);
      }
      if(op==3){
         int l,r,c; cin>>l>>r>>c;
         cout << getSum(c,r)-getSum(c,l-1) << endl;
      }

	}

   return 0;
}

