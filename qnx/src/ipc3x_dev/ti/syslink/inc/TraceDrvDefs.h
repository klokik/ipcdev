/**
 *  @file   TraceDrvDefs.h
 *
 *  @brief      Definitions of TraceDrv types and structures.
 *
 *
 *  @ver        02.00.00.46_alpha1
 *
 *  ============================================================================
 *
 *  Copyright (c) 2008-2009, Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  Contact information for paper mail:
 *  Texas Instruments
 *  Post Office Box 655303
 *  Dallas, Texas 75265
 *  Contact information:
 *  http://www-k.ext.ti.com/sc/technical-support/product-information-centers.htm?
 *  DCMP=TIHomeTracking&HQS=Other+OT+home_d_contact
 *  ============================================================================
 *
 */


#ifndef TRACEDRVDEFS_H_0xDA50
#define TRACEDRVDEFS_H_0xDA50


/* Utilities headers */
#include <IpcCmdBase.h>

/*Linux specific headers*/
#ifdef SYSLINK_BUILDOS_LINUX
#include <linux/ioctl.h>
#elif SYSLINK_BUILDOS_QNX
#include <sys/ioctl.h>
#endif


#if defined (__cplusplus)
extern "C" {
#endif


/* =============================================================================
 *  Macros and types
 * =============================================================================
 */
/*  ----------------------------------------------------------------------------
 *  IOCTL command IDs for TraceDrv
 *  ----------------------------------------------------------------------------
 */
/*!
 *  @brief  Command for GT_setTrace
 */
#define CMD_TRACEDRV_SETTRACE              _IOWR(TRACEDRV_BASE_CMD,\
                                        1u,\
                                        TraceDrv_CmdArgs)

/*  ----------------------------------------------------------------------------
 *  Command arguments for TraceDrv
 *  ----------------------------------------------------------------------------
 */
/*!
 *  @brief  Command arguments for TraceDrv
 */
typedef struct TraceDrv_CmdArgs_tag {
    union {
        struct {
            UInt32                mask;
            UInt32                oldMask;
            GT_TraceType          type;
        } setTrace;
    } args;

    Int32 apiStatus;
    UInt32 pid;
} TraceDrv_CmdArgs;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* TRACEDRVDEFS_H_0xDA50 */
