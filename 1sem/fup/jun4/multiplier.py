def receiver(file):
	matrix = open(file, 'r')
	matrix = matrix.readlines()
	for line in range(len(matrix)):
		matrix[line] = matrix[line].replace('\n', '')
		matrix[line] = matrix[line].split(sep=' ')
	return matrix

def tester(file1, file2):
	a = receiver(file1)
	b = receiver(file2)

	count_a = len(a[0])  # Number of columns (length of sub-list)
	count_b = len(b)  # Needs to be equal to number of lines (length of list)

	if count_a == count_b:
		return True
	else:
		return False

