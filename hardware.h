/* This is a MINIMAL CP/M emulator. That is, it emulates a Z80 (though 8080 would be
   enough for most CP/M software), the BDOS and the CBIOS as well, and just expects
   a CP/M program to load and run. It was written *ONLY FOR* running some ancient
   tools, namely M80 assembler and L80 linker (they don't seem to have modern versions
   for non-CP/M OSes). The emulator has BDOS/CBIOS functions implemented and in a way
   that is enough for these tools! Maybe this can change in the future, but this is the
   current situation! Stderr should be redirected, as those are DEBUG messages.

   Copyright (C)2016 LGB (Gábor Lénárt) <lgblgblgb@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifndef __XCPM_HARDWARE_H_INCLUDED
#define __XCPM_HARDWARE_H_INCLUDED

#include <stdint.h>

typedef uint8_t         Uint8;
typedef int8_t          Sint8;
typedef uint16_t        Uint16;
typedef int16_t         Sint16;
typedef uint32_t        Uint32;
typedef int32_t         Sint32;

#define Z80EX_OPSTEP_FAST_AND_ROUGH
#define Z80EX_ED_TRAPPING_SUPPORT
//#define Z80EX_CALLBACK_PROTOTYPE

#define Z80EX_TYPES_DEFINED
#define Z80EX_BYTE              Uint8
#define Z80EX_SIGNED_BYTE       Sint8
#define Z80EX_WORD              Uint16
#define Z80EX_DWORD             Uint32

#include "z80ex/z80ex.h"

extern Z80EX_CONTEXT z80ex;
extern Uint8 memory[0x10000];

extern int z80ex_ed_cb(Z80EX_BYTE opcode);

#endif
