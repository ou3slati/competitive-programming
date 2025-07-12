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
    freopen("in.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

unordered_map <int,bool> mp;
unordered_map<int,int> cnt;

int32_t main(){
   boost;
   IO();
   
   int N; cin>>N;
   int t[N];

   int nb=0;
   for(int i=0; i<N; i++){
	cin>>t[i];
	if(!mp.count(t[i])){
		nb++;
		mp[t[i]]=true;
	}
   }

   /*set <int> s;
   multiset<int> ss;*/
   int i=0;
   int res=INF;
   int cur=0;

   for(int j=0; j<N;j++){
   	if(!cnt.count(t[j])){
   		cur++; cnt[t[j]]=1;
   	}
   	else cnt[t[j]]++;
   	while(cur==nb){
   		cnt[t[i]]--;
   		if(cnt[t[i]]==0) cur--;
   		i++;
   	} 
   	res=min(res,j-i+2);

   } // wrong

   /*while(1){
   	while(i<N-1 && sz(s)<nb){
   		i++;
   		s.insert(t[i]);
   		ss.insert(t[i]);
   	}
   	while(sz(s)>=nb){
   		res=min(res,i-j+1);
   		ss.erase(ss.find(t[j]));
   		if(ss.count(t[j])==0){
   			s.erase(t[j]);
   		}
   		j++;
   	}
   	if(i>=N-1) break;

   }*/
   cout << res << endl;

	

   return 0;
}

