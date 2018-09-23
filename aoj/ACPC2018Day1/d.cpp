#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)

vector<string> s;
int Y,X;
int dx[4] = {-1,0,+1,0};
int dy[4] = {0,+1,0,-1};
char command[4] = {'L','D','R','U'};
struct State {
    int y,x,dir;
    bool operator<(const State& rhs) const {
        return (
            y != rhs.y ? y < rhs.y :
            x != rhs.x ? x < rhs.x :
            dir != rhs.dir ? dir < rhs.dir :
            false
        );
    }
    bool operator==(const State& rhs) const {
        return y == rhs.y && x == rhs.x && dir == rhs.dir;
    }

    void right_turn(){ dir = (dir+3)%4; }
    void left_turn(){ dir = (dir+1)%4; }
    // State next(int d){
    //     return (State){y+dy[d], x+dx[d], d};
    // }
    bool can_go_ahead(){
        return s[y+dy[dir]][x+dx[dir]] == '#';
    }
    void go_ahead(){
        y += dy[dir];
        x += dx[dir];
    }

};
struct Island {
    int sy,sx;
    vector<State> ring;
};

vector<Island> islands;

bool visited[500][500] = {};

bool ask(char c){
    cout<<"? "<<c<<endl;
    string ans;
    cin>>ans;
    return ans=="YES";
}

bool onland(int y,int x){
    return s[y][x] == '#';
}

void visit(int y,int x){
    visited[y][x] = true;
    rep(dir,4){
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        if(onland(ny,nx) && !visited[ny][nx]){
            visit(ny,nx);
        }
    }
}

Island get_island(int sy,int sx){
    State first = {sy,sx,0};
    bool finish = false;
    vector<State> ring;
    State cur = first;

    while(!finish){
        rep(turn,4){
            if(ring.size() >= 4 && cur == first){
                finish = true;
                break;
            }
            ring.push_back(cur);
            if(cur.can_go_ahead()){
                cur.go_ahead();
                break;
            }
            cur.left_turn();
        }
        cur.right_turn();
    }
    visit(sy,sx);
    return (Island){sy,sx,ring};
}

Island ask_island(){
    State cur = {0,0,3};
    while(ask('U')) cur.go_ahead();
    cur.left_turn();
    bool finish = false;
    vector<State> ring;
    State first = cur;

    while(!finish){
        rep(turn,4){
            if(ring.size() >= 4 && cur == first){
                finish = true;
                break;
            }
            ring.push_back(cur);
            if(ask(command[cur.dir])){
                cur.go_ahead();
                break;
            }
            cur.left_turn();
        }
        cur.right_turn();
    }

    auto corner = min_element(ring.begin(), ring.end());
    int start = corner - ring.begin();
    Island result = {first.y, first.x, {}};
    for(int i = start; i < (int)ring.size(); i++){
        result.ring.push_back(ring[i]);
    }
    rep(i,start){
        result.ring.push_back(ring[i]);
    }
    return result;
}

int main(){
    cin>>Y>>X;
    s.resize(Y);
    rep(y,Y){
        cin>>s[y];
    }
    rep(y,Y)rep(x,X){
        if(s[y][x] == '#' && !visited[y][x]){
            islands.push_back(get_island(y,x));
        }
    }
    Island res = ask_island();
    for (Island &il : islands){
        if(res.ring.size() == il.ring.size()){
            int R = res.ring.size();
            bool ok = true;
            rep(i,R){
                if(res.ring[i].dir != il.ring[i].dir){
                    ok = false;
                }
            }
            if(ok){
                int y = il.sy - res.sy;
                int x = il.sx - res.sx;
                cout<<"! "<<y<<" "<<x<<endl;
                return 0;
            }
        }
    }

    return 0;
}