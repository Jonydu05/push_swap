# Push_swap

> Porque `Swap_push` não parece tão natural

## Resumo

Esta atividade fará você ordenar dados em uma pilha, usando um conjunto limitado de instruções e o menor número possível de ações. Para ter sucesso, você terá que manipular diferentes tipos de algoritmos e escolher a solução mais apropriada (entre muitas) para uma ordenação de dados otimizada.

Esta é uma atividade em grupo que deve ser concluída por **exatamente 2 estudantes**.

**Versão: 1.1**

## Sumário

- [I. Prefácio](#i-prefácio)
- [II. Instruções comuns](#ii-instruções-comuns)
- [III. Instruções sobre IA](#iii-instruções-sobre-ia)
- [IV. Introdução](#iv-introdução)
- [V. Objetivos](#v-objetivos)
- [VI. Parte obrigatória](#vi-parte-obrigatória)
  - [VI.1 Requisitos do projeto em grupo](#vi1-requisitos-do-projeto-em-grupo)
  - [VI.2 As regras](#vi2-as-regras)
  - [VI.3 Requisitos dos algoritmos](#vi3-requisitos-dos-algoritmos)
  - [VI.3.1 Modelo de complexidade e restrições das operações](#vi31-modelo-de-complexidade-e-restrições-das-operações)
  - [VI.3.2 Métrica de desordem (obrigatória)](#vi32-métrica-de-desordem-obrigatória)
  - [VI.3.3 Estratégias obrigatórias](#vi33-estratégias-obrigatórias)
  - [VI.4 Exemplo](#vi4-exemplo)
  - [VI.5 O programa `push_swap`](#vi5-o-programa-push_swap)
  - [VI.5.1 Exemplos de uso](#vi51-exemplos-de-uso)
  - [VI.6 Benchmark de desempenho](#vi6-benchmark-de-desempenho)
- [VII. Requisitos do README](#vii-requisitos-do-readme)
- [VIII. Parte bônus](#viii-parte-bônus)
  - [VIII.1 O programa `checker`](#viii1-o-programa-checker)
- [IX. Entrega e avaliação por pares](#ix-entrega-e-avaliação-por-pares)

---

# I. Prefácio

Era uma vez, nas misteriosas terras da Ciência da Computação, um certo Donald Knuth¹ que popularizou a notação Big-O para nos ajudar a falar sobre como os algoritmos escalam. Big-O é basicamente uma maneira educada de dizer: "Seu código vai rodar rápido para sempre... ou vai ficar tão lento que você terá tempo de fazer café, bebê-lo e envelhecer enquanto espera."

Diz a lenda que, nos primórdios, os programadores não tinham Big-O. Eles simplesmente executavam seus códigos e, se demorasse demais, culpavam o hardware. Então o Big-O chegou e acabou com a diversão, provando matematicamente que às vezes seu algoritmo é simplesmente ruim — não importa quantos hamsters você coloque na roda da CPU.

Por que isso importa para o `push_swap`? Porque aqui você está, armado com duas pilhas e um conjunto de movimentos limitados e pouco intuitivos, tentando ordenar números mais rápido do que um insertion sort sonolento. O Big-O ajudará você a encarar a verdade brutal: uma estratégia brilhante `O(n log n)` sempre vai durar mais que uma estratégia desajeitada `O(n²)` quando a entrada cresce... a menos que, é claro, você escolha ignorar a matemática e assista à sua contagem de operações disparar.

Então, ao projetar seus algoritmos, lembre-se: Big-O não está aqui para assustar você — está aqui para impedir que você se torne a pessoa que escreve:

```text
pb; pa; pb; pa; pb; pa; ...
```

10.000 vezes seguidas e depois se pergunta por que o checker odeia seu programa. Ordene de forma inteligente, não lenta.

Big-O não é uma classificação de tamanho de pipoca... mas, se fosse, `O(n log n)` ainda seria o tamanho ideal.

¹ Sim, o cara com a barba gloriosa e paciência infinita.

---

# II. Instruções comuns

- Seu projeto deve ser escrito em **C**.
- Seu projeto deve ser escrito de acordo com a **Norm**. Se você tiver arquivos/funções bônus, eles também serão incluídos na verificação da Norm, e você receberá nota 0 se houver um erro de Norm.
- Suas funções não devem encerrar inesperadamente (`segmentation fault`, `bus error`, `double free`, etc.), exceto em casos de comportamento indefinido. Se isso ocorrer, seu projeto será considerado não funcional e receberá nota 0 durante a avaliação.
- Toda memória alocada no heap deve ser liberada corretamente quando necessário. Vazamentos de memória não serão tolerados.
- Se o subject exigir, você deverá entregar um `Makefile` que compile seus arquivos-fonte para o executável exigido usando as flags `-Wall`, `-Wextra` e `-Werror`, com `cc`. Além disso, seu `Makefile` não deve fazer relink desnecessário.
- Seu `Makefile` deve conter pelo menos as regras `$(NAME)`, `all`, `clean`, `fclean` e `re`.
- Para entregar bônus, você deve incluir uma regra `bonus` no `Makefile`, que adicionará todos os headers, bibliotecas ou funções que não são permitidos na parte principal. Os bônus devem ser colocados em arquivos `_bonus.{c/h}`, a menos que o subject especifique o contrário. A avaliação da parte obrigatória e da parte bônus será feita separadamente.
- Se o seu projeto permitir o uso da sua `libft`, você deverá copiar os fontes e o `Makefile` associado para uma pasta `libft`. O `Makefile` do projeto deverá compilar a biblioteca usando o `Makefile` dela e, depois, compilar o projeto.
- Recomendamos que você crie programas de teste para o projeto, mesmo que eles não precisem ser entregues e não sejam avaliados. Eles facilitarão os testes do seu trabalho e do trabalho dos seus colegas. Esses testes serão especialmente úteis durante a defesa. Durante a defesa, você poderá usar seus testes e/ou os testes do colega que estiver avaliando.
- Entregue seu trabalho no repositório Git designado. Somente o trabalho presente nos repositórios Git será avaliado. Se o Deepthought for responsável pela avaliação, isso ocorrerá após as avaliações por pares. Se ocorrer um erro em qualquer seção do seu trabalho durante a avaliação do Deepthought, a avaliação será interrompida.

---

# III. Instruções sobre IA

## Contexto

Durante sua jornada de aprendizado, a IA pode ajudar em muitas tarefas diferentes. Reserve um tempo para explorar as diversas capacidades das ferramentas de IA e como elas podem apoiar seu trabalho. No entanto, sempre use essas ferramentas com cautela e avalie criticamente os resultados. Seja código, documentação, ideias ou explicações técnicas, você nunca pode ter certeza absoluta de que sua pergunta foi bem formulada ou de que o conteúdo gerado está correto. Seus colegas são um recurso valioso para ajudar a evitar erros e pontos cegos.

## Mensagem principal

- ☛ Use IA para reduzir tarefas repetitivas ou tediosas.
- ☛ Desenvolva habilidades de criação de prompts — tanto para programação quanto para tarefas não relacionadas a código — que serão úteis em sua futura carreira.
- ☛ Aprenda como os sistemas de IA funcionam para antecipar e evitar melhor riscos, vieses e questões éticas comuns.
- ☛ Continue desenvolvendo suas habilidades técnicas e interpessoais trabalhando com seus colegas.
- ☛ Use somente conteúdo gerado por IA que você compreenda completamente e pelo qual possa assumir responsabilidade.

## Regras para estudantes

- Você deve reservar tempo para explorar ferramentas de IA e entender como elas funcionam, para poder usá-las de maneira ética e reduzir possíveis vieses.
- Reflita sobre o problema antes de criar o prompt — isso ajuda você a escrever prompts mais claros, detalhados e relevantes, usando vocabulário preciso.
- Desenvolva o hábito de verificar, revisar, questionar e testar sistematicamente qualquer coisa gerada por IA.
- Busque sempre uma revisão por parte de colegas — não dependa apenas da sua própria validação.

## Resultados esperados da fase

- Desenvolver habilidades de criação de prompts de uso geral e específicas do domínio.
- Aumentar sua produtividade com o uso eficaz de ferramentas de IA.
- Continuar fortalecendo o pensamento computacional, a resolução de problemas, a adaptabilidade e a colaboração.

## Comentários e exemplos

Você encontrará regularmente situações — provas, avaliações e outras — nas quais precisará demonstrar compreensão real. Esteja preparado, continue desenvolvendo suas habilidades técnicas e interpessoais.

Explicar seu raciocínio e debater com colegas frequentemente revela lacunas no seu entendimento. Priorize o aprendizado entre pares.

As ferramentas de IA frequentemente não possuem seu contexto específico e tendem a gerar respostas genéricas. Seus colegas, que compartilham o mesmo ambiente, podem oferecer informações mais relevantes e precisas.

Enquanto a IA tende a gerar a resposta mais provável, seus colegas podem oferecer perspectivas alternativas e nuances valiosas. Conte com eles como uma etapa de controle de qualidade.

### ✓ Boa prática

Eu pergunto à IA: "Como testo uma função de ordenação?" Ela me dá algumas ideias. Eu testo essas ideias e reviso os resultados com um colega. Refinamos a abordagem juntos.

### ✗ Má prática

Eu peço à IA para escrever uma função inteira, copio e colo no meu projeto. Durante a avaliação por pares, não consigo explicar o que ela faz nem por quê. Perco credibilidade — e reprovo no projeto.

### ✓ Boa prática

Uso IA para ajudar a projetar um parser. Depois, percorro a lógica com um colega. Encontramos dois bugs e reescrevemos a solução juntos — melhor, mais limpa e totalmente compreendida.

### ✗ Má prática

Deixo o Copilot gerar uma parte importante do meu código. Ele compila, mas não consigo explicar como trata pipes. Durante a avaliação, não consigo justificar o código e reprovo no projeto.

---

# IV. Introdução

O projeto `Push_swap` é um projeto de algoritmos muito simples e direto: os dados precisam ser ordenados.

Você tem à sua disposição um conjunto de valores inteiros, 2 pilhas e um conjunto de operações para manipular ambas.

Seu objetivo? Escrever um programa em C chamado `push_swap` que calcule e exiba na saída padrão o menor programa, composto por operações da linguagem Push_swap, capaz de ordenar os inteiros recebidos como argumentos.

Fácil?

Veremos...

---

# V. Objetivos

O objetivo deste projeto é fazer você descobrir a complexidade algorítmica de maneira muito concreta.

Ordenar números é fácil; ordená-los rapidamente usando apenas duas pilhas e um punhado de movimentos é outra história. Ordenar uma lista completamente aleatória e ordenar uma lista quase ordenada também são situações muito diferentes.

Você perceberá rapidamente como a escolha do algoritmo pode fazer a diferença entre uma vitória rápida e uma rolagem interminável de operações.

---

# VI. Parte obrigatória

## VI.1 Requisitos do projeto em grupo

- Este projeto deve ser realizado por exatamente **2 estudantes** trabalhando juntos.
- Ambos os estudantes devem contribuir de maneira significativa para o projeto e compreender todos os algoritmos implementados.
- O repositório deve indicar claramente as contribuições de ambos os estudantes no `README.md`.
- Durante a defesa, ambos os estudantes devem estar presentes e ser capazes de explicar qualquer parte do código.
- A entrega do projeto deve incluir os logins de ambos os estudantes no repositório.

## VI.2 As regras

- Você tem 2 pilhas chamadas `a` e `b`.
- No início:
  - A pilha `a` contém uma quantidade aleatória de números negativos e/ou positivos, sem duplicatas.
  - A pilha `b` está vazia.
- O objetivo é ordenar os números em ordem crescente na pilha `a`. Para isso, você dispõe das seguintes operações:

| Operação | Descrição |
|---|---|
| `sa` | **swap a**: troca os dois primeiros elementos do topo da pilha `a`. Não faz nada se houver apenas um ou nenhum elemento. |
| `sb` | **swap b**: troca os dois primeiros elementos do topo da pilha `b`. Não faz nada se houver apenas um ou nenhum elemento. |
| `ss` | Executa `sa` e `sb` ao mesmo tempo. |
| `pa` | **push a**: retira o primeiro elemento do topo de `b` e o coloca no topo de `a`. Não faz nada se `b` estiver vazia. |
| `pb` | **push b**: retira o primeiro elemento do topo de `a` e o coloca no topo de `b`. Não faz nada se `a` estiver vazia. |
| `ra` | **rotate a**: desloca todos os elementos da pilha `a` uma posição para cima. O primeiro elemento passa a ser o último. |
| `rb` | **rotate b**: desloca todos os elementos da pilha `b` uma posição para cima. O primeiro elemento passa a ser o último. |
| `rr` | Executa `ra` e `rb` ao mesmo tempo. |
| `rra` | **reverse rotate a**: desloca todos os elementos da pilha `a` uma posição para baixo. O último elemento passa a ser o primeiro. |
| `rrb` | **reverse rotate b**: desloca todos os elementos da pilha `b` uma posição para baixo. O último elemento passa a ser o primeiro. |
| `rrr` | Executa `rra` e `rrb` ao mesmo tempo. |

## VI.3 Requisitos dos algoritmos

Para exigir uma compreensão rigorosa da complexidade algorítmica (tempo e espaço), você deve implementar **quatro estratégias de ordenação distintas** e integrá-las ao seu programa `push_swap`. Seu programa deve ser capaz de selecionar uma estratégia em tempo de execução com base na configuração da entrada.

### VI.3.1 Modelo de complexidade e restrições das operações

Todas as estratégias são implementadas em C e devem gerar sequências de operações Push_swap para realizar a ordenação. Isso significa:

- Seus algoritmos em C analisam a entrada e geram a sequência apropriada de operações: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- A saída da estratégia é a sequência de operações que ordena a pilha.
- Quando você declarar uma classe de complexidade, ela deve refletir o custo medido pelo **número de operações Push_swap geradas**, e não a complexidade teórica de um algoritmo clássico baseado em arrays.

### VI.3.2 Métrica de desordem (obrigatória)

Neste subject, a desordem é um número entre `0` e `1` que indica o quanto a pilha `a` inicial está distante de estar ordenada.

Se os números já estiverem na ordem correta, a desordem é `0`. Se estiverem na pior ordem possível, a desordem é `1`. Qualquer valor intermediário significa que a pilha está parcialmente ordenada, mas ainda desorganizada.

Para calculá-la, você pode imaginar que está analisando todos os pares possíveis de números na pilha. Cada vez que um número maior aparece antes de um número menor, esse par conta como um erro. Quanto mais erros houver, mais próximo de `1` estará o valor da desordem.

```text
function compute_disorder(stack a):
    mistakes = 0
    total_pairs = 0
    for i from 0 to size(a)-1:
        for j from i+1 to size(a)-1:
            total_pairs += 1
            if a[i] > a[j]:
                mistakes += 1
    return mistakes / total_pairs
```

Você deve medir a desordem **antes de executar qualquer movimento**.

### VI.3.3 Estratégias obrigatórias

#### 1. Algoritmo simples (`O(n²)`)

Implemente pelo menos um algoritmo-base na classe `O(n²)`. Exemplos incluem:

- Adaptação de insertion sort
- Adaptação de selection sort
- Adaptação de bubble sort
- Métodos simples de extração do mínimo/máximo

#### 2. Algoritmo médio (`O(n√n)`)

Implemente pelo menos um algoritmo na classe `O(n√n)`. Exemplos incluem:

- Ordenação baseada em chunks (dividir em `√n` chunks)
- Métodos de particionamento baseados em blocos
- Adaptações de bucket sort com `√n` buckets
- Estratégias baseadas em intervalos (`ranges`)

#### 3. Algoritmo complexo (`O(n log n)`)

Implemente pelo menos um algoritmo na classe `O(n log n)`. Exemplos incluem:

- Adaptação de radix sort (LSD ou MSD)
- Adaptação de merge sort usando duas pilhas
- Adaptação de quick sort com particionamento usando pilhas
- Adaptação de heap sort
- Abordagens usando árvore indexada binária

#### 4. Algoritmo adaptativo personalizado

Projete uma estratégia adaptativa que selecione diferentes métodos internos dependendo da desordem medida. Você não está limitado a nenhum algoritmo nomeado específico; as técnicas internas ficam inteiramente a seu critério.

Entretanto, seu projeto deve respeitar as seguintes metas de complexidade para cada regime:

| Regime | Condição | Complexidade exigida |
|---|---:|---:|
| Baixa desordem | `disorder < 0.2` | `O(n²)` |
| Média desordem | `0.2 ≤ disorder < 0.5` | `O(n√n)` |
| Alta desordem | `disorder ≥ 0.5` | `O(n log n)` |

Você deve documentar no seu repositório (por exemplo, no `README.md`) a justificativa para seus limiares, as técnicas internas usadas em cada regime e um breve argumento de complexidade (limites superiores) para tempo e espaço dentro do modelo de operações Push_swap.

---

## VI.4 Exemplo

Para ilustrar o efeito de algumas dessas operações, vamos ordenar uma lista aleatória de inteiros. Neste exemplo, consideraremos que ambas as pilhas crescem para a direita.

### Estado inicial

```text
    2       1
    1       3
    3       6
    6       5
    5       8
    8
    _       _
    a       b
```

### Executando `sa`

```text
    1       1
    2       3
    3       6
    6       5
    5       8
    8
    _       _
    a       b
```

### Executando `pb pb pb`

```text
    6       3
    5       2
    8       1
    _       _
    a       b
```

### Executando `ra rb` (equivalente a `rr`)

```text
    5       2
    8       1
    6       3
    _       _
    a       b
```

### Executando `rra rrb` (equivalente a `rrr`)

```text
    6       3
    5       2
    8       1
    _       _
    a       b
```

### Executando `sa`

```text
    5       3
    6       2
    8       1
    _       _
    a       b
```

### Executando `pa pa pa`

```text
    1
    2
    3
    5
    6
    8
    _       _
    a       b
```

Os inteiros da pilha `a` são ordenados em **12 operações**. Você consegue fazer melhor?

---

# VI.5 O programa `push_swap`

| Item | Requisito |
|---|---|
| Nome do programa | `push_swap` |
| Arquivos a entregar | `Makefile`, `*.h`, `*.c` |
| Regras do Makefile | `NAME`, `all`, `clean`, `fclean`, `re` |
| Argumentos | Pilha `a`: uma lista de inteiros |
| Funções externas | `read`, `write`, `malloc`, `free`, `exit`; `ft_printf` ou equivalente |
| Funções que você deve codificar | As demais necessárias ao projeto |
| Libft autorizada | Sim |
| Descrição | Ordenar pilhas |

Seu projeto deve obedecer às seguintes regras:

- Você deve entregar um `Makefile` que compile seus arquivos-fonte. Ele não deve fazer relink.
- Variáveis globais são proibidas.
- Você deve escrever um programa chamado `push_swap` que receba como argumentos:
  - A pilha `a` formatada como uma lista de inteiros (o primeiro argumento é o topo da pilha).
  - Um seletor de estratégia opcional:
    - `--simple`: força o uso do algoritmo `O(n²)`.
    - `--medium`: força o uso do algoritmo `O(n√n)`.
    - `--complex`: força o uso do algoritmo `O(n log n)`.
    - `--adaptive`: força o uso do algoritmo adaptativo baseado na desordem.
- `--adaptive` é o comportamento padrão quando nenhum seletor é fornecido.
- O programa deve exibir a menor lista possível de operações Push_swap para ordenar a pilha `a`, com o menor número no topo.
- As operações devem ser separadas por `\n` e nada mais deve ser exibido.
- A classe de complexidade declarada para cada algoritmo deve ser válida neste modelo.
- A seleção de estratégia deve funcionar para todas as entradas válidas. Qualquer flag de seleção deve funcionar independentemente do tamanho da entrada ou do nível de desordem.
- Se nenhum parâmetro for especificado, o programa não deve exibir nada e deve devolver o prompt.
- Em caso de erro, deve exibir `Error` seguido de `\n` na saída de erro padrão (`stderr`).
- Exemplos de erros incluem argumentos que não são inteiros, inteiros fora do intervalo válido ou valores duplicados.
- Seu binário deve conter as quatro estratégias (`Simple O(n²)`, `Medium O(n√n)`, `Complex O(n log n)` e `Adaptive`). O nome da estratégia selecionada e sua classe de complexidade devem estar disponíveis no modo `--bench`.
- O modo de benchmark opcional (`--bench`) deve exibir, depois da ordenação:
  - A desordem calculada (percentual com duas casas decimais).
  - O nome da estratégia utilizada e sua classe de complexidade teórica.
  - O número total de operações.
  - A quantidade de cada tipo de operação (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
- A saída do benchmark deve ser enviada para `stderr` e só deve aparecer quando a flag estiver presente.

## VI.5.1 Exemplos de uso

Linhas prefixadas com `[bench]` representam mensagens impressas pelo modo de benchmark (em `stderr`). O fluxo de operações continua sendo enviado para `stdout`.

### Exemplo básico

```bash
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
ra
pb
ra
pb
pb
pa
pa
pa
pa
pa
pa
```

### Seleção padrão (`--adaptive`) e contagem de operações

```bash
$> ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
13
```

### Forçar a estratégia simples (`O(n²)`)

```bash
$> ./push_swap --simple 5 4 3 2 1
rra
pb
rra
pb
rra
pb
ra
pb
pb
pa
pa
pa
pa
pa
```

### Forçar a estratégia complexa (`O(n log n)`) e verificar com o checker

```bash
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
```

### `push_swap` com uma entrada grande

```bash
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
6784
$>
```

### Executar com benchmark habilitado

Para ocultar as operações e mostrar somente as métricas:

```text
Canal de saída das operações: stdout
Canal das métricas do benchmark: stderr
```

Você pode direcionar o fluxo de operações para o checker enquanto salva o benchmark em um arquivo.

### Exemplos de gerenciamento de erros

```bash
$> ./push_swap --adaptive 0 one 2 3
Error

$> ./push_swap --simple 3 2 3
Error
```

---

# VI.6 Benchmark de desempenho

Para validar este projeto, você deve atingir determinadas metas de desempenho com um número mínimo de operações.

### 100 números aleatórios

| Resultado | Número de operações |
|---|---:|
| Requisito mínimo para passar | Menos de 2000 |
| Bom desempenho | Menos de 1500 |
| Excelente desempenho | Menos de 700 |

### 500 números aleatórios

| Resultado | Número de operações |
|---|---:|
| Requisito mínimo para passar | Menos de 12000 |
| Bom desempenho | Menos de 8000 |
| Excelente desempenho | Menos de 5500 |

Tudo isso será verificado durante sua avaliação usando o checker fornecido.

---

# VII. Requisitos do README

Um arquivo `README.md` deve ser fornecido na raiz do seu repositório Git. Seu objetivo é permitir que qualquer pessoa que não conheça o projeto (colegas, equipe, recrutadores etc.) entenda rapidamente do que se trata o projeto, como executá-lo e onde encontrar mais informações sobre o assunto.

O `README.md` deve conter pelo menos:

- A **primeira linha** deve estar em itálico e ser exatamente:

  > *This project has been created as part of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]].*

- Uma seção **Description** que apresente claramente o projeto, incluindo seu objetivo e uma visão geral breve.
- Uma seção **Instructions** contendo todas as informações relevantes sobre compilação, instalação e/ou execução.
- Uma seção **Resources** listando referências clássicas relacionadas ao tema (documentação, artigos, tutoriais etc.), além de uma descrição de como a IA foi utilizada — especificando para quais tarefas e quais partes do projeto.
- Seções adicionais podem ser necessárias dependendo do projeto (por exemplo, exemplos de uso, lista de funcionalidades, escolhas técnicas etc.).
- Quaisquer adições obrigatórias serão explicitamente listadas abaixo.
- Também deve ser incluída uma explicação e justificativa detalhadas dos algoritmos selecionados para este projeto.

O inglês é recomendado; alternativamente, você pode usar o idioma principal do seu campus.

---

# VIII. Parte bônus

Devido à sua simplicidade, este projeto oferece oportunidades limitadas para funcionalidades adicionais. Porém, por que não criar seu próprio checker?

Graças ao checker, você poderá verificar se a lista de operações gerada pelo programa `push_swap` realmente ordena a pilha corretamente.

A parte bônus só será avaliada se a parte obrigatória estiver perfeita. Perfeito significa que a parte obrigatória foi totalmente concluída e funciona sem erros. Neste projeto, isso significa validar todos os benchmarks sem exceção. Se você não tiver passado **TODOS** os requisitos obrigatórios, sua parte bônus não será avaliada.

## VIII.1 O programa `checker`

| Item | Requisito |
|---|---|
| Nome do programa | `checker` |
| Arquivos a entregar | `*.h`, `*.c` |
| Makefile | `bonus` |
| Argumentos | Pilha `a`: uma lista de inteiros |
| Funções externas | `read`, `write`, `malloc`, `free`, `exit`; `ft_printf` ou equivalente |
| Funções que você deve codificar | As demais necessárias ao projeto |
| Libft autorizada | Sim |
| Descrição | Executar as operações de ordenação |

- Escreva um programa chamado `checker` que receba como argumento a pilha `a` formatada como uma lista de inteiros. O primeiro argumento deve estar no topo da pilha (atenção à ordem).
- Se nenhum argumento for fornecido, o programa encerra e não exibe nada.
- Em seguida, ele deve aguardar e ler operações da entrada padrão (`stdin`), com cada instrução seguida por `\n`.
- Depois que todas as instruções forem lidas, o programa deve executá-las sobre a pilha recebida como argumento.
- Se, após executar essas instruções, a pilha `a` estiver realmente ordenada e a pilha `b` estiver vazia, o programa deve exibir `OK` seguido por `\n` na saída padrão.
- Em qualquer outro caso, deve exibir `KO` seguido por `\n` na saída padrão.
- Em caso de erro, deve exibir `Error` seguido por `\n` na saída de erro padrão (`stderr`).
- Exemplos de erros incluem argumentos que não são inteiros, números maiores que um inteiro, duplicatas, instruções inexistentes e/ou instruções formatadas incorretamente.

### Exemplo de sucesso

```text
$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

### Exemplo de ordenação incorreta

```text
$> ./checker 3 2 1 0
sa
rra
pb
KO
```

### Exemplo de argumento inválido

```text
$> ./checker 3 2 one 0
Error
```

### Exemplo de argumento vazio

```text
$> ./checker "" 1
Error
$>
```

Você **não precisa reproduzir o comportamento exato** do binário fornecido. É obrigatório tratar erros, mas fica a seu critério decidir como fazer o parsing dos argumentos.

---

# IX. Entrega e avaliação por pares

Entregue sua atividade no repositório Git normalmente. Somente o trabalho que estiver dentro dos seus repositórios será avaliado durante a defesa. Não deixe de conferir novamente os nomes dos seus arquivos para garantir que estão corretos.

## Requisitos da entrega do projeto em grupo

- Ambos os estudantes devem estar listados como contribuidores no repositório.
- O `README.md` deve documentar claramente as contribuições de ambos os estudantes.
- Ambos os estudantes devem estar presentes durante a defesa da avaliação por pares.
- Cada estudante deve ser capaz de explicar e defender qualquer parte do código.

Durante a avaliação, ocasionalmente poderá ser solicitada uma pequena modificação no projeto. Isso pode envolver uma pequena mudança de comportamento, algumas linhas de código para escrever ou reescrever, ou uma funcionalidade fácil de adicionar.

Embora essa etapa não seja aplicável a todas as avaliações, você deve estar preparado para ela caso seja mencionada nas diretrizes de avaliação.

A modificação pode ser feita em qualquer ambiente de desenvolvimento de sua escolha (por exemplo, seu ambiente habitual) e deve ser possível realizá-la em poucos minutos — a menos que seja definido um período específico.

Por exemplo, você pode ser solicitado a fazer uma pequena atualização em uma função ou script, modificar uma exibição ou ajustar uma estrutura de dados para armazenar novas informações.

Os detalhes (escopo, objetivo etc.) serão especificados nas diretrizes de avaliação e podem variar de uma avaliação para outra para o mesmo projeto.

---

## Observação sobre esta tradução

Este documento é uma tradução para **PT-BR** do subject `Push_swap`, versão 1.1, mantendo a organização, os requisitos, os nomes das operações, flags, comandos e classes de complexidade do documento fornecido.
