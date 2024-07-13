#ifndef MODBUS_RTU_H
#define MODBUS_RTU_H

#include "SerialInterface.h"

namespace Company {
    class ModbusRTU : public SerialInterface {
    public:
        int read();
        int write(int data);
    };
}

#endif // MODBUS_RTU_H