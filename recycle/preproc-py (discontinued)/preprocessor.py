#!/usr/bin/python3
def is_arithmetic(T):
    return is_integral(T) or is_fpt(T)

def is_basic_str(T):
    return any(strfind(T, 'basic_string')) or is_Str(T)

def is_Bool(T):
    return T == 'bool'

def is_Cband(T):
    return T[:5] == 'Cband' and is_scalar(T[5:])

def is_Char(T):
    return T == 'Char'

def is_cmajor(T):
    if (is_Cmat(T) or is_Fcmat(T) or is_Cmat3(T) or \
            is_Cmat4(T) or is_Scmat(T) or is_Scmat_c(T) or  \
            is_Scmat3(T) or is_Scmat3_c(T) or is_Dcmat(T)):
        return True
    else:
        return False

def is_Cmat(T):
    return T[:5] == 'Cmat' and is_scalar(T[4:])

def is_Cmat3(T):
    return T[:5] == 'Cmat3'

def is_Cmat4(T):
    return T[:5] == 'Cmat4'

def is_Cmobd(T):
    return T[:5] == 'Cmobd'

def is_Comp(T):
    return T == 'Comp'

def is_comp_contain(T):
    return is_contain(T) and is_comp(contain_type(T))

def is_comp_dense(T):
    return is_dense(T) and is_comp(contain_type(T))

def is_contain(T):
    return contain_num(T) >= 0

def is_Dcmat(T):
    return T[:5] == 'Dcmat'

def is_dense(T):
    return is_dense_vec(T) or is_dense_mat(T) or  \
    is_dense_mat3(T) or is_dense_mat4(T) or  \
    is_Mat3(T) or is_Cmat3(T) or is_Cmat4(T)

def is_dense_mat(T):
    return is_Mat(T) or is_Cmat(T) or is_Fcmat(T) \
        or is_Scmat(T) or is_Scmat_c(T) or is_Smat(T)

def is_dense_mat3(T):
    return is_Mat3(T) or is_Cmat3(T) or is_Scmat3(T) or is_Scmat3_c(T)

def is_dense_mat4(T):
    return is_Cmat4(T) or is_Jcmat4(T)

def is_dense_vec(T):
    return is_Vbase(T) or is_Vec(T) or is_Fvec(T) or \
    is_Svec(T) or is_Svec_c(T)

def is_Diag(T):
    return T[:4] == 'Diag'

def is_diff_major(T, U):
    if (is_cmajor(T) and is_rmajor(U)):
        return True
    elif (is_rmajor(T) and is_cmajor(U)):
        return True
    else:
        return False

def is_Dmat(T):
    return T[:4] == 'Dmat'

def is_Doub(T):
    return T == 'Doub'

def is_Dvec(T):
    return T[:4] == 'Dvec'

def is_Fcmat(T):
    return T[:5] == 'Fcmat'

def is_Fcomp(T):
    return T == 'Fcomp'

def is_Fimag(T):
    return T == 'Fimag'

def is_fixed(T):
    return is_FixVec(T) or is_FixCmat(T)

def is_Float(T):
    return T == 'Float'

def is_fpt(T):
    return is_Float(T) or is_Doub(T) or is_Ldoub(T)

def is_fpt_dense(T):
    return is_dense(T) and is_fpt(contain_type(T))

def is_fundamental(T):
    return is_arithmetic(T) or is_void(T) or is_nullptr(T)

def is_Fvec(T):
    return T[:4] == 'Fvec'

def is_Imag(T):
    return T == 'Imag'

def is_Int(T):
    return T == 'Int'

def is_integral(T):
    return is_Char(T) or is_Int(T) or \
    is_Long(T) or is_Llong(T)

def is_Jcmat(T):
    return T[:5] == 'Jcmat' and T[:6] != 'Jcmat3'

def is_Jcmat3(T):
    return T[:6] == 'Jcmat3'

def is_Jcmat4(T):
    return T[:5] == 'Jcmat4'

def is_Lcomp(T):
    return T == 'Lcomp'

def is_Ldoub(T):
    return T == 'Ldoub'

def is_Limag(T):
    return T == 'Limag'

def is_Llong(T):
    return T == 'Llong'

def is_Long(T):
    return T == 'Long'

def is_Mat(T):
    return T[:3] == 'Mat' and is_scalar(T[3:])

def is_Mat3(T):
    return T[:4] == 'Mat3'

def is_Mcoo(T):
    return T[:4] == 'Mcoo'

def is_Mcooh(T):
    return T[:5] == 'Mcooh'

def is_promo(T1, T2):
    num1 = type_num(T1)
    num2 = type_num(T2)
    if (is_real(T2)):
        if (is_real(T1)):
            if (num1 >= num2):
                return True
        elif (is_comp(T1)):
            if (num1 - num2 >= 20):
                return True
        else: # is_imag(T1)
            if (num1 - num2 >= 40):
                return True
    elif (is_comp(T2)):
        if (is_comp(T2)):
            if (num1 >= num2):
                return True
    elif (is_imag(T2)):
        if (is_imag(T1)):
            if (num1 >= num2):
                return True
        if (is_comp(T1)):
            if (num2 - num1 >= 20):
                return True
    return False

def is_real(T):
    num = type_num(T)
    return num >= 0 and num < 40

def is_real_contain(T):
    return is_contain(T) and is_real(contain_type(T))

def is_real_dense(T):
    return is_dense(T) and is_real(contain_type(T))

def is_rmajor(T):
    if (is_Mat(T) or is_Mat3(T) or \
            is_Smat(T) or is_Dmat(T)):
        return True
    else:
        return False

def is_same(T1, T2):
    return T1 == T2

def is_same_contain(T1, T2):
    return is_contain(T1) and contain_num(T1) == contain_num(T2)

def is_same_contain_type(T1, T2):
    return is_same(contain_type(T1), contain_type(T2))

def is_same_major(T, U):
    if (is_cmajor(T) and is_cmajor(U)):
        return True
    elif (is_rmajor(T) and is_rmajor(U)):
        return True
    elif (ndim(T) == 1 and ndim(T) == 1):
        return True
    else:
        return False

def is_scalar(T):
    return type_num(T) >= 0 or is_Long(T)

def is_Scmat(T):
    return T[:5] == 'Scmat' and is_scalar(T[5:])

def is_Scmat_c(T):
    return numel(regexp(T, 'Scmat.*_c?', 'once')) > 0

def is_Scmat3(T):
    return T[:6] == 'Scmat3'

def is_Scmat3_c(T):
    return T[:6] == 'Scmat3'

def is_signed(T):
    return is_Char(T) or is_Int(T) or is_Llong(T) \
        or is_fpt(T)

def is_slice_mat(T):
    return is_Scmat(T) or is_Scmat_c(T) or is_Dcmat(T)

def is_slice_vec(T):
    return is_Svector(T) or is_Dvector(T)

def is_Smat(T):
    return T[:4] == 'Smat'

def is_sparse_mat(T):
    return is_Diag(T) or is_Mcoo(T) or \
    is_Mcooh(T) or is_Cmobd(T)

def is_Str(T):
    return T == 'Str'

def is_Svec(T):
    return T[:4] == 'Svec'

def is_Svec_c(T):
    return numel(regexp(T, 'Svec.*_c?', 'once')) > 0

def is_Uchar(T):
    return T == 'Uchar'

def is_Vbase(T):
    return T[:5] == 'Vbase'

def is_Vec(T):
    return T[:3] == 'Vec'

def ndim(T):
    if is_scalar(T):
        return 0
    elif is_Vbase(T) or is_dense_vec(T) or is_Fvec(T) or \
        is_Svec(T) or is_Svec_c(T) or is_Dvec(T) or is_vec(T):
        return 1
    elif is_dense_mat(T) or is_sparse_mat(T) or \
        is_Fcmat(T) or is_Scmat(T) or is_Scmat_c(T) or \
        is_Scmat3(T) or is_Scmat3_c(T) or \
        is_Dcmat(T) or is_Jcmat(T) or is_Cmobd(T) or \
        is_Cband(T):
        return 2
    elif is_Mat3(T) or is_Cmat3(T) or is_Jcmat3(T):
        return 3
    elif is_Cmat4(T) or is_Jcmat4(T):
        return 4
    else:
        raise Exception("unknown!")

def next_line(str, start):
    return find_next(str, char(10), start) + 1

def promo_type(T1, T2):
    num1 = type_num(T1)
    num2 = type_num(T2)
    if is_real(T1) and is_real(T2):
        if num1 >= num2:
            return T1
        else:
            return T2
        end
    elif is_comp(T1) and is_comp(T2):
        if num1 >= num2:
            return T1
        else:
            return T2
    elif is_real(T1) and is_comp(T2):
        if num2 - num1 >= 20:
            return T2
        elif is_Doub(T1):
            return 'Comp'
        elif is_Ldoub(T1):
            return 'Lcomp'
        end
    elif is_comp(T1) and is_real(T2):
        if num1 - num2 >= 20:
            return T1
        elif is_Doub(T2):
            return 'Comp'
        elif is_Ldoub(T2):
            return 'Lcomp'
        end
    elif is_Imat(T1) and is_comp(T2):
        if num1 - num2 <= 20:
            return T2
        elif is_Doub(contain_type(T1)):
            return 'Comp'
        elif is_Ldoub(contain_type(T1)):
            return 'Lcomp'
        end
    elif is_comp(T1) and is_Imag(T2):
        if num2 - num1 <= 20:
            return T1
        elif is_Doub(contain_type(T2)):
            return 'Comp'
        elif is_Ldoub(contain_type(T2)):
            return 'Lcomp'
        end
    end
    raise Exception('not implemented')

def rm_comp(T):
    if is_Fcomp(T):
        return 'Float'
    elif is_Comp(T):
        return 'Doub'
    elif is_Lcomp(T):
        return 'Ldoub'
    else:
        return T

def slice_type(T):
    Ts = contain_type(T)
    if is_Vec(T) or is_Svec(T):
        return 'Svec' + Ts
    elif is_Dvec(T):
        return 'Dvec' + Ts
    elif is_Cmat(T) or is_Scmat(T) or is_Dcmat(T):
        return 'Dcmat' + Ts
    elif is_Cmat3(T):
        return 'Jcmat3' + Ts
    else:
        raise Exception('not implemented!')

def slice1_type(T):
    Ts = contain_type(T)
    if is_Cmat(T) or is_Scmat(T) or is_Dcmat(T) or is_Cmat3(T):
        return 'Svec' + Ts
    elif is_Mat(T):
        return 'Dvec' + Ts
    else:
        raise Exception('not implemented!')

def slice2_type(T):
    Ts = contain_type(T)
    if is_Cmat(T) or is_Scmat(T) or is_Dcmat(T) or is_Cmat3(T):
        return 'Dvec' + Ts
    elif is_Mat(T):
        return 'Svec' + Ts
    else:
        raise Exception('not implemented!')

def slice3_type(T):
    Ts = contain_type(T)
    if is_Cmat3(T) or is_Cmat4(T):
        return 'Dvec' + Ts
    elif is_Mat3(T):
        return 'Svec' + Ts
    else:
        raise Exception('not implemented!')

def slice12_type(T):
    Ts = contain_type(T)
    if is_cmajor(T) and is_dense(T):
        return 'Scmat' + Ts
    else:
        raise Exception('slice12_type.m: not implemented!')

def type_num(T):
    if (is_Bool(T)): return 0
    elif (is_Char(T)): return 1
    elif (is_Int(T)): return 2
    elif (is_Llong(T)): return 3

    elif (is_Float(T)): return 20
    elif (is_Doub(T)): return 21
    elif (is_Ldoub(T)): return 22

    elif (is_Fcomp(T)): return 40
    elif (is_Comp(T)): return 41
    elif (is_Lcomp(T)): return 42

    elif (is_Fimag(T)): return 60
    elif (is_Imag(T)): return 61
    elif (is_Limag(T)): return 62
    else: return -1


def add_comp(T):
    if is_comp(T): return T
    elif is_Float(T): return 'Fcomp'
    elif is_Doub(T): return 'Comp'
    elif is_Ldoub(T): return 'Lcomp'
    else: raise Exception('not implemented')

def add_imag(T):
    if is_imag(T): return T
    elif is_Float(T): return 'Fimag'
    elif is_Doub(T): return 'Imag'
    elif is_Ldoub(T): return 'Limag'
    else: raise Exception('not implemented')

def contain_num(T):
    if (is_Vec(T)): return 0
    elif (is_Mat(T)): return 1
    elif (is_Cmat(T)): return 2
    elif (is_Mat3(T)): return 3
    elif (is_Cmat3(T)): return 4
    elif (is_Cmat4(T)): return 6
    elif (is_Fvec(T)): return 20
    elif (is_Fcmat(T)): return 22
    elif (is_Diag(T)): return 31
    elif (is_Mcoo(T)): return 32
    elif (is_Mcooh(T)): return 33
    elif (is_Cmobd(T)): return 34
    elif (is_Svec(T)): return 40
    elif (is_Dvec(T)): return 41
    elif (is_Smat(T)): return 42
    elif (is_Scmat(T)): return 43
    elif (is_Dmat(T)): return 44
    elif (is_Dcmat(T)): return 45
    elif (is_Jcmat(T)): return 46
    elif (is_Jcmat3(T)): return 47
    elif (is_Svec_c(T)): return 48
    elif (is_Scmat_c(T)): return 49
    elif (is_Scmat3(T)): return 50
    elif (is_Scmat3_c(T)): return 51
    else: return -1

def contain_type(T):
    if any(strfind(T, 'Char')): return 'Char'
    elif any(strfind(T, 'Int')): return 'Int'
    elif any(strfind(T, 'Llong')): return 'Llong'
    elif any(strfind(T, 'Long')): return 'Long'
    elif any(strfind(T, 'Float')): return 'Float'
    elif any(strfind(T, 'Doub')): return 'Doub'
    elif any(strfind(T, 'Ldoub')): return 'Ldoub'
    elif any(strfind(T, 'Fcomp')): return 'Fcomp'
    elif any(strfind(T, 'Comp')): return 'Comp'
    elif any(strfind(T, 'Lcomp')): return 'Lcomp'
    elif any(strfind(T, 'Imag')): return 'Imag'
    else: raise Exception('not implemented')
