def solution(priorities, location):
    answer = 0
    
    sorted_priorities = sorted(priorities)
    
    priorities = [ [priorities[i], i] for i in range(0, len(priorities)) ]
    
    cur = 0
    while True:
        if priorities[cur][0] < sorted_priorities[-1]:
            priorities.append(priorities[cur])
        else:
            sorted_priorities.pop()
            answer += 1
            if priorities[cur][1] == location:
                break
            
        cur += 1
    
    return answer