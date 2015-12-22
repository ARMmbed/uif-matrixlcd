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

#ifndef __UIF_MATRIXLCD_BASE_H__
#define __UIF_MATRIXLCD_BASE_H__

#include "mbed-drivers/mbed.h"

#include "uif-framebuffer/FrameBuffer.h"

using namespace mbed::util;
using namespace uif;

namespace uif {
    class MatrixLCDBase
    {
    public:
        // pointer to the first pixels
        virtual SharedPointer<FrameBuffer> getFrameBuffer() = 0;

        // send the front buffer to the screen
        virtual void sendFrameBuffer(SharedPointer<FrameBuffer>& buffer, FunctionPointer onTransferBegin, FunctionPointer onTransferDone) = 0;

    protected:
        MatrixLCDBase() { }
    };
} // namespace uif

#endif // __UIF_MATRIXLCD_H__
