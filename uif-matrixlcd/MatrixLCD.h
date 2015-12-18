/* mbed
 * Copyright (c) 2006-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __UIF_MATRIXLCD_H__
#define __UIF_MATRIXLCD_H__

#include "mbed-drivers/mbed.h"
#include "uif-matrixlcd/MatrixLCDImplementation.h"

using namespace mbed::util;

namespace uif {
    class MatrixLCD
    {
    public:
        MatrixLCD(SPI& spi, PinName cs, PinName disp, PinName extComIn)
            : lcd(spi, cs, disp, extComIn)
        {}

        // pointer to the first pixels
        uint8_t* getBuffer()
        {
            return lcd.getBuffer();
        }

        // number of bytes to add to a row to get to the next one
        uint16_t getStrideBytes() const
        {
            return lcd.getStrideBytes();
        }

        // number of bits in a row
        uint16_t getWidth() const
        {
            return lcd.getWidth();
        }

        // number of rows in the screen
        uint16_t getHeight() const
        {
            return lcd.getHeight();
        }

        // switch the front and back buffers, the back buffer is returned by -buffer,
        // the front buffer is rendered with -sendFrame;
        uint8_t* swapBuffers()
        {
            return lcd.swapBuffers();
        }

        // send the front buffer to the screen
        void sendFrame(FunctionPointer onTransferBegin, FunctionPointer onTransferDone)
        {
            lcd.sendFrame(onTransferBegin, onTransferDone);
        }

    private:
        MatrixLCDImplementation lcd;
    };
} // namespace uif

#endif // __UIF_MATRIXLCD_H__
