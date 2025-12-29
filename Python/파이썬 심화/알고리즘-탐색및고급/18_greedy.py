def coin_change(coins, amount):
    coins.sort(reverse=True)
    result = []
    
    for coin in coins:
        count = amount // coin
        if count > 0:
            result.append((coin, count))
            amount -= coin * count
    
    return result

coins = [1, 5, 10, 50, 100, 500]
amount = 1234
change = coin_change(coins, amount)
print(f"{amount}원을 거슬러주는 방법:")
for coin, count in change:
    print(f"{coin}원: {count}개")

def activity_selection(activities):
    activities.sort(key=lambda x: x[1])
    selected = [activities[0]]
    
    for activity in activities[1:]:
        if activity[0] >= selected[-1][1]:
            selected.append(activity)
    
    return selected

activities = [(1, 4), (3, 5), (0, 6), (5, 7), (8, 9), (5, 9)]
selected = activity_selection(activities)
print(f"\n선택된 활동: {selected}")

