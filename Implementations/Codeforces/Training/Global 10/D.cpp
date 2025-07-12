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

const int MX=2e5+10;
int N; str s;
int memo[MX][2][2];

int a,b,c;

bool check(int x, int y, int z){
	if(!x && !y) return (z==0);
	if(y==x-1) return true;
	return z==1;

}

int solve(int i, int x, int y){

	if(i==0){
		if(y==1 && b==0) return 0;
		if(y==1 && b==1 && a==0) return 0;
		if(y==0 && b==0 && a==1) return 0;
		if(x==1 && y==0 && a==0 && b==1) return 0;
		if(y==0 && a==1 && b==1 && c==0) return 0;

		return INF;
	}
	if(memo[i][x][y]!=-1) return memo[i][x][y];
	int ans=INF;


	if(x==0 && y==0) ans=min(ans,solve((i+1)%N,y,1)+(s[i]=='L'));
	if(y==1-x){
		ans=min(ans,solve((i+1)%N,y,0)+(s[i]=='R'));
		ans=min(ans,solve((i+1)%N,y,1)+(s[i]=='L'));
	}
	if(x && y) ans=min(ans,solve((i+1)%N,y,0)+(s[i]=='R'));


	return memo[i][x][y]=ans;
}
int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	cin>>N;

   	int ans=INF;
   	cin>>s;

   	for(int i=0; i<2; i++)for(int j=0; j<2; j++) for(int k=0; k<2; k++){
   		for(int ii=0; ii<N; ii++) for(int jj=0; jj<2; jj++) for(int kk=0; kk<2; kk++) memo[ii][jj][kk]=-1;
   		if(!check(i,j,k)) continue;
   		a=i; b=j; c=k; int nb=0;
   		if((a==0 && s[0]=='R')||(a==1 && s[0]=='L')) nb++;
   		if((b==0 && s[1]=='R')||(b==1 && s[1]=='L')) nb++;
   		if((c==0 && s[2]=='R')||(c==1 && s[2]=='L')) nb++;
   		ans=min(ans,solve(3%N,j,k)+nb);
   	}
   	cout << ans << endl;
   }



   return 0;
}

