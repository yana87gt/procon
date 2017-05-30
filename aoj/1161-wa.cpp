#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define debug(x) cout<<#x<<": "<<x<<endl
vector<string> s(13);
map<char,int>c2n;
bool used[10];
int N,cnt;

void dfs(int y,int x,int sum)
{
	if(x>=(int)s[y].size()){
		dfs(y+1,x,sum);
		return;
	}
	char alpha = s[y][x];
	bool FirstAppear = (c2n.find(alpha)==c2n.end());
	bool MSdigit = (x+1==(int)s[y].size());
	/* 答えの段 */
	if(y==N)
	{
		if(MSdigit && sum>=10)return;
		int value=sum%10;

		if(FirstAppear)
		{
			if(used[value])return;
			c2n[alpha]=value;
			used[value]=true;
		}else if(c2n[alpha]!=value)return;

		if(MSdigit){
			if(value>0)cnt++;
		}
		else dfs(1,x+1,sum/10);
		
		if(FirstAppear)
		{
			c2n.erase(alpha);
			used[value]=false;
		}
		return;
	}

	/* 足す段 */

	//既出
	if(!FirstAppear)
	{
		if(MSdigit && c2n[alpha]==0)return;
		dfs(y+1,x,sum+c2n[alpha]);
		return;
	}

	//数字を決めて試す
	rep(k,10)
	{
		if(used[k])continue;
		if(MSdigit && k==0 && x>0)continue; 
		c2n[alpha]=k;
		used[k]=true;
		dfs(y+1,x,sum+k);
		c2n.erase(alpha);
		used[k]=false;
	}

}


int main(void){
	while(cin>>N,N)
	{
		c2n.clear();
		rep(i,10)used[i]=false;
		cnt=0;
		int maxlength=0;
		rep1(i,N)
		{
			cin>>s[i];
			reverse(s[i].begin(), s[i].end());
			maxlength=max(maxlength,(int)s[i].size());
		}
		if((int)s[N].size() == maxlength) dfs(1,0,0);
		cout<<cnt<<endl;
	}
	return 0;
}
