#include "tkga_packet.h"

#include <string.h>

size_t tkga_encode_command(uint8_t opcode, const uint8_t *payload,
                           size_t payload_size, uint8_t *output,
                           size_t output_size)
{
    enum { header_size = 4 };

    if (output == NULL || output_size < header_size ||
        payload_size > UINT16_MAX || payload_size > output_size - header_size ||
        (payload_size != 0 && payload == NULL)) {
        return 0;
    }

    if (payload_size != 0) {
        memmove(output + header_size, payload, payload_size);
    }
    output[0] = opcode;
    output[1] = 0;
    output[2] = (uint8_t)payload_size;
    output[3] = (uint8_t)(payload_size >> 8);
    return header_size + payload_size;
}
