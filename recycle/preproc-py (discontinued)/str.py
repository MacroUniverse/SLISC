def get_line(str, start):
	ind = str.find('\n', start)
	return str[start:ind]
