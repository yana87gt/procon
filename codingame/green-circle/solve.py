import sys

def debug(msg, title=None):
    print(f'{title + ": " if title is not None else ""} {msg}', file=sys.stderr, flush=True)

release_to_plans = []

# game loop
while True:
    #  Input
    game_phase = input()  # can be MOVE, GIVE_CARD, THROW_CARD, PLAY_CARD or RELEASE
    applications_count = int(input())
    applications = []
    for i in range(applications_count):
        inputs = input().split()
        applications.append({
            # 'object_type': inputs[0], # APPLICATION
            'id': int(inputs[1]),
            'needed': list(map(int, inputs[2:])), # size: 8
        })
    players = [] # 0: me, 1: op
    for i in range(2):
        inputs = list(map(int, input().split()))
        players.append({
            'location': inputs[0], # 0~7
            'score': inputs[1],
            'permanent_daily_routine_cards': inputs[2], # number of DAILY_ROUTINE the player has played. It allows them to take cards from the adjacent zones
            'permanent_architecture_study_cards': inputs[3], # number of ARCHITECTURE_STUDY the player has played. It allows them to draw more cards
        })
    card_locations_count = int(input())
    card_locations = []
    for i in range(card_locations_count):
        inputs = input().split()
        # the location of the card list. It can be HAND, DRAW, DISCARD or OPPONENT_CARDS (AUTOMATED and OPPONENT_AUTOMATED will appear in later leagues)
        card_locations.append({
            'cards_location': inputs[0],
            'cards_count': list(map(int, inputs[1:])), # size: 10
            'bonus_cards_count': int(inputs[9]),
            'technical_debt_cards_count': int(inputs[10]),
        })
    possible_moves_count = int(input())
    possible_moves = []
    for i in range(possible_moves_count):
        possible_moves.append(input())

    # Strategy
    # 使っていい shoddy skills は1回のアプリケーション発行につき1つだけにする

    my_location = players[0]['location']
    op_location = players[1]['location']
    debug(applications)
    debug(players)
    debug(card_locations)
    debug(possible_moves)

    
    # In the first league: RANDOM | MOVE <zoneId> | RELEASE <applicationId> | WAIT; In later leagues: | GIVE <cardType> | THROW <cardType> | TRAINING | CODING | DAILY_ROUTINE | TASK_PRIORITIZATION <cardTypeToThrow> <cardTypeToTake> | ARCHITECTURE_STUDY | CONTINUOUS_DELIVERY <cardTypeToAutomate> | CODE_REVIEW | REFACTORING;
    # すでにある
    if possible_moves[0][:4] == 'MOVE':
        release_to_plans = []
        current_skills = {
            'specific': list(map(lambda c: c*2, card_locations[0]['cards_count'][:8])),
            'good': card_locations[0]['bonus_cards_count'],
            'shoddy': sum(card_locations[0]['cards_count'][:8]) * 2 + card_locations[0]['bonus_cards_count'],
        }
        for pos in range(8):
            if pos == my_location: continue
            virtual_skills = {}
            virtual_skills |= current_skills
            # if pos == op_location or (pos+1)%8 == op_location or (pos+8-1)%8 == op_location:
            #     負債カード以外を1つ渡す
            # 負債カード以外を2つ消す
            virtual_skills['specific'][pos] += 2
            virtual_skills['shoddy'] += 2
            for app in applications:
                tmp_skills = {}
                tmp_skills |= virtual_skills
                ok = True
                shoddy_count = 0
                for needed_pos, needed_num in enumerate(app['needed']):
                    if tmp_skills['specific'][needed_pos] >= needed_num:
                        tmp_skills['specific'][needed_pos] -= needed_num
                    elif tmp_skills['good'] >= needed_num:
                        tmp_skills['good'] -= needed_num
                    elif tmp_skills['good'] + tmp_skills['shoddy'] >= needed_num:
                        shoddy_count += needed_num - tmp_skills['good']
                        tmp_skills['shoddy'] -= needed_num - tmp_skills['good']
                        tmp_skills['good'] = 0
                    elif tmp_skills['shoddy'] >= needed_num:
                        shoddy_count += needed_num
                        tmp_skills['shoddy'] -= needed_num
                        if shoddy_count >= 2:
                            ok = False
                    else:
                        ok = False
                if ok:
                    release_to_plans.append({"shoddy_count": shoddy_count, "command": f"RELEASE {app['id']}", "move": f"MOVE {pos}"})
        release_to_plans.sort(key=lambda x: x["shoddy_count"])
        debug(release_to_plans, title='release_to_plans')
        release_to_plans = list(filter(lambda x: x["shoddy_count"] <= 1, release_to_plans))
        debug(release_to_plans, title='release_to_plans(filterd)')
        if len(release_to_plans) == 0:
            if my_location >= 1:
                print('MOVE 0')
            else:
                print(f'MOVE {(my_location+1)%8}')
        else:
            print(release_to_plans[0]['move'])
    else:
        for release_to_plan in release_to_plans:
            if release_to_plan["command"] in possible_moves:
                print(release_to_plan["command"])
                break
        else:
            print('WAIT')
