# Referência dos 35 comandos

ABI RC1.1 do Core v0.1. Os comprimentos se referem somente ao corpo. O cabeçalho tem quatro bytes e flags zero. Consulte CAPS e os estados dos recursos antes de enviar. As listas de erros indicam valores possíveis no contrato lógico.

| Opcode | Nome | Corpo | Bytes | Erros | DP01 exemplos |
|---|---|---|---|---|---|
| 0x01 | SET_MODE | mode:u8, flags:u8 | 2 | 1, 2, 3, 4, 7 | Sim |
| 0x02 | SET_GLOBAL_CLIP | x:s16,y:s16,w:u16,h:u16 | 8 | 1, 2, 3, 4 | Sem ensaio nos exemplos de referência |
| 0x03 | FENCE | fence_id:u16 | 2 | 1, 2, 3, 4 | Sim |
| 0x04 | PRESENT | present_id:u16,flags:u8 | 3 | 1, 2, 3, 4, 6, 7, 8 | Sim |
| 0x05 | ENGINE_RESET | scope:u8 | 1 | 1, 2, 3, 4 | Sem ensaio nos exemplos de referência |
| 0x06 | CLEAR_ERROR | mask:u16 | 2 | 1, 2, 3, 4 | Sem ensaio nos exemplos de referência |
| 0x10 | RESOURCE_CREATE | handle:u16,type:u8,flags:u8,size:u32 | 8 | 1, 2, 3, 4, 5, 6, 7, 8 | Sim |
| 0x11 | RESOURCE_FREE | handle:u16 | 2 | 1, 2, 3, 4, 6, 7 | Sem ensaio nos exemplos de referência |
| 0x12 | UPLOAD_BEGIN | handle:u16,offset:u32,length:u32,flags:u8 | 11 | 1, 2, 3, 4, 6, 7, 8 | Sim |
| 0x13 | UPLOAD_END | handle:u16,crc32:u32 | 6 | 1, 2, 3, 4, 6, 7, 8, 11 | Sim |
| 0x14 | UPLOAD_ABORT | handle:u16 | 2 | 1, 2, 3, 4, 6, 7 | Sem ensaio nos exemplos de referência |
| 0x20 | PALETTE_WRITE | bank:u8,start:u8,count:u8,RGB[3*count] | 3+3*count | 1, 2, 3, 4, 8 | Sim |
| 0x21 | PALETTE_COPY | dst:u8,src:u8,start:u8,count:u8 | 4 | 1, 2, 3, 4, 7, 8 | Sem ensaio nos exemplos de referência |
| 0x22 | PALETTE_CLEAR | bank:u8,R:u8,G:u8,B:u8 | 4 | 1, 2, 3, 4, 8 | Sem ensaio nos exemplos de referência |
| 0x30 | FB_BIND | slot:u8,handle:u16,flags:u8 | 4 | 1, 2, 3, 4, 6, 7 | Sim |
| 0x31 | FB_CLEAR | target:u8,R:u8,G:u8,B:u8 | 4 | 1, 2, 3, 4, 6, 7 | Sim |
| 0x32 | FB_FILL_RECT | target:u8,x:s16,y:s16,w:u16,h:u16,R:u8,G:u8,B:u8 | 12 | 1, 2, 3, 4, 6, 7 | Sim |
| 0x33 | FB_COPY_RECT | src:u8,dst:u8,sx:s16,sy:s16,dx:s16,dy:s16,w:u16,h:u16,flags:u8 | 15 | 1, 2, 3, 4, 6, 7 | Sem ensaio nos exemplos de referência |
| 0x40 | TILESET_BIND | layer:u8,handle:u16,tile_w:u8,tile_h:u8,bpp:u8,palette:u8 | 7 | 1, 2, 3, 4, 6, 7, 8 | Sem ensaio nos exemplos de referência |
| 0x41 | TILEMAP_BIND | layer:u8,handle:u16,map_w:u16,map_h:u16 | 7 | 1, 2, 3, 4, 6, 7, 8 | Sem ensaio nos exemplos de referência |
| 0x42 | LAYER_CONFIG | layer:u8,priority:u8,flags:u16,palette:u8 | 5 | 1, 2, 3, 4, 6, 7, 8 | Sem ensaio nos exemplos de referência |
| 0x43 | LAYER_SCROLL | layer:u8,x:s16,y:s16 | 5 | 1, 2, 3, 4 | Sem ensaio nos exemplos de referência |
| 0x44 | LAYER_ENABLE | layer:u8,enable:u8 | 2 | 1, 2, 3, 4, 6, 7, 8 | Sem ensaio nos exemplos de referência |
| 0x45 | TILEMAP_UPDATE | layer:u8,x:u16,y:u16,w:u16,h:u16,entries[u8*w*h] | 9+w*h | 1, 2, 3, 4, 6, 7, 8 | Sem ensaio nos exemplos de referência |
| 0x50 | SPRITE_DEFINE | id:u16,handle:u16,src_x:u16,src_y:u16,w:u16,h:u16 | 12 | 1, 2, 3, 4, 6, 7, 8 | Sim |
| 0x51 | SPRITE_POSITION | id:u16,x:s16,y:s16 | 6 | 1, 2, 3, 4, 6, 7, 8 | Sim |
| 0x52 | SPRITE_FRAME | id:u16,frame:u16 | 4 | 1, 2, 3, 4, 6, 7, 8 | Sim |
| 0x53 | SPRITE_ATTR | id:u16,flags:u16,palette:u8,transparent_index:u8 | 6 | 1, 2, 3, 4, 6, 7, 8 | Sim |
| 0x54 | SPRITE_PRIORITY | id:u16,priority:u8 | 3 | 1, 2, 3, 4, 6, 7, 8 | Sem ensaio nos exemplos de referência |
| 0x55 | SPRITE_ENABLE | id:u16,enable:u8 | 3 | 1, 2, 3, 4, 6, 7, 8 | Sim |
| 0x60 | BLIT | src:u16,dst:u8,sx:u16,sy:u16,dx:s16,dy:s16,w:u16,h:u16,flags:u8 | 16 | 1, 2, 3, 4, 6, 7 | Sem ensaio nos exemplos de referência |
| 0x61 | BLIT_KEYED | src:u16,dst:u8,sx:u16,sy:u16,dx:s16,dy:s16,w:u16,h:u16,flags:u8,key:u8 | 17 | 1, 2, 3, 4, 6, 7 | Sem ensaio nos exemplos de referência |
| 0x62 | DRAW_LINE | target:u8,x1:s16,y1:s16,x2:s16,y2:s16,R:u8,G:u8,B:u8 | 12 | 1, 2, 3, 4, 6, 7 | Sem ensaio nos exemplos de referência |
| 0x63 | DRAW_RECT | target:u8,x:s16,y:s16,w:u16,h:u16,R:u8,G:u8,B:u8,flags:u8 | 13 | 1, 2, 3, 4, 6, 7 | Sem ensaio nos exemplos de referência |
| 0x64 | SCROLL_RECT | target:u8,x:s16,y:s16,w:u16,h:u16,dx:s16,dy:s16,R:u8,G:u8,B:u8 | 16 | 1, 2, 3, 4, 6, 7 | Sem ensaio nos exemplos de referência |

## Comportamento por comando

- **SET_MODE.** Pede alteração do modo. Verifique MODE_ACTIVE após a fronteira elegível.
- **SET_GLOBAL_CLIP.** Atualiza o retângulo de recorte global para operações que o consultam.
- **FENCE.** Marca a conclusão ordenada de comandos anteriores e do marco de DATA associado.
- **PRESENT.** Captura a cena de trabalho para publicação. Confirme evento e tag antes do ACK.
- **ENGINE_RESET.** Executa RECOVER (0) ou REINITIALIZE (1). Verifique conclusão e retorno a CLASSIC.
- **CLEAR_ERROR.** Limpa as classes de erro selecionadas pela máscara.
- **RESOURCE_CREATE.** Reserva armazenamento para um recurso identificado por handle.
- **RESOURCE_FREE.** Libera um recurso quando nenhum uso ou lease impede a operação.
- **UPLOAD_BEGIN.** Abre uma sessão DATA para um intervalo do recurso.
- **UPLOAD_END.** Encerra a sessão após admissão completa, drenagem e verificação solicitada.
- **UPLOAD_ABORT.** Interrompe a sessão de upload do recurso.
- **PALETTE_WRITE.** Grava uma sequência de entradas RGB na paleta selecionada.
- **PALETTE_COPY.** Copia entradas entre intervalos de paleta.
- **PALETTE_CLEAR.** Preenche entradas de paleta conforme o corpo especificado.
- **FB_BIND.** Associa um recurso a um slot de framebuffer.
- **FB_CLEAR.** Preenche todo o destino com a cor indicada.
- **FB_FILL_RECT.** Preenche o retângulo indicado no destino.
- **FB_COPY_RECT.** Copia a região entre framebuffers ou posições.
- **TILESET_BIND.** Associa o atlas e a geometria de tiles à camada.
- **TILEMAP_BIND.** Associa o mapa à camada com as dimensões do corpo.
- **LAYER_CONFIG.** Atualiza configuração da camada.
- **LAYER_SCROLL.** Atualiza o deslocamento da camada.
- **LAYER_ENABLE.** Ativa ou desativa a camada.
- **TILEMAP_UPDATE.** Grava novos índices de tile na região do mapa indicada.
- **SPRITE_DEFINE.** Define o recurso e o recorte do sprite. A definição começa desabilitada.
- **SPRITE_POSITION.** Move o sprite para coordenadas inteiras com sinal.
- **SPRITE_FRAME.** Seleciona o frame no atlas.
- **SPRITE_ATTR.** Aplica flags, seleção de paleta e índice transparente.
- **SPRITE_PRIORITY.** Altera a prioridade do sprite.
- **SPRITE_ENABLE.** Ativa ou desativa o sprite.
- **BLIT.** Copia um recorte de pixels para o destino.
- **BLIT_KEYED.** Copia um recorte com exclusão de pixels pela chave.
- **DRAW_LINE.** Desenha um segmento entre os extremos indicados.
- **DRAW_RECT.** Desenha o contorno do retângulo indicado.
- **SCROLL_RECT.** Desloca uma região do destino com o preenchimento especificado.

FRAME_ACK e RX_CANCEL são controles de registro. DATA e descoberta são operações da interface. A coluna DP01 descreve a cobertura dos exemplos distribuídos.

## Campos com flags

| Comando | Valores definidos |
|---|---|
| UPLOAD_BEGIN | Bit 0 ativa VERIFY_CRC. |
| LAYER_CONFIG | Bits 0 WRAP_X, 1 WRAP_Y e 2 TRANSPARENT_ZERO. |
| SPRITE_ATTR | Bits 0 FLIP_X, 1 FLIP_Y, 2 CLIP_ENABLE e 3 TRANSPARENT_ENABLE. |
| DRAW_RECT | O seletor de estilo aceita 0 para contorno e 1 para preenchimento. |

Envie zero nos bits reservados. CLEAR_ERROR aceita as classes dos bits 0 a 6, e máscara zero preserva o estado.

## Códigos observáveis

| LAST_ERROR_CODE | Nome | Máscara da classe |
|---:|---|---|
| 0 | NONE | 0x0000 |
| 1 | UNKNOWN_OPCODE | 0x0001 |
| 2 | BAD_LENGTH | 0x0001 |
| 3 | INVALID_PARAMETER | 0x0002 |
| 4 | UNSUPPORTED | 0x0004 |
| 5 | MEMORY_EXHAUSTED | 0x0004 |
| 6 | INVALID_RESOURCE | 0x0008 |
| 7 | INVALID_STATE | 0x0010 |
| 8 | RANGE | 0x0002 |
| 9 | FIFO_OVERFLOW | 0x0020 |
| 10 | DATA_OVERFLOW | 0x0020 |
| 11 | INTEGRITY_ERROR | 0x0040 |

ERROR_CLASSES acumula classes até a limpeza explícita ou reset aplicável. LAST_ERROR_CODE identifica a falha primária mais recente. Consulte os dois valores antes de emitir CLEAR_ERROR e confirmar recuperação.
