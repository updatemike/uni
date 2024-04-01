## Exercício 1 (Utilização do valgrind)

1 - Faça download do zip anexo ao guia de laboratório.

2 - Compile o programa ex1.c com geração de informação para o debugger (`-g`):
```
$ gcc -Wall -Wextra -Werror -Wno-unused-result -g -o ex1 ex1.c
```

3 - Execute o programa ex1 com o valgrind e verifique o output produzido:
```
$ valgrind ./ex1
```

4 - Corrija o programa ex1 de forma a que o valgrind não produza erros:

## Exercício 2 (Utilização do valgrind)

1 - Compile o programa ex2.c com geração de informação para o debugger (`-g`):
```
$ gcc -Wall -Wextra -Werror -Wno-unused-result -g -o ex2 ex2.c
```

2 - Execute o programa ex2 com o valgrind e verifique o output produzido:
```
$ valgrind ./ex2 < ex2.in
```

3 - Corrija o programa ex2 de forma a que o valgrind não produza erros e
o programa leia correctamente 10 números e faça output da soma dos números
lidos.


## Exercício 3 (Utilização do valgrind)

1 - Compile o programa ex3.c com geração de informação para o debugger (`-g`):
```
$ gcc -Wall -Wextra -Werror -Wno-unused-result -g -o ex3 ex3.c
```

2 - Execute o programa ex3 com o valgrind e verifique o output produzido:
```
$ valgrind ./ex3 < ex3.in
```

3 - Corrija o programa ex3 de forma a que o valgrind não produza erros e
o programa leia correctamente strings até 9 caracteres e faça output da cópia da string lida.

## Ponteiros e Alocação Dinâmica de Memória

### Exercício 4

Implemente um programa em C que leia uma palavra do standard input e que
imprima todos os sufixos dessa palavra.  O programa deverá imprimir um sufixo
por linha começando do mais comprido para o mais curto.

Poderá supor que a palavra nunca terá mais de 1000 caracteres.

*Dica:* Sugere-se utilização de aritmética de ponteiros, para poder avançar com
um ponteiro `p` representando os diferentes sufixos e passar esse ponteiro `p`
como parâmetro para a função `printf`.


**Input**
```
abc
```

**Output**
```
abc
bc
c
```


### Exercício 5

Implemente um programa em C que leia uma sequência de palavras do standard
input e imprima as mesmas na ordem inversa.  O programa deverá imprimir uma
palavra por linha começando pela última palavra.

Poderá supor que a palavra nunca terá mais de 1000 caracteres, que não aparacem
mais que 10000 palavras e que cada palavra pode ser lida com `scanf("%s", s)`.

*Dica:* Guarde as palavras como um vector de strings.  Primeiro leia a palavra
dentro de uma string com um tamanho fixo e só depois aloca a string com o
tamanho adequado.

*Dica:* A chamada `scanf("%s", buffer)` devolve `1` se e só se a palavra foi lida
com sucesso, i.e. a leitura pode terminar se o valor devolvido não estiver `1`.

**Input**
```
abc foo bar
```

**Output**
```
bar
foo
abc
```


### Exercício 6

Implemente em C um programa que começa por perguntar ao utilizador o número de
datas a introduzir. De seguida, leia esse número de datas no formato DD-MM-AAAA.
No final deverá mostrar as datas lidas pela ordem inversa da sua introdução.

*Dica:* Use os tipos de dados e as funções do laboratório 05.

### Exercício 7

Altere o programa do exercício anterior de tal forma que as datas sejam mostradas de
forma ordenada da mais antiga para a mais recente.

*Dica:* Modifique a solução do exercício anterior, mas insira as datas no vector
de forma ordenada.

### Exercício 8

Desenvolva em C um conjunto de funções que permita manipular uma pilha
(_stack_) com realocação automática. A pilha será representada com a seguinte
estrutura:

    typedef struct {
        int *v;     /* contents of the stack */
        int cap;    /* capacity of v, i.e. how many elements can fit in v */
        int sz;     /* number of elements currently stored in v */
    } stack;

As funções a desenvolver são as seguintes:

    stack* build();                 /* builds a new empty stack with initial capacity 4 */
    void push(stack * s, int e);    /* pushes integer e on top of the stack  (reallocate v if necessary) */
    int top(stack * s);             /* returns top element in the stack */
    int pop(stack * s);             /* removes top element from the stack and return it
                                        (not necessary to reallocate v) */
    int is_empty(stack * s);        /* returns 1 iff s represents the empty stack, returns 0 otherwise */
    void destroy(stack * s);        /* frees the memory associated with the stack */

*Nota:* Poderá começar por considerar uma implementação sem a realocação automática.

### Exercício 9 (facultativo)

Implemente em C um programa que leia uma linha do standard input e verifica se
os parênteses estão bem formatados, considerando os pares de parênteses `()`,
`[]`, `{}`.

Por exemplo, a string `"{[a]b(c)}()[]"` é uma string bem formatada, enquanto a
string `"(()"` não o é.  Se o input for bem formatado, o programa deverá
imprimir `"yes"`, e no caso contrário deverá imprimir `"no"`.

*Dica:* Podem aproveitar o `ex05` para resolver este exercício. Quando
encontrarem um parêntesis a abrir, coloque-o no stack; quando encontrar um
parêntesis a fechar verifica se o topo é um "match" e retira-o da pilha.  No
final a stack deverá ficar vazio.

*Dica:* Não é necessário guardar o input; é suficiente usar o stack.

**Input**
```
"{[a]b(c)}()[]"
```

**Output**
```
yes
```

**Input**
```
"(()"
```

**Output**
```
no
```
