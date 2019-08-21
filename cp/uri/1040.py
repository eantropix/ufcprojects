[n1, n2, n3, n4] = (float(i) for i in input().split())

avg = (n1 * 2 + n2 * 3 + n3 * 4 + n4 * 1) / 10

print("Media: %.1f" % avg)

if avg >= 7.0:
	print("Aluno aprovado.")
elif avg < 5.0:
	print("Aluno reprovado.")
elif 5.0 <= avg < 7.0:
	print("Aluno em exame.")
	af = float(input())
	print("Nota do exame:", af)
	navg = (avg + af) / 2
	if navg >= 5:
		print("Aluno aprovado.")
		print("Media final:", navg)
	else:
		print("Aluno reprovado.")
		print("Media final:", navg)