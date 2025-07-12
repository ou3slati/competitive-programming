#include "scales.h"

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


//------

void init(int T) {
    
    return;
}

void orderCoins() {
    int x=getLightest(1,2,3), y=getMedian(1,2,3), z;
    FOR(i,1,4) if(i!=x && i!=y) z=i; 

    vi a={x,y,z}; 

    x=getLightest(4,5,6), y=getMedian(4,5,6);
    FOR(i,4,7) if(i!=x && i!=y) z=i; 

    vi b={x,y,z}; 

    vi vec={a[0],b[0],a[1],b[1],a[2],b[2]}; 

    //for(int x: vec) cout << x << endl;

    
    vi order; 
	int hey=1;
    int rep=15;
    while(sz(order)<6){
    	vi cur;
    	for(int x: vec) if(x!=-1){
    		cur.pb(x); 
    		if(sz(cur)==4-hey) break; 
    	}

    	hey=0;

    	/*for(int x: vec) cout << x << ' '; cout << endl;
    	for(int x: cur) cout << x << ' '; cout << endl;
    	cout << endl;*/

    	if(!sz(cur)) break;

    	if(sz(cur)==1){
    		order.pb(cur[0]); 
    	}
    	else if(sz(cur)==2){
    		int k; 
    		FOR(i,1,7) if(i!=cur[0] && i!=cur[1]){
    			k=i; break; 
    		}

    		x=getMedian(k,cur[0],cur[1]); 
    		order.pb(x); 
    		for(int &val: vec) if(val==x){val=-1; break;}
    	}
    	else if(sz(cur)==3){
    		x=getLightest(cur[0],cur[1],cur[2]); 
    		order.pb(x); 
    		for(int &val: vec) if(val==x){val=-1; break;}
    	}
    	else{
    		x=getLightest(cur[1],cur[2],cur[3]);
    		for(int &val: vec){
    			if(val==x) val=cur[1];
    			else if(val==cur[1]) val=x;
    		}
    		hey=1;
    	}
    }


    int W[] = {order[0], order[1], order[2], order[3], order[4], order[5]};
    answer(W);
}