#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int n,k,s;
struct Cube{
    int x,y,z;
    int node[2];
    int share;//with back cube
    int form;//-1:reseach now, 0:not visited, 1:line, 2:ring
};

vector<Cube> c;
vector<int> graph;

//return form
int connect(int i,bool back){
    //it's found ring
    if(c[i].form == -1){
        graph.push_back(i);
        return 2;
    }
    rep(j,n){
        if(i==j || c[j].form>0 || i==c[j].node[!back])continue;
        int sx = s-abs(c[i].x-c[j].x);
        int sy = s-abs(c[i].y-c[j].y);
        int sz = s-abs(c[i].z-c[j].z);
        if(sx<=0 || sy<=0 || sz<=0)continue;
        //connected
        c[i].node[!back] = j;
        c[j].node[back] = i;
        c[(back ? i : j)].share = 2*(sx*sy+sy*sz+sz*sx);
        c[i].form = -1;
        c[i].form = connect(j,back);
        //2:ring
        if(c[i].form==2)return 2;
        //1:line
        if(back)return 1;
        back=true;
    }
    //not found new connect
    if(back && c[i].node[0]==-1)graph.push_back(i);
    return c[i].form = 1;
}

int main(){
    while(cin>>n>>k>>s,n|k|s){
        c.clear();
        graph.clear();
        int x,y,z;
        rep(i,n){
            cin>>x>>y>>z;
            c.push_back(Cube{x,y,z,{-1,-1},0,0});
        }
        rep(i,n)if(!c[i].form)connect(i,false);
        int maxsum = 0;
        rep(i,(int)graph.size()){
            bool round = false;
            int tail = graph[i];
            int head = c[tail].node[1];
            int sum = 0, link = 0;
            while(1){
                if(link+1==k)maxsum = max(sum,maxsum);
                if((round && tail==graph[i]) || head==-1)break;
                link++;
                sum += c[head].share;
                head = c[head].node[1];
                round |= graph[i]==head;
                //(k or less)-ring
                if(round && link<k){
                    //just k-ring
                    if(link+1==k)maxsum = max(sum+c[head].share,maxsum);
                    break;
                }
                if(link == k){
                    tail = c[tail].node[1];
                    sum -= c[tail].share;
                    link--;
                }
            }
        }
        cout<<(maxsum||k==1 ? 6*s*s*k-maxsum : -1)<<endl;
    }
    return 0;
}