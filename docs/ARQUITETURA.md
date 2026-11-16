# Arquitetura funcional

O programa consulta a identidade e as capacidades oferecidas pelo ambiente, prepara os recursos e transmite pacotes CMD e dados de upload. O executor valida cada operação e mantém os recursos e o estado de trabalho. A publicação oferece ao consumidor uma cena estável em uma fronteira de quadro elegível.

O modo CLASSIC preserva a apresentação clássica. O modo NATIVE usa a cena publicada e conserva a apresentação clássica enquanto essa cena estiver indisponível. O modo 2 está reservado ao modelo de evolução TKX e retorna UNSUPPORTED no Core v0.1.

Os recursos são identificados por handles. Imagens e framebuffers usam dados indexados. Mapas descrevem índices de tiles. Paletas convertem índices em cores. O estado de trabalho determina associações, posição, prioridade e recorte. Imagens usadas por cenas pendentes ou publicadas têm leases de leitura que podem impedir gravação e liberação.

As capacidades do ambiente determinam dimensões, formatos, alocação, crédito e quantidade de sprites por linha. A seleção por linha é determinística. O programa deve verificar as capacidades efetivas antes de ativar recursos opcionais.

O Core define cinco operações lógicas por byte, com CMD e DATA independentes. O Fuse DP01 fornece um adaptador experimental Z80 para essas operações. A ABI 0x0101 define o significado lógico das operações e dos registros.
