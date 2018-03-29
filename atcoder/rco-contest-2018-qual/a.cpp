#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
typedef vector<string> Board;

vector<Board> board;
// string dir = "UDLR";

// RDLU
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Result{
    int y,x,delta;
};

vector<int> rand_command(int T){
    vector<int> res(T);
    srand(time(NULL));
    rep(i,T){
        while(true){
            res[i] = rand()%4;
            if(i==0) break;
            if(!(dx[res[i]]+dx[res[i-1]] == 0 && dy[res[i]]+dy[res[i-1]] == 0)){
                break;
            }
        }
    }
    return res;
}


Result move(int y,int x,int dir,Board &b){
    Result res;
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    if(b[ny][nx] == '.'){
        res.x = nx;
        res.y = ny;
        res.delta = 0;
    }else if(b[ny][nx] == 'o'){
        res.x = nx;
        res.y = ny;
        b[ny][nx] = '.';
        res.delta = 1;
    }else if(b[ny][nx] == 'x'){
        res.x = nx;
        res.y = ny;
        res.delta = 0;
    }else if(b[ny][nx] == '#'){
        res.x = x;
        res.y = y;
        res.delta = 0;
    }
    return res;
}


// mi:mapID, 
int simulate(int boardID,int sy,int sx,vector<int> &cmd){
    Board bd = board[boardID];
    int score = 0;
    int y = sy, x = sx;
    bd[sy][sx] = '.';
    rep(i,cmd.size()){
        Result res = move(y,x,cmd[i],bd);
        score += res.delta;
        x = res.x;
        y = res.y;
        if (bd[y][x] == 'x') break;
    }
    return score;
}

int main(void){
    int N,K,H,W,T;
    cin>>N>>K>>H>>W>>T;
    board.resize(N);
    rep(i,N){
        rep(h,H){
            string row;
            cin>>row;
            board[i].push_back(row);            
        }
    }
    vector<int> sy(N),sx(N);
    rep(i,N){
        rep(y,H){
            rep(x,W){
                if(board[i][y][x] == '@'){
                    board[i][y][x] = '.';
                    sy[i] = y;
                    sx[i] = x;
                }
            }
        }
    }

    int test_num = 100;

    vector<int> res_m;
    vector<int> res_cmd;
    int res_sum_score = 0;


    rep(_,test_num){
        vector<pair<int,int>> score_id(N);
        vector<int> cmd = rand_command(T);
        rep(i,N){
            score_id[i] = {simulate(i,sy[i],sx[i],cmd),i};
        }
        sort(all(score_id));
        
        vector<int> m(K);
        int sum_score = 0;
        rep(k,K){
            m[k] = score_id[k].second;
            sum_score += score_id[k].first;
        }
        if(sum_score > res_sum_score){
            res_sum_score = sum_score;
            res_m = m;
            res_cmd = cmd;
        }
    }
    rep(i,K){
        cout<<res_m[i]<<(i==K-1 ? "\n" : " ");
    }
    rep(i,T){
        string RDLU="RDLU";
        printf("%c",RDLU[res_cmd[i]]);
    }
    cout<<endl;
    return 0;
}
