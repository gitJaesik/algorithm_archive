def solution(bridge_length, weight, truck_weights):
    answer = 0

    finish_count = 0
    cur = 0
    in_bridge_list = []

    dd = len(truck_weights)

    while finish_count < len(truck_weights):
        if len(in_bridge_list) > 0:
            if in_bridge_list[-1][1] >= bridge_length:
                in_bridge_list.pop()
                finish_count += 1

        total_weight = sum(i[0] for i in in_bridge_list)

        if cur < len(truck_weights):
            if total_weight + truck_weights[cur] <= weight:
                in_bridge_list.insert(0, [truck_weights[cur], 0])
                cur += 1

        in_bridge_list = [[i[0], i[1] + 1] for i in in_bridge_list]
        answer += 1

    return answer


if __name__ == "__main__":
    bridge_length = 100
    weight = 100
    truck_weights = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
    solution(bridge_length, weight, truck_weights)
