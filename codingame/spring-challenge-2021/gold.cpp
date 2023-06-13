// -------- START : snippet -------- //
// #pragma GCC optimize "-O3"
// #pragma GCC optimize("inline")
// #pragma GCC optimize("omit-frame-pointer")
// #pragma GCC optimize("unroll-loops") //Optimization flags

// #pragma GCC optimize("Ofast")

// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx")  //Enable AVX
// #pragma GCC target "bmi2"
// #include <x86intrin.h> //AVX/SSE Extensions

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

template<class T> void recursive_print(string s, T t) {
    cerr << s << " = ";
    for (auto &x : t) cerr << x << ", ";
    cerr << endl;
}
#define print(...) recursive_print(#__VA_ARGS__, __VA_ARGS__)


// Given variable
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

// Variables defined by me
#define MAX_SIZE_3_NUM 5
#define MAX_SIZE_2_NUM 3
#define MAX_SIZE_1_NUM 2
#define MAX_SIZE_0_NUM 1
#define PRIORITIZE_COMPLETE_DAY 23
#define MAX_TREES_NUM 13
#define LAST_GROW_2_TO_3_DAY 19
#define LAST_SEED_DAY 17
int phase = 1;
int num_my_trees;
int num_opp_possible_complete;
int complete_cnt = 0;
bool should_wait = false;
int pre_sun = 0;
int pre_day = -1;
vector<int> my_tree_size_count;
vector<int> opp_tree_size_count;
deque<string> daily_schedule;
stringstream message;

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
    Tree(int cellIndex_, int size_, bool isMine_, bool isDormant_) {
        cellIndex = cellIndex_;
        size = size_;
        isMine = isMine_;
        isDormant = isDormant_;
    }
};
vector<Tree> trees;

int calc_num_neigh_tree(int cellIndex) {
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
    return sum;
}

int affect_shadow_point(int cellIndex, int size, int delta, bool to_me) {
    int point = 0;
    int index = cellIndex;
    for (int dist = 1; dist <= size; dist++) {
        index = cells[index].neigh[(day+delta)%6];
        if (index == -1) break;
        for (Tree &tree: trees) if(tree.cellIndex == index) {
            if (tree.size <= size) {
                point += (int)(tree.isMine == to_me) * tree.size;
            }
        }
    }
    return point;
}

bool recieve_shadow(int cellIndex, int size, int delta, bool from_me) {
    int index = cellIndex;
    for (int dist = 1; dist <= 3; dist++) {
        index = cells[index].neigh[(day+delta+3)%6];
        if (index == -1) break;
        for (Tree &tree: trees) if(tree.cellIndex == index) {
            if (tree.size >= size && tree.size >= dist) {
                if (tree.isMine == from_me) return true;
            }
        }
    }
    return false;
}

struct Action {
    public:
    // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
    string command;
    string type;
    string kind;
    int cellIndex;
    int seedIndex;
    int treeIndex;
    double weight;

    Action(string possibleAction) {
        command = possibleAction;
        auto tokens = split(command, " ");
        type = tokens[0];
        if (type != "WAIT") {
            cellIndex = stoi(tokens[1]);
            rep(i, numberOfTrees) {
                if (trees[i].cellIndex == cellIndex) {
                    treeIndex = i;
                }
            }
        }
        if (type == "SEED") {
            seedIndex = stoi(tokens[2]);
        }
        kind = type;
        if (type == "GROW") {
            stringstream ss;
            ss << " " << trees[treeIndex].size << " -> " << trees[treeIndex].size + 1;
            kind += ss.str();
        }
        weight = 0;
    }

    void calc_weight() {
        string planned_kind = daily_schedule.front();
        if (planned_kind != kind) weight = 0;
        else if (kind == "WAIT") weight = 1;
        else if (kind == "COMPLETE") {
            if (day >= 22) {
                weight = cells[cellIndex].richness;
            }
            else {
                // 1. この木が明日(+明後日)に自分の木に与えるペナルティの合計が大きい順
                weight += 1e5 * affect_shadow_point(cellIndex, 3, +1, true);
                // 2. この木が明日(+明後日)に敵/自分の木からペナルティを受けるか否か
                weight += 1e4 * recieve_shadow(cellIndex, 3, +1, false); // from ops
                weight += 1e3 * recieve_shadow(cellIndex, 3, +1, true); // from me
                // 3. この木が明日(+明後日)に敵の木にペナルティを与える合計が低い順
                weight += 1e2 * (10 - affect_shadow_point(cellIndex, 3, +1, false));
                weight += 1e1 * cells[cellIndex].richness;
            }
        }
        else if (type == "GROW") {
            int size = trees[treeIndex].size;
            // 1. この木がGROWによって明日(+明後日)に自分の木に与えるペナルティの合計の差分が小さい順
            weight += 1e5 * (10 - (affect_shadow_point(cellIndex, size+1, +1, true) - affect_shadow_point(cellIndex, size, +1, true)));
            // 2. この木がGROWによって明日(+明後日)に自分の木から受けるペナルティを回避できるようになるか否か
            weight += 1e5 * ((int)recieve_shadow(cellIndex, size, +1, true) - (int)recieve_shadow(cellIndex, size+1, +1, true));
            // 3. richness
            weight += 1e3 * cells[cellIndex].richness;
            cerr << "GROW weight: ";
        }
        else if (type == "SEED") {
            // int size = trees[treeIndex].size;
            // int cost = my_tree_size_count[0];
            // int num_neigh_tree = calc_num_neigh_tree(seedIndex)

            // TODO: affect_shadow_point, recieve_shadow を使う
            int disturb = calc_disturb(seedIndex, 3);
            weight = 10 * (10 - disturb) + cells[seedIndex].richness;
        }
        else {
            assert(false);
        }
    }

    bool operator<(const Action &rhs) const {
        return weight < rhs.weight;
    }
};
vector<Action> actions;

void plan_daily_schedule() {
    vector<deque<string>> cand_schedules;
    auto dfs = [&](auto &&f, int depth, deque<string> path, int rem_sun) -> void{
        if (depth == 0) {
            f(f, depth+1, path, rem_sun);
            int size3 = my_tree_size_count[3];
            while (rem_sun >= 4 && size3 > 0) {
                path.push_back("COMPLETE");
                rem_sun -= 4;
                size3--;
                f(f, depth+1, path, rem_sun);
            }
        }
        else if (depth == 1) {
            f(f, depth+1, path, rem_sun);
            int size3 = my_tree_size_count[3] - count(all(path), "COMPLETE");
            int size2 = my_tree_size_count[2];
            while (rem_sun >= 7 + size3 && size2 > 0) {
                if (day > 22) return;

                // Heuristic
                if (size3 >= MAX_SIZE_3_NUM) return;

                path.push_back("GROW 2 -> 3");
                rem_sun -= 7 + size3;
                size3++;
                size2--;
                f(f, depth+1, path, rem_sun);
            }
        }
        else if (depth == 2) {
            f(f, depth+1, path, rem_sun);
            int size2 = my_tree_size_count[2] - count(all(path), "GROW 2 -> 3");
            int size1 = my_tree_size_count[1];
            while (rem_sun >= 3 + size2 && size1 > 0) {
                if (day > LAST_GROW_2_TO_3_DAY) return;

                // Heuristic
                if (size2 >= MAX_SIZE_2_NUM) return;

                path.push_back("GROW 1 -> 2");
                rem_sun -= 3 + size2;
                size2++;
                size1--;
                f(f, depth+1, path, rem_sun);
            }
        }
        else if (depth == 3) {
            f(f, depth+1, path, rem_sun);
            int size1 = my_tree_size_count[1] - count(all(path), "GROW 1 -> 2");
            int size0 = my_tree_size_count[0];
            while (rem_sun >= 1 + size1 && size0 > 0) {
                if (day > 20) return;

                // Heuristic
                if (size1 >= MAX_SIZE_1_NUM) return;

                path.push_back("GROW 0 -> 1");
                rem_sun -= 1 + size1;
                size1++;
                size0--;
                f(f, depth+1, path, rem_sun);
            }
        }
        else if (depth == 4) {
            f(f, depth+1, path, rem_sun);
            map<string, int> path_cnt;
            for (auto &x : path) path_cnt[x]++;

            // Heuristic
            if (day < 2) return;
            if (day > LAST_SEED_DAY) return;
            if (my_tree_size_count[0] >= MAX_SIZE_0_NUM) return;
            int can_seed_size3 = my_tree_size_count[3] - path_cnt["COMPLETE"];
            int can_seed_size2 = my_tree_size_count[2] - path_cnt["GROW 2 -> 3"];
            int can_seed_size1 = my_tree_size_count[1] - path_cnt["GROW 1 -> 2"];
            if (can_seed_size3 > 0 || can_seed_size2 > 0 || can_seed_size1 > 0) {
                rem_sun -= can_seed_size1;
                if (rem_sun < 0) return;
                path.push_back("SEED");
                f(f, depth+1, path, rem_sun);
            }
        }
        else if (depth == 5) {
            path.push_back("WAIT");
            cand_schedules.push_back(path);
        }
    };
    dfs(dfs, 0, {}, sun);
    int max_grow_cnt = 0;
    int max_comp_cnt = 0;
    daily_schedule = cand_schedules[0];
    string chosen_schedule = "WAIT";
    for (deque<string> &cand_schedule: cand_schedules) {
        print(cand_schedule);
        // Heuristic
        // X個できるまではGROW優先
        // それからは1日1COMPLETE優先、その中でGROWの数優先
        int grow_cnt = count_if(all(cand_schedule), [](auto &s) { return s.substr(0,4) == "GROW"; });
        int comp_cnt = count_if(all(cand_schedule), [](auto &s) { return s == "COMPLETE"; });
        static bool prioritize_complete = false;
        if (day >= PRIORITIZE_COMPLETE_DAY ||
            (day > LAST_GROW_2_TO_3_DAY && opp_tree_size_count[3] >= 1)) {
            prioritize_complete = true;
        }
        if (prioritize_complete) {
            chosen_schedule = "Prioritize COMPLETE";
            if (max_comp_cnt < comp_cnt) {
                max_comp_cnt = comp_cnt;
                daily_schedule = cand_schedule;
            }
            else if (max_comp_cnt == comp_cnt && daily_schedule.size() < cand_schedule.size()) {
                daily_schedule = cand_schedule;
            }
        }
        else if (my_tree_size_count[3] < MAX_SIZE_3_NUM - 1) {
            chosen_schedule = "Prioritize GROW, don't COMPLETE";
            if (max_grow_cnt < grow_cnt && comp_cnt == 0) {
                max_grow_cnt = grow_cnt;
                daily_schedule = cand_schedule;
            }
            else if (max_grow_cnt == grow_cnt && daily_schedule.size() < cand_schedule.size() && comp_cnt == 0) {
                daily_schedule = cand_schedule;
            }
        }
        else if (sun >= 4) {
            if (comp_cnt != 1) continue;
            chosen_schedule = "1 COMPLETE and GROW";
            if (max_grow_cnt < grow_cnt) {
                max_grow_cnt = grow_cnt;
                daily_schedule = cand_schedule;
            }
            else if (max_grow_cnt == grow_cnt && daily_schedule.size() < cand_schedule.size()) {
                daily_schedule = cand_schedule;
            }
        }
        else {
            // Chose only WAIT
        }
    }
    debug(chosen_schedule);
}

int main()
{
    // Input cell info
    cin >> numberOfCells; cin.ignore();
    for (int i = 0; i < numberOfCells; i++) {
        int index, richness, neigh0, neigh1, neigh2, neigh3, neigh4, neigh5;
        cin >> index >> richness >> neigh0 >> neigh1 >> neigh2 >> neigh3 >> neigh4 >> neigh5; cin.ignore();
        cells.push_back((Cell){index, richness, {neigh0, neigh1, neigh2, neigh3, neigh4, neigh5}});
    }
    sort(all(cells), [](Cell &lhs, Cell &rhs){return lhs.index < rhs.index;});

    // Game loop
    while (1) {
        message.str("");
        message.clear();
        message << " ";

        // Input general info
        cin >> day >> nutrients >> sun >> score >> oppSun >> oppScore >> oppIsWaiting >> numberOfTrees;
        cin.ignore();
        // debug(day, nutrients, sun, score, oppSun, oppScore, oppIsWaiting, numberOfTrees);

        // Input tree info
        trees.clear();
        num_my_trees = 0;
        num_opp_possible_complete = 0;
        my_tree_size_count.clear();
        my_tree_size_count.resize(4);
        opp_tree_size_count.clear();
        opp_tree_size_count.resize(4);
        for (int i = 0; i < numberOfTrees; i++) {
            int cellIndex, size, isMine;
            bool isDormant;
            cin >> cellIndex >> size >> isMine >> isDormant; cin.ignore();
            trees.emplace_back(cellIndex, size, isMine, isDormant);
            if (isMine) {
                num_my_trees++;
                my_tree_size_count[size]++;
            } else {
                opp_tree_size_count[size]++;
            }
            if (!isMine && !isDormant && size == 3) num_opp_possible_complete++;
        }
        chmin(num_opp_possible_complete, oppSun/4);

        // Input possible action info
        cin >> numberOfPossibleActions; cin.ignore();
        actions.clear();
        for (int i = 0; i < numberOfPossibleActions; i++) {
            string possibleAction;
            getline(cin, possibleAction);
            actions.push_back(Action(possibleAction));
        }

        // Plan daily schedule
        if (pre_day + 1 == day) {
            debug("plan_daily_schedule()");
            plan_daily_schedule();
            debug(day);
            print(daily_schedule);
        }
        debug(daily_schedule.front());
        // Calc weight
        for (Action &action: actions) {
            action.calc_weight();
        }

        sort(all(actions));
        reverse(all(actions));
        for (Action &action: actions) {
            if (action.weight > 0) {
                debug(action.command, action.weight);
            }
        }

        Action &action = actions.front();
        assert(action.weight > 0);
        if (action.type == "COMPLETE") complete_cnt++;
        else if (action.type == "WAIT") {
            action.command += message.str();
        }
        cout << action.command << endl;

        daily_schedule.pop_front();
        pre_day = day;
        pre_sun = sun;
    }
}