# Corretor de Texto
<div style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div><br/>

# Apresentação do Problema 📝
<div align="justify">
  
A publicação de resultados de pesquisa é uma etapa essencial no processo científico, pois é através dessa publicação que o conhecimento é compartilhado com a comunidade acadêmica e com o público em geral. No entanto, para que essas publicações sejam efetivas, elas devem ser claras, precisas e livres de erros gramaticais e de ortografia. 

Infelizmente, muitos artigos acadêmicos sofrem de problemas de legibilidade e erros gramaticais e ortográficos. Isso não apenas dificulta a compreensão do trabalho por parte do leitor, mas também pode minar a credibilidade do autor e do trabalho em si. Afinal, se um autor não se preocupa o suficiente para garantir que seu trabalho esteja livre de erros simples, como podemos confiar em sua pesquisa e em suas conclusões? 

Assim, o objetivo deste trabalho é especificar, projetar e implementar um sistema que auxilie no processo de redação, particularmente no contexto da redação acadêmica. O sistema lê um arquivo de texto sem formatação, analisa o conteúdo e fornece feedback útil para o autor. Esse feedback pode incluir  estatísticas sobre o texto (como o número de palavras e sentenças), a identificação de erros ortográficos e gramaticais e a identificação de "stop words" - palavras que não têm conteúdo semântico e que podem ser removidas para tornar o texto mais claro e conciso.

</div>

# Implementação do Problema 💡

<div align="justify">

A solução proposta é baseada em um programa C++ que tem como objetivo principal analisar umarquivo de texto, considerando vários parâmetros. O arquivo de entrada são arquivos .txt com uma estrutura específica, onde cada sentença termina com um sinal de pontuação e cada parágrafo é separado por pelo menos uma linha em branco.

O nome do arquivo de entrada é dado pelo usuário. Os arquivos .txt com as expressões e com as stop words são definidas estaticamente no código e assume-se que estarão localizados no diretório raiz no
mesmo nível do arquivo main.

A análise é baseada principalmente em duas estruturas de dados principais: um vetor para armazenar as palavras de parada (stop words) e um mapa não ordenado (unordered_map) para armazenar informações sobre cada palavra no texto, como a frequência de sua ocorrência, linhas em que ocorre e a distância entre suas ocorrências no mesmo parágrafo.

A escolha dessas estruturas de dados foi baseada em suas propriedades e eficiência. O vetor é uma estrutura de dados linear que permite inserções eficientes no final e acesso direto a qualquer elemento. O mapa não ordenado é uma estrutura de dados de tabela hash, que permite inserções, buscas e remoções eficientes (em média, todas essas operações são O(1)).

O programa começa lendo as stop words de um arquivo específico (stopwords.txt) e armazenando-as no vetor stopWords. Em seguida, lê o arquivo de texto linha por linha usando a função analyzeText(). Se a linha não estiver vazia, ela será adicionada ao parágrafo atual e todas as palavras na linha (exceto stop words) serão adicionadas ao mapa wordInfo com suas informações atualizadas. Quando uma linha em branco é encontrada, isso indica o fim de um parágrafo e a função processParagraph() é chamada para processar o parágrafo atual.

</div>

# Análise de Complexidade 🔎

<div align="justify">
  
O principal algoritmo utilizado neste programa é o algoritmo de análise de texto. Este algoritmo tem uma complexidade de tempo O(n*m), onde n é o número de linhas no arquivo de texto e m é o número médio de palavras por linha. Isso se deve ao fato de que o algoritmo precisa percorrer todas as palavras em todas as linhas do texto. No entanto, a complexidade de tempo real pode ser menor devido ao fato de que muitas operações são realizadas em tempo constante devido ao uso do mapa não ordenado. 

O programa também usa o algoritmo de ordenação da biblioteca padrão C++ (std::sort) para ordenar as palavras em ordem alfabética no final da análise. A complexidade deste algoritmo é O(n log n), onde n é o número de palavras distintas no texto.

</div>

# Experimentação 🔬

<div align="justify">
	
Nesta seção, apresentamos os resultados de experimentos envolvendo três tipos de entradas diferentes: [<code>entrada.txt</code>](), [<code>entrada2.txt</code>](), [<code>entrada3.txt</code>](). O objetivo dos experimentos é comparar o desempenho e a eficácia desse algoritmo em diferentes tipos de entrada e diversos cenários, utilizando uma máquina com especificações definidas.

Os experimentos foram conduzidos em uma máquina com as seguintes especificações:

- Processador: Ryzen 5 5500;
- Memória RAM: 8 GB DDR4;
- Sistema Operacional: Ubuntu Linux;
- Linguagem de Programação: C++.

Para cada entrada, foram executadas 10 iterações utilizando com cada uma das entradas apresentadas. A entrada consiste em (...). Essa entrada foi mantida constante durante as iterações propostas para garantir a comparabilidade dos resultados. Durante cada iteração, o tempo de execução do algoritmo, a solução encontrada foi registrada em um arquivo <code>output.data</code>. Os resultados obtidos nos experimentos foram analisados com auxílio da tabela abaixo.

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
    <th align="center">Análise dos Parágrafos do Texto (s)</th>
    <th align="center">Análise dos Termos Não-Stop-Words (s)</th>
    <th align="center">Análise das Ocorrências de Expressões (s)</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td align="center">0.002492</td>
    <td align="center">0.001284</td>
    <td align="center">2.6e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td align="center">0.003912</td>
    <td align="center">0.001199</td>
    <td align="center">1.1e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td align="center">0.003998</td>
    <td align="center">0.001201</td>
    <td align="center">1.1e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">0.002420</td>
    <td align="center">0.001316</td>
    <td align="center">1.3e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td align="center">0.002625</td>
    <td align="center">0.001034</td>
    <td align="center">1.2e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td align="center">0.002595</td>
    <td align="center">0.001470</td>
    <td align="center">1.5e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td align="center">0.003787</td>
    <td align="center">0.001248</td>
    <td align="center">1.7e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td align="center">0.004253</td>
    <td align="center">0.001274</td>
    <td align="center">1.3e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">9</td>
    <td align="center">0.002500</td>
    <td align="center">0.001265</td>
    <td align="center">1.3e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">10</td>
    <td align="center">0.003926</td>
    <td align="center">0.001254</td>
    <td align="center">1.2e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">Média</td>
    <td align="center">0.00</td>
    <td align="center">0.00</td>
    <td align="center">0.00</td>
  </tr>
  <tr>
    <td align="center">Desvio Padrão</td>
    <td align="center">0.00</td>
    <td align="center">0.00</td>
    <td align="center">0.00</td>
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
    <th align="center">Análise dos Parágrafos do Texto (s)</th>
    <th align="center">Análise dos Termos Não-Stop-Words (s)</th>
    <th align="center">Análise das Ocorrências de Expressões (s)</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td align="center">0.002383</td>
    <td align="center">0.000965</td>
    <td align="center">6.0<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td align="center">0.003356</td>
    <td align="center">0.001253</td>
    <td align="center">7.0e<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td align="center">0.004961</td>
    <td align="center">0.001312</td>
    <td align="center">7.0<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">0.03833</td>
    <td align="center">0.001219</td>
    <td align="center">8.0e<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td align="center">0.003547</td>
    <td align="center">0.001221</td>
    <td align="center">7.0e<sup>-05</sup></td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td align="center">0.004578</td>
    <td align="center">0.001316</td>
    <td align="center">8.0e<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td align="center">0.004837</td>
    <td align="center">0.001253</td>
    <td align="center">6.0e<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td align="center">0.003222</td>
    <td align="center">0.001320</td>
    <td align="center">9.0e<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">9</td>
    <td align="center">0.003085</td>
    <td align="center">0.001251</td>
    <td align="center">8.0e<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">10</td>
    <td align="center">0.004562</td>
    <td align="center">0.001286</td>
    <td align="center">7.0e<sup>-06</sup></td>
  </tr>
  <tr>
    <td align="center">Média</td>
    <td align="center">0.00</td>
    <td align="center">0.00</td>
    <td align="center">0.00</td>
  </tr>
  <tr>
    <td align="center">Desvio Padrão</td>
    <td align="center">0.00</td>
    <td align="center">0.00</td>
    <td align="center">0.00</td>
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
    <th align="center">Análise dos Parágrafos do Texto (ms)</th>
    <th align="center">Análise dos Termos Não-Stop-Words (ms)</th>
    <th align="center">Análise das Ocorrências de Expressões (ms)</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td align="center">336.649</td>
    <td align="center">114.931</td>
    <td align="center">0.024</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td align="center">340.445</td>
    <td align="center">88.252</td>
    <td align="center">0.017</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td align="center">350.193</td>
    <td align="center">104.29</td>
    <td align="center">0.021</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">332.436</td>
    <td align="center">95.687</td>
    <td align="center">0.016</td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td align="center">354.738</td>
    <td align="center">106.540</td>
    <td align="center">0.019</td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td align="center">343.466</td>
    <td align="center">107.924</td>
    <td align="center">0.016</td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td align="center">340.969</td>
    <td align="center">104.928</td>
    <td align="center">0.019</td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td align="center">355.495</td>
    <td align="center">111.073</td>
    <td align="center">0.021</td>
  </tr>
  <tr>
    <td align="center">9</td>
    <td align="center">320.295</td>
    <td align="center">92.582</td>
    <td align="center">0.019</td>
  </tr>
  <tr>
    <td align="center">10</td>
    <td align="center">319.853</td>
    <td align="center">90.901</td>
    <td align="center">0.016</td>
  </tr>
  <tr>
    <td align="center">Média</td>
    <td align="center">339.148</td>
    <td align="center">101.781</td>
    <td align="center">0.018</td>
  </tr>
  <tr>
    <td align="center">Desvio Padrão</td>
    <td align="center">10.262</td>
    <td align="center">8.528</td>
    <td align="center">0.002</td>
  </tr>
</tbody>
</table>

<div align="justify">
	
Em resumo, (...)

</div>

# Conclusão 🎯

<div align="justify">
	
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
|  Eduardo               | <a href="https://t.me/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       | <a href="https://github.com/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>        
|  Ygor               | <a href="https://t.me/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       | <a href="https://github.com/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>
|  Gustavo               | <a href="https://t.me/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       | <a href="https://github.com/Lokinha92"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>  

</div>
