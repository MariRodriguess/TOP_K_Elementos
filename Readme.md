<h1 align="center" font-size="200em"><b>Top K palavras de um texto</b></h1>

<div align = "center" >
<!-- imagem -->

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

## 📌Sumário

- [Introdução](#Introdução)
- [Objetivos](#Objetivos)
- [Arquivos](#Arquivos)
- [Resolução do Problema](#Resolução-do-problema)
- [Funções](#Funções)
- [Bibliotecas](#Bibliotecas)
- [Resultados](#Resultados)
- [Conclusão](#Conclusão)
- [Referências](#Referências)
- [Compilação e execução](#Compilação-e-execução)
- [Contato](#Contato)

## ✒️Introdução

Este é um programa desenvolvido em C++ para a disciplina de Algoritmos e Estruturas de Dados II.
O presente trabalho aborda a resolução do problema de encontrar os K elementos mais valiosos (ou frequentes) de uma coleção de dados, utilizando as técnicas de hash e heap. Este problema é comum em diversas áreas, como análise de dados, processamento de linguagem natural e otimização de recursos. A abordagem proposta combina a eficiência da estrutura de hash para contabilizar a frequência dos elementos com a estrutura de heap para manter uma lista ordenada dos K elementos mais relevantes. É importante destacar que, nesse contexto, as K palavras mais recorrentes serão avaliadas sem considerar "stop words", como "a", "à", "ao", "aos", "aquela", a fim de que as palavras mais relevantes apareçam no topo da lista.

## 💻Objetivos

O objetivo deste trabalho consiste em projetar e implementar um programa em C/C++ que, dado um conjunto de arquivos contendo textos sem formatação, seja capaz de identificar as K palavras mais frequentes presentes nesses textos. A solução deve ser capaz de ler os arquivos, processar o conteúdo, contar as frequências das palavras (desconsiderando as "stop words") usando uma estrutura de hash e, em seguida, manter uma lista dos K elementos mais frequentes utilizando um heap. O programa deve produzir uma saída legível (pelo próprio terminal de comando), apresentando as K palavras mais frequentes em ordem crescente.

<strong><h4>Condições impostas: </h4></strong>
- Este programa deverá ler uma coleção de arquivos contento textos sem nenhuma formatação ("arquivo ASCII") onde cada sentença termina por um sinal de pontuação (".", "?", "!").
- Cada parágrafo é separado por, pelo menos, uma linha em branco.
- Considere como palavra uma sequência de letras delimitada por espaço em branco, ”coluna da esquerda”, ”coluna da direita” e símbolos de pontuação.
- Faz parte do projeto do programa fornecer uma saída legível.

## 📄Arquivos
- <strong>Main.cpp:</strong> Leitura dos arquivos ```entrada.txt```, ```stopwords.txt```, realização das chamadaa das funções necessários para o funcionamento do programa.
- <strong>functions.hpp:</strong> Declaração das funções.
- <strong>functions.cpp:</strong> Desenvolvimento das funções. 
- <strong>data/entrada.txt:</strong> Texto de entrada.
- <strong>data/stopwords.txt:</strong> Stop words, como por exemplo, para artigo (a, o, as,os) e para conjunções (e, ou).

## 🔨Resolução do problema

A fim de resolver eficientemente o problema de identificar as K palavras mais frequentes em uma coleção de textos,  código fornecido utiliza uma combinação eficaz de estruturas de dados. Vamos discutir as principais estruturas utilizadas no contexto do código e como elas se relacionam com o problema em questão:

<h3><b>Unodered map como Tabela Hash</b></h3>

O código faz uso do recurso do C++ chamado 'unordered_map' do C++, que é frequentemente utilizada como uma tabela de dispersão (hash table), e permite armazenar pares chave-valor, oferecendo acesso rápido aos valores com base nas chaves. A eficiência das operações em uma tabela de dispersão depende da qualidade da função de hash que mapeia as chaves para posições na estrutura subjacente. No caso do GCC (GNU Compiler Collection), onde este código está sendo compilado, a implementação da estrutura unordered_map utiliza uma variedade de funções de hash especializadas para diferentes tipos de chaves.

Para tipos simples, como ponteiros e inteiros, as funções de hash retornam os próprios valores ou representações simples. Para tipos mais complexos, como strings, o GCC emprega o algoritmo MurmurHashUnaligned2, que é conhecido por suas propriedades de dispersão eficientes e uniformes. O resultado final do MurmurHashUnaligned2 é um valor hash que é uma combinação complexa dos bits dos dados de entrada, misturados e processados ao longo de várias iterações. Essa complexidade ajuda a minimizar colisões e a garantir que pequenas variações nos dados resultem em alterações significativas nos valores de hash. Isso contribui para um desempenho sólido e eficiente das operações de tabela de dispersão no contexto da biblioteca padrão do C++.

Nesse caso, o 'unordered_map' é utilizado para criar uma tabela de hash chamada "glossario", onde a chave será a palavra encontrada nos textos, e o valor associado a essa chave será o número de vezes que essa palavra ocorre. À medida que os textos são processados, cada palavra é analisada e verificada se já está presente na tabela de hash ("glossario"). Se a palavra ainda não estiver lá, ela é inserida como uma chave na tabela, e o valor correspondente é inicializado com 1, indicando que essa é a primeira ocorrência da palavra. Caso a palavra já esteja na tabela, o valor associado a essa chave é incrementado, representando que a palavra ocorreu novamente.

Devido à natureza de tabela de hash do 'unordered_map', as operações de inserção, busca e atualização são realizadas em tempo médio constante (O(1)), tornando a estrutura ideal para lidar com grandes quantidades de dados e garantindo que as operações de manutenção do glossário sejam rápidas e eficientes. O 'unordered_map' (ou qualquer outra estrutura de dados da biblioteca padrão) fornece uma abstração mais alta e uma interface mais amigável para trabalhar com tabelas de hash. Isso pode economizar tempo e esforço na implementação e manutenção, se comparado à abordagem manual de implementar uma tabela de hash.


<h3><b>Utilização de Heap para Manter as K Palavras Mais Frequentes:</b></h3>

Em algoritmos de processamento de dados, a estrutura de dados de "heap" desempenha um papel crucial na ordenação, na obtenção de elementos com prioridade e em outras operações de busca e organização eficiente. Um heap é uma árvore binária especial que obedece a uma propriedade específica: em um "heap máximo", cada nó pai tem um valor maior ou igual aos valores de seus nós filhos, enquanto em um "heap mínimo", cada nó pai tem um valor menor ou igual aos valores de seus nós filhos.

O processo de "heapify" é uma operação fundamental para manter a propriedade de heap em uma estrutura de dados, seja convertendo um array em um heap ou reorganizando os elementos após alguma alteração. Em um "heapify_min", o objetivo é transformar um array ou uma estrutura de dados em um "heap mínimo", onde cada nó pai tem um valor menor ou igual aos valores de seus nós filhos.

É possível utilizar as expressões "2 * i + 1" e "2 * i + 2" para alcançar os filhos esquerdos e direitos de um nó, respectivamente.

#### Demonstrando o Método na Prática:

Para ilustrar o funcionamento do método na prática, consideremos um conjunto de números desorganizados representados em duas estruturas diferentes: uma árvore e um vetor.

Estrutura Inicial da Árvore:

<img src="https://github.com/MariRodriguess/TOP_K_Elementos/assets/127866299/773d3178-66d9-4b0e-83c2-425bf498f9bc" width="400" height="200">
<br><br>

Estrutura Inicial do Vetor:

<img src="https://github.com/MariRodriguess/TOP_K_Elementos/assets/127866299/ed8f20ec-b60a-4e04-9a5f-259e6714eeb0" width="400" height="100">
<br><br>

Agora, vamos aplicar diretamente o processo de heapify mínimo a essas estruturas para transformá-las em um heap mínimo. O resultado é o seguinte:

Estrutura Final da Árvore:

<img src="https://github.com/MariRodriguess/TOP_K_Elementos/assets/127866299/d8076aed-cc76-48bf-82f5-803988096226" width="400" height="200">
<br><br>

Estrutura Final do Vetor:

<img src="https://github.com/MariRodriguess/TOP_K_Elementos/assets/127866299/5201cb40-cfe2-48a5-a3b2-8b5add8455c9" width="400" height="100">
<br><br>

Nessas estruturas, cada nó pai possui um valor menor ou igual aos valores de seus nós filhos. O menor valor está na raiz (3), e a propriedade de heap mínimo é mantida em todos os níveis. Esse exemplo ilustra como a aplicação do processo de heapify mínimo reorganiza as estruturas de forma apropriada para criar um heap mínimo. A propriedade essencial do heap mínimo é preservada, resultando em uma estrutura eficiente para operações que dependem dessa propriedade.

Quando se realiza a operação de heapify em um único nó, o tempo necessário é de O(log K), onde K é o total de nós presentes. Como resultado, o processo de construir um Heap completo demandará N operações de heapify, culminando em uma complexidade de tempo total de O(N*log K).

O código apresentado implementa um "heapify_min" usando um vector chamado "heap" para armazenar as K palavras mais frequentes em um conjunto de textos. A função "addHeap" é responsável por manter o heap de tamanho K, garantindo que as palavras com as menores contagens estejam sempre no topo do heap. Para atingir isso, ela faz uso da função "heapify", que reorganiza os elementos no vector para manter a propriedade de heap mínimo.

<h3><b>Vetores para Armazenamento de Stop Words e Heap</b></h3>

Vetores são utilizados para armazenar as "stop words" e também para criar um heap de palavras mais frequentes. As "stop words" são carregadas em um vetor chamado "stopWords" por meio da função "processStopWords". Isso permite que as "stop words" sejam consultadas de maneira eficiente quando se verifica se uma palavra encontrada é uma "stop word". Além disso, outro vetor chamado "heap" de pares (PAIR) é usado para manter as K palavras mais frequentes. 

<h3><b>Expressões Regulares (Regex) para Processamento de Texto:</b></h3>

A expressão regular "wordRegex" é usada para identificar palavras nos textos. Ela considera caracteres alfanuméricos, incluindo letras maiúsculas e minúsculas, números e o caractere de apóstrofo, permitindo a extração de palavras válidas. Essa expressão regular é aplicada através do objeto "sregex_iterator" para encontrar todas as ocorrências de palavras em cada linha dos textos.

## 🔨 Funções 

- ```processStopWords:``` Durante a leitura do arquivo que contém as palavras de parada (stop words), elas são adicionadas a um vetor. Esse vetor é usado para comparação durante o processo de leitura do arquivo de entrada principal.

- ```processArq:```Esta função é responsável por abrir o(s) arquivo(s) de entrada contendo o texto para leitura. Cada palavra é lida usando a estrutura de expressões regulares (REGEX). Se uma palavra começar ou terminar com um hífen devido à formatação do texto, esses hífens são eliminados. Em seguida, a função "verifPalavra" é chamada para processar a palavra.

- ```verifStopWords:```Esta função é do tipo booleano e verifica se uma palavra está contida no vetor de "stop words". Ela retorna verdadeiro se a palavra estiver presente no vetor e falso caso contrário.

- ```validar:```
Outra função booleana, "validar", é usada para verificar palavras de tamanho dois. Ela examina se a palavra contém caracteres especiais. Por exemplo, se a palavra consistir em apenas um caractere especial, como " ” ", ela é considerada inválida. Caso contrário, a palavra é considerada válida.

- ```verifPalavra:```A função "verifPalavra" é a função principal que centraliza o processo de verificação de uma palavra. Primeiro, é chamada a função "verifStopWords". Se a palavra não for uma "stop word" e passar nesse teste, a função "validar" é chamada para verificar se a palavra é válida. Se ambas as condições forem atendidas, a função "addGlossario" é chamada para adicionar a palavra ao glossário.

- ```addGlossario:```Esta função verifica se uma palavra já foi adicionada anteriormente ao glossário. Se já tiver sido, incrementa o número de ocorrências dessa palavra. Caso contrário, a palavra é adicionada ao glossário e o número de ocorrências é definido como 1.

- ```heapify:```Essa função realiza a manutenção das propriedades do heap. Ela compara o nó atual com seus filhos (esquerdo e direito) e encontra o menor deles. Se o nó atual não for o menor, ele é trocado com o nó menor e a função é chamada recursivamente para o nó que foi trocado. Isso garante que a menor contagem permaneça na raiz do heap.

- ```addHeap:```Nesta função, todo o glossário é percorrido. Durante essa iteração, as primeiras K palavras e suas ocorrências são adicionadas a um vetor de pares (PAIR). Após a adição das K palavras, a função "heapify" é chamada para garantir que o vetor esteja organizado como um heap de mínimo. Posteriormente, a função continua a ler o glossário e, a partir da K+1-ésima palavra em diante, compara as ocorrências de cada palavra com a palavra no topo do vetor (a palavra com menor ocorrência). Se a palavra do glossário tiver mais ocorrências, ela substitui a palavra no topo do vetor. A função "heapify" é chamada novamente para manter a propriedade do heap após a substituição. Esse processo se repete até que todo o glossário seja lido e o vetor "Heap" contenha as K palavras mais recorrentes.

## 📚Bibliotecas

As seguintes bibliotecas foram incorporadas a este programa:

#include &lt;iostream&gt; <br>
#include &lt;fstream&gt; <br>
#include &lt;string&gt; <br>
#include &lt;regex&gt; <br>
#include &lt;unordered_map&gt; <br>
#include &lt;iomanip&gt; <br>

## 🎯Resultados

A saída deve conter as K palavras mais frequentes do texto de entrada em ordem crescente.

<h4><b>Entradas: Dom Casmurro + Semana de Machado de Assis, contendo ao todo 34148 linhas. </b></h4>
<img src="https://github.com/MariRodriguess/TOP_K_Elementos/assets/127866299/3d9b2c30-ea72-4f34-84b2-2ee0e85145f9">

<h4><b>Saida:</b></h4>
<img src="https://github.com/MariRodriguess/TOP_K_Elementos/assets/127866299/6db21c95-d374-47df-95bd-b35c2905884d">



## ✔️Conclusão

Neste projeto, abordamos a resolução do problema de identificar as palavras mais frequentes em um texto, destacando as estruturas de dados adotadas e suas justificativas para a eficiência da solução. A utilização de um 'unordered_map', "vector" e "min-heap" demonstrou ser uma abordagem eficaz para lidar com essa tarefa.

O uso do 'unordered_map' permitiu a contagem eficiente das ocorrências de cada palavra no texto. Essa estrutura de dados, baseada em uma tabela de dispersão (hash), oferece inserção e busca rápidas, com complexidade média de O(1), ideal para manter as ocorrências das palavras em um formato chave-valor. O "vector" foi escolhido para manter uma lista de "stop words". Embora a busca linear em um vetor possa ter complexidade O(n), neste caso, a lista de "stop words" é relativamente pequena, o que torna a busca aceitável. A estrutura do heap foi essencial para manter as K palavras mais frequentes. Através do heap de mínimo, garantimos que as K palavras com menores ocorrências sejam mantidas no topo, facilitando a substituição de palavras menos frequentes à medida que novas palavras são processadas.

Ao comparar essas estruturas, é possível considerar a substituição do uso de um "unordered_map" por um "map". Ambos possuem complexidade média de inserção e busca de O(1), entretanto, o "unordered_map" se destaca por sua eficiência em operações de busca em cenários onde a ordem não é um fator crítico, como ocorre neste projeto. Além disso, o uso do heap é justificado pela própria natureza do problema, visto que a busca pela K-ésima palavra mais frequente é uma operação central, tornando o heap uma escolha apropriada.

Adicionalmente, para futuras otimizações, pode-se considerar a substituição do uso de expressões regulares pelo emprego de "istringstream" e tokenização. Isso tende a acelerar o processamento, visto que o processo de tokenização pode ser mais eficiente e direto em comparação ao uso de expressões regulares.

Resumidamente, as escolhas das estruturas de dados, bem como a consideração de otimizações como a substituição das expressões regulares, contribuíram para uma solução eficaz no problema de identificar palavras mais frequentes.

## ✔️Referências
- https://builtin.com/software-engineering-perspectives/heapify-heap-tree-cpp
- https://acervolima.com/diferenca-entre-min-heap-e-max-heap/
- https://en.cppreference.com/w/cpp/container/unordered_map
- https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm

## 👾Compilação e execução

* Especificações da máquina em que o código foi rodado:
  * AMD Ryzen 5-3500U;
  * Sistema Operacional Windows 11 Pro;
  * Terminal do Visual Studio;
  * 12GB de RAM.
<br>

* **(!!!)** Inicialmente, duas configurações precisam ser especificadas no código:

  * **Quantidade de Arquivos a Serem Lidos:**
Para permitir a leitura de um ou vários arquivos de texto, você deve definir a quantidade na variável qtdArq. Além disso, nomeie todos os arquivos como data/input(x).txt, em que o valor de x é um parâmetro ajustável. Por exemplo, se deseja processar dois arquivos de entrada, os nomes serão data/input1.txt e data/input2.txt, seguindo essa sequência para a quantidade de arquivos definida em qtdArq. É importante observar que a pasta chamada "data" foi criada para alocar os arquivos de entrada.

  * **Quantidade de Palavras com Maior Ocorrência Desejada:**
Para obter as K palavras mais frequentes no texto, você só precisa ajustar a variável "k" para o valor desejado. Por exemplo, se almeja as 20 palavras mais recorrentes, basta definir k=20. Isso permitirá que o código identifique e exiba as palavras mais frequentes conforme a quantidade definida.

  * 
    <br> <img src="https://github.com/MariRodriguess/TOP_K_Elementos/assets/127866299/477dabdd-de12-4ef2-bbea-1c95a50ec8fe">

* | Comando                |  Função                                                                                           |                     
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
  |  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

## ✉️Contato
<div>
 <br><p align="justify"> Mariana Rodrigues Lamounier Melo</p>
 <a href="https://t.me/MariRodriguess0">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:mariana.itapec@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>mariana.itapec@gmail.com</i>
</a>
