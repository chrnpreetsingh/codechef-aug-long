#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
	    long long N,X,Y;
	    cin>>N>>X>>Y;
	    vector<long long> A(N);
	    for(int i=0;i<N;i++){
	       cin>>A[i]; 
	    }
	    priority_queue<long long,vector<long long>,greater<long long>> pq;
	    for(auto it : A){
	        pq.push(it);
	    }
	    while(Y>0){
	        long long mn=pq.top();
	        if((mn^X)>mn){
	            pq.pop();
	            pq.push(mn^X);
	            Y--;
	        }
	        else{
	            if((Y&1)==0) break;
	            else{
	                pq.pop();
	                pq.push(mn^X);
	                break;
	            }
	        }
	    }
	    int cont=0;
	    while(!pq.empty()){
	        A[cont]=pq.top();
	        pq.pop();
	        cont++;
	    }
	    for(auto it : A){
	        cout<<it<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
