#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int Y,X;

struct Item{
    int x1,x2,y1,y2;
    set<pair<int,int>> st;
    Item(){
        x1 = y1 = +100;
        x2 = y2 = -100;
    }
    void update(int x,int y){
        x1 = min(x1,x);
        x2 = max(x2,x);
        y1 = min(y1,y);
        y2 = max(y2,y);
        st.insert({x,y});
    }

    bool isRectangle(){
        return (x2-x1+1)*(y2-y1+1) == (int) st.size();
    }
    bool isin(int x,int y){
        return x1<=x && x<=x2 && y1<=y && y<=y2;
    }
};

int main(void){
    int T;
    cin>>T;
    while(T--){
        cin>>Y>>X;
        vector<string> s(Y);
        rep(y,Y) cin>>s[y];
        vector<Item> items(26);
        rep(y,Y)rep(x,X){
            if(s[y][x] == '.') continue;
            int a = s[y][x] - 'A';
            items[a].update(x,y);
        }
        for(auto it=items.begin(); it!=items.end();){
            if((int)it->st.size() == 0){
                it = items.erase(it);
            }else ++it;
        }

        size_t prev = 0;
        while(prev != items.size()){
            prev = items.size();
            for(auto it=items.begin(); it!=items.end();){
                if(it->isRectangle()){
                    for(int x=it->x1; x<=it->x2; x++){
                        for(int y=it->y1; y<=it->y2; y++){
                            for(auto &back : items){
                                if(back.isin(x,y)){
                                    back.update(x,y);
                                }
                            }
                        }
                    }
                    it = items.erase(it);
                }else ++it;
            }
        }
        cout<<(items.size() ? "SUSPICIOUS" : "SAFE")<<endl;
    }
    return 0;
}
