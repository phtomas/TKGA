# Registros lógicos da ABI

Use os seletores com REG_SELECT8. As larguras abaixo são em bytes. Registros de captura dinâmica são atualizados pelo seletor STATUS.

| Seletor | Identificador | Bytes | Acesso | Coerência |
|---|---|---:|---|---|
| 0x00 | ID_SIGNATURE | 4 | R | Constante do perfil |
| 0x01 | IF_VERSION | 2 | R | Constante do perfil |
| 0x02 | CMDSET_VERSION | 2 | R | Constante do perfil |
| 0x03 | CAPS_FEATURES | 2 | R | Constante do perfil |
| 0x04 | CAPS_FORMATS | 1 | R | Constante do perfil |
| 0x05 | CAPS_MAX_HANDLES | 2 | R | Constante do perfil |
| 0x06 | CAPS_MAX_RESOURCE_BYTES | 4 | R | Constante do perfil |
| 0x07 | CMD_CAPACITY | 2 | R | Constante do perfil |
| 0x08 | DATA_CAPACITY | 2 | R | Constante do perfil |
| 0x09 | MAX_CMD_PAYLOAD | 2 | R | Constante do perfil |
| 0x0A | CAPS_MAX_WIDTH | 2 | R | Constante do perfil |
| 0x0B | CAPS_MAX_HEIGHT | 2 | R | Constante do perfil |
| 0x0C | CAPS_MAX_SPRITES | 2 | R | Constante do perfil |
| 0x0D | CAPS_SPRITES_PER_LINE | 2 | R | Constante do perfil |
| 0x0E | CAPS_MAX_LAYERS | 1 | R | Constante do perfil |
| 0x0F | CAPS_PALETTE_BANKS | 2 | R | Constante do perfil |
| 0x10 | CAPS_PALETTE_ENTRIES | 2 | R | Constante do perfil |
| 0x11 | CAPS_DESCRIPTOR_VERSION | 1 | R | Constante do perfil |
| 0x12 | CAPS_DESCRIPTOR_SIZE | 1 | R | Constante do perfil |
| 0x13 | CAPS_TARGET_MASK | 1 | R | Constante do perfil |
| 0x14 | CAPS_TILE_GEOMETRIES | 1 | R | Constante do perfil |
| 0x15 | CAPS_MAP_MAX_WIDTH | 2 | R | Constante do perfil |
| 0x16 | CAPS_MAP_MAX_HEIGHT | 2 | R | Constante do perfil |
| 0x17 | CAPS_MAX_SPRITE_WIDTH | 2 | R | Constante do perfil |
| 0x18 | CAPS_MAX_SPRITE_HEIGHT | 2 | R | Constante do perfil |
| 0x19 | CAPS_PRESENT | 1 | R | Constante do perfil |
| 0x40 | STATUS | 2 | R | Captura dinâmica |
| 0x41 | CMD_FREE | 2 | R | Captura dinâmica |
| 0x42 | DATA_FREE | 2 | R | Captura dinâmica |
| 0x43 | LAST_ERROR_CODE | 1 | R | Captura dinâmica |
| 0x44 | ERROR_CLASSES | 2 | R | Captura dinâmica |
| 0x45 | COMPLETED_FENCE | 2 | R | Captura dinâmica |
| 0x46 | LAST_PRESENTED | 2 | R | Captura dinâmica |
| 0x47 | UPLOAD_STATE | 1 | R | Captura dinâmica |
| 0x48 | UPLOAD_HANDLE | 2 | R | Captura dinâmica |
| 0x49 | UPLOAD_REMAINING | 4 | R | Captura dinâmica |
| 0x4A | MODE_ACTIVE | 1 | R | Captura dinâmica |
| 0x80 | RX_CANCEL | 1 | W | Pulso |
| 0x81 | FRAME_ACK | 2 | W | Staging de dois bytes |

STATUS usa bits 0 READY, 1 BUSY, 2 CMD_EMPTY, 3 CMD_FULL, 4 DATA_FULL, 5 ERROR_PENDING, 6 RX_PARTIAL, 7 UPLOAD_ACTIVE e 8 FRAME_EVENT. Bits 9 a 15 são reservados. FRAME_EVENT pode persistir com BUSY em zero.
