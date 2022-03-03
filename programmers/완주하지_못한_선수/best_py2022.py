import collections


def solution(participant, completion):
    print('first')
    print(collections.Counter(participant))

    print('second')
    print(collections.Counter(completion))

    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]


if __name__ == "__main__":

    a1 = ["leo", "kiki", "eden"]
    b1 = ["eden", "kiki"]
    print(solution(a1, b1))

    a3 = ["mislav", "stanko", "mislav", "ana"]
    b3 = ["stanko", "ana", "mislav"]
    print(solution(a3, b3))