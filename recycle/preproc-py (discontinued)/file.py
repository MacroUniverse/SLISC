#!/usr/bin/python3

# write a string to a file
def filewrite(file_name, str):
    fout = open(file_name, 'w')
    fout.write(str)
    fout.close()

# read a string from a file
def fileread(file_name):
    fout = open(file_name, 'r')
    str = fout.read()
    fout.close()
    return str
