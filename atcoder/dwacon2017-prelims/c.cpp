#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

queue<int> qu[5];
map<int,int> mp;

int main(void){
	int N,A,cnt=0;
	cin>>N;
	rep(i,N){
		cin>>A;
		mp[i]=A;
		qu[A].push(i);
	}
	while(mp.size()){
		cnt++;
		auto itr = mp.begin();
		int num=itr->second;
		mp.erase(itr);
		qu[num].pop();

		int rem=4-num;
		while(rem){
			if(rem==3){
				if(qu[3].size()){
					mp.erase(qu[3].front());
					qu[3].pop();
					rem=0;
				}else if(qu[2].size()){
					mp.erase(qu[2].front());
					qu[2].pop();
					rem=1;
				}else if(qu[1].size()){
					mp.erase(qu[1].front());
					qu[1].pop();
					rem=2;
				}else rem=0;
			}
			if(rem==2){
				if(qu[2].size()){
					mp.erase(qu[2].front());
					qu[2].pop();
					rem=0;
				}else if(qu[1].size()){
					mp.erase(qu[1].front());
					qu[1].pop();
					rem=1;
				}else rem=0;
			}
			if(rem==1){
				if(qu[1].size()){
					mp.erase(qu[1].front());
					qu[1].pop();
					rem=0;
				}else rem=0;
			}		
		}
	}
	cout<<cnt<<endl;
	return 0;
}
