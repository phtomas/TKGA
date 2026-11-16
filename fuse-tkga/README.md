# Fuse-TKGA — Developer Preview PUB03C

**Extensão experimental de emulação gráfica TKGA/TKX para Fuse 1.6.0**, com libspectrum 1.5.0 e Core PC10. **Concepção e coordenação da extensão TKGA: José Albuquerque**. Fuse e libspectrum preservam integralmente os créditos upstream.

## Baixar a fonte
- [Pacote completo de fontes, patches, Core PC10, exemplos e receitas](./PUB03C/FUSE_TKGA_PUB03C_SOURCE.zip) — **99.137 bytes**
- SHA-256 do ZIP: `67c6552b9058d1bf03e2c6a4a653c6924e8809d948fc70844d81459d683cf45f`.

Extraia o ZIP e siga **README.md**, **BUILD.md** e **REPRODUZIR.md** dentro dele. O pacote contém **41 arquivos**, incluindo os **12 fontes do Core PC10**, o patch de 21 caminhos, overlays, provas e textos de licenciamento. Os tarballs oficiais do Fuse e libspectrum são baixados separadamente, com versões e checksums especificados no pacote.

O ZIP **não distribui ROMs, DLLs ou executável Fuse pré-compilado**. A ROM do Spectrum 48K para executar exemplos deverá ser fornecida licitamente pelo testador.

## O que foi testado

- Build Win32, combinando fontes e patches do pacote: **PASS** após correção de diretório `test` ausente no primeiro ensaio.
- **Classic, Hello e FirstFrame: PASS** no reteste com o auxiliar `sdk/helpers.inc` validado. As falhas das primeiras tentativas permanecem documentadas.
- Golden Z80: 18.913 linhas conferidas após normalizar CRLF/LF.
- Execução independente em outros sistemas e integração física com TK90X: **não homologadas** nesta prévia.

## Direitos e colaboração

Contribuições próprias TKGA, incluindo o Core selecionado e a extensão, sob **GPL-2.0-or-later**. O Fuse e libspectrum são obras de seus respectivos autores, mantidos os avisos e licenças upstream. A documentação original desta entrega segue **CC BY-SA 4.0**. Confira os arquivos `COPYING`, `LICENSES.md`, `CREDITS.md` e `licenses/` incluídos no pacote.

Este é um preview de **fontes para desenvolver e testar**, não um emulador já instalado. [Arquitetura TKGA](../../docs/ARQUITETURA.md) · [Política de atribuição](../../POLITICA_COPYLEFT.md).
