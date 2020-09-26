import collections

def solution(genres, plays):
    answer = []

    len_songs = len(genres)

    # 장르 정렬
    dictOfGenres = {}

    for i in range(0, len_songs):
        if genres[i] not in dictOfGenres:
            dictOfGenres[genres[i]] = plays[i]
        else:
            dictOfGenres[genres[i]] += plays[i]

    dictOfGenres = {val[0]: val[1] for val in sorted(
        dictOfGenres.items(), key=lambda x: (-x[1], x[0]))}

    # 장르 내 정렬
    dictOfPlays = {}
    for i in range(0, len_songs):
        if genres[i] not in dictOfPlays:
            dictOfPlays[genres[i]] = []

        dictOfPlays[genres[i]].append((plays[i], i))

    for key in dictOfPlays:
        dictOfPlays[key] = sorted(
            dictOfPlays[key], key=lambda x: (-x[0], x[1]))

    for genres in dictOfGenres:
        answer.append(dictOfPlays[genres][0][1])
        if len(dictOfPlays[genres]) > 1:
            answer.append(dictOfPlays[genres][1][1])

    return answer