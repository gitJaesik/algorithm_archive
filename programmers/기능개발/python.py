def solution(progresses, speeds):
    answer = []

    day = 1
    dimension = []
    for idx in range(0, len(progresses)):
        while progresses[idx] + speeds[idx] * day < 100:
            day += 1
        if day in dimension:
            answer[len(dimension) -1] += 1
        else:
            answer.append(1)
            dimension.append(day)
    
    return answer