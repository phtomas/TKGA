# Manual do programador

## Descoberta e créditos

Use um único consumidor/produtor lógico por interface, inclusive no código de interrupção. Selecione um registro por REG_SELECT8 e leia sua largura por REG_READ8. Valide os quatro bytes `54 4B 47 41` e leia IF_VERSION e CMDSET_VERSION, ambos `0x0101` no PC10. Consulte CAPS e preserve o caminho clássico quando a assinatura, a versão ou as capacidades necessárias estiverem indisponíveis.

À entrada de cada consulta dinâmica selecione STATUS (`0x40`). Isso captura o banco dinâmico para leitura coerente. Ao selecionar outro campo da captura, inicia-se o cursor desse campo. Renovar STATUS atualiza a captura. Leituras além da largura retornam zero no contrato Core.

CMD_WRITE8 recebe quatro bytes de cabeçalho seguidos do corpo. O cabeçalho contém opcode de um byte, flags de um byte iguais a zero e comprimento do corpo u16 little-endian. Cada inteiro multibyte usa little-endian. Coordenadas s16 usam complemento de dois em pixels. Confirme crédito CMD_FREE para cabeçalho e corpo inteiros. DATA_WRITE8 tem crédito separado e atende o upload ativo. Retornos da API host e códigos em LAST_ERROR_CODE pertencem a domínios distintos.

## Recursos e upload

BITMAP (tipo 1) e FRAMEBUFFER (tipo 4) começam com seis bytes, versão 1, formato de um byte, largura u16 e altura u16. INDEX4 (formato 1) usa ceil(largura/2) bytes por linha, primeiro pixel no nibble alto e nibble baixo final zero em largura ímpar. INDEX8 (formato 2) usa um byte por pixel. TILEMAP (tipo 3) usa índices de um byte em linhas contíguas, com a geometria definida na associação.

Escolha um handle diferente de zero. Emita RESOURCE_CREATE, confirme FENCE e erros, emita UPLOAD_BEGIN e confirme o estado ativo. Envie até o menor valor entre DATA_FREE e UPLOAD_REMAINING. O primeiro upload cobre o recurso inteiro. Após admitir todos os bytes, envie UPLOAD_END, aguarde um FENCE e confira o estado final e o erro. Com bit 0 de UPLOAD_BEGIN ativo, informe no END o CRC-32/ISO-HDLC sobre os bytes DATA da sessão. Com esse bit desligado, o campo CRC vale zero.

## Preparação e publicação

Configure a paleta e prepare o framebuffer e os demais recursos. Associe um framebuffer válido ao slot BACK quando disponível. Para sprites, defina o recorte e a imagem, selecione atributos, posição e frame e então habilite. Para camadas, associe tileset e mapa, configure e habilite. Ao pedir NATIVE, confira MODE_ACTIVE em uma captura renovada.

1. Emita PRESENT com uma tag em ordem serial de 16 bits.
2. Aguarde FRAME_EVENT e a tag em LAST_PRESENTED, renovando STATUS.
3. Selecione FRAME_ACK uma vez e escreva os bytes baixo e alto dessa tag por REG_WRITE8.

FENCE comprova o término da execução anterior e de seu marco de DATA, inclusive conclusão com erro. PRESENT captura o estado de trabalho. A tag de publicação só muda quando a cena é publicada. O ACK consome o evento da tag publicada. O recurso publicado conserva o lease até sua retirada segura. Reutilize os recursos carregados ao atualizar metadados entre quadros.

## Erros e retomada

Leia LAST_ERROR_CODE e ERROR_CLASSES na mesma captura. CLEAR_ERROR limpa classes selecionadas. RX_CANCEL cancela recepção CMD parcial. ENGINE_RESET oferece RECOVER (escopo 0) e REINITIALIZE (escopo 1). Confira o estado de conclusão, os recursos esperados e o modo CLASSIC antes de retomar. No Fuse DP01, a disponibilidade e os procedimentos de recuperação dependem do cenário e do ciclo do emulador.

## Vetor de codificação

O primeiro FENCE com tag `0x1234` usa `03 00 02 00 34 12`. Depois da execução, consulte COMPLETED_FENCE e os erros. Este vetor documenta a serialização da ABI e pressupõe um contexto válido e crédito de seis bytes.
