namespace exercicio {

  template <typename TF>
  template <typename TE>
  Lista<TF>::ElementoLista<TE>::ElementoLista(TE Info, ElementoLista<TE>* Ant, ElementoLista<TE>* Prox) :
  info{Info}, ant{Ant}, prox{Prox} {

  }

  template <typename TF>
  template <typename TE>
  Lista<TF>::ElementoLista<TE>::~ElementoLista() {

  }

  template <typename TF>
  template <typename TE>
  TE Lista<TF>::ElementoLista<TE>::getInfo() {
    return info;
  }

  template <typename TF>
  template <typename TE>
  void Lista<TF>::ElementoLista<TE>::setInfo(TE Info) {
    info = Info;
  }

  template <typename TF>
  template <typename TE>
  Lista<TF>::ElementoLista<TE>* Lista<TF>::ElementoLista<TE>::getAnt() {
    return ant;
  }

  template <typename TF>
  template <typename TE>
  void Lista<TF>::ElementoLista<TE>::setAnt(ElementoLista<TE>* Ant) {
    ant = Ant;
  }

  template <typename TF>
  template <typename TE>
  Lista<TF>::ElementoLista<TE>* Lista<TF>::ElementoLista<TE>::getProx() {
    return prox;
  }

  template <typename TF>
  template <typename TE>
  void Lista<TF>::ElementoLista<TE>::setProx(ElementoLista<TE>* Prox) {
    prox = Prox;
  }

  template <typename TF>
  template <typename TE>
  void Lista<TF>::ElementoLista<TE>::remover() {
    if (ant) ant->prox = prox;
    if (prox) prox->ant = ant;
  }

  template <typename TF>
  Lista<TF>::Lista() :
    inicio{nullptr}, fim{nullptr}, atual{nullptr} {

  }

  template <typename TF>
  Lista<TF>::~Lista() {
    esvaziar();
  }

  template <typename TF>
  void Lista<TF>::inserir(TF info) {
    if (info) { //info == NULL == 0 == false
      
      ElementoLista<TF>* novo = new ElementoLista<TF>(info);

      if (!inicio) {
      
        inicio = novo;
        fim = novo;
      
      } else {
        
        fim->setProx(novo);
        novo->setAnt(fim);

        fim = novo;

      }



    }
  }

  template <typename TF>
  void Lista<TF>::esvaziar() {

    ElementoLista<TF>* paux = inicio;
    atual = inicio;
    
    while (atual != nullptr) {
      paux = atual->getProx();

      delete atual;

      atual = paux;

    }

    inicio = nullptr;
    fim = nullptr;
    atual = nullptr;


  }

  template <typename TF>
  TF Lista<TF>::voltarInicio() {
    atual = inicio;

    if (atual) return atual->getInfo();
    else return nullptr;

  }

  template <typename TF>
  TF Lista<TF>::irProximo() {

    atual = atual->getProx();

    return (atual) ? atual->getInfo() : nullptr;

  }

  template <typename TF>
  void Lista<TF>::removerPrimeiro(TF elemento) {
    voltarInicio();

    for(voltarInicio(); atual != nullptr; irProximo()) {
      if (atual->getInfo() == elemento) {
        if (atual == inicio) inicio = atual->getProx();
        if (atual == fim) fim = atual->getAnt();
        atual->remover();
        delete atual;
        voltarInicio();
        return; 
      }
    }
  }


}