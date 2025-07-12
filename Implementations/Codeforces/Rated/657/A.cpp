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
   	int N; cin>>N;
    str s; cin>>s;
    str res;
    for(int i=0; i<N-6; i++){
    	str ss; 
    	for(int j=i; j<i+7; j++) ss+=s[j];
    		//cout << ss << endl;
    	if(!((ss[0]=='a' ||ss[0]=='?') && (ss[6]=='a' ||ss[6]=='?'))) continue;
    	if(!((ss[1]=='b' ||ss[1]=='?') && (ss[5]=='b' ||ss[5]=='?'))) continue;
    	if(!((ss[2]=='a' ||ss[2]=='?') && (ss[4]=='a' ||ss[4]=='?'))) continue;
    	if(ss[3]!='c' && ss[3]!='?') continue;
    	
    	res=s;
    	res[i]=res[i+6]='a';
    	res[i+1]=res[i+5]='b';
    	res[i+2]=res[i+4]='a';
    	res[i+3]='c';

    	int cnt=0;
    	for(int i=0; i<N-6; i++){
    		str ss;
    		for(int j=i;j<i+7) cnt++;
    	}
    	if(cnt>1) continue;

    	for(int i=0; i<N; i++){
    		if(res[i]==?){
    			if(!i) res[i]='b';
    			else if(i==N-1 || res[i-1]!='a' ||(i<N-1 && res[i+1]!='a')) res[i]='b';
    			if(res[])
    		}
    	}
    }


    if(res.empty()){
    	cout << "No" << endl;
    }
    else cout << "Yes" << endl << res << endl;
   }
	

   return 0;
}

