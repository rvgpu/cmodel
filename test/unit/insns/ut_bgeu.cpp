#include <gtest/gtest.h>
#include "sm/compute_unit.h"
#include "ut_insns.hpp"

#define CHECK_BRANCH(a, b) do { \
        WRITE_REG(fetch.insn.rs1(), a); \
        WRITE_REG(fetch.insn.rs2(), b); \
        ExecuateInst();           \
        auto pc = Getpc();        \
        auto next_pc = GetNextpc(); \
        if (a >= b) { \
            EXPECT_EQ(next_pc, pc + 76); \
        } else { \
            EXPECT_EQ(next_pc, pc + 4); \
        } \
    } while(0)


TEST_F(ut_rv64_insns, decode_and_execute_rv64i_bgeu) {
    // 0x0496f663 : bgeu a3, s1, 76
    insts.push_back(0x0496f663);
    LoadInst();

    CHECK_BRANCH(1, 2);
    CHECK_BRANCH(2, 2);
    CHECK_BRANCH(3, 2);
    CHECK_BRANCH(2, 0);
    CHECK_BRANCH(0, 2);
    CHECK_BRANCH(0, 0);
}