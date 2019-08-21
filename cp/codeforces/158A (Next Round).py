n, k = input().split()
n = int(n)
k = int(k)
participants = [int(x) for x in input().split()]

passing_score = participants[k]
print(participants)
print(passing_score)


def how_many_passed(passing_score):
    passed_count = 0
    for contestant in participants:
        if contestant >= passing_score:
            passed_count += 1
    print(passed_count)


how_many_passed(passing_score)
