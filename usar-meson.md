# Um resumo do que precisa ser feito

crie um arquivo chamado "meson.build" e escreva nele: 
( a terceira linha só é necessária se você for realmente usar o SFML, assim como o "dependencies: dep")

project('nome do seu projeto aqui', 'cpp')
src= ['main.cpp', 'outro-arquivo-fonte.cpp', 'mais-um-arquivo-fonte.cpp']
dep = [dependency('sfml-all')]
executable('tutorial', sources: src, dependencies: dep)

Para compilar o programa, na primeira vez ou sempre que você precisar alterar o meson.build rode:

  meson build

e então, na primeira e em todas as outras rode:

  ninja -C build

e, finalmente, para executar seu programa (no linux):

  ./build/tutorial

# Explicação completa

vá para a pasta principal do seu projeto, seja qual for, e crie um arquivo chamado
"meson.build".

na primeira linha, escreva o comando project. O primeiro argumento é o nome do projeto,
e o segundo a linguagem de programação usada.

Note que todas as strings são marcadas por apóstrofes, ou "aspas simples"

    project('tutorial', 'cpp') 

Então, você chama o comando executable, com o primeiro argumento sendo o nome 
do arquivo executável que será gerado, e o segundo, os arquivos fontes a compilar.
também é possível acessar esse argumento escrevendo "sources :", um argumento nomeado.

É certo que você terá mais de um arquivo de código fonte, então é necessário criar um 
vetor de strings com o nome de todos os arquivos fontes, que será passado para a 
função executable.

E, finalmente, se você tiver alguma biblioteca externa, terá que adicionar isso através do
comando  dependency, que aceita um nome de biblioteca. Como você pode ter mais de uma
biblioteca, é aconselhável usar o padrão de vetor também. Esse vetor é passado para a função
executable através do parâmetro nomeado dependencies:

    src = ['main.cpp', 'Personagem.cpp']
    deps = [dependency('sfml-all')]
    executable('tutorial', sources : src, dependencies: deps)



Com o arquivo de configuração pronto, agora é preciso usá-lo. Em um console na pasta onde está
o meson.build, digite o seguinte comando:

  meson build

"build", na verdade, é o nome da pasta onde o meson guardará todos os arquivos que gerar. 
Você pode usar qualquer nome nessa pasta, mas por padrão é melhor continuar usando "build".
O meson, na verdade, gera arquivos de compilação para outro compilador funcionar. Esse 
compilador se chama ninja. Para usá-lo, use o seguinte comando:

  ninja -C build

o "-C build" basicamente fala para o ninja que ele precisa ir até a pasta build antes de 
executar. Se você usar outro nome no passo anterior, coloque esse nome. Se você escrevesse

  cd build
  ninja

o efeito seria o mesmo, mas para se poupar de ficar trocando de pasta o tempo todo, pode ser 
mais prático usar a forma anterior. Se a compilação ocorrer com sucesso (yay!), rode o programa
com o comando

  ./build/tutorial

(ou qualquer outro nome que você tenha passado como primeiro argumento para a função executable)
Novamente, é necessário escrever "./build/" apenas porquê não queremos entrar e sair o tempo todo 
da pasta build. Porém, se antes você usou o comando "cd build", só precisará escrever "./tutorial"
para executar seu programa.