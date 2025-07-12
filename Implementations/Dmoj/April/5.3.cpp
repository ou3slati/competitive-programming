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

const int MXN=5*100000+10;
int N;
vi BIT(MXN,0); vi BIT2(MXN,0);

int t[MXN],p[MXN];

int LSB(int i){
   return i&(-i);
}


void update(int idx, int v){
   while(idx<=N){
      BIT[idx]+=v;
      idx+=LSB(idx);
   }
}

void update2(int idx, int v){
   while(idx<=N){
      BIT2[idx]+=v;
      idx+=LSB(idx);
   }
}

int sum(int i){
   int res=0;
   while(i>0){
      res+=BIT[i];
      i-=LSB(i);
   }
   return res;
}

int sum2(int i){
   int res=0;
   while(i>0){
      res+=BIT2[i];
      i-=LSB(i);
   }
   return res;
}

int getSum(int l, int r){
   return sum(r)-sum(l-1);
}
int getSum2(int l, int r){
   return sum2(r)-sum2(l-1);
}

bool sub1(){
   for (int i=2; i<=N; i++){
      if(p[i]!=p[i-1]+1) return false;
   }
   return true;
}



vi BITT(MXN,0);

void updatee(int idx, int v){
   while(idx<=N){
      BITT[idx]++;
      idx+=LSB(idx);
   }
}

int getSum(int i){
   int res=0;
   while(i>0){
      res+=BITT[i];
      i-=LSB(i);
   }
   return res;
}




int32_t main(){
   boost;
   cin>>N;

   for (int i=1; i<=N; i++) cin>>t[i];
   for (int i=1; i<=N; i++) cin>>p[i];
   if(sub1()){
      int ans=0;
      for (int i=1; i<=N; i++){
         ans+=getSum(N)-getSum(t[i]);
         cout << ans << endl;
         updatee(t[i],1);
      }


      return 0;
   }

   int res=0;
   for(int i=1; i<=N; i++){
      int x=p[i];
      update(x,t[x]-1);
      if(t[x]==1) res+=getSum(1,x);
      else if(x!=N) res+=getSum2(x+1,N)-getSum(x+1,N);
      update2(x,1);
      cout << res << endl;
   }

   return 0;
}


/*
8
2 1 2 2 1 2 2 1
8 6 5 1 3 2 7 4
*/
