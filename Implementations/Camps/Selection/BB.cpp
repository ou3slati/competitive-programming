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
str s; 
int memo[1000000];
int mx[1000000];

bool check(int i,int j, int l){
	str a=s.substr(i,l);
	str b=s.substr(j,l);
	//cout << i << ' ' << j << endl;
	//cout << a << ' ' << b << endl;
	return (a==b);
}

int solve(int idx){
	if(idx>N-idx-1) return 0;
	if(idx==N-idx-1) return 1;
	if(memo[idx]!=-1) return memo[idx];

	int ans=0;
	//cout << idx << endl;
	int j=N-idx-1;
	for(int i=idx; i<N && i<j; i++){
		if(check(idx,j,i-idx+1)==true) ans=max(ans,solve(i+1)+2);
		j--;
	}
	if(ans==0) ans=1;

	return memo[idx]=ans;
}

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	cin>>s;
   	N=sz(s);

   	/*str rev=s; reverse(all(rev));
   	cout << rev << endl;*/
   	
   	/*for(int i=0; i<(N); i++){
   		int r=N-i-1;
   		str cur,cur2;
   		mx[i]=0;
   		for(int j=i; j<N && r>=j; j++){
   			cur+=s[j]; 
   			reverse(all(cur2)); cur2+=s[r]; reverse(all(cur2));
   			if(cur==cur2) mx[i]=j-i+1;
   			r--;
   		}
   		
   	}*/


   	//for(int i=0; i<N; i++) cout << mx[i] << ' '; cout << endl;

   	memset(memo,-1,sizeof(memo));
   	cout << solve(0) << endl;
   }
	

   return 0;
}

