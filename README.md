# TKGA / TKX — Developer Preview 0.1

**Uma nova arquitetura gráfica para a família TK90X/ZX Spectrum, construída e testada por etapas.**

Concepção e coordenação técnica: **José Albuquerque**. Publicação inicial: **15 de novembro de 2026**.

A TKGA investiga como ampliar as possibilidades gráficas dos computadores clássicos sem perder de vista a compatibilidade com a apresentação original. Este repositório público documenta o contrato de programação, reúne um SDK mínimo de serialização C11 e registra resultados e limitações com separação explícita entre software, simulação e hardware.

> **Prévia para desenvolvedores, não produto pronto.** A integração do TKbus com um TK90X/TK95 físico **não está homologada**. Estes documentos não autorizam conectar nem energizar um protótipo.

## Conteúdo desta prévia

- [Arquitetura funcional](docs/ARQUITETURA.md) e [manual de programação](docs/MANUAL.md)
- [35 comandos da ABI RC1.1](docs/COMANDOS.md) e [registros lógicos](docs/REGISTROS.md)
- [Evidências, alcance e limitações](docs/RESULTADOS.md) e [próximos marcos](docs/ROADMAP.md)
- [SDK mínimo C11](sdk/): serializador de pacotes, [exemplo FENCE](examples/fence.c) e [teste automatizado](tests/packet_test.c)
- [Como compilar e testar](BUILD.md)

Os **35 comandos são uma especificação de contrato**; não significa que todos estejam implementados nos bitstreams experimentais. O SDK serializa comandos: **não inclui um executor gráfico completo**.

### Experimente o primeiro pacote

```sh
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

O exemplo codifica `FENCE 0x1234` nos bytes `03 00 02 00 34 12`.

## Onde a engenharia já chegou

| Camada | Evidência | Situação |
|---|---|---|
| Core PC10 portátil | 12 grupos; 5.489 casos normativos em Debug e Release | Testado em software, fontes ainda privadas |
| Core + SDK | `COMPLETED_FENCE = 0x1234`, `LAST_ERROR = 0` | Integração de bancada em software |
| Fuse-TKGA DP01 | Exemplos demonstraram 15 opcodes | Emulador experimental, fontes não incluídas |
| Duas Tang Nano 20K | Vídeo LEGACY observado em bancada; ensaios de framebuffer/HDMI | Evidência experimental, não certificação da ABI completa |
| TK90X/TK95 → TKbus → TKGA | Esquema as-built, frontend e homologação elétrica pendentes | Não testado ponta a ponta no TK real |

Relatos de vídeo LEGACY, incluindo jogos observados na bancada, não equivalem a uma validação do protótipo TKbus montado nem à conclusão dos gates M01–M11.

## O que está propositalmente fora

Não distribuímos aqui o Core PC10 completo, o Fuse modificado, RTL histórico, bitstreams, ROMs, Resgate Aéreo nem fontes/assets de jogos de terceiros. Cada um exige avaliação independente de titularidade, dependências, licença e/ou segurança.

## Licença, créditos e colaboração

- **Documentação original** deste repositório: [Creative Commons Attribution 4.0 International (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/).
- **Código original C e CMake** incluído nesta prévia: [MIT](LICENSE-CODE).
- Atribuição: **José Albuquerque — TKGA/TKX**, com os reconhecimentos e limites em [CREDITS.md](CREDITS.md) e [RIGHTS.md](RIGHTS.md).
- Contribuições e correções: [CONTRIBUTING.md](CONTRIBUTING.md).

O projeto é uma iniciativa aberta à comunidade. Para alegar compatibilidade, identifique a ABI, o backend e os testes efetivamente executados.
