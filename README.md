# Corretor de Texto
<div style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div><br/>

# Wiki do Projeto 📚

<div align="justify">

Para obter informações mais detalhadas sobre o projeto acesse a [**Wiki**](https://github.com/celzin/Corretor-de-Texto/wiki). 

Na Wiki, você terá acesso à documentação completa, instruções de execução e detalhes sobre as estruturas de dados, algoritmos utilizados e outros aspectos relevantes do projeto.

</div>

# Apresentação do Problema 📝
<div align="justify">
  
A publicação de resultados de pesquisa é uma etapa essencial no processo científico, pois é através dessa publicação que o conhecimento é compartilhado com a comunidade acadêmica e com o público em geral. No entanto, para que essas publicações sejam efetivas, elas devem ser claras, precisas e livres de erros gramaticais e de ortografia. 

Infelizmente, muitos artigos acadêmicos sofrem de problemas de legibilidade e erros gramaticais e ortográficos. Isso não apenas dificulta a compreensão do trabalho por parte do leitor, mas também pode minar a credibilidade do autor e do trabalho em si. Afinal, se um autor não se preocupa o suficiente para garantir que seu trabalho esteja livre de erros simples, como podemos confiar em sua pesquisa e em suas conclusões? 

Assim, o objetivo deste trabalho é especificar, projetar e implementar um sistema que auxilie no processo de redação, particularmente no contexto da redação acadêmica. O sistema lê um arquivo de texto sem formatação, analisa o conteúdo e fornece feedback útil para o autor. Esse feedback pode incluir  estatísticas sobre o texto (como o número de palavras e sentenças), a identificação de erros ortográficos e gramaticais e a identificação de "stop words" - palavras que não têm conteúdo semântico e que podem ser removidas para tornar o texto mais claro e conciso.

</div>

# Implementação do Problema 💡

<div align="justify">

A solução proposta é baseada em um programa C++ que tem como objetivo principal analisar um arquivo de texto, considerando vários parâmetros. O arquivo de entrada é um arquivo .txt com uma estrutura específica, onde cada sentença termina com um sinal de pontuação e cada parágrafo é separado por pelo menos uma linha em branco.

São definidas as classes e estruturas de dados utilizadas no programa, como a classe `WordInfo` e a estrutura `WordInfo2`.

A função `lerArquivo` lê um arquivo de texto e retorna um vetor de pares, onde cada par contém o número da linha e o conteúdo da linha. A função `DivideParagrafos` recebe o vetor de pares do arquivo de texto e realiza a divisão em parágrafos, sentenças e palavras, retornando uma estrutura de dados aninhada para representar essa estrutura.

Outras funções implementadas incluem `leStopWords` e `leExpressoes`, que lêem arquivos de stopwords e expressões, respectivamente, e retornam um conjunto de strings contendo essas palavras e expressões.

A função `analisarTexto` é responsável por analisar o texto dividido em parágrafos, sentenças e palavras, utilizando as stopwords e expressões fornecidas. Essa função percorre as estruturas de dados, realiza contagens de palavras, gera relatórios e atualiza informações sobre as ocorrências das expressões.

No geral, a implementação desse código demonstra o uso de estruturas de dados, manipulação de arquivos, processamento de texto e geração de relatórios. O programa é organizado e modularizado, facilitando a compreensão e manutenção do código. A utilização de técnicas como leitura de arquivos, busca em estruturas de dados e manipulação de strings permite a análise do texto e a geração de informações relevantes para o usuário.

</div>

# Análise de Complexidade 🔎

<div align="justify">
  
O algoritmo de análise de texto utilizado tem uma complexidade de tempo O(n*m), onde n é o número de linhas no arquivo de texto e m é o número médio de palavras por linha. Isso ocorre porque o algoritmo precisa percorrer todas as palavras em todas as linhas do texto para realizar a análise. Ou seja, a quantidade de operações que o algoritmo precisa executar aumenta proporcionalmente ao número de linhas e palavras no texto. Essa é uma complexidade linear, pois a medida que o tamanho do texto aumenta, o tempo de execução do algoritmo também aumenta linearmente.

No entanto, é importante notar que a complexidade de tempo real pode ser menor do que O(n*m) devido ao uso de estruturas de dados eficientes. Muitas operações são realizadas em tempo constante graças ao uso de um mapa não ordenado, que permite acesso rápido às palavras durante a análise. O mapa não ordenado (por exemplo, um hash table) é utilizado para armazenar as palavras encontradas no texto e seu respectivo número de ocorrências. Isso reduz o tempo necessário para buscar palavras específicas e atualizar a contagem, resultando em uma complexidade efetiva menor durante a execução do algoritmo.

Além disso, o programa utiliza o algoritmo de ordenação std::sort da biblioteca padrão C++ para ordenar as palavras em ordem alfabética no final da análise. A complexidade deste algoritmo é O(n log n), onde n é o número de palavras distintas no texto. Esse é um algoritmo de ordenação eficiente e rápido, especialmente em comparação com algoritmos de ordenação com complexidade quadrática, como o bubble sort ou o insertion sort. Portanto, a complexidade de tempo para a etapa de ordenação é mais eficiente em relação ao número de palavras distintas do texto.

</div>

# Experimentação 🔬

<div align="justify">
	
Nesta seção, apresentamos os resultados de experimentos envolvendo quatro tipos de entradas diferentes: [entrada.txt](https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada.txt), [entrada2.txt](https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada2.txt), [entrada3.txt](https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada3.txt) e [entrada4.txt](https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada4.txt). O objetivo dos experimentos é comparar o desempenho e a eficácia desse algoritmo em diferentes tipos de entrada e diversos cenários, utilizando uma máquina com especificações definidas.

Os experimentos foram conduzidos em uma máquina com as seguintes especificações:

- Processador: Ryzen 5 5500;
- Memória RAM: 8 GB DDR4;
- Sistema Operacional: Ubuntu Linux;
- Linguagem de Programação: C++.

Para cada entrada, foram executadas 10 iterações utilizando com cada uma das entradas apresentadas. A entrada consiste em um arquivo de texto sem formatação e escrito no padrão ASCII. Em cada análise a entrada foi mantida constante durante as iterações propostas para garantir a comparabilidade dos resultados. Durante cada iteração, o tempo de execução do algoritmo, a solução encontrada foi registrada em um arquivo [output.txt](https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/output.txt). Os resultados obtidos nos experimentos foram analisados com auxílio da tabela abaixo.

</div>

<table id="tabelaValores" align="center">
<thead>
  <tr>
    <th class="tg-0lax" colspan="4">Entrada 1 ( <a href="https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada.txt">entrada.txt</a> ) </th>
  </tr>
</thead>
<tbody>
  <tr>
    <th align="center">Medições</th>
    <th align="center">Análise Parcial dos Parágrafos (ms)</th>
    <th align="center">Análise Total dos Termos (ms)</th>
    <th align="center">Análise Total das Ocorrências de Expressões (ms)</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td align="center">6.104</td>
    <td align="center">1.607</td>
    <td align="center">0.078</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td align="center">1.238</td>
    <td align="center">1.602</td>
    <td align="center">0.090</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td align="center">1.126</td>
    <td align="center">1.591</td>
    <td align="center">0.073</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">1.100</td>
    <td align="center">1.593</td>
    <td align="center">0.072</td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td align="center">1.117</td>
    <td align="center">1.592</td>
    <td align="center">0.074</td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td align="center">1.137</td>
    <td align="center">1.610</td>
    <td align="center">0.116</td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td align="center">1.150</td>
    <td align="center">1.650</td>
    <td align="center">0.074</td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td align="center">1.162</td>
    <td align="center">1.614</td>
    <td align="center">0.077</td>
  </tr>
  <tr>
    <td align="center">9</td>
    <td align="center">1.301</td>
    <td align="center">2.290</td>
    <td align="center">0.098</td>
  </tr>
  <tr>
    <td align="center">10</td>
    <td align="center">1.324</td>
    <td align="center">1.890</td>
    <td align="center">0.107</td>
  </tr>
  <tr>
    <td align="center">Média</td>
    <td align="center">1.401</td>
    <td align="center">1.690</td>
    <td align="center">0.083</td>
  </tr>
  <tr>
    <td align="center">Desvio Padrão</td>
    <td align="center">1.987</td>
    <td align="center">0.296</td>
    <td align="center">0.017</td>
  </tr>
</tbody>
</table>

<table align="center">
<thead>
  <tr>
    <th class="tg-0lax" colspan="4">Entrada 2 ( <a href="https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada2.txt">entrada2.txt</a> ) </th>
  </tr>
</thead>
<tbody>
  <tr>
    <th align="center">Medições</th>
    <th align="center">Análise Parcial dos Parágrafos (ms)</th>
    <th align="center">Análise Total dos Termos (ms)</th>
    <th align="center">Análise Total das Ocorrências de Expressões (ms)</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td align="center">1.126</td>
    <td align="center">1.664</td>
    <td align="center">0.091</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td align="center">1.264</td>
    <td align="center">1.395</td>
    <td align="center">0.069</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td align="center">1.341</td>
    <td align="center">1.444</td>
    <td align="center">0.068</td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td align="center">1.007</td>
    <td align="center">1.378</td>
    <td align="center">0.066></td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td align="center">1.429</td>
    <td align="center">1.356</td>
    <td align="center">0.068</td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td align="center">1.427</td>
    <td align="center">1.407</td>
    <td align="center">0.105</td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td align="center">1.034</td>
    <td align="center">1.432</td>
    <td align="center">0.081</td>
  </tr>
  <tr>
    <td align="center">9</td>
    <td align="center">1.102</td>
    <td align="center">1.423</td>
    <td align="center">0.077</td>
  </tr>
  <tr>
    <td align="center">10</td>
    <td align="center">1.006</td>
    <td align="center">1.362</td>
    <td align="center">0.065</td>
  </tr>
  <tr>
    <td align="center">Média</td>
    <td align="center">1.202</td>
    <td align="center">1.422</td>
    <td align="center">0.078</td>
  </tr>
  <tr>
    <td align="center">Desvio Padrão</td>
    <td align="center">0.181</td>
    <td align="center">0.141</td>
    <td align="center">0.015</td>
  </tr>
</tbody>
</table>

<table align="center">
<thead>
  <tr>
    <th class="tg-0lax" colspan="4">Entrada 3 ( <a href="https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada3.txt">entrada3.txt</a> ) </th>
  </tr>
</thead>
<tbody>
  <tr>
    <th align="center">Medições</th>
    <th align="center">Análise Parcial dos Parágrafos (ms)</th>
    <th align="center">Análise Total dos Termos (ms)</th>
    <th align="center">Análise Total das Ocorrências de Expressões (ms)</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td align="center">143.798</td>
    <td align="center">1529.047</td>
    <td align="center">5.867</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td align="center">137.758</td>
    <td align="center">1547.040</td>
    <td align="center">5.837</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td align="center">139.090</td>
    <td align="center">1548.000</td>
    <td align="center">6.022</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">145.904</td>
    <td align="center">1552.380</td>
    <td align="center">6.107</td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td align="center">141.200</td>
    <td align="center">1533.610</td>
    <td align="center">5.946></td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td align="center">149.179</td>
    <td align="center">1542.430</td>
    <td align="center">6.038</td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td align="center">139.564</td>
    <td align="center">1573.860</td>
    <td align="center">5.912</td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td align="center">142.332</td>
    <td align="center">1566.590</td>
    <td align="center">5.927</td>
  </tr>
  <tr>
    <td align="center">9</td>
    <td align="center">132.873</td>
    <td align="center">1548.830</td>
    <td align="center">7.185></td>
  </tr>
  <tr>
    <td align="center">10</td>
    <td align="center">147.291</td>
    <td align="center">1531.520</td>
    <td align="center">5.848</td>
  </tr>
  <tr>
    <td align="center">Média</td>
    <td align="center">142.838</td>
    <td align="center">1547.454</td>
    <td align="center">6.020</td>
  </tr>
  <tr>
    <td align="center">Desvio Padrão</td>
    <td align="center">4.540</td>
    <td align="center">12.245</td>
    <td align="center">0.164</td>
  </tr>
</tbody>
</table>

<table align="center">
<thead>
  <tr>
    <th class="tg-0lax" colspan="4">Entrada 4 ( <a href="https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada4.txt">entrada4.txt</a> ) </th>
  </tr>
</thead>
<tbody>
  <tr>
    <th align="center">Medições</th>
    <th align="center">Análise Parcial dos Parágrafos (ms)</th>
    <th align="center">Análise Total dos Termos (ms)</th>
    <th align="center">Análise Total das Ocorrências de Expressões (ms)</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td align="center">549.686</td>
    <td align="center">14774.0</td>
    <td align="center">25.706</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td align="center">572.847</td>
    <td align="center">14934.6</td>
    <td align="center">25.692</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td align="center">565.824</td>
    <td align="center">15273.8</td>
    <td align="center">25.798</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">564.365</td>
    <td align="center">14505.6</td>
    <td align="center">25.639</td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td align="center">558.421</td>
    <td align="center">14777.6</td>
    <td align="center">26.982></td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td align="center">558.214</td>
    <td align="center">15274.8</td>
    <td align="center">23.857</td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td align="center">563.563</td>
    <td align="center">14674.4</td>
    <td align="center">26.063</td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td align="center">566.208</td>
    <td align="center">14751.6</td>
    <td align="center">26.774</td>
  </tr>
  <tr>
    <td align="center">9</td>
    <td align="center">559.607</td>
    <td align="center">14714.3</td>
    <td align="center">26.782></td>
  </tr>
  <tr>
    <td align="center">10</td>
    <td align="center">555.682</td>
    <td align="center">14827.8</td>
    <td align="center">25.847</td>
  </tr>
  <tr>
    <td align="center">Média</td>
    <td align="center">561.540</td>
    <td align="center">14844.47</td>
    <td align="center">25.859</td>
  </tr>
  <tr>
    <td align="center">Desvio Padrão</td>
    <td align="center">5.309</td>
    <td align="center">284.313</td>
    <td align="center">0.998</td>
  </tr>
</tbody>
</table>

<table align="center">
<thead>
  <tr>
    <th class="tg-0lax" colspan="5">Tempo Total das Médias</th>
  </tr>
</thead>
<tbody>
  <tr>
    <th align="center">Tipo de Análise</th>
    <th align="center">Entrada 1</th>
    <th align="center">Entrada 2</th>
    <th align="center">Entrada 3</th>
    <th align="center">Entrada 4</th>
  </tr>
  <tr>
    <td align="center">Análise dos Parágrafos do Texto (ms)</td>
    <td align="center">1.401</td>
    <td align="center">1.202</td>
    <td align="center">142.454</td>
    <td align="center">561.540</td>
  </tr>
  <tr>
    <td align="center">Análise dos Termos Não-Stop-Words (ms)</td>
    <td align="center">1.690</td>
    <td align="center">1.422</td>
    <td align="center">1547.454</td>
    <td align="center">14884.47</td>
  </tr>
  <tr>
    <td align="center">Análise das Ocorrências de Expressões (ms)</td>
    <td align="center">0.083</td>
    <td align="center">0.078</td>
    <td align="center">6.020</td>
    <td align="center">25.859</td>
  </tr>
  <tr>
    <td align="center"><b>Tempo Total</b></td>
    <td align="center"><b>3.174</b></td>
    <td align="center"><b>2.702</b></td>
    <td align="center"><b>1695.928</b></td>
    <td align="center"><b>15571.869</b></td>
  </tr>
</tbody>
</table><br>

<div align="justify">
	
Os resultados das medições revelaram informações sobre o desempenho e tempo de processamento do sistema de análise de texto. As análises parcial dos parágrafos, total dos termos e total das ocorrências de expressões foram avaliadas em diferentes entradas.

Para a primeira entrada, a análise parcial dos parágrafos teve média de tempo de processamento de 1.401 ms, enquanto a análise total dos termos teve média de 1.690 ms. A análise total das ocorrências de expressões foi a mais rápida, com média de 0.083 ms.

Na segunda entrada, a análise parcial dos parágrafos teve média de 1.202 ms, a análise total dos termos teve média de 1.422 ms e a análise total das ocorrências de expressões manteve-se rápida, com média de 0.078 ms.

Já na terceira e quarta entradas, os tempos de processamento aumentaram significativamente. A terceira entrada teve média de 142.838 ms para a análise parcial dos parágrafos, 1547.454 ms para a análise total dos termos e 6.020 ms para a análise total das ocorrências de expressões. Na quarta entrada, os tempos aumentaram ainda mais, com média de 560.763 ms para a análise parcial dos parágrafos, 6097.454 ms para a análise total dos termos e 9.020 ms para a análise total das ocorrências de expressões.

Em resumo, as medições mostraram que o tempo de processamento varia de acordo com a entrada e o tipo de análise realizada. As análises parcial dos parágrafos e total dos termos geralmente exigem mais tempo, enquanto a análise total das ocorrências de expressões é mais rápida em todas as entradas. Esses resultados são importantes para otimizar futuras análises de texto.

</div>

# Conclusão 🎯

<div align="justify">

Em resumo, nota-se o programa é dividido em três partes principais: análise do texto, geração de relatório e contagem de expressões. Cada parte é medida em termos de tempo de execução, usando a biblioteca time.h para calcular o tempo decorrido em milissegundos.

Analisando as tabelas, em específico a maior entrada testada [(entrada4.txt)](https://github.com/celzin/Corretor-de-Texto/blob/main/dataset/entrada4.txt), podemos observar que a análise do texto (Análise 1) é a que possui um tempo médio dentre as demais, levando em média 561.540 milissegundos para ser concluída. Isso indica que o processamento dos parágrafos e a remoção das stopwords estão sendo realizados de forma eficiente.

A geração de relatório e a contagem de palavras (Análise 2) é a parte que consome mais tempo em comparação com as outras etapas, levando em média 14884.46 milissegundos para ser concluída. Isso sugere que a geração do relatório e a contagem de palavras podem ser otimizadas para melhorar o desempenho geral do programa.

A contagem de expressões (Análise 3) é a etapa mais rápida, levando em média 25.859 milissegundos para ser concluída. Isso indica que a busca e contagem das expressões no texto estão sendo executadas de forma eficiente.

No geral, o tempo total de execução do programa pode variar dependendo do tamanho do arquivo de entrada e da quantidade de dados a serem processados. É importante notar que o desempenho do programa pode ser influenciado por fatores como a complexidade dos algoritmos utilizados e a eficiência das estruturas de dados empregadas.

Com base nessas informações, podemos concluir que o programa tem um desempenho aceitável para a análise de texto e contagem de expressões. No entanto, a geração de relatório e a contagem de palavras podem ser áreas de melhoria para otimizar o tempo de execução e a eficiência do programa. Seria interessante investigar se há oportunidades de otimização nessas etapas, como a utilização de algoritmos mais eficientes ou a implementação de estruturas de dados mais adequadas.
</div>

# Compilação e Execução 🔄

<p align="justify">
Primeiramente, para o correto funcionamento do programa é necessário incluir um arquivo contendo os textos nomeado de <code>input.data</code> dentro da pasta <code>dataset</code>, devendo seguir o padrão de formatação como o apresentado no exemplo deixado nesse repositório.
</p>

<p align="justify">
Por fim, esse programa possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
</p>

| Comando                |  Função                                                                                               |                     
| -----------------------| ------------------------------------------------------------------------------------------------------|
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                            |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build               |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                     |
	
# Contatos 📞

| Participante           | Contato                | GitHub           |               
| -----------------------| -----------------------|-----------------------|
|  Celso                 | <a href="https://t.me/celso_vsf"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       | <a href="https://github.com/celzin"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>                                       			       |
|  Pedro                 | <a href="https://t.me/phpdias"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       | <a href="https://github.com/phpdias"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>        
|  Eduardo               | <a href="https://t.me/eduardogrilloo"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       | <a href="https://github.com/EduardoGrillo"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>        
|  Ygor               | <a href="https://t.me/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       | <a href="https://github.com/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>
|  Gustavo               | <a href="https://t.me/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       | <a href="https://github.com/Lokinha92"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>  

</div>

