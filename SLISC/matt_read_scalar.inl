void Matt::matt_read_scalar(Char_O s, ifstream &m_in)
{
    Int temp; m_in >> temp; s = (T)temp;
}

void Matt::matt_read_scalar(Int_O s, ifstream &m_in)
{
    m_in >> s;
}

void Matt::matt_read_scalar(Llong_O s, ifstream &m_in)
{
    m_in >> s;
}

void Matt::matt_read_scalar(Doub_O s, ifstream &m_in)
{
    m_in >> s;
}

void Matt::matt_read_scalar(Comp_O s, ifstream &m_in)
{
    Doub cr = 0, ci = 0;
    Char ch;
    m_in >> cr;
    ch = m_in.get();
    if (ch == Matt::dlm) {
        c = cr; return;
    }
    m_in >> ci;
    if (ch == '-')
        ci *= -1.;
    c = Comp(cr, ci);
    m_in.ignore(100, Matt::dlm);
}

