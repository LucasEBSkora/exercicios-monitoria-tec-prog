# incluir a biblioteca

o comando necessário para incluir a biblioteca é o 
#include <SFML/Graphics.hpp>


# classe sf::RenderWindow
Essa classe representa a janela onde tudo será desenhado.

seu construtor é usado da seguinte maneira
sf::RenderWindows(sf::VideoMode(larguraDaJanela, alturaDaJanela), "titulo da janela", opções de estilo (serão abordadas depois))

Para desenhar algo na tela, se usa a função
sf::RenderWindow(sf::RectangleShape);

# classe sf::RectangleShape
Essa classe é um retângulo onde se pode desenhar uma forma.

	body.setSize(sf::Vector2f(200.0f, 200.0f));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("walk2.png");
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);





Observação - Essa cola será completada quando os exercícios prescritos necessitarem desses conteúdos. 