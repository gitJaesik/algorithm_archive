def getStrNum(num):
    newValue = ""
    if num < 10:
        newValue = "0" + str(num)
    else:
        newValue = str(num)

    return newValue


def getNextPlusCicle(num):
    num2 = getStrNum(num)
    sum = int(num2[0]) + int(num2[1])
    sum2 = getStrNum(sum)

    return int(num2[1] + sum2[1])


def main():
    a = int(input())
    origin = a
    cnt = 1
    while True:
        a = getNextPlusCicle(a)
        if origin == a:
            break
        cnt += 1
    print(cnt)


if __name__ == "__main__":
    main()
