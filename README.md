# exercicios-monitoria-tec-prog

Esse repositório consiste de exercícios, tutoriais e dicas úteis para a disciplina de Técnicas de Programação, do curso de Engenharia de Computação da UTFPR.

O monitor da disciplina e mantenedor desse repositório recomenda a utilização do sistema de build Meson e o próprio github como ferramentas auxiliares na disciplina.

# meson

Um sistema de build é, basicamente, um programa que compila um projeto para você sem que você tenha que usar diretamente o compilador através de arquivos de configuração. Existem inúmeros deles, o mais famoso sendo o Make, que utiliza os arquivos "Makefile". Mas por quê, então, usar o Meson?
1- O meson é um sistema crossplatform, funcionando em linux, windows e mac;
2- Os arquivos de configuração do Meson, chamados "meson.build", usam uma sintaxe extramemente simples;
3- sem nenhuma configuração extra, o meson inclui  várias configurações de compilador que levam à mais warnings, permitindo que o usuário veja facilmente os problemas secundários de seus código.
4- O meson por padrão só compilar arquivos que foram modificados, o que economiza muito tempo quando o projeto fica grande;

Para dicas de instalação do Meson, veja o arquivo "instalar-meson.txt"
Para um tutorial de utilização, veja o arquivo "usar-meson.txt"

# git/github

O Git/Github são ferramentas de controle de versionamento, em essência. O git, basicamente, permite que você mantenha um backup de múltiplas versões de algum "repositório" (basicamente, um nome chique para uma pasta), comparando mudanças de uma versão para a próxima e permitindo voltar para uma versão anterior. Entretanto, por si só, o git só é capaz de compartilhar e sincronizar esse repositório no mesmo computador/rede. Aí que entre o github, que permite postar esses repositórios na internet para que qualquer um os use.

Para um tutorial de utilização de comandos do git e sua sincronização com o github, veja o arquivo "dicas-github.txt"

# SFML

O SFML é uma biblioteca gráfica muito boa, e com todos os recursos necessários para ser utilizada em um programa desenvolvido no paradigma orientado a objetos. Entretanto, ele não está instalado por padrão nos computadores da UTFPR. O script (download_and_install_sfml.sh) incluido nesse repositório "dá um jeito" de instalá-lo. para rodá-lo, 
copie ele no seu diretório home (a + seu RA) e, em um terminal, escreva "./download_and_install_sfml.sh". O script irá rodar e instalará o SFML para seu usuário. Talvez ele não funcione imediatamente, então, se houver algum problema, digite em qualquer terminal o comando "source ~/.bashrc". Se continuar sem funcionar, avise  o monitor. o arquivo "cola-sfml.md" contem quase tudo que você precisará saber de SFML para fazer o jogo (na verdade, inclui tudo que o monitor usou).
# disclaimer

Tudo que está escrito acima são coisas que o monitor aprendeu ou sozinho, ou através de seus colegas e amigos (convenhamos que o segundo caso é bem mais comum). Outros tutoriais muito mais completos podem ser encontrados na internet, mas o monitor acredita que isso pode ser suficiente (ou quase) para o requisitado pela disciplina de Técnicas de Programação.
