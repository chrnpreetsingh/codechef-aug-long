#include<bits/stdc++.h>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
	    int X;
	    bool B=false;
	    cin>>X;
	    for(int i=1;i*i<=X;i++){
	        if((X-2*i)%(i+2)==0 && X!=2*i){
	            B=true;
	            break;
	        }
	    }
	    if(B){
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
