s = input("Insert a string: ")
chars_list = []
chars_count = 0
for letter in s:
    if letter not in chars_list and letter != ' ':
        chars_list.append(letter)
        n = s.count(letter)
        print("\n%s appears %d times" % (letter, n))

        
            