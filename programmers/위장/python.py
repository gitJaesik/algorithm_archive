def solution(clothes):
    answer = 0
    dictOfClothes = {}
    for clothe in clothes:
        if clothe[1] in dictOfClothes:
            dictOfClothes[clothe[1]] += 1
        else:
             dictOfClothes[clothe[1]] = 1
                
    answer = 1
    for key in dictOfClothes:
        answer *= dictOfClothes[key] + 1
        
    answer -= 1 
    
    return answer