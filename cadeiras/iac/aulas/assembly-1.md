# Assembly

## Historia
CISC - Complex Instruction Set Computing
- Introdução de intruções complicadas em hardware (ex divisao, raizes, etc)  
- Backwards compatibility  
- - Sacrifcios de hardware: utilização de transistors e registos  

RISC - Reduced Instruction Set Computing
- Instruções simples
- - -transistors usados
- - +simples, +rapido, +registos, +paralelismo

## Instructions
Registos: x0, x2, ..., x31 (x0 não se pode usar, é 0, tem-se 32 registos disponíveis)  

Instrução:
- tem que caber em 32bits


- add(i). ADD com valor imediato ou constante. Constante tem que ser o 2º argumento.    
```
OPERAÇÂO  TARGET           ARG1           ARG2       
add       x10,             x11,           x12            x10 = x11 
sub       x10,             x11,           x12            x10 = x11 
addi      x10,             x11,           70             x10 = x11 + 70
addi      x10,             x11,           -70            x10 = x11 + -70

OPERAÇÕES LÓGICAS (todas as operações lógicas têm versão com constante, ex: andi)
and       x10,             x10,           x11            x10 = x10 & x11
or        x10,             x10,           x11            x10 = x10 | x11
xor       x10,             x10,           x11            x10 = x10 ^ x11
sll       x10,             x10,           x11            x10 = x10 << x11
srl       x10,             x10,           x11            x10 = x10 >> x11
sra       x10,             x10,           x11            x10 = 
```

### Exemplo de ADD:
```
x10 0  0  1  1
x11 0  1  1  1  +
vai 1  1  1     +
s1  1  2  3  2
s2  1  0  1  0
```
- s1 - somar os bits
- - se soma der 2 ou 3 passa-se +1 (vai) para o proximo bit mais significativo
- s2 - se soma de bits mais o 'vai' for 2
- - coloca-se 0 no valor final
- s2 - se a soma de bit mais o 'vai' for 3
- - coloca-se 1 no valor final

### Exemplo de SUB:
```
x10 0  1  0  1
x11 0  0  1  1  -
vai    1        -
s1  0  0 -1  0
```
- s1 - subtrair os bits
- - se subtração mais 'vai' der -1 passa-se -1 (vai) para o próximo bit mais significativo
- - se subtração mais 'vai' der 1 ou 0 o resultado final para o bit é respectivamente 1 ou 0
- - se subtração mais 'vai' der -1 o resultado final para o bit é 1

* Para poupar 1 registo não existe subi, faz-se addi com valor negativo  

### Exemplo de AND:
```
x10  0  0  1  1
x11  0  1  0  1
res  0  0  0  1
```
* AND - both A and B  

### Exemplo de OR:
```
x10  0  0  1  1
x11  0  1  0  1
res  0  1  1  1
```
* OR - either A or B  

### Exemplo de XOR:
```
x10  0  0  1  1
x11  0  1  0  1
res  0  1  1  0
```
* Exclusive OR - A or B but not both or neither  

### Exemplo de SLL (shift left):
```
x10 = 0011 = 3
x11 = 0010 = 2
desloca 0011 2 bits para a esquerda e acrescenta 0 a direita
res = 1100 = 12
```
* SLL vai acabar por ser x10 = x10 * 2^x11. Neste caso x10 = 3 * 2² = 12  

### Exemplo de SRL (shift right):
```
x10 = 1100 = 12
x11 = 0010 = 2
desloca 1100 2 bits para a direita e acrescenta 0 a esquerda
res = 0011 = 3
```
* SRL vai acabar por ser x10 = x10 / 2^x11. Neste caso x10 = 12 / 2² = 3. Esta divisão é inteira!  

### Exemplo de SRA (shift right algoritmico)  
* O SRL acrescenta 0 ao bit mais significativo quando se faz shift bit a bit.  
* Isto origina problemas com o sinal de números binários de complemento 2 (bit mais significativo).  
* SRA acrescenta ao bit mais significativo dependendo do bit mais significativo.  
* Se o bit mais significative for 0 acrescenta 0, senão acrescenta 1.  
```
x10 = 0011 = 3
x11 = 0010 = 2
desloca 0011 2 bits para a direita e acrescenta 0 a esquerda
res = 0000

x10 = 1100 = -4
x11 = 0010 = 2
desloca 1100 2 bits para a direita e acrescenta 1 a esquerda
res = 1111 = -1
```
* SRA vai acabar por ser x10 / 2^x11 = -4 / 2² = -1  