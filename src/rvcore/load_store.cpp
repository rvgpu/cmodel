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

#include "common/utils.hpp"
#include "common/debug.hpp"
#include "load_store.hpp"
#include "encoding.hpp"

load_store::load_store() {
}

writeback_t load_store::run(inst_issue inst) {
    writeback_t result = {0, 0};

    switch (inst.code) {
        case encoding::INST_LS_FSW: {
            uint64_t addr = inst.rs1 + inst.s_imm;
            RVGPU_DEBUG_PRINT("[EXEC.LS.FSW] store.i32: mem[0x%lx] = 0x%lx (%f)\n", addr, inst.frs2, utils::reg2f(inst.frs2));
            *((uint32_t *)addr) = (uint32_t)inst.frs2;
            break;
        }
        case encoding::INST_LS_FLW: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            uint32_t data = *((uint32_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.FLW] load.i32: fr[%ld] 0x%x (%f) from mem[0x%lx]\n", inst.rd, data, utils::reg2f(data), addr);
            result = writeback_t {inst.frd, data};
            break;
        }
        case encoding::INST_LS_FSD: {
            uint64_t addr = inst.rs1 + inst.s_imm;
            RVGPU_DEBUG_PRINT("[EXEC.LS.FSD] store.i64: mem[0x%lx] = 0x%lx (%f)\n", addr, inst.frs2, utils::reg2d(inst.frs2));
            *((uint64_t *)addr) = (uint64_t)inst.frs2;
            break;
        }
        case encoding::INST_LS_FLD: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            uint64_t data = *((uint64_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.FLD] load.i64: fr[%ld] 0x%lx (%f) from mem[0x%lx]\n", inst.rd, data, utils::reg2d(data), addr);
            result = writeback_t {inst.frd, data};
            break;
        }
        case encoding::INST_LS_SB: {
            uint64_t addr = inst.rs1 + inst.s_imm;
            RVGPU_DEBUG_PRINT("[EXEC.LS.SB] store.i8: mem[0x%lx] = 0x%x\n", addr, (uint32_t)inst.rs2);
            *((int8_t *)addr) = (int8_t)inst.rs2;
            break;
        }
        case encoding::INST_LS_SH: {
            uint64_t addr = inst.rs1 + inst.s_imm;
            RVGPU_DEBUG_PRINT("[EXEC.LS.SH] store.i16: mem[0x%lx] = 0x%x\n", addr, (uint32_t)inst.rs2);
            *((uint16_t *)addr) = (uint16_t)inst.rs2;
            break;
        }
        case encoding::INST_LS_SW: {
            uint64_t addr = inst.rs1 + inst.s_imm;
            RVGPU_DEBUG_PRINT("[EXEC.LS.SW] store.i32: mem[0x%lx] = 0x%x\n", addr, (uint32_t)inst.rs2);
            *((int32_t *)addr) = (int32_t)inst.rs2;
            break;
        }
        case encoding::INST_LS_SD: {
            uint64_t addr = inst.rs1 + inst.s_imm;
            RVGPU_DEBUG_PRINT("[EXEC.LS.SD] store.i64: mem[0x%lx] = 0x%lx\n", addr, inst.rs2);
            *((int64_t *)addr) = (int64_t)inst.rs2;
            break;
        }
        case encoding::INST_LS_LB: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            int8_t data = *((int8_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.LB] load.i8: r[%ld] 0x%x from mem[0x%lx]\n", inst.rd, data, addr);
            result = writeback_t {inst.rd, uint64_t(data)};
            break;
        }
        case encoding::INST_LS_LBU: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            uint8_t data = *((uint8_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.LBU] load.u8: r[%ld] 0x%x from mem[0x%lx]\n", inst.rd, data, addr);
            result = writeback_t {inst.rd, uint64_t(data)};
            break;
        }
        case encoding::INST_LS_LH: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            int16_t data = *((int16_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.LH] load.i16: r[%ld] 0x%x from mem[0x%lx]\n", inst.rd, data, addr);
            result = writeback_t {inst.rd, uint64_t(data)};
            break;
        }
        case encoding::INST_LS_LHU: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            uint16_t data = *((uint16_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.LHU] load.u16: r[%ld] 0x%x from mem[0x%lx]\n", inst.rd, data, addr);
            result = writeback_t {inst.rd, uint64_t(data)};
            break;
        }
        case encoding::INST_LS_LW: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            int32_t data = *((int32_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.LW] load.i32: r[%ld] 0x%x from mem[0x%lx]\n", inst.rd, data, addr);
            result = writeback_t {inst.rd, uint64_t(data)};
            break;
        }
        case encoding::INST_LS_LWU: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            uint32_t data = *((uint32_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.LW] load.i32: r[%ld] 0x%x from mem[0x%lx]\n", inst.rd, data, addr);
            result = writeback_t {inst.rd, uint64_t(data)};
            break;
        }
        case encoding::INST_LS_LD: {
            uint64_t addr = inst.rs1 + inst.i_imm;
            int64_t data = *((int64_t *)addr);
            RVGPU_DEBUG_PRINT("[EXEC.LS.LD] load.i64: r[%ld] 0x%lx from mem[0x%lx]\n", inst.rd, data, addr);
            result = writeback_t {inst.rd, uint64_t(data)};
            break;
        }
        default:
            RVGPU_ERROR_PRINT("error code of load store\n");
            break;
    }

    return result;
}

