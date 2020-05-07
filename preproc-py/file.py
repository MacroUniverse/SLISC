#!/usr/bin/python3
# write a string to a file
def filewrite(file_name, str):
    fout = open(file_name, 'w')
    fout.write(str)
    fout.close()
