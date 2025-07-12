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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

const int MX=3e5+70;
int N;
int t[MX];
int bit[MX];
int r[MX],l[MX];


int lsb(int i){return i&-i;}
void update(int idx){
   while(idx<MX){
      bit[idx]++;
      idx+=lsb(idx);
   }
}

int getSum(int idx){
   int ans=0;
   while(idx>0){
      ans+=bit[idx];
      idx-=lsb(idx);
   }
   return ans;
}

int32_t main(){
   boost;
	for(int i=0; i<MX; i++) r[i]=l[i]=bit[i]=0;
	cin>>N;

	vpi vec;
	for(int i=0; i<N; i++){
      cin>>t[i];
      vec.pb({t[i],i});
	}sort(all(vec));

	int nb=0;
	for(int i=0; i<N; i++){
      if(i==0||vec[i-1].fi<vec[i].fi) nb++;
      t[vec[i].se]=nb;
	}


	for(int i=0; i<N; i++){
      l[i]=getSum(t[i]-1);
      update(t[i]);
	}

	for(int i=0; i<MX; i++) bit[i]=0;
	for(int i=N-1; i>=0; i--){
      r[i]=getSum(t[i]-1);
      update(t[i]);
	}

	int res=0;
	for(int i=0; i<N; i++) res+=r[i]*l[i];
	cout << res << endl;

   return 0;
}

