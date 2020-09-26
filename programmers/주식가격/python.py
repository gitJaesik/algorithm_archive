def solution(prices):
    answer = []

    stk = []
    dictOfAnswer = {}
    for idx in range(0, len(prices)-1):
        stk.append((prices[idx], idx))

        while(len(stk) > 0):
            if stk[len(stk)-1][0] > prices[idx+1]:
                (_, index) = stk.pop()
                dictOfAnswer[index] = idx+1 - index
            else:
                break
    dictOfAnswer[len(prices) - 1] = 0

    for ss in stk:
        dictOfAnswer[ss[1]] = len(prices) - ss[1] - 1

    for idx in range(0, len(prices)):
        answer.append(dictOfAnswer[idx])

    return answer

if __name__ == "__main__":
    prices = [1, 2, 3, 2, 3]
    solution(prices)