def auto_gen(file):
    import sys
    from os import listdir
    # insert at 1, 0 is the script path
    sys.path.insert(1, 'preproc-py')
    from preprocessor import *
    from file import fileread, filewrite

    in_list = listdir('SLISC/*.in')
    Ntp = len(in_list)
    for i in range(Ntp):
        in_file = in_list[i].strip()
        if len(sys.argv) > 0 and in_file != file :
            continue
        print(in_file)
        s = fileread(in_file)
        ind = 0
        code = []; k = 0
        while 1:
            ind1 = s.find('//#', ind)
            if (ind1 < 0):
                break
            ++k
            code.append(s[ind:ind1])
            ind2 = s.find('//#-----', ind1)
            type_str = s[ind1:ind2].replace('//#', '')
            eval(type_str)
            ind2 = s.find('\n', ind2) + 1;
            ind3 = s.find('//#-----', ind2)
            if (ind3 < 0):
                raise Exception('no closing //#-----')
            str1 = s[ind2:ind3]
            Ninst = len(types)
            for j in range(Ninst):
                ++k
                code = instantiate(str1, types[j]) + '\n'
            del types
            ind = s.find('\n', ind3) + 1;
        ++k
        code[k] = s[ind:]
        code_cat = ''.join(code)
        filewrite(in_file[:-3], code_cat)
