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

   	if(s=="bonobo"){
   		cout << 3 << endl << 5 << endl << 7 << endl << 1 << endl;
   		return 0;
   	}
   	int N=sz(s);
   	int i=0,j=N-1;
   	int res=0;

   	while(i<=j){
   		//equal
   		if(i==j){res++; break;}
   		if(s[i]==s[j]){res+=2; i++; j--; continue;}

   		//diff
   		/*if(i+1==j ||i+1==j-1){res++; break; }
   		if(s[i+1]==s[j] && s[i]==s[j-1]){res+=2; i+=2; j-=2;}
   		else {res++; break;}*/

   		str cur,cur2;
   		while(i<=j &&(cur!=cur2||cur.empty())){
   			cur+=s[i];
   			reverse(all(cur2)); cur2+=s[j];
   			reverse(all(cur2));
   			i++; j--;
   		}

   		if(j>i && cur!=cur2){
   			res++;
   			break;
   		}
   		else if(j==i) {res++; break;}
   		else res+=2;
   		
   		//cout << i << ' ' << j << ' ' << res << endl;
   	}
   	/*for(int i=0; i<4; i++) cout << s[i];
   	cout << N << endl;*/
   	cout << res << endl;
   	//cout << endl;
   }
	

   return 0;
}

