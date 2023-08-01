/*
 * Copyright © 2023 Sietium Semiconductor.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <cstdio>
#include "common/command_stream.h"
#include "stream_multiprocessor.h"

sm::sm() {
    auto isa_parser = new isa_parser_t("RV64IMAFD");
    m_sp = new stream_processor();
    p = new compute_unit(isa_parser);
    sp = (uint32_t*) malloc(5000 * sizeof (uint32_t));
    sp = sp + 2000;
}

void sm::run_vs(message msg) {
    printf("[SM] receive message VS: %d %d\n", msg.start, msg.count);

    m_sp->setup(msg);
    m_sp->run();
}

void sm::run(message msg) {
    switch(msg.msg) {
        case CMD_MESSAGE_START_CU_VS:
            run_vs(msg);
            break;
        default:
            break;
    }
}
