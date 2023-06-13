'''
# IDE
https://www.codingame.com/ide/challenge/fall-challenge-2022

# ルール
https://tsukammo.hatenablog.com/

# Leader Board
https://www.codingame.com/contests/fall-challenge-2022/leaderboard

# Replay
https://www.codingame.com/replay/684709569
https://www.codingame.com/replay/684770223
https://www.codingame.com/replay/684771377
https://www.codingame.com/replay/685575216

* 侵略している
    https://www.codingame.com/replay/689089685
    https://www.codingame.com/replay/689089320

# マスの表記
[M]: 自分のUnitありマス
[m]: 自分のUnitなしマス
[F]: 相手のUnitありマス
[f]: 相手のUnitなしマス
[R]: 自分のリサイクルマス
[r]: 相手のリサイクルマス
[.]: 空マス
[#]: 草マス
'''

from collections import defaultdict
import sys
import heapq

ME = 1
FOE = 0
NEUTRAL = -1
INF = 1000
dx = [0, -1, 0, +1]
dy = [-1, 0, +1, 0]
phase = 1

# Const values in Game
width, height = [int(i) for i in input().split()]
is_left_side = None
cut_done = False

def debug(text):
    print(text, file=sys.stderr, flush=True)

class Cell():
    def input_data(self, x: int, y: int):
        self.x, self.y = x, y
        scrap_amount, owner, units, recycler, can_build, can_spawn, in_range_of_recycler = [int(k) for k in input().split()]
        self.scrap_amount, self.owner, self.units, self.recycler, self.can_build, self.can_spawn, self.in_range_of_recycler = scrap_amount, owner, units, recycler, can_build, can_spawn, in_range_of_recycler

        self.reachable = [INF, INF] # [FOR, ME]
        self.targeted = False
        self.not_pass = False
        self.deleted_next_turn = False
        self.build_next_turn = False

c = [[Cell() for y in range(height)] for x in range(width)]

# (x, y) の周り4マスの座標を返す
# 空きマス, 範囲外のマス は省く
# デフォルトでは recycler を省く
def next_xy(x: int, y: int, allow_recycler: bool = False) -> list:
    nexts = []
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 0 or nx >= width or ny < 0 or ny >= height: continue
        if c[nx][ny].scrap_amount == 0: continue
        if not allow_recycler and c[nx][ny].recycler: continue
        nexts.append((nx, ny))
    return nexts

# cost ターンで (x, y) に辿りつける (src_x, src_y) を全て返す
def get_src_units(cost: int, x: int, y: int) -> list: # [(x, y, is_unit), ...]
    if c[x][y].reachable[ME] != cost:
        return []
    src_units = []
    if cost == 0 and c[x][y].reachable[ME] == 0:
        src_units.append((x, y, True))
    if cost == 1 and c[x][y].units == 0 and c[x][y].owner == ME:
        src_units.append((x, y, False))
    for nx, ny in next_xy(x, y):
        src_units += get_src_units(cost - 1, nx, ny)
    return src_units

# (src_x, src_y) から (dst_x, dst_y) に行くときの最適な MOVE command を返す
def get_proper_step(src_x: int, src_y: int, dst_x: int, dst_y: int) -> str:
    qu = []
    cost_map = dict()
    heapq.heappush(qu, (0, dst_x, dst_y))
    while len(qu) != 0:
        cost, x, y = heapq.heappop(qu)
        if (x, y) in cost_map and cost_map[(x, y)] <= cost: continue
        if c[x][y].owner == FOE: continue
        if c[x][y].not_pass: continue
        if c[x][y].scrap_amount == 0: continue
        if c[x][y].recycler: continue
        cost_map[(x, y)] = cost
        for nx, ny in next_xy(x, y):
            heapq.heappush(qu, (cost + 1, nx, ny))
    nexts = list(filter(lambda xy: (xy[0], xy[1]) in cost_map, next_xy(src_x, src_y)))
    if len(nexts) == 0: return ""
    nexts.sort(key=lambda xy: (cost_map[(xy[0], xy[1])], c[xy[0]][xy[1]].scrap_amount))
    # min_cost = cost_map[(nexts[0][0], nexts[0][1])]
    # nexts = list(filter(lambda xy: cost_map[(xy[0], xy[1])] == min_cost, nexts))
    nexts.sort(key=lambda xy: (
        cost_map[(xy[0], xy[1])],
        c[xy[0]][xy[1]].reachable[FOE] - c[xy[0]][xy[1]].reachable[ME] <= 1,
        abs(xy[1] - src_y)
    ))
    return f"MOVE 1 {src_x} {src_y} {nexts[0][0]} {nexts[0][1]}"

# Game loop
for turn in range(500):
    # Const values in Turn
    my_matter, opp_matter = [int(i) for i in input().split()]
    my_units = [] # (x, y)
    my_top_x = my_top_y = my_bottom_x = my_bottom_y = my_front_x = my_front_y = None
    opp_front_xs = [] if is_left_side is None else[INF if is_left_side else -INF for _ in range(height)]

    for y in range(height):
        for x in range(width):
            # Input
            c[x][y].input_data(x, y)

            # Set is_left_side
            if turn == 0 and c[x][y].units > 0 and is_left_side is None:
                if c[x][y].owner == ME:
                    is_left_side = x < width - x - 1
                else:
                    is_left_side = x >= width - x - 1
                # Init opp_front_xs
                opp_front_xs = [INF if is_left_side else -INF for _ in range(height)]

            if c[x][y].owner == ME and c[x][y].units > 0:
                # List up my_units
                for i in range(c[x][y].units):
                    my_units.append((x, y))

                # Waller
                if my_top_y is None:
                    my_top_x = my_bottom_x = my_front_x = x
                    my_top_y = my_bottom_y = my_front_y = y
                assert my_front_x is not None and my_bottom_y is not None
                if (is_left_side and x >= my_front_x) or (not is_left_side and x <= my_front_x):
                    my_front_x, my_front_y = x, y
                if y == my_top_y and is_left_side:
                    my_top_x = x
                if y > my_bottom_y:
                    my_bottom_x, my_bottom_y = x, y
                if y == my_bottom_y and is_left_side:
                    my_bottom_x = x

            # Set opp_front_xs
            if c[x][y].owner == FOE and c[x][y].units > 0:
                if is_left_side:
                    opp_front_xs[y] = min(x, opp_front_xs[y])
                else:
                    opp_front_xs[y] = max(x, opp_front_xs[y])
            if c[x][y].owner == FOE and c[x][y].units == 0 and not c[x][y].recycler:
                if is_left_side:
                    opp_front_xs[y] = min(x+1, opp_front_xs[y])
                else:
                    opp_front_xs[y] = max(x-1, opp_front_xs[y])

    assert not(my_top_x is None or my_top_y is None or my_bottom_x is None or my_bottom_y is None)

    debug(f'opp_front_xs = {opp_front_xs}')

    # recycler によって次のターン not_pass になる場所を調べる
    next_turn_scrap_amounts = defaultdict(int)
    for y in range(height):
        for x in range(width):
            next_turn_scrap_amounts[(x, y)] += c[x][y].scrap_amount
            if c[x][y].recycler:
                for nx, ny in next_xy(x, y, allow_recycler=True):
                    next_turn_scrap_amounts[(nx, ny)] -= 1
    for y in range(height):
        for x in range(width):
            if next_turn_scrap_amounts[(x, y)] <= 0:
                c[x][y].not_pass = True
                c[x][y].deleted_next_turn = True

    commands = []

    '''
    [m][F] -> [R][F]
    '''
    for y in range(height):
        for x in range(width):
            if not (c[x][y].units == 0 and c[x][y].owner == ME and not c[x][y].recycler): continue
            if not c[x][y].can_build: continue
            if c[x][y].deleted_next_turn: continue
            # [m] = (x, y)
            for nx, ny in next_xy(x, y):
                if c[nx][ny].units > 0 and c[nx][ny].owner == FOE:
                    commands.append(f'BUILD {x} {y}')
                    c[x][y].not_pass = True
                    c[x][y].build_next_turn = True
                    break

    '''
    ✅  準分断(phase = 2) / 分断(phase = 3) 判定
        y = 0 の x = 相手サイドから (y = height - 1 もしくは 相手サイドのx) に辿り着けるパスはあるか判定する
        最も相手サイドを通るように経路をdfsする
            * .owner == ME かつ unit = 0 のマス
            * .recycler (ownerは問わない)
            * .build_next_turn == True
            * .scrap_amount == 0
            * .deleted_next_turn == True
        無事経路が見つかったのであれば、経路中の[m]をカウント (= my_area_count) して、
        my_matter -= max((my_area_count - 1) * 10, 0) をする (このターンのBUILD は先にやっておく)
        これで次のターンに BUILD できるように最低限節約できる。
        経路中の[m]は持っておいて、 not_pass にする(いるとBUILD できないので)
    -> TODO: 相手の opp_matter で対応できないくらいにを強気にunitを増やして荒らす
    '''
    if phase <= 2:
        x_range = list(range(width - 1, -1, -1) if is_left_side else range(width))
        # TODO: 最初からx_range全部quに入れる
        for top_x in x_range:
            assert is_left_side is not None
            qu = []
            cost_map = dict()
            def cell_cost(xx: int, yy: int) -> int:
                if xx < 0 or xx >= width or yy < 0 or yy >= height: return INF
                return int(
                    c[xx][yy].owner == ME and
                    c[xx][yy].units == 0 and
                    not c[xx][yy].recycler and
                    not c[xx][yy].build_next_turn and
                    not c[xx][yy].deleted_next_turn
                )
            heapq.heappush(qu, (cell_cost(top_x, 0), top_x, 0))
            while len(qu) != 0:
                cost, x, y = heapq.heappop(qu)
                if (x, y) in cost_map and cost_map[(x, y)] <= cost: continue
                if x < 0 or x >= width or y < 0 or y >= height: continue
                ok = False
                ok |= (c[x][y].owner == ME and c[x][y].units == 0)
                ok |= c[x][y].recycler
                ok |= c[x][y].build_next_turn
                ok |= c[x][y].scrap_amount == 0
                ok |= c[x][y].deleted_next_turn
                if not ok: continue
                cost_map[(x, y)] = cost
                if is_left_side:
                    nexts = [(x+1, y+1), (x+1, y), (x, y+1), (x-1, y+1), (x-1, y)]
                else:
                    nexts = [(x-1, y+1), (x-1, y), (x, y+1), (x+1, y+1), (x+1, y)]
                for nx, ny in nexts:
                    heapq.heappush(qu, (cost + cell_cost(nx, ny), nx, ny))

            found = False
            for dst_x in x_range:
                if (dst_x, height - 1) in cost_map:
                    cost = cost_map[(dst_x, height - 1)]
                    if cost >= 1:
                        my_matter -= (cost - 1) * 10
                        phase = 2
                    else:
                        phase = 3
                    debug(f'Cutting cost: {cost}')
                    found = True
                    break
            if found: break

    debug(f'phase = {phase}')

    '''
    [M]+[.][F]+
        M <= F or phase = 1 -> ✅ [m][.][F] にして次のターンでのリサイクルに備える
        M > F or phase >= 2 -> ✅ [m][M][F]
    (Without matter)

    * TODO(Low): M < F で突っ込んでいるが？ -> RISCしたのに再現しなくて泣いちゃった
    '''
    for y in range(height):
        for x in range(width):
            if c[x][y].not_pass: continue
            if not (c[x][y].owner == NEUTRAL and c[x][y].scrap_amount > 0): continue
            # [.] = (x, y) 
            opp_unit_count = 0
            my_unit_count = 0
            for nx, ny in next_xy(x, y):
                if c[nx][ny].units > 0:
                    if c[nx][ny].owner == FOE:
                        # [F] = (nx, ny)
                        opp_unit_count += c[nx][ny].units
                    else:
                        my_unit_count += my_units.count((nx, ny))
            if opp_unit_count == 0 or my_unit_count == 0: continue

            if my_unit_count <= opp_unit_count or phase == 1:
                # [m][.][F]+ にして次のターンでのリサイクルに備える
                debug(f'[M]+[.][F]+ -> [m][.][F]: [.] = {(x, y)}')
                c[x][y].not_pass = True
                for nx, ny in next_xy(x, y):
                    # [M] = (nx, ny)
                    # TODO(Low): 2方向以上の [M] についても notpass にしちゃってるけどいい？
                    if my_units.count((nx, ny)) > 0 and c[nx][ny].owner == ME:
                        c[nx][ny].not_pass = True
            else:
                # [m][M][F]
                # TODO(Light): .targeted って機能してる？
                c[x][y].targeted = True
                for nx, ny in next_xy(x, y):
                    count = my_units.count((nx, ny))
                    if count > 0 and c[nx][ny].owner == ME:
                        # [M] = (nx, ny)
                        commands.append(f'MOVE {count} {nx} {ny} {x} {y}')
                        for i in range(count):
                            my_units.remove((nx, ny))

    '''
    [M][f]+ かつ [M]の周りに[.]がない かつ phase >= 2
        -> TODO(High): [m][M=1]* して足りなければSPAWN
        # ([f]の周り,[M]の周りの[F]の総数にあわせて[m][M]にする)
        -> TODO(Low): [M][r] の可能性もあるので保険で他のマスへのMOVEも入れておく
    '''
    if phase >= 2:
        for y in range(height):
            for x in range(width):
                if not(c[x][y].units > 0 and c[x][y].owner == ME): continue
                if c[x][y].deleted_next_turn: continue
                if c[x][y].not_pass: continue
                # [M] = (x, y)

                rem_units = my_units.count((x, y))
                for nx, ny in next_xy(x, y):
                    if c[nx][ny].units == 0 and c[nx][ny].owner == FOE and not c[nx][ny].not_pass:
                        # [f] = (nx, ny)
                        if rem_units > 0:
                            commands.append(f'MOVE 1 {x} {y} {nx} {ny}')
                            my_units.remove((x, y))
                            rem_units -= 1
                        elif my_matter >= 10:
                            commands.append(f'SPAWN 1 {x} {y}')
                            my_matter -= 10
                        else:
                            debug(f"Can't SPAWN 1 {x} {y} for [M][f]+")


    '''
    [m][f] かつ phase >= 2 -> [M=1][f]
        * ✅ 実装
        * TODO: どれくらい有効か見てみる
    '''
    if phase >= 2:
        for y in range(height):
            for x in range(width):
                if not(c[x][y].units == 0 and c[x][y].owner == ME): continue
                if c[x][y].recycler: continue
                if c[x][y].deleted_next_turn: continue
                if c[x][y].not_pass: continue
                # [m] = (x, y)
                ng = False
                foe_area_count = 0
                for nx, ny in next_xy(x, y):
                    if c[nx][ny].owner == NEUTRAL and c[nx][ny].scrap_amount > 0 and not c[nx][ny].deleted_next_turn:
                        # [.] = (nx, ny)
                        ng = True
                    if c[nx][ny].owner == FOE and c[nx][ny].units == 0:
                        # [f] = (nx, ny)
                        foe_area_count += 1
                    if c[nx][ny].owner == FOE and c[nx][ny].units > 0:
                        # [F] = (nx, ny)
                        ng = True
                if ng: continue
                if not ng and my_matter >= 10 and foe_area_count > 0:
                    commands.append(f'SPAWN 1 {x} {y}')
                    my_matter -= 10

    '''
    [M][F]+
        [.]+[M][F]+ ->
            ✅  空きマス(*1 recyclerで3ターン以内に消えない)にできる限りMOVE
            ✅  残った M に対して F+ の量になるまで追加 SPAWN
            ✅  空きマスにMOVEし足りなかった分 SPAWN
        Mの周りに空きマス(*1)がない ->
            phase >= 2
                -> TODO(High): 攻め
            phase = 1
                -> ✅ なるべく少ないFに突っ込む
    '''
    for y in range(height):
        for x in range(width):
            if not(c[x][y].units > 0 and c[x][y].owner == ME): continue
            # [M] = (x, y)
            next_opp_unit_count = 0
            next_space_xy = []
            rem_units = my_units.count((x, y))
            for nx, ny in next_xy(x, y):
                if c[nx][ny].units > 0 and c[nx][ny].owner == FOE:
                    # [F] = (nx, ny)
                    next_opp_unit_count += c[nx][ny].units
                # TODO(Middle): recycler で3ターン以内に消える空きマスであれば無視して良い
                if c[nx][ny].owner == NEUTRAL and c[nx][ny].scrap_amount > 0 and not c[nx][ny].deleted_next_turn:
                    # [.] = (nx, ny)
                    next_space_xy.append((nx, ny))

            # そもそも周りにFがいなければなにもしない
            if next_opp_unit_count == 0: continue

            if len(next_space_xy) > 0:
                # 空きマス(*1)にできる限りMOVE
                for nx, ny in next_space_xy:
                    if rem_units > 0:
                        commands.append(f'MOVE 1 {x} {y} {nx} {ny}')
                        my_units.remove((x, y))
                        rem_units -= 1
                    elif my_matter >= 10:
                        commands.append(f'SPAWN 1 {x} {y}')
                        my_matter -= 10
                    else:
                        debug(f"Can't SPAWN 1 {x} {y} for [.]+[M][F]+")
                spawn_num = max(next_opp_unit_count - rem_units, 0)

                # rem_units は MOVE しないようにする
                for _ in range(rem_units):
                    my_units.remove((x, y))

                if my_matter >= spawn_num * 10 and spawn_num > 0:
                    commands.append(f'SPAWN {spawn_num} {x} {y}')
                    my_matter -= spawn_num * 10
                else:
                    debug(f"Can't SPAWN {spawn_num} {x} {y}")

                if phase >= 2:
                    spawn_num = my_matter // 20
                    for _ in range(spawn_num):
                        if my_matter >= 10:
                            commands.append(f'SPAWN 1 {x} {y}')
                            my_matter -= 10
                        else:
                            debug(f"Can't SPAWN 1 {x} {y}")
                            break
            else:
                # Mの周りに空きマス(*)がなければ、なるべく少ないFに突っ込む
                next_opp_units = []
                next_opp_count = 0
                for nx, ny in next_xy(x, y):
                    if c[nx][ny].units > 0 and c[nx][ny].owner == FOE:
                        next_opp_units.append((c[nx][ny].units, nx, ny))
                        next_opp_count += c[nx][ny].units
                next_opp_units.sort()
                commands.append(f'MOVE {rem_units} {x} {y} {next_opp_units[0][1]} {next_opp_units[0][2]}')
                for _ in range(rem_units):
                    my_units.remove((x, y))
                if phase >= 2:
                    spawn_num = next_opp_unit_count + 1
                    for _ in range(spawn_num):
                        if my_matter >= 10:
                            commands.append(f'SPAWN 1 {x} {y}')
                            my_matter -= 10
                        else:
                            debug(f"Can't SPAWN 1 {x} {y}")
                            break


    '''
    TODO: [F][.][.][M] は全体のアルゴリズムでいざという時に詰められているか？
    '''

    # Calc reachable cost
    qu = []
    for y in range(height):
        for x in range(width):
            if c[x][y].owner != NEUTRAL:
                heapq.heappush(qu, (int(c[x][y].units == 0), x, y, c[x][y].owner))
    while len(qu) != 0:
        cost, x, y, player = heapq.heappop(qu)
        if c[x][y].reachable[player] <= cost: continue
        if c[x][y].owner != NEUTRAL and c[x][y].owner != player: continue
        if c[x][y].not_pass: continue
        if c[x][y].scrap_amount == 0: continue
        if c[x][y].recycler: continue
        c[x][y].reachable[player] = cost
        for nx, ny in next_xy(x, y):
            # TODO(Low): recycler によるNターン後の道の封鎖を考慮(そのマスの寿命をdfsで計算する)
            heapq.heappush(qu, (cost + 1, nx, ny, player))

    # List up destinations
    destinations = [] # (cost, x, y)
    for y in range(height):
        for x in range(width):
            # TODO: 目的地リストの中で、上のタスクで使用してるマスは除外
            if c[x][y].reachable[ME] == INF: continue
            diff = c[x][y].reachable[FOE] - c[x][y].reachable[ME]
            if diff == 0:
                destinations.append((c[x][y].reachable[ME], x, y))
            elif diff == 1:
                destinations.append((c[x][y].reachable[ME], x, y))
    if len(destinations) == 0:
        '''
        分断完了後のマス埋め
        空きマスの隣にSPAWN & destinations追加
        * TODO: cut_done の判定は分断のときにやる
        '''
        cut_done = True
        for y in range(height):
            for x in range(width):
                if not(c[x][y].owner == NEUTRAL and c[x][y].scrap_amount > 0): continue
                # [.] = (x, y)
                destinations.append((c[x][y].reachable[ME], x, y))
                cancel = False
                spawn_command = ""
                for nx, ny in next_xy(x, y):
                    if c[nx][ny].owner == ME and c[nx][ny].units > 0:
                        cancel = True
                    if c[nx][ny].owner == ME and c[nx][ny].units == 0:
                        spawn_command = f'SPAWN 1 {nx} {ny}'
                if not cancel and spawn_command != "" and my_matter >= 150:
                    commands.append(spawn_command)
                    my_matter -= 10

    '''
    TODO:
    Move my_units to destinations
    diff が +2 or +3 のところに手分けして行く
    '''

    # Top Waller
    if (my_top_x, my_top_y) in my_units:
        if is_left_side:
            x_range = range(width - 1, -1, -1)
            dst_x, dst_y = width - 1, 0
        else:
            x_range = range(width)
            dst_x, dst_y = 0, 0
        for y in range(height):
            if abs(opp_front_xs[y]) != INF:
                dst_x, dst_y = opp_front_xs[y], y
                break
        found = False
        for x in x_range:
            for y in range(0, min(my_top_y + 1, height//2)):
                # TODO: my_top_x, my_top_y からの reachable を計算すべし
                diff = c[x][y].reachable[FOE] - c[x][y].reachable[ME]
                if y > 0 and diff >= 2 and diff <= 3:
                    dst_x, dst_y = x, y
                    found = True
                    break
                elif y == 0 and diff >= 1 and diff <= 3:
                    dst_x, dst_y = x, y
                    found = True
                    break
            if found: break
        command = get_proper_step(my_top_x, my_top_y, dst_x, dst_y)
        debug(f'Top Waller: {(my_top_x, my_top_y)} -> {(dst_x, dst_y)}')
        if command != "":
            commands.append(command)
            my_units.remove((my_top_x, my_top_y))

    # Bottom Waller
    if (my_bottom_x, my_bottom_y) in my_units:
        if is_left_side:
            x_range = range(width - 1, -1, -1)
            dst_x, dst_y = width - 1, height - 1
        else:
            x_range = range(width)
            dst_x, dst_y = 0, height - 1
        for y in range(height - 1, -1, -1):
            if abs(opp_front_xs[y]) != INF:
                dst_x, dst_y = opp_front_xs[y], y
                break
        found = False
        for x in x_range:
            for y in range(height - 1, max(my_bottom_y - 1, height//2), -1):
                # TODO: my_bottom_x, my_bottom_y からの reachable を計算すべし
                diff = c[x][y].reachable[FOE] - c[x][y].reachable[ME]
                if y < height - 1 and diff >= 2 and diff <= 3:
                    dst_x, dst_y = x, y
                    found = True
                    break
                elif y == height - 1 and diff >= 1 and diff <= 3:
                    dst_x, dst_y = x, y
                    found = True
                    break
            if found: break
        command = get_proper_step(my_bottom_x, my_bottom_y, dst_x, dst_y)
        debug(f'Bottom Waller: {(my_bottom_x, my_bottom_y)} -> {(dst_x, dst_y)}')
        if command != "":
            commands.append(command)
            my_units.remove((my_bottom_x, my_bottom_y))

    # TODO: (my_front_x, my_front_y)

    # TODO もっとまともなのを考える
    # 1. dst からみて最短で来れる my_unit がいれば来させる
    destinations.sort(key=lambda item: item[0]) # cost小さい順
    for dst_cost, dst_x, dst_y in destinations[:max(len(my_units), 4)]:
        src_units = get_src_units(dst_cost, dst_x, dst_y)
        for unit_x, unit_y, _ in src_units:
            if not cut_done and (unit_x, unit_y) == (my_top_x, my_top_y): continue
            if not cut_done and (unit_x, unit_y) == (my_bottom_x, my_bottom_y): continue
            if (unit_x, unit_y) in my_units:
                step_command = get_proper_step(unit_x, unit_y, dst_x, dst_y)
                if step_command != "":
                    commands.append(step_command)
                    my_units.remove((unit_x, unit_y))
                    c[dst_x][dst_y].targeted = True
                    break
    # 2. unit からみて余ってる destinations がいれば来させる
    destinations = list(filter(lambda dst: not c[dst[1]][dst[2]].targeted, destinations))
    if len(destinations) > 0 and len(my_units) > 0:
        # 2-B. destinations の中で遠いものに全て向かわせる？
        _, dst_x, dst_y = destinations[-1]

        for unit_x, unit_y in my_units:
            if not cut_done and (unit_x, unit_y) == (my_top_x, my_top_y): continue
            if not cut_done and (unit_x, unit_y) == (my_bottom_x, my_bottom_y): continue
            step_command = get_proper_step(unit_x, unit_y, dst_x, dst_y)
            if step_command != "":
                commands.append(step_command)
        my_units = []

    # TODO: [M(deleted_next_turn)] があるのであれば動かす
    # TODO: リサイクルは自分の周りの1以上のマスの中で最小scrapamountであればやってもいい
    # TODO(Low): unitがいるマスはそのunitだけじゃなくそこからSPAWNもできるということをあまり考慮していない
    # TODO(High): 真ん中や余っているunitを良い感じに塗らせたり、SPAWNさせたりする
    #     → 2 <= diff <= 3 を sortしてunits をそれぞれいい感じに向かわせる
    # TODO: それぞれの意思決定を debug print で分かりやすくする

    # Field print
    for y in range(height):
        row = []
        for x in range(width):
            if c[x][y].recycler:
                row.append("RR" if c[x][y].owner == "ME" else "rr")
            elif c[x][y].owner == FOE:
                row.append("FF" if c[x][y].units > 0 else "ff")
            elif c[x][y].reachable[ME] == INF:
                row.append("  ")
            elif c[x][y].not_pass:
                row.append("xx")
            elif c[x][y].owner == ME:
                row.append("MM" if c[x][y].units > 0 else "mm")
            else:
                diff = c[x][y].reachable[FOE] - c[x][y].reachable[ME]
                if diff == 0:
                    row.append("00")
                elif abs(diff) < 10:
                    row.append(f'{"+" if diff > 0 else ""}{diff}')
                else:
                    row.append("++" if diff > 0 else "--")
        print(' '.join(row), file=sys.stderr, flush=True)

    # Output
    commands = list(filter(lambda command: command, commands))
    if len(commands) == 0:
        print("WAIT")
    else:
        print('; '.join(commands))
