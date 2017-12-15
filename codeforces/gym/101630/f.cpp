#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(s) s.begin(),s.end()
using namespace std;

int tx,ty,n;
bool mrx,mry,swxy;

void output(int x,int y){
	int r=1,u=-1;
	//printf("(%d,%d) \n",x,y);
	if(swxy){
		swap(x,y);
		r=-r;
		u=-u;
	}
	if(mry){
		u=-u;
		y=-y;
	}
	if(mrx){
		r=-r;
		x=-x;
	}
	printf("%d %d %d %d\n",x,y+u*(n-1),x+r*(n-1),y);

}

int mdist(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

void solve(){
	int k = tx/n +1;
	while(true){
		if(tx < n*k && ty < n*k && mdist(n*k,n*k,tx,ty) > k) break;
		k++;
	}
	printf("%d\n",k);
	if(n*(k-1) <= tx && tx < n*k && ty <= k*(n-1)){
		int down = k*(n-1)-ty;
		int x=-n, y=0;
		rep(i,k){
			if(down >= (n-1)){
				down -= n-1;
			}else{
				y += (n-1)-down;
				down = 0;
			}
			x += n;
			output(x,y);
		}
	}else{
		int xx = n*(k-1);
		int yy = k*(n-1);
		int cnt = 1;
		while(true){
			if(xx-cnt <= tx && ty <= yy+cnt) break;			
			cnt++;
		}
		cnt++;
		
		int x=-(n-1);
		int y=-1;
		rep(i,k){
			if(cnt>0){
				y += n;
				x += n-1;
				cnt--;
			}else{
				y += n-1;
				x += n;
			}
			output(x,y);
		}
	}
	
}

int main(){
	int m;
	scanf("%d ",&m);
	rep(i,m){
		cin>>tx>>ty>>n;
		if(tx<0){
			tx = -tx;
			mrx = true;
		}else mrx = false;
		
		if(ty<0){
			ty = -ty;
			mry = true;
		}else mry = false;
		
		if(tx<ty) {
			swap(tx,ty);
			swxy = true;
		}else swxy = false;
		
		solve();
	}
	return 0;
} 
