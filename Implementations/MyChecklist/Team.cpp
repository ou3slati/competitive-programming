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

const int MOD = 1e9+9; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

/*void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}*/

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("team.in", "r", stdin); 
    freopen("team.out", "w", stdout); 
#endif 
}


const int MX=1001;

int N,M,K;
vi a(MX),b(MX);
int match[MX];

int memo[MX][MX][11][2];


int solve(int i, int j, int r, int st){
	if(r==0) return 1;
	if(i>=N || j>=M) return 0;  

	if(memo[i][j][r][st]!=-1) return memo[i][j][r][st];

	int ans;
	if(st==0){
		ans=(solve(i+1,j,r,0)+solve(i,j,r,1))%MOD;
	}
	else{
		ans=(ans+solve(i,j+1,r,1));
		if(match[i]<=j) ans=(ans+solve(i+1,j+1,r-1,0))%MOD;
	}

	return memo[i][j][r][st]=ans;
}

int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));
   cin>>N>>M>>K;
   for(int i=0; i<N; i++) cin>>a[i];
   for(int i=0; i<M; i++) cin>>b[i];

   sort(all(a)),sort(all(b)); reverse(all(b)); reverse(all(a));
   
   int j=0;
   for(int i=0; i<N; i++){
   	while(j<M && b[j]>=a[i]) j++;
   	match[i]=j;
   }

   /*for(int i=0; i<N; i++) cout << a[i] << ' '; cout << endl;
   for(int i=0; i<M; i++) cout << b[i] << ' '; cout << endl;
   for(int i=0; i<N; i++) cout << match[i] << ' '; cout << endl;*/

   cout << solve(0,0,K,0) << endl;
	

   return 0;
}

