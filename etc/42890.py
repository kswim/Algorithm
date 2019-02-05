combination = []

def solution(relation):
    answer = 0
    keys = []
    size = len(relation[0])

    result = []
    for i in range(size): 
        dfs(i, size, result)

    comb = sorted(combination, key=len)

    for items in comb:
        result = []
        able = True
        for cols in keys:
            cnt = 0
            for col in cols: 
                if col in items:
                    cnt = cnt+1
            if cnt == len(cols):
                able= False
                break
                
        if not able :
            continue
        
        for Tuple in relation:
            curr = []
            for i in items:
                curr.append(Tuple[i])
            if curr in result:
                break
            else:
                result.append(curr)
        else:
            keys.append(items)
    
    answer = len(keys)
    
    return answer

def dfs(curr, size, result):
    if curr == size:
        return 
    else:
        result.append(curr)
        combination.append(result[:])
        
        for i in list(range(curr+1,size+1)):
            dfs(i,size, result)
        result.pop()
