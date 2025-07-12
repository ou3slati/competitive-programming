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

bool check(int a, int b, int c, int d){
	int cnt=0;
	if(a%2==1) cnt++;
	if(b%2==1) cnt++;
	if(c%2==1) cnt++;
	if(d%2==1) cnt++;
	return cnt<2;
}

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	int a,b,c,d; cin>>a>>b>>c>>d;
   	int x=0; if(min(min(a,b),c)>0) x++;
   	if(check(a,b,c,d)||check(a-x,b-x,c-x,d+x)) cout << "Yes" << endl;
   	else cout << "No" << endl; 
   }
	

   return 0;
}

