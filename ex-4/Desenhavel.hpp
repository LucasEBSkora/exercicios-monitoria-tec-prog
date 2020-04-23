#ifndef _DESENHAVEL_HPP_
#define _DESENHAVEL_HPP_

#include "Vetor2D.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"

namespace exercicio {

  class Desenhavel {
    protected:
      Vetor2F posicao;
      Vetor2F v;
      const char* caminho;
      
    public:
      

      /*
        Parâmetros padrão: 
        digamos que tenhamos uma função 
        void f(int x, int y), mas que quase sempre o segundo parâmetro acabe sendo 0. Em C++, podemos usar a sintaxe
        
        void f(int x, int y = 0) para dizer que se alguém chamar a função f com apenas um parâmetro, deve-se assumir que o segundo é 0. Efetivamente, 
        isso quer dizer que na verdade criamos duas funções:

        void f(int x, int y);
        e
        void f(int x) {
          f(x, 0);
        }

        o fato de termos duas funções com o mesmo nome não é um problema em C++ devido a algo chamado sobrecarga de função/método: podemos ter duas funções
        com o mesmo nome, se as duas tiverem assinaturas diferentes. Assinatura é um nome chique para os parâmetros de uma função. Assim, podemos ter ao mesmo tempo
        as seguintes funções:

        f(int x, int y)
        f(int x)
        f(char x, float y)

        e assim vai.

        Quando definimos métodos com parâmetros padrão, os valores padrão precisam ser colocados no .h/.hpp 
        Porque?
        porque o .h é basicamente um protótipo da função, um jeito de dizer para o compilador "vou definir isso aqui depois, não estranhe se eu chamar"
        Pois bem, o compilador precisa saber que uma mesma função pode aceitar várias assinaturas, e, portanto, precisa disso definido já no protótipo. Por alguma razão
        estranha, o compilador dá erro se você colocar parâmetros padrão no .cpp e no .h/.hpp ao mesmo tempo, então coloque só nos .h/.hpp

        Um ótimo uso de parâmetros padrão são em construtoras:
        Sempre que você cria uma classe, o C++ cria por padrão um construtor sem parâmetros padrão e um destrutor padrão. E, como não sabemos se o comportamento 
        padrão é o desejado, normalmente definimos nós mesmos esse construtor sem parâmetros, para ter controle sobre ele. Entretanto, se o seu construtor normal
        tiver todos os parâmetros como opcionais, como dito antes, já temos efetivamente um construtor com a assinatura "sem parâmetros", e esse segundo construtor
        não é necessário.


        Outra coisa importante: Para um parâmetro ser padrão, todos os parâmetros depois dele tem que ser também. Assim, uma função
        como 
        F(int x, int y = 0, int z) é impossível,
        mas F(int x, int y = 0, int z = 0) não.


      */

      Desenhavel(Vetor2F pos, Vetor2F vel, const char* caminhoTextura = nullptr);
      virtual ~Desenhavel();
      virtual void inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge);
      virtual void atualizar(float t);
      virtual void desenhar(GerenciadorGrafico &g);
  };

}

#endif