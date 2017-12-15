#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(s) s.begin(),s.end()
using namespace std;

int v[3];
int w[2];
bool solve(){
	sort(v,v+3);
	sort(w,w+2);
	do{
		do{
			if(v[0]*2+v[1] <= w[0] && v[0]*2+v[2]*2 <= w[1]){
				return true;
			}
			if(v[0]+v[1]+v[2] <= w[0] && v[0]+v[1]+v[2]*2 <= w[1]){
				return true;
			}
			if(v[0]*3+v[1]+v[2] <= w[0] && v[1]+v[2] <= w[1]){
				return true;
			}
		}while(next_permutation(v,v+3));
	}while(next_permutation(w,w+2));
	return false;
}

int main(){
	cin>>v[0]>>v[1]>>v[2]>>w[0]>>w[1];
	cout<<(solve() ? "Yes" : "No")<<endl;
	return 0;
} 
