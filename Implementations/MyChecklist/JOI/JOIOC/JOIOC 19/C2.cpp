#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define dbgv(v) for(auto x: v) cerr << x << ' '; cerr << endl;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

const int nx[4]={-1,0,1,0},ny[4]={0,1,0,-1};

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

//-----------------------------------------------//

void ckmax(int &x, int y){
	x=max(x,y);
}

const int INF=2e9;
const int MX=800+10;

int N,M,g[MX][MX];

int main(){
	IO();

	int K; 
	cin>>K>>N>>M;
	string s; cin>>s;

	//LE && LW
	int cnt=0,LE=0,LW=0;
	FOR(i,0,K){
		cnt++;
		if(i==K-1 || (i+1<K && s[i+1]!=s[i])){
			if(s[i]=='W') ckmax(LW,cnt);
			else ckmax(LE,cnt);
			cnt=0;
		}
	}

	int i=-1,j=K; 
	while(i+1<K && s[i+1]==s[0]){
		i++;
		cnt++;
	}
	while(j-1>i && s[j-1]==s[0]){
		j--; 
		cnt++;
	}
	if(s[0]=='W') ckmax(LW,cnt);
	else ckmax(LE,cnt);

	//cout << LE  << ' ' << LW << endl;

	//------//

	FOR(i,0,N) FOR(j,0,M){
		cin>>g[i][j];
		if(g[i][j]==0) g[i][j]=INF; 
	}

	int l[N][M],r[N][M];
	FOR(i,0,N){
		int lst=-1;
		FOR(j,0,M){
			l[i][j]=lst+1;
			if(g[i][j]>LE) lst=j;
		}

		lst=M; 
		ROF(j,0,M){
			r[i][j]=lst-1;
			if(g[i][j]>LW) lst=j;
			
		}
	}

	vi vec;
	FOR(i,0,N) FOR(j,0,M) if(g[i][j]!=INF){
		vec.pb(r[i][j]-l[i][j]+1);
	}
	sort(all(vec));

	int ans=0;
	for(auto x: vec) ans+=(x==vec[0]);
	cout << vec[0] << endl;
	cout << ans << endl;
}