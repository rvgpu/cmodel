#include "ut_inst.hpp"

TEST_F(ut_inst, decode_and_execute_rv64id_fcvt_w_d) {
    // 0xc2001553       fcvt.w.d   a0, ft0, rtz
    insts.push_back(0xc2001553);
    SetFReg(fpreg::ft0, std::bit_cast<uint64_t>(1.1));
    ExecuateInst();
    EXPECT_EQ(GetIReg(reg::a0), 1);
}
