//  from Numerical Recipes 3ed
void sort2_vv(Char *v, Long *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Char a;
    Long b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

//  from Numerical Recipes 3ed
void sort2_vv(Int *v, Int *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Int a;
    Int b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

//  from Numerical Recipes 3ed
void sort2_vv(Int *v, Long *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Int a;
    Long b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

//  from Numerical Recipes 3ed
void sort2_vv(Llong *v, Long *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Llong a;
    Long b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

//  from Numerical Recipes 3ed
void sort2_vv(Doub *v, Long *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Doub a;
    Long b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

