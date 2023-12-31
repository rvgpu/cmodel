#include "ut_inst.hpp"

TEST_F(ut_inst, decode_and_execute_rv64i_pseudo_j) {
    // 0x0380006f : j 56 (jal x0, 56)
    insts.push_back(0x0380006f);

    ExecuateInst();

    auto pc = (uint64_t)insts.data();
    auto next_pc = GetPC();

    EXPECT_EQ(next_pc, pc + 56);
}