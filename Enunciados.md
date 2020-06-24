# Enunciados:

## Observação: Para todos os exercícios, faça o diagrama de classes UML e compile usando o Meson (ou outro sistema de build)

## Ex 1 - Desenhar na tela: 

### Crie um programa com uma classe principal com os seguintes atributos:
  1. uma janela do SFML
  2. um objeto de uma classe Personagem
    
### e os seguintes métodos:
  3. construtor
  4. destrutor
  5. metodo rodar, que chama o metodo atualizar e desenhar do Personagem em loop 

### e a classe Personagem com os seguintes atributos:
  1. um sf::Texture com a textura do personagem
  2. um sf::RectShape para desenhar o personagem
  3. duas variáveis float para a posição do Personagem

### e os seguintes métodos:
  4. Construtor, que precisa de uma posição inicial, de uma string dizendo o caminho para a textura a usar
  5. Destrutor, que desaloca a textura
  6. método atualizar, que muda o valor da posição
  7. Método desenhar, que desenha a textura na posição e precisa de um ponteiro pra sf::RenderWindow como parâmetro

## as duas classes devem ser colocadas em um namespace chamado exercicio.

## Ex 2 - Múltiplos personagens sendo utilizados:

### Crie uma classe ListaPersonagens:
  1. Duplamente encadeada
  2. com funções para percorrer a lista, adicionar ao fim, e esvaziar a lista 

### Modifique a classe Personagem para:
  1. a posição do personagem ser representada por um objeto sf::Vector2f, e exista um objeto sf::Vector2f representando sua velocidade;
  2. a função "atualizar" de personagem receba um valor de tempo em segundos, e atualize a posição do personagem de acordo com sua velocidade e o tempo passado;

### Modifique a classe Principal para:
  1. Ela possuir uma lista de Personagens, cada um com uma velocidade diferente, e atualize e desenhe todos
  2. Ela verificar se um evento de fechar a janela aconteceu, e, se sim, terminar

## Ex 3 - Gerenciador Gráfico desacoplado - V1:

### Observação:
#### Essa é uma de inúmeras maneiras de resolver esse problema, e não tem nada errado com usar a biblioteca diretamente. Entretanto, posso garantir que o uso de uma classe como essa irá fazer seu código mais claro e desacoplado, além de já basicamente deixar tudo relacionado ao SFML pronto desde o início (se combinada com um gerenciado de eventos também desacoplado).

Antes de tudo, como queremos desacoplar o máximo possível o programa da biblioteca usada, precisamos de uma modelo para substituir sf::Vector2. Por isso, criaremos nossa própria classe vetor como modelo!

### Crie uma classe modelo Vetor2D que representa um vetor/ponto em R² (R2). Ela deve ter:
  1. Operador de soma
  2. Operador de subtração
  3. Operador de multiplicação por escalar (3 métodos: com int, float e double)
  4. Operador de divisão por escalar (idem)
  5. Produto escalar
  6. Método retornando seu módulo
  7. Método retornando seu versor
  8. Método para realizar projeções ortogonais

### Pode parecer exagero, mas muitos desses métodos serão úteis.


### Crie uma classe GerenciadorGrafico que possui os seguintes atributos:

  1. uma sf::RenderWindow agregada por ponteiro;
  2. um sf::view, representando a parte da janela mostrada;
  3. um std::map<std::string, sf::Texture*>, que será usada para armazenar todas as texturas usadas (a chave será o caminho para a imagem em questão, que deverá ficar armazenada no objeto que precisa daquela textura);

### e os seguintes métodos:

  1. mostrar(), que simplesmente chamará o método display da RenderWindow;
  2. limpar(int r, int g, int b), que limpa a tela para a cor passada como argumento;
  3. um método bool carregarTextura(), que recebe uma string representando o caminho no sistema de arquivos para a imagem à carregar, a carrega e guarda no mapa, retornando se houve sucesso no carregamento;
  4. um método desenhar(), que recebe uma string (o caminho usado no método carregar) e um Vetor2D que representa a posição na tela para desenhar;
  5. Um método centralizar(), que recebe um Vetor2D e centraliza a tela nele.

### OBSERVAÇÃO 2:
#### Por enquanto, essa classe não saberá lidar com a tela ser redimensionada, e não fará animações.

## Ex 4 - Gerenciador de eventos:
  
 Primeiro de tudo, para esse tutorial, será importante ter classes com comportamentos diferentes, mas q precisem de eventos.
  
Por isso, mudaremos Personagem para Desenhavel, e tornaremos todos os métodos virtuais, além de adicionar mais um método virtual que recebe umo objeto 
da classe classe sf::Event chamado tratarEvento. Criaremos, então, duas classes derivadas: Inimigo, que na verdade manterá o comportamento da classe Personagem anterior, e Heroi, que se moverá de acordo com os botões do teclado.

Mas antes tinhamos uma lista de personagens, e agora temos uma de Desenhaveis! Por isso, transformaremos a lista antiga em um modelo, e criaremos uma classe lista desacoplada ListaDesenhaveis.

Iremos agora criar um gerenciador de eventos usando recursos do C++ moderno, nomeadamente, a classe std::function, que permite tratar uma função como objeto.

### Então, para começar:

  1. Transforme a classe Personagem em uma classe Desenhavel com todos os métodos virtuais
  2. Crie duas classes derivadas, Inimigo, com o mesmo comportamento de antes, e Heroi, que se moverá com os botões do teclado usando o gerenciador de eventos
  3. Transforma a ListaPersonagens em uma classe modelo Lista, e crie uma classe nova ListaDesenhaveis que agrega uma Lista<Desenhavel> e possui as funções específicas para Desenhaveis que existiam na ListaPersonagens antiga específicas para Desenháveis (atualizarPersonagens, desenharPersonagens, inicializarPersonagens, etc.)
  4. Adicione um método sf::RenderWindow* getJanela() const; à classe GerenciadorGrafico, que dá acesso ao ponteiro para sf::RenderWindow.
   
### Crie uma classe GerenciadorEventos com os seguintes atributos:

  1. um campo estático int chamado ProximoId;
  2. um ponteiro para sf::RenderWindow, que será usado para acessar o método pollEvent;
  3. três mapas std::map<int, std::function<void(sf::Event)>> (leia o segundo argumento como "funções com parametro sf::Event e retorno void"), um para eventos relacionados ao mouse, outro para eventos relacionados ao teclado e o último para outros (como o evento de fechar a janela, por exemplo).
  4. crie um método setJanela para inicializar o valor do atributo sf::RenderWindow*
  
  5. crie três pares de métodos:
    1. int adicionarOuvinte_____(std::function<void(Event)> chamada);
    2. void removerOuvinte_____(int id);

substituindo os _____ por Teclado, Mouse e Outros. Basicamente, se um objeto precisa saber quando um evento ocorre, chamará o método apropriado acima e retornará ID único. Se o objeto não precisar mais ouvir esse evento, pode chamar o método de remoção passando esse id.

## Ex 5 - Gerenciador de Colisões

Um gerenciador de Colisões é uma classe que determina se cada par de "seres que precisam colidir", como personagens e inimigos ou personagens e o cenário, estão colidindo. Para isso funcionar, precisamos fazer algumas modificações nas classes criadas anteriormente.

  1. Crie uma novo arquivo .hpp que inclua a declaração um enum chamado "IdsDesenhaveis" com cada tipo de Desenhavel (no nosso caso, até agora, temos apenas o Heroi e o Vilao).
  2. Na classe GerenciadorGrafico, crie um método getTamanho() que toma como parâmetro uma string e retorna as dimensões (como Vetor2F) da textura correspondente.
  3. Na classe Desenhavel, adicione um campo do tipo IDsDesenhaveis chamado "id", que usaremos para diferenciar com qual outro tipo de Desenhavel uma entidade está colidindo (e pode ser útil no futuro tbm)
  4. Na classe Desenhavel, adicione um campo dimensões (Vetor2F), que deve ser inicializado por chamada à GerenciadorGrafico::getDimensoes(). Adicione também um método getDimensoes().
  5. Na classe Desenhavel, faça o método inicializar receber também uma referência escondida para GerenciadorColisoes, e também atualize a ListaPersonagens adequadamente.
  6. Crie uma classe derivada de Desenhavel chamada "Colidivel", com método virtual puro colidir, que será chamada quando este Colidivel colidir com outro. Ele recebe como parametros o id, posicao e tamanho do outro Colidivel. As classes Heroi e Vilao devem agora estender Colidivel, e o método colidir nas duas deve ser escrito de forma à dar algum comportamento para os objetos das duas classes quando colidem entre si (para Vilao) e com a outra (Vilao com Heroi e Heroi com Vilao)
  
Com essas modificações feitas, podemos trabalhar na nova Classe. Crie uma classe GerenciadorColisoes que possua os seguintes atributos:
  1.  Um std::set<Colidivel*>, onde armazenaremos todos os Colidiveis administrados por essa classe
e os seguintes métodos:
  2. Um construtor vazio.
  3. Um destrutor vazio.
  4. Um método adicionarColidivel(), que recebe um ponteiro para Colidivel e o adiciona no vetor.
  5. Um método removerColidivel(), que recebe um ponteiro para Colidivel e, se ele já exister no vetor, o remove.
  6. Um método removerTodos(), que esvazia o vetor de colidiveis.
  7. Um método verificarColisoes(), que irá efetivamente verificar se houve colisões
  8. Um método privado estaoColidindo() que recebe dois ponteiros para Colidivel e retorna um valor booleano dizendo se eles estão colidindo.

Um objeto dessa classe deve ser agregado na classe Principal, e o método verificarColisoes deve ser chamado dentro do loop em rodar().

## Ex 6 - TileMap 

Tilemap é uma técnica para desenho de mapas em jogos onde muitas partes do cenário se repetem, e são úteis por economizarem memória e serem 
mais fáceis de modificar. Basicamente, ao invés de ter uma imagem enorme com todo o mapa do nível, você tem várias imagens representando os
pedacinhos que se repetem (uma para um pedaçinho de areia, água, grama, uma armadilha, etc.) e um arquivo com uma matriz onde cada índice representa uma das diferentes imagens.

Para implementar isso, precisaremos criar três classes:

## classe Tilemap : 

obs: short é uma versão mais curta de um inteiro, ocupando menos espaço na memória.

Uma classe que cuida de carregar o mapa da memória e de permitir fácil acesso à ele. 
Ela exige a seguinte classe aninhada:

  ### classe LinhaTileMap
  que deverá ter:
   1. Um construtor que toma como parâmetros um ponteiro para const unsigned short e um unsigned int que representa o comprimento da linha
   2. Uma sobrecarga do operador de colchetes que retorna o valor naquela posição da linha. 

E precisa dos seguintes atributos:
  1. Um Vetor2U chamado dimensoesMapa;
  2. Um ponteiro para ponteiro de unsigned short (que armazenará a matriz);
  3. Um const char* chamado caminho, que armazena o caminho para o mapa carregado;

E os seguintes métodos:
  1. Um construtor que toma como parâmetros um caminho para arquivo;
  2. Um destrutor, que desalocará o mapa;
  3. um método privado carregarMapa(), que é chamado no construtor;
  4. Um método getDimensoesMapa() const;
  5. Um método imprimirMapa() const, que imprime a matriz no terminal (para debug);
  6. Um método setTile, que toma como parâmetros um Vetor2U representando uma posição no mapa e um unsigned short representando o novo código a ser armazenado naquela posição;
  7. Uma sobrecarga do operador de colchetes que retorna um LinhaTileMap que aponta para a linha da matriz desejada.


## Classe Tile :
  Uma classe que representa um tipo de Tile (sim, uma só instância para todas as repetições do tile). 

  Como essa classe também exige Ids que possam ser comparados com Ids de desenhaveis, modifique o nome do arquivo, enum e namespace IdDesenhaveis para Ids.

Ela possui os seguintes atributos:
  1. Um Ids::Ids ID (como o ID da classe Desenhavel)
  2. Um const char* caminho para a imagem que deverá ser carregada
  3. Um Vetor2F representando seu tamanho
  4. Uma referência escondida para o GerenciadorGrafico, usada para desenhar a classe;
e os seguintes métodos:
  1. Um construtor, que toma como parâmetros um id, um caminho e um tamanho;
  2. um destrutor vazio;
  3. Uma função virtual inicializar, que toma como parâmetro uma referência escondida para o GerenciadorGrafico
  4. Um método desenhar() constante que toma como parãmetro a posição onde ela deve ser desenhada
  5. Um método getId;
  6. Um método virtual colidir(), que recebe o Id e a posição do que colidiu com o tile, mas também a posição do tile que colidiu.


## Classe GerenciadorTiles :

Uma classe que gerenciará o Tilemap, os Tiles, e, no futuro, calculará as colisões dos outros colidíveis com o Mapa. 

Defina uma struct IdPosicaoTamanho com os seguintes campos (que será o tipo de retorno de checarColisoes):
  1. um unsigned short, que representa o id do tile que colidiu com o Colidivel passado para a função;
  2. Um Vetor2F representando a posição do centro do tile;
  3. Um vetor2F representando as dimensões do tile;

Ela precisará dos seguintes atributos:
  1. Um TileMap;
  2. Um Vetor2F dimensoesTiles, que precisa ser igual às dimensões das imagens;
  3. Um const char* caminho, que representa o caminho até o arquivo do tileMap;
  4. Um std::vector<Tile> com os Tiles utilizados

e dos seguintes métodos:
  1. Um construtor, que toma como parâmetros um std::vector<Tile>, um Vetor2F representando as dimensões dos tiles, e o caminho para o arquivo do TileMap;
  2. Um destrutor;
  3. Uma sobrecarga do update() de Desenhavel que não faz nada, pois a classe não precisa ser atualizada (uma alternativa melhor seria restruturar um pouco as classes)
  4. Uma sobrecarga do inicializar de Desenhavel, que inicializa os Tiles no vector;
  5. Uma sobrecarga do desenhar() de Desenhavel
  6. Um método checarColisoes() que recebe a posição, tamanho e Id de alguma objeto e retorna um std::vector<IdPosicaoTamanho> que descreve todos os tiles com o qual aqule Colidivel colidiu (se isso acontecer).

## Ex 6.5 - Animações 

Crie na classe GerenciadorGrafico uma sobrecarga de método da função desenhar que, além dos dois primeiros parâmetros,
toma também dois Vetor2U, o primeiro representando o número de frames em uma textura, e o segundo qual frame desejamos desenhar.

## Ex 7 - Padrões de projeto: Estado e pilha de Estados

Um padrão de projeto é, bem, um padrão usado em projetos. Basicamente, a ideia é que muitos problemas que surgem em programas são parecidos com outros, e, para resolvê-los, foram criados padrões que, com algumas adaptações, resolvem esses problemas. 
Um deles, muito útil para jogos, é o padrão de projeto "Estado". A idéia dele é permitir que um objeto tenha comportamentos diferentes de acordo com seu estado interno.
Por exemplo, você poderia usar um bloco switch-case para determinar qual fase ou menu do seu jogo precisa ser carregada, mas isso é altamente acoplado e difícil de manter. Com o padrão de projeto de Estado, você precisa apenas mudar o estado interno do objeto para o comportamento mudar.

São necessários (no mínimo) 3 classes para implementar esse padrão de projeto: 
Um contexto, que é a classe do objeto que precisa variar seu comportamento (no nosso caso, o próprio jogo)
Uma classe abstrata Estado, que declara os métodos que precisam ser implementados em cada estado.
Uma ou várias implementações de Estado, que representam cada estado interno possível do contexto.

Um exemplo menos abstrato, no contexto do jogo, seria ter como Contexto a classe Principal, e como implementações de Estado coisas como MenuPrincipal, MenuPausa, FaseFloresta, FaseCaverna, etc.

Além de usar esse padrão de projetos, colocaremos os estados atuais do jogo em uma pilha. Isso quer dizer que, quando quisermos entrar em um menu de pausa, só temos que adicionar o estado do Menu na pilha, e quando quisermos sair do menu, é só tirar o estado da pilha.

Portanto, criaremos 4 classes:

## Classe Estado
  Essa classe abstrata terá um método virtual puro "executar" que retorna um membro de um Enum codigoRetorno que identifica se a pilha de estados deve mudar (por exemplo, tirar aquele estado da pilha, colocar outro por cima, tirar esse estado e o de baixo, etc.). Em princípio, terá como atributo apenas uma referẽncia para o GerenciadorGrafico.

## Classe GerenciadorEstado.
  Essa classe inclui os seguintes atributos:
  1. Uma std::stack privada de ponteiros para objetos de Estados

  E os seguintes métodos:
  1. construtor e destrutor
  2. método protegido pushEstado(), que recebe um ponteiro para estado e o coloca na pilha
  3. método protegido popEstado(), que tira o estado do topo da pilha
  4. método protegido esvaziaPilha(), que tem como parâmetro opcional um ponteiro para Estado. Esse método esvazia a pilha, e, se um ponteiro não-nulo for passado, o adiciona à pilha.
  5. método público executar(), que retorna um valor booleano (que representa se o programa deve terminar de executar) e chama o método executar do Estado no topo da pilha
  6. método público virtual puro inicializar(), que carrega o estado inicial da pilha
  7. método protegido virtual puro processarCodigo(), que recebe um enum codigoRetorno e manipula a pilha de acordo com o código (por exemplo, com um código "trocarFase", tiraria a fase atual da pilha e empurraria a próxima).

Além disso, criaremos implementações dessas duas classes, simplesmente adequando as funcionalidades já existentes do programa para esse novo modelo.

## Ex 8a -  Menus e Elementos de Menu - 1 : Botões
  Um dos vários requisitos do jogo é a implementação de, no mínimo, um menu principal e um de pausa. iremos criar menus com botões e entrada de texto, cujos botões podem ser selecionados com o  mouse, e entrada do texto suportando letras, números e espaços. Para isso, serão necessárias modificações no gerenciador gráfico. Antes disso, criaremos uma pequena classe ajudante:

  Crie uma classe Cor, com:
  Os seguintes atributos:
  1. 4 unsigned char (vulgo um valor entre 0 e 255) chamados r, g, b, a PUBLICOS 
  e os seguintes métodos:
  1. Um construtor, com todos os parametros opcionais (note que o valor padrão de 'a' deveria ser 255, pois o valor de alpha ser 0 significa uma cor transparente)

  Com isso fora do caminho, podemos continuar.
  
  No gerenciador gráfico, adicione o seguinte atributo:
  1. Um sf::Font fonte, que será a fonte usada para escrever texto (inicializada no construtor)
  E os seguintes métodos:
  1. void desenharRetanguloSolido() const, que toma como argumentos a posição do centro, as dimensões de um retângulo, e a cor desse retângulo
  2. void DesenharTexto() const, que toma como parâmetros uma string, a posição onde o texto deverá ser desenhado, o tamanho do texto e um bool "centralizar" com valor padrão true, que controla se o texto deve ser centralizado.
  3. Vetor2F getPosicaoMouse() const, que retorna a posição atual do mouse dentro da janela.

  A ideia é que, ao criar um botão, passaremos para ele um método que será chamado quando ele for apertado. 

  Criar uma classe Botão, com os seguintes atributos:
  1. Uma Vetor2F posicao privado
  2. Uma Vetor2F tamanho privado
  3. Uma Cor cor privada
  4. Um std::String texto protegido
  5. um std::function<void(void)> (uma função sem parâmetros nem retorno) quandoApertado protegido
  E os seguintes métodos:
  1. Um construtor que inicializa todos os parâmetros acima
  2. Um destrutor vazio
  3. Um método virtual desenhar que toma como parâmetro uma referência constante para o gerenciador gráfico
  4. getters para posicao e tamanho
  5. Um método apertar, que chama a função em quandoApertado.

  Para gerenciar esses botões, teremos um GerenciadorBotoes, que basicamente atua como o gerenciador de colisoes misturado com a lista de Desenhaveis, mas apenas para botões.

  Crie uma classe GerenciadorBotoes, com os seguintes atributos:
  1. Um std:vector<*Botao> botoes privado
  2. Uma referência para um GerenciadorEventos privada
  3. Uma referência privada para o GerenciadorGrafico
  4. um unsigned int idOuvinteMouse privado
  E os seguintes métodos:
  1. Um construtor, que toma como parâmetros um std::vector<*Botao>, uma referência para um GerenciadorEventos e uma para um GerenciadorGrafico, inicializando todas os atributos
  2. Um destrutor, que destroi todos os Botoes
  3. Um método desenhar(), que desenha todos os botões
  4. Um método ouvinteMouse(), que, quando o botão esquerdo do mouse é solto, verifica se isso ocorreu sobre um botão, chamando seu método apertar caso sim.
  5. Um método adicionarBotao() que adiciona um ponteiro para Botão no vetor

  E agora, criaremos uma classe abstrata Menu, que terá o comportamento normal de um menu, ou seja, esperar o usuário clicar em botões. 
  Para um menu normal, 

  Crie uma classe Menu extendendo Estado, com os seguintes atributos:
  1. Um GerenciadorEventos protegido
  2. Um GerenciadorBotoes protegido
  3. Um CodigoRetorno protegido, que representa o retorno de executar()
   e os seguintes métodos:
  4. Um destrutor virtual vazio
  5. O método executar, que retorna o código de retorno apropriado para o botão que for pressionado. Esse método é virtual.
  6. Um método protegido setCodigoRetorno()
  7. Um método virtual puro inicializar(), que inicializa a lista de botões (precisa ser assim por questões de simplicidade na declaração dos ouvintes dos botões)

Criaremos também uma classe MenuPrincipal, que permite entrar na FaseExemplo ou sair do jogo.

## Ex 8b - entrada de texto.
Além de precisarmos de botões, precisaremos também de entradas de texto, pois um dos requisitos do jogo é permitir que os jogadores coloquem seus nomes. Para isso, usaremos basicamente duas novas classes: um CampoTexto, que gerencia a parte gráfica, e uma PromessaString, que guarda a String sendo criada.

  Crie uma classe PromessaString com os seguintes atributos:
  1. Uma String privada string, que guardará a string sendo construída
  2. Um unsigned int idOuvinteTeclado, que guardara a id da ouvinte usada
  3. Um bool privado capturaIniciada, que controla se a captura está acontecendo
  4. Um bool privado stringPronta, que controla se a string terminou de ser adquirida
  5. Uma referência para GerenciadorEventos, onde o ouvinte será colocado.
  6. Um unsigned short comprimentoMaximo, que representa o máximo comprimento aceitável para a string
  E os seguintes métodos: 
  1. Um construtor que toma como parâmetros uma referência para GerenciadoEventos e o comprimento aceitável, inicializando os outros parâmetros.
  2. Um destrutor que remove o ouvinte do GerenciadorEventos.
  3. Um método começar, que esvazia a string e começa a aquisição da string
  4. getters para a string e para stringPronta
  5. um método privado adquirir, que será passado como ouvinte para o gerenciador de eventos. Basicamente, se o usuário digitar letras, números e espaços, os adiciona a string (se o tamanho da string for menor ou igual ao máximo), se apertar enter termina a aquisição (removendo o ouvinte), e se apertar backspace tira um caractere.

  Crie uma classe CampoTexto que herda de Botao com os seguintes atributos:
  1. Uma PromessaString privada
  e os seguintes métodos:
  1. Um construtor que toma como parâmetros uma referência para GerenciadorEventos e um tamanho máximo de string(passados para o construtor de PromessaString), além de uma posicao, tamanho, tamanho do texto e cor para passar para o construtor de Botao.
  2. Um destrutor vazio.
  3. Um método getString que só retorna a string se getStringPronta retornar true
  4. um método getStringPronta que só "passa para a frente" o resultado tirado da PromessaString
  5. Um método desenhar que sobreescreve o normal imprimindo o texto sem centralizá-lo (se isso parecer mais estéticamente agradável pra você)
  6. Um método iniciarCaptura, que será passado para quandoApertado no construtor e começa uma nova captura se ela já não começou.
