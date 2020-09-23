def solution(phone_book):
    answer = True
    
    # print(phone_book)
    
    # map을 만듦
    # map 안에 element가 존재하는지 여부 확인
    
    # dictOfPhone = { i : 1 for i in phone_book }
    dictOfPhone = {}
    
    for phone in phone_book:
        phone_len = len(phone)
        for i in range(1, phone_len+1):
            # print(phone[0:i])
            if phone[0:i] in dictOfPhone:
                dictOfPhone[phone[0:i]] += 1
            else:
                dictOfPhone[phone[0:i]] = 1
    
    # print(dictOfPhone)
    
    for phone in phone_book:
        # print(phone)
        if dictOfPhone[phone] > 1:
            answer = False
            break
    
    return answer