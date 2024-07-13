#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

namespace Company {
    class SerialInterface {
    public:
        virtual int read() = 0;
        virtual int write(int data) = 0;
    };
}

#endif // SERIAL_INTERFACE_H