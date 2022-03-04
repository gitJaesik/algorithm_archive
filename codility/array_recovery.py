
# A to B

# A = [2, 5, 3, 7, 9, 6]
# B = [0, 0, 0, 0, 0, 0]
# ans = 0
# for K in range(0, len(A)):
#  for J in range(0, K):
#   if J < k and A[J] < A[K]:
#    ans = A[J]
#  B[K] = ans

# index: K < J
# A[K] < A[J]
# J is fixed
# K = max(ans, K)
# if K is not exist, then B[J] is 0 == K is -1 not in index


# B to A

def solution(A, M):
    # M = 4, B = [0, 2, 2]
    B = A[:]
    ans = 0
    for K in range(0, len(A)):
        for J in range(0, K):
            if A[J] < A[K]:
                ans = A[J]
        B[K] = ans

    print(B)

    return 0


def main():
    B = [2, 5, 3, 7, 9, 6]
    print(solution(B, 10))


if __name__ == "__main__":
    main()
