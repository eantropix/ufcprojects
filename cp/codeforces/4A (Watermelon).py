w = int(input())  # w will be "divided" into two possible values:
high = w - 1  # high, which will start at w - 1
low = 1  # low, which starts at 1
flag = False  # this indicates whether w has two even candidates
while high >= w/2 and not flag:  # tries all combinations till w/2. Continuing further would be redundant
    if high % 2 == 0 and low % 2 == 0:  # if they're both even:
        if high + low == w:  # if they add up to original weight
            flag = True
    high -= 1
    low += 1
    

if flag:
    print('YES')
else:
    print('NO')
