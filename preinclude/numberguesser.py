highest = 10000
tries = 0
answer = random.randint(1, highest)
print("Try to guess a number between 1 and {}! Let's do this.".format(highest)
guess = int(input("Start by guessing a number!"))

while(tries < 10):
	if guess != answer:
		if guess > answer:
			tries += 1
			print("Guess lower!")
			print("You have {} guesses left!".format(10 - tries)
		else:
			tries += 1
			print("Guess higher!")
			print("You have {} guesses left!".format(10 - tries)
	else:
		print("CONGRATULATIONS!! YOU GUESSED IT!!")
else:
	print("GAME OVER!!")
