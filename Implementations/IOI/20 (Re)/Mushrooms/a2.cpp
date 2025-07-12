#include "mushrooms.h"

#include "bits/stdc++.h"
using namespace std;

typedef vector<int>vi;
#define pb push_back
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
#define sz(v) (int)v.size()

int C=25;
int A=1,B=0;
vi tyA={0},tyB;

int count_mushrooms(int N){
	int i=1; 
	while(i<N && max(sz(tyA),sz(tyB))<C){
		vi vec={0,i};
		int x=use_machine(vec);
		x++;

		if(x==1){
			tyA.pb(i);
			A++;
		}
		else{
			tyB.pb(i);
			B++;
		}
		i++;
	}

	C=max(sz(tyA),sz(tyB));

	while(i<N){
		int cnt=0; 
		vi vec;
		while(i<N && cnt<C){
			if(sz(tyA)>=sz(tyB)){
				vec.pb(tyA[cnt]); 
				vec.pb(i);
			}
			else{
				vec.pb(tyB[cnt]); 
				vec.pb(i);
			}

			i++;
			cnt++;
		}

		int x=use_machine(vec); x++;

		if(sz(tyA)>=sz(tyB)){ //A used
			int b=x/2,a=cnt-b;
			A+=a; B+=b;
			if(x%2==0) tyB.pb(vec.back());
			else tyA.pb(vec.back());
		}
		else{ // B used
			int a=x/2,b=cnt-a;
			A+=a; B+=b;
			if(x%2==0) tyA.pb(vec.back());
			else tyB.pb(vec.back());
		}

		C=max(sz(tyA),sz(tyB));
	}
	return A; 
}
