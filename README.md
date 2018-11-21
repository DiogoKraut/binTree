# Trabalho CI057

Diogo Paris Kraut - GRR20166365

## Main
1. Le a entrada de stdin
2. Como toda entrada contem uma arvore secundaria, cria esta arvore.
3. Interpreta o primeiro carácter da entrada.
   - Caso input, insere a arvore secundaria na arvore principal.
   - Caso busca, executa procedimento que busca a arvore secundaria, imprimeindo os nós percorridos.
   - Caso remocao, remove o noh que contem uma arvore secundaria equivalente aa que foi passada e libera o noh.
4. Libera toda a memoria que foi alocada durante execucao.

## Impressao
1. Nohs nulos com irmao nulo sao omitidos.         Ex: filhos do noh (10)
2. Nohs nulos com irmao nao nulo sao explicitados. Ex: irmao de 3, (10(3)()).
3. Nohs com ambos filhos nao nulos.                Ex: (10(3)(15)).

No caso da arvore primaria: Nohs nulos explicitados tem seus colchetes na mesma
linha.
    [(10):10
		[(8):8
		]
		[]
		]

## Makefile
1. make - compilar.
2. make clean - limpar diretorio de arquivos .o e core.
3. make purge - make clean + remove executavel.
