#include "bits/stdc++.h"
using namespace std; 

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
typedef string str;
#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//------------------------------------------------------//

void ckmin(int &x, int y){x=min(x,y);}

const int MX=2e5;
int N;
map<str,int>mp;
vi out(MX);

vi memo((1<<20),-1);

int solve(int m){
	if(m+1==(1<<N)) return 0;
	if(memo[m]!=-1) return memo[m];

	int ans=1e9;
	FOR(i,0,N) FOR(j,i+1,N) if(!((m>>i)&1) && !((m>>j)&1)){
		int nm=m;
		nm|=(1<<i);
		nm|=(1<<j);
		int c=(out[i]!=j)+(out[j]!=i);
		ckmin(ans,solve(nm)+c);
	}
	return memo[m]=ans;
}

int main(){
	IO();

	cin>>N;
	int cnt=0;
	FOR(i,0,N){
		str s,ss; cin>>s>>ss;
		if(!mp.count(s)) mp[s]=cnt++;
		if(!mp.count(ss)) mp[ss]=cnt++;

		out[mp[s]]=mp[ss];
	}
	if(N&1){
		cout << -1 << endl;
		return 0;
	}

	cout << solve(0) << endl;

	
	
	
}
