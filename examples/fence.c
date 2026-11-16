#include "tkga_packet.h"

#include <stdio.h>

int main(void)
{
    const uint8_t fence_opcode = 0x03;
    const uint16_t fence_id = 0x1234;
    const uint8_t payload[] = {(uint8_t)fence_id, (uint8_t)(fence_id >> 8)};
    uint8_t packet[6];
    size_t size = tkga_encode_command(fence_opcode, payload, sizeof payload,
                                      packet, sizeof packet);

    if (size != sizeof packet) {
        return 1;
    }
    for (size_t i = 0; i < size; ++i) {
        printf("%02X%c", (unsigned)packet[i], i + 1 == size ? '\n' : ' ');
    }
    return 0;
}
