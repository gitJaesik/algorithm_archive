from queue import PriorityQueue

def solution(scoville, K):
    answer = 0
    
    pq = PriorityQueue()
    
    for item in scoville:
        pq.put(item)
        
    while True:
        m = pq.get()
        
        if m < K:
            if pq.qsize() == 0:
                answer = -1
                break
            
            m2 = pq.get()
            pq.put(m + m2 * 2)
            answer += 1
        else:
            break
        
    return answer