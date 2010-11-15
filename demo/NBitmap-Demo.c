/***************************************************************************

 NBitmap.mcc - New Bitmap MUI Custom Class
 Copyright (C) 2007 by NList Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 TextEditor class Support Site:  http://www.sf.net/projects/texteditor-mcc

 $Id: NBitmap-Test.c 397 2010-04-30 09:40:29Z thboeckel $

***************************************************************************/

#include <libraries/iffparse.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>
#include <proto/utility.h>
#include <clib/alib_protos.h>
#include <mui/NBitmap_mcc.h>

#if defined(__amigaos4__)
struct Library *IntuitionBase = NULL;
struct Library *UtilityBase = NULL;
struct Library *MUIMasterBase = NULL;
#else
struct IntuitionBase *IntuitionBase = NULL;
#if defined(__AROS__)
struct UtilityBase *UtilityBase = NULL;
#else
struct Library *UtilityBase = NULL;
#endif
struct Library *MUIMasterBase = NULL;
#endif

#if defined(__amigaos4__)
struct IntuitionIFace *IIntuition = NULL;
struct UtilityIFace *IUtility = NULL;
struct MUIMasterIFace *IMUIMaster = NULL;

#define GETINTERFACE(iface, base)	(iface = (APTR)GetInterface((struct Library *)(base), "main", 1L, NULL))
#define DROPINTERFACE(iface)			(DropInterface((struct Interface *)iface), iface = NULL)
#else // __amigaos4__
#define GETINTERFACE(iface, base)	TRUE
#define DROPINTERFACE(iface)
#endif // __amigaos4__

const ULONG icon32_normal[] = {
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x49da7d7f, 0xebd87e80, 0xffd5856b, 0xc5c3725d, 0x37bb5e4f, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x31e68689, 0xd0df8484, 0xffd37979, 0xffbf6566, 0xffb55a5d, 0xffb96547, 0x38b05341, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x59e0b86a, 0xbcda7b81, 0xffe48b8a, 0xffd37979, 0xffc16767, 0xffae5454, 0xffa44a4d, 0xc5994339, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x6cecdb5c, 0xffe6ce73, 0xffca786b, 0xffd07477, 0xffd27877, 0xffc26868, 0xffb05656, 0xff9b4142, 0xff984336, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x6dffff00, 0xffede049, 0xffe9d876, 0xffd2a861, 0xffb66057, 0xffbf6366, 0xffba6060, 0xffa64c4c, 0xff9b4141, 0xec923839, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x66ffff00, 0xf9ffff00, 0xfff6e829, 0xffe0c657, 0xffdbbf5a, 0xffc5904b, 0xffac5949, 0xffa3474b, 0xff9a4040, 0xd1923838, 0x49892c2e, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x57ffff00, 0xe9ffff00, 0xfffbf117, 0xfffaf127, 0xffefd627, 0xffcea545, 0xffcca03d, 0xffae6d2b, 0xff974033, 0xba903438, 0x308a2a2e, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x45ffff00, 0xdbffff00, 0xfffbf118, 0xfff9f02a, 0xfff9e51c, 0xfff4c904, 0xffd7a40d, 0xffb77c25, 0xffa76522, 0xff994d1c, 0x5b8b3619, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x33ffff04, 0xccfdf821, 0xfff9ee26, 0xfff9f029, 0xfff9e51c, 0xfff4c706, 0xffddaa00, 0xffb38200, 0xff895407, 0xfc874012, 0x6e87310f, 0x05560000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x21ffff0a, 0xbafdfa1f, 0xfff9ef29, 0xfff9ef27, 0xfff9e41b, 0xfff5c804, 0xffddaa00, 0xffb58300, 0xff7e4d00, 0xf5611c00, 0x765c0000, 0x12000000, 0x0f000000, 0x0a000000, 0x05000000, 0x01000000, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x04fff400, 0x89fdf318, 0xfff9ed27, 0xfff8ed27, 0xfff9e51c, 0xfff5c805, 0xffdfad00, 0xffb58300, 0xff7e4c00, 0xec601d00, 0x77550000, 0x23000000, 0x24000000, 0x22000000, 0x1d000000, 0x12000000, 0x06000000, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x3bffd056, 0xe8f6c940, 0xffebc243, 0xfff5d722, 0xfff7cd03, 0xffdfab00, 0xffb58300, 0xff7d4c00, 0xe25f1e00, 0x734a0000, 0x2f000000, 0x30000000, 0x2f000000, 0x2b000000, 0x24000000, 0x16000000, 0x08000000, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x06ffccb8, 0x9df9be82, 0xffe8ab76, 0xffd29658, 0xffdaa61f, 0xffd8a506, 0xffb48201, 0xff7f4f00, 0xd95b1c00, 0x6f3c0000, 0x3c000000, 0x3c000000, 0x39000000, 0x30000000, 0x24000000, 0x18000000, 0x0c000000, 0x04000000, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x3bfabb83, 0xeee9ac71, 0xffd1955a, 0xffb77b40, 0xffa96e2d, 0xffa26c13, 0xff804f02, 0xcf5d2100, 0x6b2d0000, 0x46000000, 0x42000000, 0x3b000000, 0x2f000000, 0x21000000, 0x11000000, 0x06000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x01ffffff, 0xa1f1ac66, 0xffd29558, 0xffb2763a, 0xff9d6427, 0xff90581e, 0xf285510c, 0xad562600, 0x671e0000, 0x4a000000, 0x41000000, 0x34000000, 0x26000000, 0x17000000, 0x0b000000, 0x03000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x44777372, 0xf59e7c5c, 0xffa36d36, 0xff945b1e, 0xf6865015, 0xbf6a3e0e, 0x7f3b2304, 0x55090000, 0x45000000, 0x37000000, 0x27000000, 0x18000000, 0x0b000000, 0x03000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x06000000, 0xb45f6162, 0xff4c4b49, 0xf85e4120, 0xc073420a, 0x7a3b2106, 0x53100701, 0x42000000, 0x35000000, 0x25000000, 0x17000000, 0x0a000000, 0x02000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x09000000, 0xfc494949, 0xc0242427, 0x7607060f, 0x420c0300, 0x2f000000, 0x24000000, 0x1c000000, 0x12000000, 0x06000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x06000000, 0x15000000, 0x20000000, 0x1f000000, 0x15000000, 0x0a000000, 0x02000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
};
const ULONG icon32_selected[] = {
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x0d000000, 0x7320396e, 0xec304e89, 0xff3f5d99, 0xff4664a0, 0xff3f5d99, 0xec304e89, 0x7320396e, 0x0d000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x1b000000, 0xac2b4479, 0xff43619d, 0xff5775b1, 0xff617fbb, 0xff5775b1, 0xff43619d, 0xac2b4479, 0x1b000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xcd314b80, 0xff4e6ca8, 0xff6a88c4, 0xff7d9bd7, 0xff6a88c4, 0xff4e6ca8, 0xcd314b80, 0x2a000000, 0x00ff00ff, 0x04000000, 0x64000000, 0x07000000, 0x03000000, 0x48000000, 0x03000000, 0x00ff00ff, 0x03000000, 0x4c000000, 0x03000000, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xe538558d, 0xff516fab, 0xff6f8dc9, 0xff89a7e3, 0xff6f8dc9, 0xff516fab, 0xe538558d, 0x2a000000, 0x00ff00ff, 0x0b000000, 0x84000000, 0x0e000000, 0x09000000, 0x67000000, 0x3d000000, 0x72000000, 0x4c000000, 0xa5000000, 0x5b000000, 0x03000000, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xfb3e5b98, 0xff4a68a4, 0xff6785c0, 0xff7f9ddb, 0xff6785c0, 0xff4a68a4, 0xfb3e5b98, 0x2a000000, 0x00ff00ff, 0x12000000, 0x88000000, 0x15000000, 0x0f000000, 0x80000000, 0x40000000, 0x87000000, 0x58000000, 0x87000000, 0x17000000, 0x03000000, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xff22417e, 0xff38548c, 0xff687a9e, 0xff97a9ce, 0xff687a9e, 0xff38548c, 0xff22417e, 0x2a000000, 0x00ff00ff, 0x14000000, 0x8b000000, 0x80000000, 0x6d000000, 0x86000000, 0x52000000, 0x71000000, 0x8a000000, 0x74000000, 0x6a000000, 0x08000000, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xff102f6b, 0xff23417c, 0xff334771, 0xff41506d, 0xff334771, 0xff23417c, 0xff102f6b, 0x2a000000, 0x00ff00ff, 0x0d000000, 0x13000000, 0x18000000, 0x17000000, 0x16000000, 0x1d000000, 0x22000000, 0x20000000, 0x19000000, 0x0f000000, 0x04000000, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x1b000000, 0x38000000, 0x54000000, 0x54000000, 0x54000000, 0x54000000, 0x54000000, 0x38000000, 0x1b000000, 0x00ff00ff, 0x06000000, 0x0c000000, 0x11000000, 0x11000000, 0x0d000000, 0x0e000000, 0x0d000000, 0x10000000, 0x0f000000, 0x09000000, 0x04000000, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x0d000000, 0x1b000000, 0x2a000000, 0x2a000000, 0xb9000000, 0x2a000000, 0x2a000000, 0x1b000000, 0x0d000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x0d000000, 0x7320396e, 0xec304e89, 0xff3f5d99, 0xff4664a0, 0xff3f5d99, 0xec304e89, 0x7320396e, 0x0d000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0xab000000, 0x00ff00ff, 0x00ff00ff, 0x1b000000, 0xac2b4479, 0xff43619d, 0xff5775b1, 0xff617fbb, 0xff5775b1, 0xff43619d, 0xac2b4479, 0x1b000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xcd314b80, 0xff4e6ca8, 0xff6a88c4, 0xff7d9bd7, 0xff6a88c4, 0xff4e6ca8, 0xcd314b80, 0x2a000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0xab000000, 0x00ff00ff, 0xab000000, 0x2a000000, 0xe538558d, 0xff516fab, 0xff6f8dc9, 0xff89a7e3, 0xff6f8dc9, 0xff516fab, 0xe538558d, 0x2a000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xfb3e5b98, 0xff4a68a4, 0xff6785c0, 0xff7f9ddb, 0xff6785c0, 0xff4a68a4, 0xfb3e5b98, 0x2a000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xff22417e, 0xff38548c, 0xff687a9e, 0xff97a9ce, 0xff687a9e, 0xff38548c, 0xff22417e, 0x2a000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x2a000000, 0xff102f6b, 0xff23417c, 0xff334771, 0xff41506d, 0xff334771, 0xff23417c, 0xff102f6b, 0x2a000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x1b000000, 0x38000000, 0x54000000, 0x54000000, 0x54000000, 0x54000000, 0x54000000, 0x38000000, 0x1b000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
	0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x0d000000, 0x1b000000, 0x2a000000, 0x2a000000, 0x2a000000, 0x2a000000, 0x2a000000, 0x1b000000, 0x0d000000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
};

#define ICON32_WIDTH 24
#define ICON32_HEIGHT 20
#define ICON32_DEPTH 32

int main(void)
{
  if((IntuitionBase = (APTR)OpenLibrary("intuition.library", 36)) &&
    GETINTERFACE(IIntuition, IntuitionBase))
  {
    if((UtilityBase = (APTR)OpenLibrary("utility.library", 36)) &&
      GETINTERFACE(IUtility, UtilityBase))
    {
      if((MUIMasterBase = OpenLibrary("muimaster.library", 19)) &&
        GETINTERFACE(IMUIMaster, MUIMasterBase))
      {
        Object *app, *window;
        const char * const classes[] = { "NBitmap.mcc", NULL };

        app = MUI_NewObject("Application.mui",
              MUIA_Application_Author,      "NBitmap.mcc Open Source Team",
              MUIA_Application_Base,        "NBitmap-Test",
              MUIA_Application_Copyright,   "(c) 2007 NBitmap.mcc Open Source Team",
              MUIA_Application_Description, "NBitmap.mcc demo program",
              MUIA_Application_Title,       "NBitmap-Demo",
              MUIA_Application_Version,     "$VER: NBitmap-Demo (" __DATE__ ")",
              MUIA_Application_UsedClasses, classes,

              MUIA_Application_Window,
                window = WindowObject,
                MUIA_Window_Title,    "NBitmap-Test",
                MUIA_Window_ID,       MAKE_ID('M','A','I','N'),
                MUIA_Window_RootObject, VGroup,
                  Child, HGroup,
                    Child, NBitmapObject,
                      MUIA_NBitmap_Type,   MUIV_NBitmap_Type_File,
                      MUIA_NBitmap_Normal, "PROGDIR:icon.png",
                      MUIA_NBitmap_Label,  "Music",
                      MUIA_NBitmap_Button, TRUE,
                    End,
                    Child, NBitmapObject,
                      MUIA_NBitmap_Width,  ICON32_WIDTH,
                      MUIA_NBitmap_Height, ICON32_HEIGHT,
                      MUIA_NBitmap_Type,   MUIV_NBitmap_Type_ARGB32,
                      MUIA_NBitmap_Normal, icon32_normal,
                      MUIA_NBitmap_Selected, icon32_selected,
                      MUIA_NBitmap_Label,  "raw icon",
                      MUIA_NBitmap_Button, TRUE,
                    End,
                    Child, RectangleObject, End,
                  End,
                  Child, RectangleObject, End,
                End,
              End,
            End;

        if(app != NULL)
        {
          ULONG sigs = 0;

          DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

          set(window, MUIA_Window_Open, TRUE);

          while((LONG)DoMethod(app, MUIM_Application_NewInput, &sigs) != (LONG)MUIV_Application_ReturnID_Quit)
          {
            if(sigs)
            {
              sigs = Wait(sigs | SIGBREAKF_CTRL_C);

              if(sigs & SIGBREAKF_CTRL_C)
                break;
            }
          }

          MUI_DisposeObject(app);
        }
        else
          PutStr("Failed to create application\n");

        DROPINTERFACE(IMUIMaster);
        CloseLibrary(MUIMasterBase);
        MUIMasterBase = NULL;
      }
      else
        PutStr("Failed to open muimaster.library V19\n");

      DROPINTERFACE(IUtility);
      CloseLibrary((struct Library *)UtilityBase);
      UtilityBase = NULL;
    }
    else
      PutStr("Failed to open utility.library V36\n");

    DROPINTERFACE(IIntuition);
    CloseLibrary((struct Library *)IntuitionBase);
    IntuitionBase = NULL;
  }
  else
    PutStr("Failed to open intuition.library V36\n");

  return 0;
}
