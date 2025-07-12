//Never stop trying
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	int N,K; cin>>N>>K;
   	int a[N];
   	int mx=-INF;
   	for(int i=0; i<N; i++){cin>>a[i]; mx=max(mx,a[i]);}

   	int mx2=-INF;
   	for(int i=0; i<N; i++){a[i]=mx-a[i]; mx2=max(mx2,a[i]);}

   	if(K%2==0) for(int i=0; i<N; i++)a[i]=mx2-a[i];
   	for(int i=0; i<N; i++) cout << a[i] << ' '; cout << endl;

   }
	

   return 0;
}

// 8 7 5 2 1 -5
// 0 1 3 6 7 12
// 12 11 9 6 5 0
//