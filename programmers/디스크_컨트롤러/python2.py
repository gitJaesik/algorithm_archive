import heapq

def solution(jobs):
    answer = 0
    dict_jobs = {job[0] : job[1] for job in jobs}
    job_times = []
    [heapq.heappush(job_times, job[0]) for job in jobs]

    h = []
    finished = 0
    current_job = []
    while finished < len(jobs):
        job_time = heapq.heappop(job_times)

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
            heapq.heappush(job_times, int(int(job_time) + int(job[0])))

    answer = int(answer / len(jobs))

    return answer

if __name__ == "__main__":
    # jobs = [[0, 3], [1, 9], [2, 6]]
    # jobs = [[0, 10], [1, 9], [2, 6], [30, 5]]
    jobs = [[0, 10], [1, 9], [2, 9], [30, 5]]
    print(solution(jobs))
