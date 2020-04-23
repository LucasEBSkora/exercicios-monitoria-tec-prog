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

  1. Crie uma novo arquivo .hpp que inclua a declaração de um namespace dentro do namespace exercício chamado "IDsDesenhaveis", e defina dentro dele um enum com cada tipo de Desenhavel (no nosso caso, até agora, temos apenas o Heroi e o Vilao).
  2. Na classe GerenciadorGrafico, crie um método getTamanho() que toma como parâmetro uma string e retorna as dimensões (como Vetor2F) da textura correspondente.
  3. Na classe Desenhavel, adicione um campo do tipo IDsDesenhaveis chamado "id", que usaremos para diferenciar com qual outro tipo de Desenhavel uma entidade está colidindo (e pode ser útil no futuro tbm)
  4. Na classe Desenhavel, adicione um campo dimensões (Vetor2F), que deve ser inicializado por chamada à GerenciadorGrafico::getDimensoes(). Adicione também um método getDimensoes().
  5. Na classe Desenhavel, faça o método inicializar receber também uma referência escondida para GerenciadorColisoes, e também atualize a ListaPersonagens adequadamente.
  6. Crie uma classe derivada de Desenhavel chamada "Colidivel", com método virtual puro colidir, que será chamada quando este Colidivel colidir com outro. Ele recebe como parametros o id, posicao e tamanho do outro Colidivel. As classes Heroi e Vilao devem agora estender Colidivel, e o método colidir nas duas deve ser escrito de forma à dar algum comportamento para os objetos das duas classes quando colidem entre si (para Vilao) e com a outra (Vilao com Heroi e Heroi com Vilao)
  
Com essas modificações feitas, podemos trabalhar na nova Classe. Crie uma classe GerenciadorColisoes que possua os seguintes atributos:
  1.  Um std::vector<Colidivel*>, onde armazenaremos todos os Colidiveis administrados por essa classe
e os seguintes métodos:
  2. Um construtor vazio.
  3. Um destrutor vazio.
  4. Um método adicionarColidivel(), que recebe um ponteiro para Colidivel e o adiciona no vetor.
  5. Um método removerColidivel(), que recebe um ponteiro para Colidivel e, se ele já exister no vetor, o remove.
  6. Um método removerTodos(), que esvazia o vetor de colidiveis.
  7. Um método verificarColisoes(), que irá efetivamente verificar se houve colisões
  8. Um método privado estaoColidindo() que recebe dois ponteiros para Colidivel e retorna um valor booleano dizendo se eles estão colidindo.

Um objeto dessa classe deve ser agregado na classe Principal, e o método verificarColisoes deve ser chamado dentro do loop em rodar().