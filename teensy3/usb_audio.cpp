/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2016 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "usb_dev.h"
#include "HardwareSerial.h"
#include <string.h> // for memcpy()

#ifdef AUDIO_INTERFACE // defined by usb_dev.h -> usb_desc.h
#if F_CPU >= 20000000

uint16_t usb_audio_receive_buffer[AUDIO_RX_SIZE/2] __attribute__ ((section(".dmabuffers"), aligned (4)));
uint16_t usb_audio_transmit_buffer[AUDIO_TX_SIZE/2] __attribute__ ((section(".dmabuffers"), aligned (4)));

// Called from the USB interrupt when an isochronous packet arrives
// we must completely remove it from the receive buffer before returning
//
void usb_audio_receive_callback(unsigned int len)
{
	//serial_print(".");
}

// Called from the USB interrupt when ready to transmit another
// isochronous packet.  If we place data into the transmit buffer,
// the return is the number of bytes.  Otherwise, return 0 means
// no data to transmit
unsigned int usb_audio_transmit_callback(void)
{
	return 0;
}


#endif // F_CPU
#endif // AUDIO_INTERFACE
