# Compilar e executar

Use CMake 3.20 ou superior, um compilador C11 e um gerador CMake com ferramentas instaladas. A árvore funciona localmente sem downloads, jogos, ROMs ou bibliotecas de terceiros empacotadas.

```sh
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

O CTest executa o exemplo e a regressão da serialização. A saída esperada do exemplo é `03 00 02 00 34 12`. Em geradores de configuração única, use `-DCMAKE_BUILD_TYPE=Debug` ou `Release` na configuração inicial para selecionar a configuração desejada.

Inclua `tkga_packet.h` e ligue seu programa à biblioteca `tkga_packet`. A função devolve a quantidade de bytes gravada. O chamador escolhe o opcode e fornece o corpo conforme a ABI. O executor do protocolo é responsável pelos efeitos, pelas regras do comando e pelo controle de crédito.
