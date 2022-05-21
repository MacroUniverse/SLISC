#include "../SLISC/Bit.h"
#include "../SLISC/file.h"
#include "../SLISC/quad_math.h"

// >> and << operating on signed integer is "undefined"!
// Char and Uchar reinterpret cast conserves bit, but static cast might not (for older architecture)

void test_Bit()
{
    using namespace slisc;
    if (!little_endian())
        SLS_WARN("this system is using big endian, is it x86 or x64 architecture?");

    Char byte = 0;
    for (Long i = 0; i < 8; ++i) {
        if (bitL(&byte, i) != 0 || bitR(&byte, i) != 0)
            SLS_ERR("failed!");
    }

    if (to_bitstr(bit2char(128)) != "10000000")
        SLS_ERR("failed!");

    for (Long i = 0; i < 8; ++i) {
        Char byte = 0;
        set_bitR(&byte, i);
        if (byte != bit2char(pow(2, i)))
            SLS_ERR("failed!");
        unset_bitR(&byte, i);
        if (byte != 0)
            SLS_ERR("failed!");

        byte = 0;
        set_bitL(&byte, i);
        if (byte != bit2char(pow(2, 7-i)))
            SLS_ERR("failed!");
        unset_bitL(&byte, i);
        if (byte != 0)
            SLS_ERR("failed!");
    }

    Char ui[] = {Char(255), Char(128), 85};
    if (to_bitstr(ui) != "11111111")
        SLS_ERR("failed!");
    if (to_bitstr(ui+1) != "10000000")
        SLS_ERR("failed!");
    if (to_bitstr(ui+2) != "01010101")
        SLS_ERR("failed!");
    if (str2bit("10100101") != bit2char(0b10100101))
        SLS_ERR("failed!");

    Char uc = 0b10100101;
    toggle_bitL(&uc, 1);
    if (uc != bit2char(0b11100101))
        SLS_ERR("failed!");

    // base conversion
    Uchar num[4], num1[4];
    num[0] = 1; num[1] = 0; num[2] = 1; num[3] = 1;
    Int n = baseN2Int(num, 4, 2);
    num1[0] = 3; num1[1] = 3; num1[2] = 3; num1[3] = 3;
    Int2baseN(num1, 4, 2, n);
    for (Long i = 0; i < 4; ++i)
        if (num[i] != num1[i])
            SLS_ERR("failed!");

    // base85 and int conversion (5 char = 4 bytes = 1 int)
    Str str1 = "1;^cB", str2 = "33333";
    Int a = b852Int(&str1[0]);
    Int2b85(&str2[0], a);
    if (str1 != str2)
        SLS_ERR("failed!");

    // base85 encoding
    // Str str85;
    // int2b85(str85, "12345");
    // cout << str85 << endl;
}
