n_lines = int(input())
words = [''] * n_lines
for i in range(n_lines):
    words[i] = input()
    letter_count = 0
    for letter in words[i]:
        letter_count += 1
    if letter_count > 10:
        new_word = str(words[i][0] + str(letter_count - 2) + words[i][-1])
        words[i] = new_word

for word in words:
    print(word, '\n')
