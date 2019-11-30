void disp(VecLlong_I v, Int_I precision = def_disp_prec)
{
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (v.size() == 0)
        cout << "empty";
    else
        for (Long i = 0; i < v.size(); ++i) {
            cout << to_num(v[i]) << "   ";
        }
    cout << endl << endl;
    cout.precision(oldPrecision);
}

void disp(VecDoub_I v, Int_I precision = def_disp_prec)
{
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (v.size() == 0)
        cout << "empty";
    else
        for (Long i = 0; i < v.size(); ++i) {
            cout << to_num(v[i]) << "   ";
        }
    cout << endl << endl;
    cout.precision(oldPrecision);
}

void disp(VecComp_I v, Int_I precision = def_disp_prec)
{
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (v.size() == 0)
        cout << "empty";
    else
        for (Long i = 0; i < v.size(); ++i) {
            cout << to_num(v[i]) << "   ";
        }
    cout << endl << endl;
    cout.precision(oldPrecision);
}

void disp(MatLlong_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

void disp(MatDoub_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

void disp(MatComp_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

void disp(CmatLlong_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

void disp(CmatDoub_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

void disp(CmatComp_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

void disp(SvecLlong_I v, Int_I precision = def_disp_prec)
{
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (v.size() == 0)
        cout << "empty";
    else
        for (Long i = 0; i < v.size(); ++i) {
            cout << to_num(v[i]) << "   ";
        }
    cout << endl << endl;
    cout.precision(oldPrecision);
}

void disp(SvecDoub_I v, Int_I precision = def_disp_prec)
{
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (v.size() == 0)
        cout << "empty";
    else
        for (Long i = 0; i < v.size(); ++i) {
            cout << to_num(v[i]) << "   ";
        }
    cout << endl << endl;
    cout.precision(oldPrecision);
}

void disp(SvecComp_I v, Int_I precision = def_disp_prec)
{
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (v.size() == 0)
        cout << "empty";
    else
        for (Long i = 0; i < v.size(); ++i) {
            cout << to_num(v[i]) << "   ";
        }
    cout << endl << endl;
    cout.precision(oldPrecision);
}

void disp(DcmatLlong_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

void disp(DcmatDoub_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

void disp(DcmatComp_I a, Int_I precision = def_disp_prec)
{
    Long i, j, m{ a.n1() }, n{ a.n2() };
    auto oldPrecision = cout.precision();
    cout.precision(precision);
    if (a.size() == 0) cout << "empty";
    else
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cout << to_num(a(i, j)) << "   ";
            }
            cout << endl;
        }
    cout << endl;
    cout.precision(oldPrecision);
}

