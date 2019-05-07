Segue o trabalho de Algoritmos 3 da UFPR desenvolvido por Roberta Samistraro Tomigian de GRR20171631.

O trabalho usa como base uma árvore binária de busca A que tem como nodos uma árvore secundária B. 

A árvoreA tem as seguintes funcionalidades:
    1) Busca: imprime em parenteses alinhados cada nodo da arvoreA visitado, que é a arvoreB. E verifica se a soma da árvoreB está inclusa na árvoreA.
    2) Inclusão: recebe uma árvoreB e inclui se não existe nenhum com a mesma soma. 
    3) Exclusão: recebe uma árvoreB, calcula index, busca pelo index e remove se existir na árvoreA.
    4) Impressão: imprime em pré-ordem a árvoreA, em colchetes alinhados. Cada nodo dele é uma representação em parenteses alinhados da árvoreB.

    Todo elemento da árvore A possui um index que simboliza a soma de todos os nos da Árvore B. A busca procura na árvore um elemento que possui o mesmo index de uma determinada sub árvore.
    Esse programa não tem como finalidade comparar a sub-árvore buscada com as existentes, e de mesmo indice, na árvore principal.

A árvoreB tem as seguintes funcionalidades: 
    1) Inclusão: Funciona do mesmo modo que árvoreA, mas com inteiros como nodo.
    2) Impressão: Em parenteses alinhados. 

Leitura e escrita:
    O programa recebe um arquivo de entrada que contém em seu interior instruções desse modo: char árvoreB
    No qual o char pode ser i (inserção), b (busca) e r (remocao). E a árvoreB é uma árvore em parênteses alinhados, por exemplo, (10(5)()). 
    Após a leitura ele faz as contas necessárias e grava em um arquivo de saída a árvoreA e todos os seus passo-a-passo de execução, que estão contidos no de entrada.
    Esse passo-a-passo pode ser inserção, busca e remocao, em suas ordens desejadas e seus respectivos valores.

Compilação:
    Para compilar deve-se digitar make na linha de comando (dentro da pasta que contém o programa). No makefile tem os seguintes comandos: 

    gcc -o busca busca.c árvoreA.c árvoreB.c
    busca teste.in > teste_arq.out 

    No qual teste.in é o arquivo de entrada e o teste_arq.out é o de saída.
    Na própria pasta de input, contida nesse zip, há alguns exemplos de entradas e seu formato correto. E um exemplo de output para o input testado.

