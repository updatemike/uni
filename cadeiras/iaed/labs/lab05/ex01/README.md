## Exercício 01 (Tabelas bidimensionais)

Considere constantes ALUNOS=10 e DISCIPLINAS=5.  Cada aluno é identificado por um número 0..ALUNOS-1 e cada disciplina é identificada por um número 0..DISCIPLINAS-1.  Implemente um programa que calcule a disciplina mais popular (na média) e o aluno que na média mais gosta de estudar.

O input é dado no standard input da seguinte forma: um número inteiro positivo N, e N triplos A D V, onde A é um número de um aluno, D um número de uma disciplina, e V um número inteiro entre -100..100, representando o nível de entusiasmo do aluno A pela disciplina D. Se uma certa combinação de A, D não aparece no input, então V deve assumir-se com valor 0.

O resultado deve ser impresso com a disciplina mais popular na primeira linha e o aluno mais entusiástico na segunda linha.
Caso existam duas disciplinas/alunos com o mesmo score, deverá ser impresso o que tiver menor identificador.

*Sugestão:* Guardar os valores numa matriz `int  valores[ALUNOS][DISCIPLINAS]` e implementar funções
`long score_disciplina(int disciplina, int valores[ALUNOS][DISCIPLINAS])` e `long score_aluno(int aluno, int valores[ALUNOS][DISCIPLINAS])`.

**Input**
```
2
1 4 10
1 3 5
```

**Output**
```
4
1
```
The results for the evaluation of this exercise can be found [here](https://gitlab.rnl.tecnico.ulisboa.pt/iaed24/feedback/labs/ist163484/-/tree/master/lab05/ex01/README.md), in the feedback repository.
