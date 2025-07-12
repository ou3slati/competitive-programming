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

int32_t main(){
   boost;
   IO();
   int TC; cin>>TC;
   while(TC--){
   	
	   	str s; cin>>s;
	   	int N=sz(s);

	   	int t[10];
	   	for(int i=0; i<10; i++) t[i]=0;
	   	for(int i=0; i<N; i++) t[s[i]-'0']++;
	   	sort(t,t+10);

	   	int res=N-t[9];

	   	for(char c='0'; c<='9'; c++) for(char cc='0'; cc<='9'; cc++){
	   		int cnt=0;
	   		//cout << c << ' ' << cc << endl;
	   		for(int i=0; i<N; i++){
	   			while(i<N && s[i]!=c) i++; i++;
	   			while(i<N && s[i]!=cc) i++;
	   			if(i<N) cnt+=2;
	   		}
	   		//cout << cnt << endl;
	   		res=min(res,N-cnt);
	   	}
	   	cout << res << endl;

   }
	

   return 0;
}

