import heapq

def solution(jobs):
    answer = 0
    dict_jobs = {job[0] : job[1] for job in jobs}

    h = []
    finished = 0
    current_job = []
    job_time = 0
    while finished < len(jobs):

        if job_time in dict_jobs:
            heapq.heappush(h, [dict_jobs[job_time], job_time])

        if len(current_job) != 0:
            if job_time - current_job[2] >= current_job[1]:
                answer += job_time - current_job[0]
                current_job.clear()
                finished += 1

        if len(current_job) == 0 and len(h) > 0:
            job = heapq.heappop(h)
            current_job = [job[1], job[0], job_time]

        job_time += 1

    answer = int(answer / len(jobs))

    return answer

if __name__ == "__main__":
    jobs = [[0, 3], [1, 9], [2, 6]]
    print(solution(jobs))
