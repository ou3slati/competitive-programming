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

str s; 
int N;
const int MX=1e5+10;
int memo[MX][2];

int solve(int i, int st){
	if(i==N && st==0) return 0;
	if(i==N) return INF;
	if(memo[i][st]!=-1) return memo[i][st];
	int ans=INF;
	if(st==1){
		ans=min(ans,solve(i+1,0)+10-(s[i]-'0'));
		ans=min(ans,solve(i+1,1)+10-(s[i]-'0')-1);
	}
	if(st==0){
		ans=min(ans,solve(i+1,1)+(s[i]-'0')+1);	
		ans=min(ans,solve(i+1,0)+(s[i]-'0'));
	}

	return memo[i][st]=ans;
}

int32_t main(){
   boost;
   IO();
   memset(memo,-1,sizeof(memo));
   str ss;
   cin>>ss;
   s+='0';
   N=sz(s);
   
   cout << solve(0,0) << endl;
	

   return 0;
}

