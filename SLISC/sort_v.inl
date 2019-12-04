// sort first m elements of arr, quicksort algorithm
void sort_v(Int *arr, Long_I N, Long_I m = -1)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Int a;
    VecLong istack(NSTACK);
    if (m>0) n = MIN(m, n);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = arr[j];
                for (i = j - 1; i >= l; i--) {
                    if (arr[i] <= a) break;
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = a;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(arr[k], arr[l + 1]);
            if (arr[l] > arr[ir]) {
                swap(arr[l], arr[ir]);
            }
            if (arr[l + 1] > arr[ir]) {
                swap(arr[l + 1], arr[ir]);
            }
            if (arr[l] > arr[l + 1]) {
                swap(arr[l], arr[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = arr[l + 1];
            for (;;) {
                do i++; while (arr[i] < a);
                do j--; while (arr[j] > a);
                if (j < i) break;
                swap(arr[i], arr[j]);
            }
            arr[l + 1] = arr[j];
            arr[j] = a;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort.");
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

// sort first m elements of arr, quicksort algorithm
void sort_v(Llong *arr, Long_I N, Long_I m = -1)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Llong a;
    VecLong istack(NSTACK);
    if (m>0) n = MIN(m, n);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = arr[j];
                for (i = j - 1; i >= l; i--) {
                    if (arr[i] <= a) break;
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = a;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(arr[k], arr[l + 1]);
            if (arr[l] > arr[ir]) {
                swap(arr[l], arr[ir]);
            }
            if (arr[l + 1] > arr[ir]) {
                swap(arr[l + 1], arr[ir]);
            }
            if (arr[l] > arr[l + 1]) {
                swap(arr[l], arr[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = arr[l + 1];
            for (;;) {
                do i++; while (arr[i] < a);
                do j--; while (arr[j] > a);
                if (j < i) break;
                swap(arr[i], arr[j]);
            }
            arr[l + 1] = arr[j];
            arr[j] = a;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort.");
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

// sort first m elements of arr, quicksort algorithm
void sort_v(Doub *arr, Long_I N, Long_I m = -1)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Doub a;
    VecLong istack(NSTACK);
    if (m>0) n = MIN(m, n);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = arr[j];
                for (i = j - 1; i >= l; i--) {
                    if (arr[i] <= a) break;
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = a;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(arr[k], arr[l + 1]);
            if (arr[l] > arr[ir]) {
                swap(arr[l], arr[ir]);
            }
            if (arr[l + 1] > arr[ir]) {
                swap(arr[l + 1], arr[ir]);
            }
            if (arr[l] > arr[l + 1]) {
                swap(arr[l], arr[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = arr[l + 1];
            for (;;) {
                do i++; while (arr[i] < a);
                do j--; while (arr[j] > a);
                if (j < i) break;
                swap(arr[i], arr[j]);
            }
            arr[l + 1] = arr[j];
            arr[j] = a;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort.");
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

