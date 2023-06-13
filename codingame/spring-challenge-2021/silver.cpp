// -------- START : snippet -------- //
// #pragma GCC optimize "-O3"
#include <bits/stdc++.h>
using namespace std;

// -------- START : macro -------- //

#define ll long long
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)
#define rep1(i,n) for(long long i = 1; i <= (long long)(n); ++i)
#define len(c) (ll)c.size()
#define all(v) (v).begin(),(v).end()
#define lb(v,x) (lower_bound(all(v),x)-v.begin())
#define ub(v,x) (upper_bound(all(v),x)-v.begin())
#define has(c,x) (c.find(x) != c.end())
#define uniq(v) v.erase(unique(all(v)),v.end())
#define bit(k) (1LL<<(k))
#define INF int(1e9)

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

// -------- END : macro -------- //

// -------- START : debug macro -------- //

template<class T,class U> ostream& operator<<(ostream& ost, const pair<T,U> &p) { ost << "(" << p.first << ", " << p.second << ")"; return ost; }
#define ostream_container { ost << "{"; for(const auto &t : v) { if (&t != &*v.begin()) ost << ", "; ost << t; } ost << "}"; return ost; }
template<class T> ostream& operator<<(ostream &ost, const vector<T> &v) ostream_container
template<class T> ostream& operator<<(ostream &ost, const set<T> &v) ostream_container
template<class T,class U> ostream& operator<<(ostream &ost, const map<T,U> &v) ostream_container

template<class H> void recursive_debug(string s, H h) {
    cerr << s << " = " << h << endl;
}
template<class H,class... T> void recursive_debug(string s, H h, T... t) {
    int comma = s.find(',');
    cerr << s.substr(0,comma) << " = " << h << ", ";
    recursive_debug(s.substr(comma+1), t...);
}
#define debug(...) recursive_debug(#__VA_ARGS__, __VA_ARGS__)


int numberOfCells; // 37
int day; // the game lasts 24 days: 0-23
int nutrients; // the base score you gain from the next COMPLETE action
int sun; // your sun points
int score; // your current score
int oppSun; // opponent's sun points
int oppScore; // opponent's score
bool oppIsWaiting; // whether your opponent is asleep until the next day
int numberOfTrees; // the current amount of trees
int numberOfPossibleActions; // all legal actions

#define MAX_TREES_NUM 13
#define SEED_PERIOD 16
#define NUM_TREE_PLANED 10
int seed_rem = NUM_TREE_PLANED - 2;
int phase = 1;
int num_my_trees;
int num_opp_possible_complete;
int complete_cnt = 0;
vector<int> my_tree_size_count;
stringstream message;

vector<int> FIELD1 = {0,8,10,12,14,16,18,19,22,25,28,31,34};
vector<int> FIELD2 = {1,3,5,9,13,17,20,24,26,30,32,36};
vector<int> FIELD3 = {2,4,6,7,11,15,21,23,27,29,33,35};
vector<bool> my_territory;


vector<string> split(string s, string d) {
    vector<string> elems;
    s += d;
    int r;
    for (int l = 0; l < int(s.size()); l = r + d.size()){
        r = s.find(d, l);
        string item = s.substr(l, r - l);
        if (item != "") elems.push_back(item);
    }
    return elems;
}

struct Cell {
    public:
    int index; // 0 is the center cell, the next cells spiral outwards
    int richness; // 0 if the cell is unusable, 1-3 for usable cells
    int neigh[6]; // the index of the neighbouring cell for each direction
};
vector<Cell> cells;

struct Tree {
    public:
    int cellIndex; // location of this tree
    int size; // size of this tree: 0-3
    bool isMine; // 1 if this is your tree
    bool isDormant; // 1 if this tree is dormant
};
vector<Tree> trees;

int get_num_neigh_tree(int cellIndex) {
    int neigh_tree_cnt = 0;
    for (auto &tree: trees) {
        rep(j,6) {
            if (tree.cellIndex == cells[cellIndex].neigh[j]) neigh_tree_cnt++;
        }
    }
    return neigh_tree_cnt;
}

int calc_disturb(int cellIndex, int size) {
    vector<bool> is_mine(numberOfCells);
    for (Tree &tree: trees) {
        if (tree.isMine) {
            is_mine[tree.cellIndex] = true;
        }
    }
    auto dfs = [&](auto &&f, int cellIndex, int direction, int dist) {
        if (dist == 0) return 0;
        if (cellIndex == -1) return 0;
        return f(f, cells[cellIndex].neigh[direction], direction, dist-1) + is_mine[cellIndex];
    };
    int sum = 0;
    rep(direction, 6) {
        sum += dfs(dfs, cells[cellIndex].neigh[direction], direction, size);
    }
    debug("calc_disturb", cellIndex, sum);
    return sum;
} 

struct Action {
    public:
    // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
    string command;
    string kind;
    int cellIndex;
    int seedIndex;
    int treeIndex;
    double weight;

    Action(string possibleAction) {
        command = possibleAction;
        auto tokens = split(command, " ");
        kind = tokens[0];
        if (kind != "WAIT") {
            cellIndex = stoi(tokens[1]);
            rep(i, numberOfTrees) {
                if (trees[i].cellIndex == cellIndex) {
                    treeIndex = i;
                }
            }
        }
        if (kind == "SEED") {
            seedIndex = stoi(tokens[2]);
        }
        weight = 0;
    }

    void calc_weight() {
        if (kind == "WAIT") {
            weight = 1;
        } else if (kind == "COMPLETE") {
            int cost = 4;
            int disturb = calc_disturb(cellIndex, 3);
            if (phase == 1) {
                weight = 0;
            }
            else if (phase == 2) {
                weight = 1e10 * (10 - disturb);
            }
            else if (phase == 3) {
                if (my_tree_size_count[3] >= 4) {
                    weight = 1e10 * (10 - disturb);
                }
                else if (my_tree_size_count[3] == num_my_trees && sun >= my_tree_size_count[3] * 4) {
                    weight = 1e10 * (10 - disturb);
                }
                else if (day == 23) {
                    weight = 1e10 * cells[cellIndex].richness;
                }
                else {
                    weight = 0;
                }
            }
        } else if (kind == "GROW") {
            int tree_size = trees[treeIndex].size;
            int cost = (1 << (tree_size+1)) - 1 + my_tree_size_count[tree_size+1];
            int disturb = calc_disturb(cellIndex, 3);
            weight = 1e3 * (11 - my_tree_size_count[tree_size+1]) + 1e1 * cells[cellIndex].richness;
            if (phase == 1) {
                if (my_tree_size_count[3] < 3) {
                    weight = 1e3 * (tree_size + 1) + 1e1 * (10 - disturb);
                }
                else {
                    weight = 1e3 * (8 - cost) + 1e1 * (10 - disturb);
                }
            }
            else if (phase == 2) {
                weight = 0;
            }
            else if (phase == 3) {
                if (day == 23 || day + 3 - tree_size > 23) {
                    weight = 0;
                }
                else {
                    weight = 1e3 * (7 - my_tree_size_count[tree_size+1]) + 1e1 * (10 - disturb);
                }
            }
        } else if (kind == "SEED") {
            int cost = my_tree_size_count[0];
            int num_neigh_tree = get_num_neigh_tree(seedIndex);
            if (seed_rem <= 0) {
                weight = 0;
            }
            else if (day > 15) {
                weight = 0;
            }
            else if (num_neigh_tree == 0) {
                weight = 1e9 * cells[seedIndex].richness;
            }
            else if (cells[seedIndex].richness == 3) {
                weight = 1e8 * (4 - num_neigh_tree);
            }
            else if (num_neigh_tree == 1 && day >= 10) {
                weight = 1e7 * cells[seedIndex].richness;
            }
            else if (num_neigh_tree == 2 && day >= 12) {
                weight = 1e1 * cells[seedIndex].richness;
            }
            else {
                weight = 0;
            }
        } else {
            assert(false);
        }
    }

    bool operator<(const Action &rhs) const {
        return weight < rhs.weight;
    }
};
vector<Action> actions;


void decide_teritory() {
    int cnt[3] = {};
    for (int id : FIELD1) {
        if (cells[id].richness > 0) cnt[0]++;
    }
    for (int id : FIELD2) {
        if (cells[id].richness > 0) cnt[1]++;
    }
    for (int id : FIELD3) {
        if (cells[id].richness > 0) cnt[2]++;
    }
    int max_cnt = max({cnt[0], cnt[1], cnt[2]});
    my_territory.resize(37);
    if (cnt[0] == max_cnt) {
        for (int id : FIELD1) {
            my_territory[id] = true;
        }
    } else if (cnt[1] == max_cnt) {
        for (int id : FIELD2) {
            my_territory[id] = true;
        }
    } else if (cnt[2] == max_cnt) {
        for (int id : FIELD3) {
            my_territory[id] = true;
        }
    } else {
        assert(false);
    }
}

void update_phase() {
    if (phase == 1 && my_tree_size_count[3] >= 3 &&
        (my_tree_size_count[2]*2 + my_tree_size_count[1]*1 >= 8) && sun >= 12)
    {
        phase = 2;
    }
    else if (phase == 2 && complete_cnt >= 3) {
        phase = 3;
    }
    message << "P: " << phase << ", ";
}

int main()
{
    cin >> numberOfCells; cin.ignore();
    cells.resize(numberOfCells);
    for (int i = 0; i < numberOfCells; i++) {
        int index; // 0 is the center cell, the next cells spiral outwards
        int richness; // 0 if the cell is unusable, 1-3 for usable cells
        int neigh0; // the index of the neighbouring cell for each direction
        int neigh1;
        int neigh2;
        int neigh3;
        int neigh4;
        int neigh5;
        cin >> index >> richness >> neigh0 >> neigh1 >> neigh2 >> neigh3 >> neigh4 >> neigh5; cin.ignore();
        cells[i] = {index, richness, {neigh0, neigh1, neigh2, neigh3, neigh4, neigh5}};
        rep(j,6) debug(cells[i].neigh[j]);
    }
    sort(all(cells), [](Cell &lhs, Cell &rhs){return lhs.index < rhs.index;});

    // decide_teritory();

    // game loop
    while (1) {
        message.str("");
        message.clear();
        message << " ";

        cin >> day; cin.ignore();
        cin >> nutrients; cin.ignore();
        cin >> sun >> score; cin.ignore();
        cin >> oppSun >> oppScore >> oppIsWaiting; cin.ignore();
        cin >> numberOfTrees; cin.ignore();
        debug(day, nutrients, sun, score, oppSun, oppScore, oppIsWaiting, numberOfTrees);

        trees.clear();
        trees.resize(numberOfTrees);
        num_my_trees = 0;
        num_opp_possible_complete = 0;
        my_tree_size_count.clear();
        my_tree_size_count.resize(4);
        for (int i = 0; i < numberOfTrees; i++) {
            int cellIndex; // location of this tree
            int size; // size of this tree: 0-3
            bool isMine; // 1 if this is your tree
            bool isDormant; // 1 if this tree is dormant
            cin >> cellIndex >> size >> isMine >> isDormant; cin.ignore();
            trees[i] = {cellIndex, size, isMine, isDormant};
            if (isMine) {
                num_my_trees++;
                my_tree_size_count[size]++;
            }
            if (!isMine && !isDormant && size == 3) num_opp_possible_complete++;
        }
        chmin(num_opp_possible_complete, oppSun/4);

        cin >> numberOfPossibleActions; cin.ignore();
        actions.clear();
        for (int i = 0; i < numberOfPossibleActions; i++) {
            string possibleAction;
            getline(cin, possibleAction); // try printing something from here to start with
            actions.push_back(Action(possibleAction));
        }
        update_phase();

        for (int i = 0; i < numberOfPossibleActions; i++) {
            actions[i].calc_weight();
        }
        sort(all(actions));
        for (int i = 0; i < numberOfPossibleActions; i++) {
            if (actions[i].weight > 0) {
                debug(actions[i].command, actions[i].weight);
            }
        }
        if (actions.back().kind == "COMPLETE") complete_cnt++;
        else if (actions.back().kind == "SEED") seed_rem--;
        else if (actions.back().kind == "WAIT") {
            message << "R: " << seed_rem;
            actions.back().command += message.str();
        }
        cout << actions.back().command << endl;
    }
}