import sys
import math
import traceback

X = 17630
Y = 9000

def dist(x1, y1, x2, y2):
    return int(((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5)


if __name__ == '__main__':
    # Auto-generated code below aims at helping you parse
    # the standard input according to the problem statement.

    # base_x: The corner of the map representing your base
    base_x, base_y = [int(i) for i in input().split()]
    heroes_per_player = int(input())  # Always 3
    heroes_base_list = [
        {"x": 2000, "y": 7000},
        {"x": 5000, "y": 5000},
        {"x": 8000, "y": 2000},
    ]
    if base_x != 0:
        heroes_base_list = list(map(lambda base: {"x": X - base["x"], "y": Y - base["y"]}, heroes_base_list))

    # game loop
    while True:
        try:
            for i in range(2):
                health, mana = [int(j) for j in input().split()]
            entity_count = int(input())  # Amount of heros and monsters you can see
            entity_list = []
            for i in range(entity_count):
                _id, _type, x, y, shield_life, is_controlled, health, vx, vy, near_base, threat_for = [int(j) for j in input().split()]

                priority = 0
                if _type == 0:
                    if near_base == 1 and threat_for == 1:
                        priority += 40000 - dist(x+vx, y+vy, base_x, base_y)
                    elif near_base == 0 and threat_for == 1:
                        priority += 30000 - dist(x+vx, y+vy, base_x, base_y)
                    elif near_base == 0 and threat_for == 0:
                        priority += 1000

                entity_list.append({
                    "id": _id,
                    "type": _type,
                    "x": x,
                    "y": y,
                    # "shield_life": shield_life,
                    # "is_controlled": is_controlled,
                    "health": health,
                    "vx": vx,
                    "vy": vy,
                    "near_base": near_base,
                    "threat_for": threat_for,

                    "priority": priority,
                })
            entity_list.sort(key=lambda x: x["priority"], reverse=True)

            # priority Top 1,2,3 を heros に割り振る
            hero_list = list(filter(lambda entity: entity["type"] == 1, entity_list))
            monster_list = list(filter(lambda entity: entity["type"] == 0, entity_list))
            for i, monster in enumerate(monster_list):
                if i >= 3: break
                if monster["priority"] < 100: break
                assigned_hero = min(hero_list, key=(
                    lambda hero: dist(hero["x"], hero["y"], monster["x"] + monster["vx"], monster["y"] + monster["vy"])
                                + 100000 if "command" in hero else 0
                ))
                hero_list[assigned_hero["id"]]["command"] = f'MOVE {monster["x"] + monster["vx"]} {monster["y"] + monster["vy"]}'

            for i, hero in enumerate(hero_list):
                # print("Debug messages...", file=sys.stderr, flush=True)
                if "command" in hero:
                    print(hero["command"])
                else:
                    print(f'MOVE {heroes_base_list[i]["x"]} {heroes_base_list[i]["y"]}')
        except Exception as e:
            err_msg = traceback.format_exc().replace(" ", "_").replace("\n", " ")
            print(err_msg, file=sys.stderr, flush=True)
