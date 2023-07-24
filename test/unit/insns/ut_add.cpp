#include <gtest/gtest.h>
#include "sm/compute_unit.h"
#include "ut_insns.hpp"

#define CHECK_ADD(a, b) do { \
        WRITE_REG(fetch.insn.rs1(), a); \
        WRITE_REG(fetch.insn.rs2(), b); \
        ExecuateInst();           \
        result = READ_REG(fetch.insn.rd()); \
        EXPECT_EQ(result, (a + b)); \
    } while(0)

TEST_F(ut_rv32_insns, decode_and_execute_rv32i_add) {
    // 0x00b785b3 # add a1, a5, a1
    insts.push_back(0x00b785b3);
    uint32_t result;
    LoadInst();
    CheckDecoderRegister(11, 15, 11);

    CHECK_ADD(1, 2);
    CHECK_ADD(-1, 2);
    CHECK_ADD(1, -2);
    CHECK_ADD(1, -1);
}

TEST_F(ut_rv64_insns, decode_and_execute_rv64i_add) {
    //0x00d786b3 : add a3, a5, a3
    insts.push_back(0x00d786b3);
    uint32_t result;
    LoadInst();
    CheckDecoderRegister(13, 15, 13);

    CHECK_ADD(1, 2);
}