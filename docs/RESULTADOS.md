# Resultados e limitações

| Ambiente | Estado e escopo |
|---|---|
| Core PC10 | **Comprovado** em software. Builds isoladas Debug e Release passaram em 12 grupos cada, incluindo a suíte normativa de 5.489 casos. |
| VIS01–VIS04 | **Comprovado** historicamente em renderização de referência fora da tela. As quatro campanhas registraram 50, 92, 169 e 226 casos aprovados. |
| Fuse-TKGA DP01 | **Experimental**. Evidência histórica para descoberta, recursos, paleta, sprites, framebuffer, FENCE, publicação e ACK. Os exemplos cobrem 15 opcodes distintos. |
| Lógica FPGA de vídeo e framebuffer | **Experimental**. Há simulações, síntese e demonstrações de bancada de vídeo clássico e de publicação de imagens em ensaios dirigidos. Os subconjuntos experimentais têm capacidades e divergências próprias. |
| Uso físico com TK90X/TK95 | **Não homologado**. |

O perfil DP01 documentado é Win32. Seus números de capacidade descrevem a configuração emulada. O carregamento de recursos grandes pode ser lento. Estado TKGA fica fora da serialização de snapshots do emulador, e RZX não registra a extensão. Use os procedimentos de cada ensaio ao comparar resultados.

A demonstração Resgate Aéreo registrou uma cadência lógica emulada de aproximadamente 50,08 atualizações por segundo nos cenários aprovados. O resultado descreve o relógio da emulação. Os arquivos da demonstração exigem avaliação própria de distribuição.
