/*******************************************************************************
Copyright (C) Marvell International Ltd. and its affiliates

This software file (the "File") is owned and distributed by Marvell 
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the two
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.

********************************************************************************
Marvell Commercial License Option

If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.

********************************************************************************
Marvell GPL License Option

If you received this File from Marvell, you may opt to use, redistribute and/or 
modify this File in accordance with the terms and conditions of the General 
Public License Version 2, June 1991 (the "GPL License"), a copy of which is 
available along with the File in the license.txt file or by writing to the Free 
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or 
on the worldwide web at http://www.gnu.org/licenses/gpl.txt. 

THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED 
WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY 
DISCLAIMED.  The GPL License provides additional details about this warranty 
disclaimer.
********************************************************************************
Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or 
modify this File under the following licensing terms. 
Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    *   Redistributions of source code must retain the above copyright notice,
	    this list of conditions and the following disclaimer. 

    *   Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution. 

    *   Neither the name of Marvell nor the names of its contributors may be 
        used to endorse or promote products derived from this software without 
        specific prior written permission. 
    
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/


#ifndef __INCmvDramIfh
#define __INCmvDramIfh

#include "ctrlEnv/mvCtrlEnvSpec.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* includes */
#include "ctrlEnv/mvCtrlEnvSpec.h"
#include "mvSysDdrConfig.h"

/* defines  */
/* DRAM Timing parameters */
#define SDRAM_TWR                    15  /* ns tWr */
#define SDRAM_TRFC_64_512M_AT_200MHZ 70  /* ns tRfc for dens 64-512 @ 200MHz */
#define SDRAM_TRFC_64_512M           75  /* ns tRfc for dens 64-512          */
#define SDRAM_TRFC_1G                120 /* ns tRfc for dens 1GB             */
#define SDRAM_TR2R_CYC               1   /* cycle for tR2r                   */
#define SDRAM_TR2WW2R_CYC            1   /* cycle for tR2wW2r                */


#define CAL_AUTO_DETECT     0   /* Do not force CAS latancy (mvDramIfDetect) */
#define ECC_DISABLE         1   /* Force ECC to Disable                      */
#define ECC_ENABLE          0   /* Force ECC to ENABLE                       */


/* typedefs */


/* enumeration for DDR1 supported CAS Latencies */
typedef enum _mvDimmDdr1Cas
{
    DDR1_CL_1_5  = 0x02, 
    DDR1_CL_2    = 0x04, 
    DDR1_CL_2_5  = 0x08, 
    DDR1_CL_3    = 0x10, 
    DDR1_CL_4    = 0x40, 
    DDR1_CL_FAULT
} MV_DIMM_DDR1_CAS;

/* enumeration for DDR2 supported CAS Latencies */
typedef enum _mvDimmDdr2Cas
{
    DDR2_CL_3    = 0x08, 
    DDR2_CL_4    = 0x10, 
    DDR2_CL_5    = 0x20, 
    DDR2_CL_6    = 0x40, 
    DDR2_CL_FAULT
} MV_DIMM_DDR2_CAS;

/* enumeration for DDR3 supported CAS Latencies */
typedef enum _mvDimmDdr3Cas
{
    DDR3_CL_5    = 0x2, 
    DDR3_CL_6    = 0x4, 
    DDR3_CL_7    = 0x8, 
    DDR3_CL_8    = 0x10, 
    DDR3_CL_9    = 0x20, 
    DDR3_CL_10    = 0x40, 
    DDR3_CL_FAULT
} MV_DIMM_DDR3_CAS;

/* This structure describes CPU interface address decode window               */
typedef struct _mvDramIfDecWin 
{
	MV_ADDR_WIN   addrWin;    /* An address window*/
	MV_BOOL       enable;     /* Address decode window is enabled/disabled    */
}MV_DRAM_DEC_WIN;

/* DDR parameters structure */
typedef struct 
{
	MV_U32      	addr;
	MV_U32		val;
} MV_DDR_MC_PARAMS;

typedef struct
{
	MV_U32 	addr;
	MV_U32	mask;
	MV_U32	val;
} MV_DDR_INIT_POLL_AMV;	/* address/mask/value */


/* mvDramIf.h API list */
MV_VOID   mvDramIfBasicAsmInit(MV_VOID);
#if defined(MV_DDR_INCLUDE_DDRMC)

MV_STATUS mvDramIfDetect(MV_U32 forcedCl);
MV_VOID   _mvDramIfConfig(MV_VOID);

MV_STATUS mvDramIfWinSet(MV_TARGET target, MV_DRAM_DEC_WIN *pAddrDecWin);
MV_STATUS mvDramIfWinGet(MV_TARGET target, MV_DRAM_DEC_WIN *pAddrDecWin);
MV_STATUS mvDramIfWinEnable(MV_TARGET target,MV_BOOL enable);

MV_32 mvDramIfBankSizeGet(MV_U32 bankNum);
MV_32 mvDramIfBankBaseGet(MV_U32 bankNum);
MV_32 mvDramIfSizeGet(MV_VOID);

MV_U32 mvDramIfParamCountGet(MV_VOID);
MV_STATUS mvDramIfParamFill(MV_U32 ddrFreq, MV_DDR_MC_PARAMS * params, MV_U32 * paramcnt);
MV_STATUS mvDramReconfigParamFill(MV_U32 ddrFreq, MV_U32 cpuFreq, MV_DDR_MC_PARAMS * params, MV_U32 * cnt);
MV_STATUS mvDramInitPollAmvFill(MV_DDR_INIT_POLL_AMV * amv);

MV_VOID mvIntrfaceParamPrint(MV_VOID);
MV_VOID mvIntrfaceWidthPrint(MV_VOID);


#elif defined(MV_DDR_INCLUDE_DDR2)

MV_STATUS mvDramIfDetect(MV_U32 forcedCl, MV_BOOL eccDisable);
MV_VOID   _mvDramIfConfig(int entryNum);

MV_U32 mvDramIfBankSizeGet(MV_U32 bankNum);
MV_U32 mvDramIfBankBaseGet(MV_U32 bankNum);
MV_U32 mvDramIfSizeGet(MV_VOID);

MV_U32 mvDramIfCalGet(void);
MV_STATUS mvDramIfSingleBitErrThresholdSet(MV_U32 threshold);
MV_VOID mvDramIfSelfRefreshSet(void);
void mvDramIfShow(void);
MV_U32 mvDramIfGetFirstCS(void);


#elif defined(MV_DDR_INCLUDE_DDR1_2)

MV_STATUS mvDramIfDetect(MV_U32 forcedCl);
MV_VOID   _mvDramIfConfig(MV_VOID);

MV_STATUS mvDramIfWinSet(MV_TARGET target, MV_DRAM_DEC_WIN *pAddrDecWin);
MV_STATUS mvDramIfWinGet(MV_TARGET target, MV_DRAM_DEC_WIN *pAddrDecWin);
MV_STATUS mvDramIfWinEnable(MV_TARGET target,MV_BOOL enable);
MV_32 mvDramIfBankSizeGet(MV_U32 bankNum);
MV_32 mvDramIfBankBaseGet(MV_U32 bankNum);
MV_32 mvDramIfSizeGet(MV_VOID);


#endif




#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCmvDramIfh */
