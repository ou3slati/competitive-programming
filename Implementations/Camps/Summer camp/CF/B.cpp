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

int32_t main(){
   boost;
   IO();

   str s; cin>>s;
   int N=sz(s);
   int hash[26];
   int hash2[26];
   for(int i=0; i<26;i++) hash[i]=0;
   for(int i=0; i<N;i++) hash[s[i]-'a']++;

   int even=0,odd=0;
   for(int i=0; i<26; i++){
   	int x=hash[i];
   	if(x%2==0) even++;
   	else odd++;
   	hash2[i]=hash[i];
   }

   
   if(N%2==0){


   	if(odd==2){
   		cout << "Yes" << endl;
   		bool done=false;
   		int a,b;
   		for(int i=0; i<26; i++) if(hash[i]%2==1){
   			if(done) b=i;
   			else {
			a=i; done=true;}
   		}
   		if(b>a){
   			hash[b]--; hash[a]++;
   		}
   		else {
   			hash[a]--; hash[b]++;
   		}

   		str res;
   		for(int i=0; i<26; i++){
   			for(int j=0; j<hash[i]/2; j++) res+=char('a'+i);
   		}
   		str cur=res;
   		reverse(all(cur));
   		res+=cur;
   		cout << res<< endl;
	}
   	else cout << "No" << endl;
   }

   else if(N%2==1){
   	if(odd==1 || odd==3){
		cout << "Yes" << endl;
		if(odd==1) {
			//for(int i=0; i<26; i++) cout << hash[i] << ' '; cout << endl;

			int nb=0;
			for(int i=0; i<26; i++) if(hash[i]>0) nb++;

			if(nb==1){
				str res;
				for(int i=0; i<26; i++) if(hash[i]>0) for(int j=0; j<hash[i]/2; j++) res+=char('a'+i);
				str cur=res;
			 reverse(all(cur));
				if(res[0]=='a') res+='b';
				else res+='a';
				res+=cur;
				cout << res << endl;

				return 0;
			}

			str res;
			int a;
			for(int i=0; i<26; i++) if(hash[i]%2==1) a=i;
			for(int i=25; i>a; i--) if(hash[i]>0){
				hash[i]--;
				hash[a]++;
				a=i;
				break;
			}
			for(int i=0; i<26; i++){
	   			for(int j=0; j<hash[i]/2; j++) res+=char('a'+i);
	   		}
	   		str cur=res; 
	   		res+=char(a+'a');
	   		reverse(all(cur));
	   		res+=cur;


	   		str res2;
	   		a=0;
	   		int cc=-1;
	   		for(int i=1; i<26; i++) if(hash2[i]%2==1){
	   			hash2[i]--;
	   			hash2[0]++;
	   			cc=i;
	   		}
	   		for(int i=0; i<26; i++){
	   			for(int j=0; j<hash2[i]/2; j++) res2+=char('a'+i);
	   		}
	   		cur=res2; 
	   		if(cc!=-1) res2+=char(a+'a');
	   		else res2+='b';
	   		reverse(all(cur));
	   		res2+=cur;

	   		cout << min(res,res2) << endl;

		}
		else{
			int a,b,c;
			bool done=false,done2=false;
			for(int i=0; i<26; i++) if(hash[i]%2==1){
				if(!done){
					done=true;
					a=i;
				}
				else if(done && !done2){
					done2=true;
					b=i;
				}
				else c=i;
			}
			int t[3]={a,b,c};
			sort(t,t+3);
			a=t[0]; b=t[1]; c=t[2];
			hash[a]++; 
			hash[c]--;
			str res;
	   		for(int i=0; i<26; i++) {
	   			for(int j=0; j<hash[i]/2; j++) res+=char('a'+i);
	   		}
	   		str cur=res; res+=char(b+'a');
	   		reverse(all(cur));
	   		res+=cur;
	   		cout << res<< endl;

		}
	}
   	else cout << "No" << endl;
   }
   return 0;
}


