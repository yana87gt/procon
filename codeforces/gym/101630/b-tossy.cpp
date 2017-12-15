#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(s) s.begin(),s.end()
using namespace std;

int w,h;

bool solve(int a, int b, int c){
	if(2*a+b <= w && 2*a+ 2*c <= h) return true;
	if(a+b+c <= w && a+b+c+c <= h) return true;
	if(a+b <= w && a+b+c+c+c <= h) return true;
	return false;
}

int main(){
	vector<int> a(3);
	rep(i,3) cin>>a[i];
	cin>>w>>h;
	sort(all(a));
	
	rep(_,2){
		do {
			if(solve(a[0], a[1], a[2])){
				cout << "Yes" << endl;
				return 0;
			}
		} while(next_permutation(all(a)));
		swap(w,h);
	}
	cout << "No"<<endl;
	
	return 0;
} 
