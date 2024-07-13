#include <gtest/gtest.h>

#include "ModbusRTU.h"

using namespace Company;

TEST(ModbusRTUTests, WriteOperation) {
    ModbusRTU dev;
    auto result = dev.write((int)'a');
    ASSERT_EQ(1, result);
}