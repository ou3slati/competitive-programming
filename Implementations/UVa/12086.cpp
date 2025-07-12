#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

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

const int MXN=200000;
vi ft;
int N;

int LSB(int i){ return i&(-i); }

void update(int i, int x){
   while(i<=N){
      ft[i]+=x;
      i+=LSB(i);
   }
}

int getSum(int i){
   int ret=0;
   while(i>0){
      ret+=ft[i];
      i-=LSB(i);
   }
   return ret;
}

int sum(int l, int r){
   return getSum(r)-getSum(l-1);
}

int32_t main(){
   boost;

   int tc=0;
   while(1){
      cin>>N;
      if(N==0) break;
      /*if(tc) cout << endl;
      cout << "Case "<<++tc <<':'<<endl;*/
      int t[N+1];
      ft.assign(N+1,0);
      int x,y;
      vi vec;
      for (int i=1; i<=N; i++){
         cin>>x;
         vec.pb(x);
      }
      for (int i=1; i<=sz(vec); i++){
         int v=vec[i-1];
         ft[i]+=v;
         t[i]=v;
         ft[i+LSB(i)]+=ft[i];
      }
      char s;
      vector<pi> vec2(MXN,{0,0}),vec3(MXN,{0,0});
      int i=0,j=0;
      while(1){
         cin>>s;
         if(s=='E'){
            cin>>s>>s;
            break;
         }
         cin>>x>>y;
         if(s=='M'){vec2[i]={x,y}; i++;}
         else{vec3[j]={x,y}; j++;}
      }
      /*for (int i=0; i<sz(vec2); i++){
         s=vec2[i].fi;
         x=vec2[i].se.fi; y=x=vec2[i].se.se;
         if(s=="M") cout << sum(x,y) << endl;
         else{
            update(x,y-t[x]);
            t[x]=y;
         }
      }*/
   }

   return 0;
}

