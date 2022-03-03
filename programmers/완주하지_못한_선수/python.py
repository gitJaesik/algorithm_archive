def solution(participant, completion):
    answer = ''

    dictOfParticipant = {}

    for person in participant:
        if person in dictOfParticipant:
            dictOfParticipant[person] += 1
        else:
            dictOfParticipant[person] = 1

    for person in completion:
        if person in dictOfParticipant:
            dictOfParticipant[person] -= 1
            if dictOfParticipant[person] == 0:
                del dictOfParticipant[person]

    listKey = list(dictOfParticipant.keys())
    answer = listKey[0]

    return answer