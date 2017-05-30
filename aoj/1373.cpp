#include <bits/stdc++.h>
using namespace std;
map<int,int> e;	//<end,start>

bool insert(int x){
	//  [0]
	if(e.find(0)!=e.end())return false;

	auto itr = e.lower_bound(x);
	bool touchleft = (e.find(x-1)!=e.end());

	if(itr==e.end()){
		//  [  ]X #
		if(touchleft){
			e[x]=e[x-1];
			e.erase(x-1);
		}
		//  __X__#
		else e[x]=x;
		return true;
	}
	
	//  [left    right]
	int left=itr->second, right=itr->first;

	//  0[__X__ ]  or  0[  X]  [  ]
	if(left==1 && (x<right || (int)e.size()>1)) return false;

	if(left<=x){
		//  [   X]
		if(x==right)e.erase(itr);
		//  [__X ]
		else e[right] = x+1;
		return insert(left-1);
	}

	// __X__[  ]
	e[x]=x;

	// [  ]X__[  ]
	if(touchleft){
		e[x]=e[x-1];
		e.erase(x-1);
	}	

	//  X[  ]
	if(x==left-1){
		e[right] = e[x];
		e.erase(x);
	}
	return true;
}

int main(void){
	int n,x;
	cin>>n;
	while(n--){
		cin>>x;
		if(insert(x))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
