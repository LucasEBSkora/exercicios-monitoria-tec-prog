# incluir a biblioteca

o comando necessário para incluir a biblioteca é o 
#include <SFML/Graphics.hpp>

# Modelos sf::Vector2/sf::Vector3
	essas classes na verdade são templates (ou modelos), o que significa, de forma simplificada, que são classes feitas para funcionar com qualquer tipo de dado,
	podendo ser determinados na hora da declaração. sf::Vector2 e sf::Vector3 são, efetivamente, vetores (no sentido da algebra linear) de duas e três dimensões, respectivamente, mas que podem aceitar qualquer tipo de valor.
	
	Assim, sf::Vector2<int> criaria um vetor bidimensional de inteiros, sf::Vector3<float> um tridimensional de floats, e assim vai.

	existem alguns atalhos predefinidos. Exemplos são sf::Vector2f (sf::Vector2<float>), sf::Vector2i (sf::Vector2<int>), e sf::Vector2i (sf::Vector2<unsigned>) 

	Esses modelos possuem inúmeras sobrecargas de operador, ou seja, podemos usar coisas como "+", "-", "*" e "/" para operar com eles.
	assim, para
	
	sf::Vector2f u(1.5, 2.0), v(1.0, 5.0);

	u + v retornará (2.5, 7.0)

	u - v retornará (0.5, -3.0)

	u*2 retornará (3.0, 4.0)

	e 

	v/5.0 retornará (0.2, 1.0).

	Quase todas as posições e tamanhos dentro do SFML são controladas usando tais vetores.
	


# classe sf::RenderWindow

## Essa classe representa a janela onde tudo será desenhado.

seu construtor é usado da seguinte maneira

sf::RenderWindows(sf::VideoMode(larguraDaJanela, alturaDaJanela), "titulo da janela", opções de estilo (serão abordadas depois));

Para desenhar algo na tela, se usa a função

draw(sf::Drawable);

Para verificar se ocorreu algum evento, se chama a função

bool sf::RenderWindow::pollEvent(sf::Event & event);

que retorna verdadeiro se ocorreu algum evento, e, se ocorreu, carrega esse evento no parãmetro passado. Eventos são coisas como apertar teclas, mexer o mouse, clicar para fechar a janela, etc. Mais explicações na parte sobre essa classe

Exemplos:

sf::RenderWindow janela = sf::RenderWindow(sf::VideoMode(800, 600), "exemplo 1 :)")

sf::RectangleShape forma;
sf::Sprite bicho;

janela.draw(forma);
janela.draw(bicho);

# sf::Event
## Representa eventos do SFML. Normalmente se criam vazios e são "preenchidos" pelo método sf::RenderWindow::pollEvent(sf::Event *event);

Incluem todas os atributos que poderiam ser necessários para representar um evento do SFML. O que diz qual tipo de evento é o campo type, que pode ter vários valores. Por enquanto, nos manteremos apenas com o evento 

sf::Event::Closed

que acontece quando a janela é fechada.

# classe sf::Texture
## essa classe representa uma textura, ou seja, um desenho. Normalmente carregada de uma png e passada para outros objetos, esses sim sendo desenhados.

O construtor dessa classe não tem parâmetros.

para carregar uma imagem em um objeto dessa classe:

sf::Texture::loadFromFile(const std::string& filename) 

exemplo:

sf::Texture *text = new sf::Texture();
text->loadFromFile("amigo.png");

note que, como é necessário garantir que o objeto continua existindo até ele não precisar mais ser desenhado, normalmente se utilizando ponteiros para esses objetos,
dando-nos controle sobre quando são desalocados.

outra função útil é

sf::Vector2f sf::Texture::getSize()

que retorna as dimensões da textura (em pixels)

# classe sf::Color
Representa uma cor no SFML. Seu construtor precisa de 3 valores de cor obrigatórios (r, g, e b) e um quarto opcional (a)

# classe sf::Font
Uma fonte usada para desenhar texto. Construtor vazio, mas tem um método loadFromFile que toma um caminho para um arquivo de fonte (no formato ttf, por exemplo).

# classe sf::Text 
Representa uma String dentro do sfml. Seu construtor toma como parâmetros uma string, uma sf::Font e o tamanho que deve ser usado para o texto (unsigned int). Para descobrir o tamanho necessário para imprimir o texto, há o getter setGlobalBounds, e também há os getters e setters para Origin e Position.

# classe sf::RectangleShape
Essa classe é um retângulo onde se pode deseSprite
Essa classe é uma das que você mais manipulará, e, por isso, tem muitos métodos úteis.

Para os seguintes valores, essa classe tem funções get e set:

1. sf::Vector2f Size (as dimensões do retângulo)
2. sf::Texture Texture (textura sendo desenhada dentro do retângulo)
3. sf::Vector2f Position (a posição desse retângulo quando ele for desenhado na tela)
4. sf::Vector2f Origin (a origem a ser utilizada para o objeto. Quando ele for desenhado, a origem será o ponto que ficará na posição especificada em Position. (a explicação tá ruim, mas teste o que acontece)
5. FillColor (Um objeto sf::Color com a cor de preenchimento do retângulo, se você estiver utilizando-o de verdade como um retângulo)

Além disso, existe a função 
sf::RectShape::move(sf::Vector2f &offset), que soma o vetor passado à posição atual do objeto.

Exemplos de uso:

body.setSize(sf::Vector2f(200.0f, 200.0f));

sf::Texture playerTexture;
playerTexture.loadFromFile("walk2.png");
body.setTexture(texture);
body.setOrigin(body.getSize() / 2.0f); //Coloca a origem no centro do retângulo


# class sf::Sprite
## Essa classe basicamente gerencia a posição, tamanho e transformações de uma textura. Sempre precisa receber um sf::Texture* para funcionar, pois só pode desenhar
texturas (ao contrário de classes como sf::RectangleShape, que podem desenhar tanto texturas quanto retângulos de uma cor específica).

Todos os gets, sets e a função move explicada em sf::Sprite também estão disponíveis nessa classe, exceto Size, pois ela usa por padrão o tamanho da textura, e o fato que  getTexture() recebe a textura por referência escondida, ao invés de por ponteiro. Por enquanto usaremos sf::RectangleShape para desenhar coisas na tela, até chegarmos na parte do gerenciador gráfico desacoplado.


# classe sf::Clock
## Uma classe pequena usada para medir o tempo.

seu construtor não recebe parâmetros, e assim que é chamado, o relógio começa a rodar.

Para receber o tempo que o relógio está registrando, chame a função

sf::Time sf::Clock::getElapsedTIme() 

que retorna o tempo desde o relógio ser iniciado ou reiniciado pela última vez.

e para resetar o relógio, chame a função

sf::Time sf::Clock::Restart(), que além de zerar o relógio retorna o tempo desde a última vez que a função foi chamada

# classe sf::Time
## Uma classe para representar valores de tempo

Time é uma classe que representa um valor de tempo. Normalmente é retornada por funções de sf::Clock.

Para receber o valor de Tempo como segundos, chame a função asSeconds().
Existem também asMilliseconds() e as Microseconds().

# classe sf::View

Essa classe é usada para representar uma "câmera" retangular dentro da tela. Ela permite que você mostre apenas uma parte do que está sendo desenhado, ao invés do todo. Em essência, pode ser usada para dar zoom e mover a tela com o personagem sem tem que mover todos os personagens junto.

Seu construtor recebe dois Vector2f, um representando seu centro, e o outro suas dimensões. existem também métodos separados setCenter e setSize.

Para aplicar uma View a uma RenderWindow, use o método
sf::RenderWindow::setView().

Exemplo:

sf::RenderWindow janela;
sf::View camera;

camera.setCenter(200, 200); //camera.setCenter(sf::Vector2f(200, 200));

camera.setSize(400, 300); //camera.setSize(sf::Vector2f(400,300));

janela.setView(camera);

# Observação
#### Essa cola será completada quando os exercícios prescritos necessitarem de conteúdos adicionais, e só cobre os métodos imprescindíveis. É sempre bom acessar a documentação do SFML 2.5.1 para ler o que mais essas classes podem fazer (https://www.sfml-dev.org/documentation/2.5.1/).