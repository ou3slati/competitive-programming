#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

typedef string str;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//---------------------------------------------------//

const int MX=2e5;
int N; 
vi a(MX);


string f(string a, string b){
	str ans; 
	FOR(i,0,N){
		if(a[i]==b[i]) ans+=a[i];
		else{
			for(char c: {'J','O','I'}) 
				if(a[i]!=c && b[i]!=c) ans+=c; 
		}
	}
	return ans; 
}
str combine(vector<string>vec){
	string ans=vec[0];
	FOR(i,1,sz(vec)) ans=f(ans,vec[i]);
	return ans; 
}

int main() {
    IO();

    map<char,int>mp; 
    mp['J']=0;
    mp['O']=1;
    mp['I']=2;

    cin>>N; 
    string a[3]; 
    FOR(i,0,3) cin>>a[i];

    set<string>st; 
    FOR(m,1,1<<3){
    	vector<string>vec;
    	FOR(i,0,3) if((m>>i)&1) vec.pb(a[i]);
    	st.insert(combine(vec));
    }
    FOR(i,0,3) FOR(j,0,3) if(i!=j) FOR(k,0,3) if(i!=k && j!=k){
    	st.insert(combine({a[i],a[j],a[k]}));
    }

    //for(auto x: st) cout << x << endl;
    
    int Q; cin>>Q;
    string s; 
    FOR(idx,0,Q+1){
    	if(!idx){
    		cin>>s;
    	}
    	else{
    		int l,r; char c; cin>>l>>r>>c; 
    		l--; r--;
    		FOR(i,l,r+1) s[i]=c; 
    	}
    	if(st.count(s)) cout << "Yes" << endl;
    	else cout << "No" << endl;
    }

    
    

    return 0;
}
