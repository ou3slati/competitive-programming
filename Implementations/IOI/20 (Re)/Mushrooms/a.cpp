#include "mushrooms.h"

#include "bits/stdc++.h"
using namespace std;

typedef vector<int>vi;
#define pb push_back
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
#define sz(v) (int)v.size()

int C=70;
int A=1,B=0;
vi tyA={0},tyB;

int count_mushrooms(int N){
	int i=1; 

	while(i<3){
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

		if(N==2) return A;
	}

	while(i+1<N && max(sz(tyA),sz(tyB))<C){
		if(sz(tyA)>=2){
			vi vec={i,tyA[0],i+1,tyA[1]};
			int x=use_machine(vec)+1;
			if(x==1){
				tyA.pb(i); tyA.pb(i+1);
				A+=2;
			}
			else if(x==2){
				tyA.pb(i+1); tyB.pb(i);
				A++; B++;
			}
			else if(x==3){
				tyA.pb(i); tyB.pb(i+1);
				A++; B++;
			}
			else{
				tyB.pb(i); tyB.pb(i+1);
				B+=2;
			}
		}
		else{
			vi vec={i,tyB[0],i+1,tyB[1]};
			int x=use_machine(vec)+1;
			if(x==1){
				tyB.pb(i); tyB.pb(i+1);
				B+=2;
			}
			else if(x==2){
				tyB.pb(i+1); tyA.pb(i);
				A++; B++;
			}
			else if(x==3){
				tyB.pb(i); tyA.pb(i+1);
				A++; B++;
			}
			else{
				tyA.pb(i); tyA.pb(i+1);
				A+=2;
			}
		}
		i+=2;
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
