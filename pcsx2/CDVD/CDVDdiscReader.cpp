
/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2010  PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */


/*
 *  Original code from libcdvd by Hiryu & Sjeep (C) 2002
 *  Modified by Florin for PCSX2 emu
 *  Fixed CdRead by linuzappz
 */

// Note: Presumably I'm going to be pulling from the same files, so the same credits. 
// I'll update if they turn out to be different. I'm initially setting this up as a
// second null reader.

////////////////////////////////////////////////////////
//
// CDVD disc interface

#include "PrecompiledHeader.h"
#include "IopCommon.h"

//#define ENABLE_TIMESTAMPS

//#ifdef _WIN32
//#	include <wx/msw/wrapwin.h>
//#endif

//#include <ctype.h>
//#include <time.h>
//#include <wx/datetime.h>
//#include <exception>
//#include <memory>

//#include "IsoFS/IsoFS.h"
//#include "IsoFS/IsoFSCDVD.h"
#include "CDVDdiscReader.h"

//#include "DebugTools/SymbolMap.h"
#include "AppConfig.h"

s32 CALLBACK DISCopen(const char* pTitle)
{
	return 0;
}

void CALLBACK DISCclose()
{
}

s32 CALLBACK DISCreadTrack(u32 lsn, int mode)
{
	return -1;
}

// return can be NULL (for async modes)
u8* CALLBACK DISCgetBuffer()
{
	return NULL;
}

s32 CALLBACK DISCreadSubQ(u32 lsn, cdvdSubQ* subq)
{
	return -1;
}

s32 CALLBACK DISCgetTN(cdvdTN *Buffer)
{
	return -1;
}

s32 CALLBACK DISCgetTD(u8 Track, cdvdTD *Buffer)
{
	return -1;
}

s32 CALLBACK DISCgetTOC(void* toc)
{
	return -1;
}

s32 CALLBACK DISCgetDiskType()
{
	return CDVD_TYPE_NODISC;
}

s32 CALLBACK DISCgetTrayStatus()
{
	return CDVD_TRAY_CLOSE;
}

s32 CALLBACK DISCdummyS32()
{
	return 0;
}

void CALLBACK DISCnewDiskCB(void (* /* callback */)())
{
}

s32 CALLBACK DISCreadSector(u8* tempbuffer, u32 lsn, int mode)
{
	return -1;
}

s32 CALLBACK DISCgetBuffer2(u8* buffer)
{
	return -1;
}

s32 CALLBACK DISCgetDualInfo(s32* dualType, u32* _layer1start)
{
	return -1;
}

CDVD_API CDVDapi_Disc =
{
	DISCclose,
	DISCopen,
	DISCreadTrack,
	DISCgetBuffer,
	DISCreadSubQ,
	DISCgetTN,
	DISCgetTD,
	DISCgetTOC,
	DISCgetDiskType,
	DISCgetTrayStatus,
	DISCdummyS32,
	DISCdummyS32,

	DISCnewDiskCB,

	DISCreadSector,
	DISCgetBuffer2,
	DISCgetDualInfo,
};