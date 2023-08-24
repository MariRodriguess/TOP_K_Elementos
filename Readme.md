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
- [Bibliotecas](#Funções)
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

O código faz uso do recurso do C++ chamado 'unordered_map', que é uma implementação da estrutura de dados de tabela de hash. Essa estrutura permite criar uma espécie de "tabela" na qual é possível armazenar informações em pares chave-valor. 

Nesse caso, o 'unordered_map' é utilizado para criar uma tabela de hash chamada "glossario", onde a chave será a palavra encontrada nos textos, e o valor associado a essa chave será o número de vezes que essa palavra ocorre. À medida que os textos são processados, cada palavra é analisada e verificada se já está presente na tabela de hash ("glossario"). Se a palavra ainda não estiver lá, ela é inserida como uma chave na tabela, e o valor correspondente é inicializado com 1, indicando que essa é a primeira ocorrência da palavra. Caso a palavra já esteja na tabela, o valor associado a essa chave é incrementado, representando que a palavra ocorreu novamente.

Devido à natureza de tabela de hash do 'unordered_map', as operações de inserção, busca e atualização são realizadas em tempo médio constante (O(1)), tornando a estrutura ideal para lidar com grandes quantidades de dados e garantindo que as operações de manutenção do glossário sejam rápidas e eficientes. O 'unordered_map' (ou qualquer outra estrutura de dados da biblioteca padrão) fornece uma abstração mais alta e uma interface mais amigável para trabalhar com tabelas de hash. Isso pode economizar tempo e esforço na implementação e manutenção, se comparado à abordagem manual de implementar uma tabela de hash.


<h3><b>Vetores para Armazenamento de Stop Words e Heap</b></h3>

Vetores são utilizados para armazenar as "stop words" e também para criar um heap de palavras mais frequentes. As "stop words" são carregadas em um vetor chamado "stopWords" por meio da função "processStopWords". Isso permite que as "stop words" sejam consultadas de maneira eficiente quando se verifica se uma palavra encontrada é uma "stop word". Além disso, outro vetor chamado "heap" de pares (PAIR) é usado para manter as K palavras mais frequentes. 

<h3><b>Utilização de Heap para Manter as K Palavras Mais Frequentes:</b></h3>

O código implementa um heap de mínimo usando o vector "heap" para manter as K palavras mais frequentes. A função "addHeap" é responsável por manter o heap de tamanho K. Isso é alcançado por meio da função "heapify". Essas funções garantem que a palavra com a menor contagem esteja sempre no topo do heap, permitindo substituí-la por palavras mais frequentes à medida que elas são encontradas nos textos.


O código faz uso de uma estrutura de dados chamada "heap de mínimo" para manter as K palavras mais frequentes encontradas nos textos. Um heap de mínimo é uma estrutura de dados em forma de árvore onde o valor de cada nó é menor ou igual aos valores de seus nós filhos. Isso faz com que o menor valor esteja sempre na raiz do heap.

O heap implementado no código utiliza um vector chamado "heap" para armazenar as palavras e suas contagens. A função "addHeap" é responsável por manter o tamanho do heap limitado a K, garantindo que as palavras com as menores contagens estejam no topo. Isso é realizado por meio da função "heapify".

<h3><b>Expressões Regulares (Regex) para Processamento de Texto:</b></h3>

A expressão regular "wordRegex" é usada para identificar palavras nos textos. Ela considera caracteres alfanuméricos, incluindo letras maiúsculas e minúsculas, números e o caractere de apóstrofo, permitindo a extração de palavras válidas. Essa expressão regular é aplicada através do objeto "sregex_iterator" para encontrar todas as ocorrências de palavras em cada linha dos textos.

## 🔨 Funções 

- ```processStopWords:``` Durante a leitura do arquivo que contém as palavras de parada (stop words), elas são adicionadas a um vetor. Esse vetor é usado para comparação durante o processo de leitura do arquivo de entrada principal.

- ```processArq:```Esta função é responsável por abrir o arquivo de entrada contendo o texto para leitura. Cada palavra é lida usando a estrutura de expressões regulares (REGEX). Se uma palavra começar ou terminar com um hífen devido à formatação do texto, esses hífens são eliminados. Em seguida, a função "verifPalavra" é chamada para processar a palavra.

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

<h3><b>Entrada</b></h3>
<img src="imagens/entrada.jpg">

<h3><b>Saida</b></h3>
<img src="imagens/saida.jpg">


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
  * Terminal do Visual Studio, utilizando o compilador Mingw;
  * 12GB de RAM.
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
