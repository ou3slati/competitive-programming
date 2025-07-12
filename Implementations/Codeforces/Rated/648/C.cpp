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
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
	int N; cin>>N;
	int a[N],b[N];
	int t[N+1][2];
	int h[N+1]; memset(h,0,N+1);
	for(int i=0; i<N+1; i++) h[i]=0;
	//cout << h[0] << endl;
	//unordered_set <int> s;
	for(int i=0; i<N; i++){
      cin>>a[i];
      t[a[i]][0]=i;
	}
	for(int i=0; i<N; i++){
      cin>>b[i];
      t[b[i]][1]=i;
	}
	for(int i=1;i<=N; i++){
      int x;
      int l=t[i][0],r=t[i][1];
      if(r<l) x=N-l+r;
      else x=r-l;
      h[x]++;
      //cout << x << endl;
	}
	int mx=0;
	for(int i=0; i<=N; i++){
      //int y=s.count(i);
      mx=max(mx,h[i]);
   }
	cout << mx << endl;


   return 0;
}

