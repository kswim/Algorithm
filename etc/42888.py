def solution(record):
    answer = []
    result = []
    user = dict()
    
    for item in record:
        info = item.split()
        if info[0] == "Enter" or info[0] == "Leave":
            result.append((info[1], info[0]))
        
        if info[0] == "Enter" or info[0] == "Change":
            user[info[1]] = info[2]

    for uid, string in result:
        if string == 'Enter':
            answer.append(user[uid]+'님이 들어왔습니다.')
        else:
            answer.append(user[uid]+'님이 나갔습니다.')

    return answer
