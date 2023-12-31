#include "ut_inst.hpp"

TEST_F(ut_inst, decode_and_execute_rv64id_fmin_d) {
    // 0x2a100053 : fmin.d f0, f0, f1
    insts.push_back(0x2a100053);

    double a = 1.1f;
    double b = 2.1f;
    SetFReg(fpreg::f0, std::bit_cast<uint64_t>(a));
    SetFReg(fpreg::f1, std::bit_cast<uint64_t>(b));

    ExecuateInst();

    uint64_t res = GetFReg(fpreg::f0);
    EXPECT_DOUBLE_EQ(std::bit_cast<double>(res), a < b ? a : b);
}