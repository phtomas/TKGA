# Resgate Aéreo — Developer Preview PUB03C

**Jogo experimental para Fuse-TKGA**, com arte independente da linhagem PUB03B. **Criação, concepção e coordenação do desenvolvimento: José Albuquerque**, com assistência de IA.

![Captura autêntica da execução do Resgate Aéreo](./PUB03C/media/cover.png)

## Jogue e explore

- [Baixar o jogo TAP — 22.227 bytes](./PUB03C/resgate-aereo-pub03b.tap)
- [Baixar pacote completo: fontes, geradores, arte, TAP, mídia e testes](./PUB03C/RESGATE_AEREO_PUB03C_PREVIEW.zip)
- [Ver GIF real do voo e içamento](./PUB03C/media/fixture-voo-e-icamento.gif) — 7,62 s, sequência automatizada
- [Ver captura real de gameplay](./PUB03C/media/screen-gameplay.png)

**SHA-256 ZIP:** `991ca7092d4a17ffc539ac4f96bc1f83dc917d9079da7a6342391196a92d3266`  
**SHA-256 TAP:** `6ea589cf46f527e76148d7b50eb6f12b6905aea4f39ce7281a5fbc7be2af37f3`.

Para executar, obtenha e compile o [Fuse-TKGA PUB03C](../../fuse-tkga/README.md), utilize uma ROM Spectrum 48K que possa usar licitamente, e carregue o TAP. A construção do TAP foi verificada **sem ROM**.

## Controles

| Teclas | Ação |
|---|---|
| Q / A | Subir / descer |
| O / P | Deslocamento lateral |
| Z / X | Girar |
| V | Corda / cancelar antes do contato, quando aplicável |
| C | Resgate pousado e entrega |
| R | Reiniciar |

Pouse à direita do hangar para completar a entrega.

## Estado de desenvolvimento

- Fonte, ferramentas e assets independentes foram reconstruídos em diretórios limpos, produzindo o **mesmo TAP byte a byte**.
- Boot e capa foram ensaiados no Fuse compilado da seleção pública.
- Voo, içamento, caminhada, entrega e reset foram exercitados por **automação** na campanha PUB03B; o GIF mostra essa execução automatizada, **não uma sessão humana**.
- **Teclado humano e execução no TK físico: NOT_RUN**. Portanto, esta é uma prévia jogável *experimental*, não homologada.

## Licenças e créditos

Código próprio: **GPL-3.0-or-later**. Arte independente isolada, capturas e documentação original: **CC BY-SA 4.0**, com crédito a José Albuquerque. Adaptação integrada no TAP sob GPLv3, conforme `LICENSES.md` e `CREDITS.md` dentro do ZIP. Outras ferramentas e emuladores preservam os respectivos titulares; ROM comercial e arte RA01 não estão incluídas.

[Política de atribuição](../../POLITICA_COPYLEFT.md) · [Referência TKGA](../../docs/MANUAL.md).
