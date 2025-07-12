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
const ll INF = 2012;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("bbreeds.in", "r", stdin); 
    freopen("bbreeds.out", "w", stdout); 
#endif 
}

str s; 
int N;
int memo[1001][1001];

bool check(){
	int cnt=0;
	for(auto x: s){
		if(x=='(') cnt++;
		else if(!cnt) return false;
		else cnt--;
	}
	if(cnt) return false;
	return true;
}

int solve(int i, int r){
	if(i==N&&r==0) return 1;
	if(i==N) return 0;
	if(memo[i][r]!=-1) return memo[i][r];
	int ans=solve(i+1,r);
	if(s[i]=='(') ans=(ans+solve(i+1,r+1))%MOD;
	else if(r) ans=(ans+solve(i+1,r-1))%MOD;
	return memo[i][r]=ans;
}

int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));

   cin>>s;
   N=sz(s);

   if(!check()){
   	cout << 0 << endl;
   	return 0;
   }
   cout << solve(0,0) << endl;
   
	

   return 0;
}

