#ifndef TKGA_PACKET_H
#define TKGA_PACKET_H

#include <stddef.h>
#include <stdint.h>

/*
 * Serialize the four-byte command header followed by its payload.
 * Return zero and leave output untouched on invalid arguments or short capacity.
 * A null payload is allowed when payload_size is zero. Buffers may overlap.
 * Command semantics and transport credit belong to the caller and receiver.
 */
size_t tkga_encode_command(uint8_t opcode, const uint8_t *payload,
                           size_t payload_size, uint8_t *output,
                           size_t output_size);

#endif
