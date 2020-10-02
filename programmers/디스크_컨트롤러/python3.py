import heapq


def solution(jobs):
    last = -1
    now = 0
    answer = 0
    wait_jobs = []
    n = len(jobs)
    count = 0
    while(count < n):
        for job in jobs:
            if last < job[0] <= now:
                answer += (now-job[0])
                heapq.heappush(wait_jobs, job[1])
        if len(wait_jobs) > 0:
            answer += len(wait_jobs)*wait_jobs[0]
            last = now
            now += heapq.heappop(wait_jobs)
            count += 1
        else:
            now += 1
    return answer//n
