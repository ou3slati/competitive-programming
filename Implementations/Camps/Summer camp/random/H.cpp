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

const int MX=1e5+10;
str s;
int N;
int memo[MX][2][2][2];

int solve(int i, int x, int ob, int ob2){
	//cout << i << ' ' << x << ' ' << ob << ' ' << ob2 << endl;
	if(i==N && x==0 && ob==0 && ob2==0) return 1;
	if(i==N) return 0;

	if(memo[i][x][ob][ob2]!=-1) return memo[i][x][ob][ob2];

	int ans=0,a,b;
	int obp,obp2;

	a=0; b=0; obp=ob; obp2=ob2;
	if(s[i]=='1'){ if(ob==1) obp=0; if(ob2==1) obp2=0; }
	if((a+b+x)%2==((a)^(b))) ans=(ans+solve(i+1,((a+b+x)>1),obp,obp2))%MOD; 

	a=0; b=1; obp=ob; obp2=ob2;
	if(s[i]=='0') obp2=1; 
	if(ob==1 && s[i]=='1') obp=0;
	if((a+b+x)%2==((a)^(b))) ans=(ans+solve(i+1,((a+b+x)>1),obp,obp2))%MOD;

	a=1; b=0; obp=ob; obp2=ob2;
	if(s[i]=='0') obp=1; 
	if(ob2==1 && s[i]=='1') obp2=0;
	if((a+b+x)%2==((a)^(b))) ans=(ans+solve(i+1,((a+b+x)>1),obp,obp2))%MOD;

	a=1; b=1; obp=ob; obp2=ob2;
	if(s[i]=='0') obp=obp2=1;
	if((a+b+x)%2==((a)^(b))) ans=(ans+solve(i+1,((a+b+x)>1),obp,obp2))%MOD;

	return memo[i][x][ob][ob2]=ans;
}

int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));
   cin>>s; N=sz(s);
   reverse(all(s));
   cout << solve(0,0,0,0) << endl;
	

   return 0;
}

