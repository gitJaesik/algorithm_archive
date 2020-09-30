import heapq


def solution(scoville, K):
    answer = 0

    h = []
    [heapq.heappush(h, i) for i in scoville]

    while h[0] < K:
        if len(h) <= 1:
            answer = -1
            break
        heapq.heappush(h, heapq.heappop(h) + (heapq.heappop(h) * 2))
        answer += 1

    return answer
