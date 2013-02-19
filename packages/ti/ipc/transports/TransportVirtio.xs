/*
 * Copyright (c) 2012-2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== TransportVirtio.xs ================
 */

/*
 *  ======== module$use ========
 */
function module$use()
{
    var TransportVirtio = this;
    xdc.useModule("ti.sdo.utils.MultiProc");
    xdc.useModule("ti.sdo.ipc.MessageQ");
    xdc.useModule("ti.sysbios.knl.Swi");
    xdc.useModule("ti.ipc.transports.TransportVirtioSetup");
    xdc.loadPackage("ti.ipc.namesrv");

    if (Program.cpu.deviceName == "OMAPL138") {
        xdc.useModule("ti.ipc.family.omapl138.VirtQueue");
    }
    else if (Program.platformName.match(/6614/)) {
        xdc.useModule("ti.ipc.family.tci6614.VirtQueue");
    }
    else if (Program.platformName.match(/Kepler/)) {
        xdc.useModule("ti.ipc.family.tci6638.VirtQueue");
    }
    else
    {
        print("TransportVirtio.xs: Did not match any platform!");
    }
}
/*
 *  ======== module$static$init ========
 */
function module$static$init(mod, params)
{
  /* Init Virtio Transport params */
  mod.gateSwiHandle = null;
}
