//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MX=1e6+15;
int spf[MX];
int s;
int L,D;

void sieve(){
   for(int i=2; i<MX; i++) if(spf[i]==-1){
      for(int j=i; j<MX; j+=i) spf[j]=i;
   }
}

void f(int N){
   int Nr=N;
   if(N==1){
      s=0; return;
   }
   vi vec;
   for(; N>1; N/=spf[N]){
      vec.pb(spf[N]);
      //cout << N << endl;
      //N/=spf[N];
   }

   /*for(int i=2; i*i<=N; i++){
      while(N%i==0){
         vec.pb(i);
         N/=i;
      }
   }
   if(N>1) vec.pb(N);*/
   //for(auto x: vec) cout << x << ' '; cout << endl;


   vpi v;
   for(int i=0; i<sz(vec); i++){
      int x=vec[i];
      int p=0;
      while(i<sz(vec) && vec[i]==x){p++; i++;} i--;
      v.pb({x,p});
   }
   //for(auto x: v) cout << x.fi <<' ' << x.se << endl;
   for(int i=0; i<sz(v); i++){
      int x=v[i].fi,p=v[i].se;
      s*=((int)(pow(x,p+1)+0.5)-1)/(x-1);
   }
   //cout << s << endl;
   s-=Nr;
}

int solve(){
   int res=0;
	for(int N=L; N>=1; N--){
      s=1;
      f(N);
      //cout << s << endl; cout << endl;
      if(abs(s-N)<=D) res++;
      //cout << N << endl;
	}
	return res;
}

int main(){
   boost;
   memset(spf,-1,MX);
   sieve();

	cin>>L>>D;
	cout << solve() << endl;

   return 0;
}
//124963
