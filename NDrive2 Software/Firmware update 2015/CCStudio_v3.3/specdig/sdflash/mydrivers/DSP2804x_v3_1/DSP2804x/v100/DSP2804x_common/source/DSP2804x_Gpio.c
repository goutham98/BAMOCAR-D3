// TI File $Revision: /main/2 $
// Checkin $Date: July 17, 2006   16:20:08 $
//###########################################################################
//
// FILE:	DSP2804x_Gpio.c
//
// TITLE:	DSP2804x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2804x Header Files V1.00 $
// $Release Date: August 15, 2006 $
//###########################################################################

#include "DSP2804x_Device.h"     // DSP2804x Headerfile Include File
#include "DSP2804x_Examples.h"   // DSP2804x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
   EALLOW;
   
   // Each GPIO pin can be: 
   // a) a GPIO input/output
   // b) peripheral function 1
   // c) peripheral function 2
   // d) peripheral function 3
   // By default, all are GPIO Inputs 
   GpioCtrlRegs.GPAMUX1.all = 0x0000;     // GPIO functionality GPIO0-GPIO15
   GpioCtrlRegs.GPAMUX2.all = 0x0000;     // GPIO functionality GPIO16-GPIO31
   GpioCtrlRegs.GPBMUX1.all = 0x0000;     // GPIO functionality GPIO32-GPIO34

   GpioCtrlRegs.GPADIR.all = 0x0000;      // GPIO0-GPIO31 are GP inputs
   GpioCtrlRegs.GPBDIR.all = 0x0000;      // GPIO32-GPIO34 are inputs   
   
   // Each input can have different qualification
   // a) input synchronized to SYSCLKOUT
   // b) input qualified by a sampling window
   // c) input sent asynchronously (valid for peripheral inputs only)
   GpioCtrlRegs.GPAQSEL1.all = 0x0000;    // GPIO0-GPIO15 Synch to SYSCLKOUT 
   GpioCtrlRegs.GPAQSEL2.all = 0x0000;    // GPIO16-GPIO31 Synch to SYSCLKOUT
   GpioCtrlRegs.GPBQSEL1.all = 0x0000;    // GPIO32-GPIO34 Synch to SYSCLKOUT 

   // Pull-ups can be enabled or disabled. 
   GpioCtrlRegs.GPAPUD.all = 0x0000;      // Pullup's enabled GPIO0-GPIO31
   GpioCtrlRegs.GPBPUD.all = 0x0000;      // Pullup's enabled GPIO32-GPIO34
   //GpioCtrlRegs.GPAPUD.all = 0xFFFF;    // Pullup's disabled GPIO0-GPIO31
   //GpioCtrlRegs.GPBPUD.all = 0xFFFF;    // Pullup's disabled GPIO32-GPIO34
   EDIS;

}	
	
//===========================================================================
// End of file.
//===========================================================================