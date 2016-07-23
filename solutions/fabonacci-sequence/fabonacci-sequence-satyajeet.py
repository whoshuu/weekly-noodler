def fab(i, n) :
	if i == 0:
		raise ValueError('i must be greater than 0')
	elif i == n:
		return 1
	
	if n < 1:
		return 0
	else:
	  	return fab(i, n - 1) + fab(i, n - 2)
