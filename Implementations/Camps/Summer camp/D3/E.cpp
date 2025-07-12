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

int N;
int memo[1001][1001];
int l[1001],v[1001];

bool removed[1001][1001]; //step pos
int pref[1001][1001]; // step pos

bool can(int pos, int step){
	if(removed[step][pos]==true) return false;
	return true;
}

int solve(int i, int n){
	if(n==N-1) return 1;
	if(memo[i][n]!=-1) return memo[i][n];

	int nb=0,nb2=0;
	if(i+l[n]>N){
		nb=pref[n][N-2]-pref[n][i];
		nb+=pref[n][(i+l[n]-1)%N]-pref[n][0];
	}
	else{
		nb=pref[n][i+l[n]-1]-pref[n][i];
	}

	if(i-l[i]<0){

	}
	else{
		nb2=pref[n][i-1]-pref[n][0];
		nb2+=pref[n][(((i-l[n]-1)%(N))+(N))%(N)];
	}


	int nxt=(i+l[n]+nb)%(N),nxt2=(((i-l[n]-nb2)%(N))+(N))%(N);

	if((can(nxt,n) && solve(nxt,n+1)==1)||(can(nxt2,n) && solve(nxt2,n+1)==1) )return memo[i][n]=1;
	return memo[i][n]=0;
}

int32_t main(){
   boost;
   IO();

   int s;
   cin>>N>>s;
   for(int i=0; i<N; i++) cin>>l[i];
   for(int i=0; i<N; i++) for(int j=0; j<N; j++) removed[i][j]=false,memo[i][j]=-1,pref[i][j]=0;

   for(int i=0; i<N; i++){
   	cin>>v[i]; v[i]--;
   	for(int j=i; j<N; j++) removed[j][v[i]]=true,pref[j][v[i]]=1;
   }

for(int j=0; j<N; j++) for(int i=1; i<N; i++) pref[j][i]+=pref[j][i-1];

	

   if(solve(s-1,0)==1) cout << "Yes" << endl;
   else cout << "No" << endl;
	

   return 0;
}

