/********************************
 * 资源来自网络，用于初始化SVGA256色
 * ******************************/

#include "main.h"
#include <dos.h>
#include <graphics.h>
#include "svgautil.h"
#include "svga256.h"

void setvgapalette256(DacPalette256 *PalBuf)
{
      struct REGPACK reg;

      reg.r_ax = 0x1012;
      reg.r_bx = 0;
      reg.r_cx = 256;
      reg.r_es = FP_SEG(PalBuf);
      reg.r_dx = FP_OFF(PalBuf);
      intr(0x10, &reg);
}