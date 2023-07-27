#include <gtest/gtest.h>
#include "sm/compute_unit.h"

#include "ut_insns.hpp"

TEST_F(ut_rv32_insns, decode_and_execute_rv32i_auipc) {
    //auipc bits: 0x1297
    insts.push_back(0x1297);
    LoadInst();

    ExecuateInst();

    //next_pc = pc + 4;
    //x[rd] = pc + signe_external(bitsp[31:12] << 12)
    auto rd_data = READ_REG(fetch.insn.rd());
    auto pc_constsnt_offset = (uint32_t)rd_data - (uint32_t)pc;

    EXPECT_EQ(fetch.insn.bits(), 0x1297);
    EXPECT_EQ(pc_constsnt_offset, 0x1000);
}

TEST_F(ut_rv64_insns, decode_and_execute_rv64i_auipc) {
    //auipc bits: 0x97; auipc  ra, 0
    insts.push_back(0x97);
    LoadInst();
    ExecuateInst();
    auto rd_data = READ_REG(fetch.insn.rd());
    EXPECT_EQ(rd_data, pc);
}