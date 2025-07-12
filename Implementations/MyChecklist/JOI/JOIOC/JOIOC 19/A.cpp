#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

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

const int MX=5e3+10;

int N,v[MX][MX];
vi a(MX);

void precompute(){
	FOR(r,2,N){
		int j=r-1;
		multiset<int,greater<int>>s;
		ROF(l,0,r){
			int m=(l+r)/2;
			while(j>m){
				s.erase(s.find(a[j])); 
				j--;
			}

			if(r-l>=2){
				v[l][r]=*s.begin()+a[l]+a[r];
			}

			s.insert(a[l]);
		}
	}

	ROF(l,0,N) FOR(r,l+2,N){
		if(l) ckmax(v[l-1][r],v[l][r]);
		if(r+1<N) ckmax(v[l][r+1],v[l][r]);
	}
}

int main(){
	IO();

	cin>>N;
	FOR(i,0,N) cin>>a[i];

	precompute();

	int Q; cin>>Q;
	FOR(i,0,Q){
		int l,r; cin>>l>>r;
		l--; r--;
		cout << v[l][r] << endl;
	}



}