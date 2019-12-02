inline void matt_write_scalar(Char_I s, ofstream &m_out)
{
    m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Int_I s, ofstream &m_out)
{
    m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Llong_I s, ofstream &m_out)
{
    m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Doub_I s, ofstream &m_out)
{
    m_out << to_num(s) << Matt::dlm;
}

inline void matt_write_scalar(Comp_I s, ofstream &m_out)
{
	if (imag(s) == 0)
		m_out << real(s) << Matt::dlm;
	else if (imag(s) < 0)
		m_out << real(s) << imag(s) << "i ";
	else
		m_out << real(s) << '+' << imag(s) << "i ";
}

