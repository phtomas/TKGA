#include "tkga_packet.h"

#include <stdio.h>
#include <string.h>

int main(void)
{
    static const uint8_t fence[] = {0x03, 0, 2, 0, 0x34, 0x12};
    uint8_t overlap[] = {0x34, 0x12, 0, 0, 0, 0};
    uint8_t short_buffer[] = {0xAA, 0xAA, 0xAA};
    const uint8_t expected_short[] = {0xAA, 0xAA, 0xAA};
    static uint8_t large[260];
    memset(large, 0x5A, 256);

    if (tkga_encode_command(3, overlap, 2, overlap, sizeof overlap) != sizeof fence ||
        memcmp(overlap, fence, sizeof fence) != 0) {
        fputs("FENCE bytes or overlapping buffers are incorrect\n", stderr);
        return 1;
    }
    if (tkga_encode_command(3, NULL, 0, short_buffer, sizeof short_buffer) != 0 ||
        memcmp(short_buffer, expected_short, sizeof short_buffer) != 0) {
        fputs("A short buffer must remain unchanged\n", stderr);
        return 1;
    }
    if (tkga_encode_command(3, large, 0x100, large, sizeof large) != sizeof large ||
        large[2] != 0 || large[3] != 1 ||
        large[4] != 0x5A || large[259] != 0x5A) {
        return 1;
    }
    return 0;
}
