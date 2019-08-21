s1 = input("Insert the first string: ")
s2 = input("Insert the second string: ")

index = s1.find(s2)
if index != -1:
    print("\n%s found within %s at position %d" % (s2, s1, index))
else:
    print("%s was not found within %s" % (s2, s1))