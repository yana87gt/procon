#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(),(a).end()

struct Info
{
    int AC,penalty,tid;
    Info (int tid_){
        AC = penalty = 0;
        tid = tid_;
    }
    bool operator<(const Info &right) const {
        if(AC != right.AC){
            return AC > right.AC;
        }else if(penalty != right.penalty){
            return penalty < right.penalty;
        }else{
            return tid < right.tid;
        }
    }
};


int main(void){
    int T,P,R;
    while(cin>>T>>P>>R, T|P|R){
        vector<Info> info;
        rep(tid,T){
            info.push_back(Info(tid));
        }
        int wa[50][10] = {};
        rep(i,R){
            int tid, pid, time;
            string message;
            cin>>tid>>pid>>time>>message;
            tid--, pid--;
            if(message == "WRONG"){
                wa[tid][pid]++;
            }else{
                info[tid].AC++;
                info[tid].penalty += wa[tid][pid]*1200 + time;
            }
        }
        sort(all(info));
        for(Info i : info){
            printf("%d %d %d\n",i.tid+1, i.AC, i.penalty);
        }
    }

    return 0;
}
