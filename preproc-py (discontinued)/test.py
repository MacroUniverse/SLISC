s = "abcd"
print(s)
fout = open("test.txt","w")
fout.write(s)
fout.close()

fin = open("test.txt","r")
s1 = fin.read()
print(s1)
if (s1 != s):
	raise Exception("An error occurred")
