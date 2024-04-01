# Estruturas Auto-referenciadas

### Exercício 1

Implemente em C um programa que leia uma sequência de inteiros terminada por `0` e imprima a mesma sequência, mas invertida. 
O programa deve ser implementado usando listas ligadas. A lista será representada pela seguinte estrutura:

```
    typedef struct stru_node {
        struct stru_node *next;
        int v;
    } node;
```

e deverá ser manipulada pelas seguintes funções:

```
    /* remove the first element of the list and return the new head */
    node * pop(node * head);
    /* add integer e as the first element of the list and return the new head */
    node * push(node * head, int e);
    /* frees all memory associated with the list and returns NULL */
    node * destroy(node * head);
    /* print the elements of the integers in the list, one per line */
    void print(node * head);
```

**Input**
```
1 2 0
```

**Output**
```
2
1
```


### Exercício 2

Implemente em C um programa que leia uma linha de caracteres e imprime `yes` se a linha for um palíndromo e imprima `no` no caso contrário.

*Dica:* Reutilize a lista ligada do `ex01`. Adicionalmente implemente as funções:

```
    int is_eq(node *h1, node *h2);   /* compara duas listas */
    node * rev(node * head);         /* devolve uma nova lista que corresponda a lista dada invertida */
```

**Input**
```
abba
```

**Output**
```
yes
```

**Input**
```
abbx
```

**Output**
```
no
```



### Exercício 3

Implemente em C um programa que leia uma sequência de strings sem espaços terminada por a string `"x"` e imprima a mesma sequência, mas invertida. O programa deve ser implementado usando listas ligadas. Podem assumir que cada string tem no máximo 1000 caracteres. Entretanto, deve-se só alocar memória suficiente para as strings dadas.

A lista será representada pela seguinte estrutura:

```
    typedef struct stru_node {
        struct stru_node *next;
        char *v;
    } node;
```

e deverá ser manipulada pelas seguintes funções definidas no exercício 1:

```
    /* remove the first element of the list and return the new head */
    node * pop(node *head);
    /* add string e as the first element of the list and return the new head */
    node * push(node *head, const char *e);
    /* frees all memory associated with the list and returns NULL */
    node * destroy(node *head);
    /* print the elements of the integers in the list, one per line */
    void print(node *head);
```

**Nota:** Não se esquecam, no __pop__, de libertar as strings alocadas no __push__.

**Input**
```
bye hello x
```

**Output**
```
hello
bye
```


### Exercício 4

Implemente em C um programa que leia uma linha de caracteres e guarda os caracteres numa lista __duplamente__ ligada.
Imprima `yes` se a linha for um palíndromo e imprima `no` no caso contrário.

A lista será representada pelas estrutura seguintes:

```
    typedef struct str_node  {
        struct str_node *next, *previous;
        char c;
    } node;

    typedef struct  {
        struct str_node *head, *last;
    } list;
```

e deverá ser manipulada pelas seguintes funções:

```
    list* mk_list();                 /* cria nova lista vazia */
    void  free_list(list *l);        /* liberta toda a memoria associada a lista */
    void  add_last(list *l, char c); /* adiciona o char c como o ultimo elemento da lista */
    int   is_paly(const list *ls);   /* calcula se a dada lista e um palindromo */
```


**Input**
```
abba
```

**Output**
```
yes
```

**Input**
```
abbx
```

**Output**
```
no
```


### Exercício 5

Implemente uma calculadora para Notação polaca (também denominada notação de prefixo) inversa
([https://en.wikipedia.org/wiki/Reverse_Polish_notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)),
onde  o operador segue os operandos. Por exemplo, `(3+4)` é `3 4 +`; `(3+4) * 5` é `3 4 + 5 *`.
A expressão é dada no standard input como uma sequência de palavras. O programa deverá imprimir o resultado numa linha separada.


**Dica:** Os resultados intermédios podem ser guardados numa pilha.

**Dica:** A função `atoi` pode ser usada para converter uma string no `int`.


**Input**
```
7 2 + 1 +
```

**Output**
```
10
```
