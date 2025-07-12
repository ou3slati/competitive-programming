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

int A,B,C,D;
str s;
int N;
vi memo[26][26][26][26]; 
int ch[26];

int solve(int i, int a, int b, int c, int d){

	int cn=0,vo=0;
	if(!ch[a]) cn++; else vo++; 
	if(!ch[b]) cn++; else vo++; 
	if(!ch[c]) cn++; else vo++; 
	if(!ch[d]) cn++; else vo++; 

	int cns=0,cns2=0;
	
	cns++;
	if(c==d) cns++;
	if(b==d) cns++;
	if(a==d) cns++;
	
	if(ch[d]) swap(cns,cns2);


	
	

	if(i==sz(s)) return 1;
	//if(memo[i][a][b][c][d]!=-1) return memo[i][a][b][c][d];
	int ans=0;
	for(int j=0; j<26; j++){
		if(s[i]!='*' && j!=s[i]-'a')continue;

		if(ch[j]==0  && (cn<B||i<B) && (cns<D||i<D)){
			ans+=solve(i+1,b,c,d,j);
		}
		else if(ch[j]==1 && (vo<A||i<A) && (cns2<C||i<C)) ans+=solve(i+1,b,c,d,j);
	}
	return memo[i][a][b][c][d]=ans;
}



int32_t main(){
   boost;
   IO();


   for(int i=0; i<26; i++) ch[i]=0;
   ch[0]=ch['i'-'a']=ch['e'-'a']=ch['u'-'a']=ch['o'-'a']=1;
   cin>>A>>B>>C>>D;
   cin>>s;
   N=sz(s);
   for(int i=0; i<26; i++) for(int j=0; j<26; j++) for(int k=0; k<26; k++) for(int l=0; l<26; l++) memo[i][j][k][l].resize(26);
   cout << solve(0,0,0,0,0) << endl;
	

   return 0;
}

