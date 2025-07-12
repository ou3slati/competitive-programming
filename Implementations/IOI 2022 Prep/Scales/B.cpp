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

    vi order; 

    int i=0, j=0;
    while(i<3 || j<3){
    	if(i==3){
    		while(j<3) order.pb(b[j++]); 
    	}
    	else if(j==3){
    		while(i<3) order.pb(a[i++]); 
    	}
    	else{
    		int x=a[i], y=b[j], z; 
    		if(i+1==3 && j+1==3){
    			z=a[i-1];

    			int md=getMedian(x,y,z); 
    			order.pb(md);

    			if(md==x) i++; 
    			else j++;  
    		}
    		else{
    			if(i+1<3) z=a[i+1]; 
    			else z=b[j+1]; 

    			int mn=getLightest(x,y,z); 
    			order.pb(mn); 
    			
    			if(mn==x) i++; 
    			else j++; 
    		}
    	}
    }


    int W[] = {order[0], order[1], order[2], order[3], order[4], order[5]};
    answer(W);
}