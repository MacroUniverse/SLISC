#include "../SLISC/Bit.h"
#include "../SLISC/file.h"

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

     if (bit2str(bit2char(128)) != "10000000")
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
     if (bit2str(ui) != "11111111")
          SLS_ERR("failed!");
     if (bit2str(ui+1) != "10000000")
          SLS_ERR("failed!");
     if (bit2str(ui+2) != "01010101")
          SLS_ERR("failed!");
     if (str2bit("10100101") != bit2char(0b10100101))
          SLS_ERR("failed!");
     
     Char uc = 0b10100101;
     toggle_bitL(&uc, 1);
     if (uc != bit2char(0b11100101))
          SLS_ERR("failed!");
}
