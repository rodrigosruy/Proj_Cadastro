#include <stdio.h>
#include <stdlib.h>
#define LEN 100
 char lixo;
int main(){
    typedef struct Data{ //typedef struct da Data
        int dia;
        int mes;
        int ano;

    }Data;
    typedef struct Registro{ //typedef struct do Registro
        char nome[LEN];
        int idade;
        char rg[LEN];

        Data *entrada;

    }Registro;

    typedef struct Celula{ //typedef struct da Celula

        struct Celula *proximoFila;
        struct Celula *anteriorLista;
        struct Celula *proximoLista;
        //montado desse jeito para possibilitar que a fila acesse dados que foram modificados enquanto a pessoa esta na fila
        Registro *dados;
    }Celula;
    typedef struct Lista{ //typedef struct da Lista
        Celula *inicio;
        int qtde;

    }Lista;
    typedef struct Queue{ //typedef struct da Fila
        Celula *inicio;
        Celula *fim;
        int qtde;
    }Queue;
    typedef struct Vertice{ //typedef struct dos vertices da arvore
        struct Vertice* esq;
        struct Vertice* dir;
        struct Vertice* pai;
        Celula* atual;
    }Vertice;
    typedef struct Arvore{ //typedef struct da Arvore
        Vertice* raiz;
        int qtde;
    }Arvore;
    int escolha = -1;
    Lista* inicializarLista(){ //cria novo tipo Lista
        Lista *lini = (Lista*)malloc(sizeof(Lista));
        lini -> qtde = 0;
        lini -> inicio = NULL;

        return lini;
    }
    Queue* inicializarQueue(){ //cria novo tipo Queue
        Queue* qini = (Queue*)malloc(sizeof(Queue));
        qini -> qtde = 0;
        qini -> inicio = NULL;
        qini -> fim = NULL;

        return qini;
    }
    Data* inicializarData(){ //cria novo tipo Data (apenas chamado dentro de inicializarRegistro()
        Data* dataini = (Data*)malloc(sizeof(Data));
        return dataini;
    }
    Registro* inicializarRegistro(){//cria novo tipo Registro (apenas chamado dentro de inicializarCelula()
        Registro* registroini = (Registro*)malloc(sizeof(Registro));
        registroini->entrada = inicializarData();
        return registroini;
    }
    Celula* inicializarCelula(){ //cria novo tipo Celula
        Celula* celulaini = (Celula*)malloc(sizeof(Celula));
        celulaini ->proximoLista = NULL;
        celulaini ->anteriorLista = NULL;
        celulaini ->proximoFila = NULL;
        celulaini ->dados = inicializarRegistro();


        return celulaini;
    }
    Vertice* inicializarVertice(){
        Vertice* verticeini = (Vertice*)malloc(sizeof(Vertice));
        verticeini->pai = NULL;
        verticeini->esq = NULL;
        verticeini->dir = NULL;
        verticeini->atual = NULL;
        return verticeini;
    }
    Arvore* inicializarArvore(){
        Arvore* novaArvore = (Arvore*)malloc(sizeof(Arvore));
        novaArvore->raiz = NULL;
        novaArvore->qtde = 0;
        return novaArvore;
    }
    int comparaNome(Celula *atual,char nome[]){ //funcao dedicada para retornar se os nomes são iguais ou nao
        for (int i = 0; i < LEN; ++i){
            if (nome[i] != atual->dados->nome[i]){ //se for diferente, retornar
                return 0;
            }
            if (nome[i] == '\0'){ //se for igual e tiver \0, sair do loop
                break;
            }
        }
        return 1;
    }
    void adicionarLista(Celula* novacelula,Lista *l){ //adiciona celulas a uma lista
        if (l->qtde == 0){ //caso inicial
            l->inicio = novacelula;
            l->qtde+=1;
        }
        else{
                l->inicio->anteriorLista = novacelula;
                novacelula->proximoLista = l->inicio;
                l->inicio = novacelula;
                l->qtde+=1;

        }
    }
    void adicionarFila(Celula* novacelula, Queue* q){ //adiciona celula a uma fila

        if (q->qtde == 0){
            q->inicio = novacelula;
            q->fim = novacelula;
            q->qtde+=1;
            printf("\nAdicionado!\nPos atual: %d\n",q->qtde);
        }
        else if (q->qtde>0){

            q->fim->proximoFila = novacelula;
            q->fim = novacelula;
            q->qtde+=1;
            printf("\nAdicionado!\nPos atual: %d\n",q->qtde);
        }
    }
    void andarFila(Queue *q){ //remove a primeira pessoa da fila
        if (q->qtde == 0){
            printf("Fila esta vazia! Ninguem para atender!\n");
            return;
        }
        else if (q->qtde == 1){
            printf("Ultimo!\nAcabou de ser atendido:\nNome:%s",q->inicio->dados->nome);
            q->inicio = NULL;
            q->fim = NULL;
            q->qtde--;
        }

        else{
            printf("Acabou de ser atendido:\nNome:%s",q->inicio->dados->nome);
            Celula* temp = q->inicio;
            q->inicio = q->inicio->proximoFila;
            temp->proximoFila = NULL;
            q->qtde--;
        }

    }



    void cadastrar(Lista *l,Queue* q){ //recebe informacoes para colocar em uma novacelula, as adiciona a uma lista, e da a opcao de adicionar para uma fila

        Celula* novacelula = inicializarCelula(); //declara nova celula
        Registro* registronovo = novacelula -> dados; //para facilitar escrever
        Data* datanova = registronovo ->entrada;

        printf("\nDigite o nome: ");
        fgets(registronovo->nome,LEN,stdin); //coloca o nome na novacelula;
        printf("\nTESTE : %s\n",novacelula->dados->nome); //print de teste

        printf("\nDigite a idade: ");
        scanf("%d",&registronovo->idade); //coloca a idade na novacelula
        scanf("%c",&lixo);
        printf("\nTESTE: %d\n",novacelula->dados->idade); //print de teste

        printf("\nDigite o RG: ");
        fgets(registronovo->rg,LEN,stdin); //coloca o RG na novacelula
        printf("\nTESTE: %s\n",novacelula->dados->rg); //print de teste

        printf("\nDigite o dia de entrada: "); //coloca a data na novacelula
        scanf("%d",&datanova->dia);
        scanf("%c",&lixo);
        printf("\nDigite o mes de entrada: ");
        scanf("%d",&datanova->mes);
        scanf("%c",&lixo);
        printf("\nDigite o ano de entrada: ");
        scanf("%d",&datanova->ano);
        scanf("%c",&lixo);


        printf("\nTESTE: %d/%d/%d\n",datanova->dia,datanova->mes,datanova->ano); //print de teste


        adicionarLista(novacelula,l);
        int escolha = -1;

        printf("\nGostaria de entrar na fila(Queue)?\n1-Sim\n0-Nao\n");

            scanf("%d",&escolha);
            scanf("%c",&lixo);
            if (escolha == 1){ //forma rapida de adicionar para a queue
                adicionarFila(novacelula,q);


            }
            printf("Enter para retornar ao menu de cadastro...");
            scanf("%c",&lixo); //jogando fora a entrada recebida (\n)





    }
    void consultarLista(Lista *l){ //mostra os conteudos do cadastro selecionado
        char nomeProcurado[LEN];
        int comp = 0;
        printf("Qual o nome do cadastro que deseja olhar?\n");
        fgets(nomeProcurado,LEN,stdin);
        Celula* atual = l->inicio;
        while (atual != NULL){
                comp = comparaNome(atual,nomeProcurado);
                if (comp == 1){
                    break; //achado!
                }
                atual=atual->proximoLista;

        }
        if (atual == NULL){ //caso onde nao existe/nome errado
            printf("Nome nao encontrado/cadastros vazio!\n");
            return;
        }
        else{
             printf("\nNome: %sIdade: %d\nRG: %sEntrada: %d/%d/%d\n\n",atual->dados->nome,atual->dados->idade,atual->dados->rg,atual->dados->entrada->dia,atual->dados->entrada->mes,atual->dados->entrada->ano);
        }




    }
    void mostrarLista(Lista *l){ //mostra todos os cadastros dentro da lista

        Celula* atual = l->inicio;
        if (atual == NULL){
            printf("Lista Vazia!\n");
        }
        else{
            while (atual!= NULL){

                printf("\nNome: %sIdade: %d\nRG: %sEntrada: %d/%d/%d\n\n",atual->dados->nome,atual->dados->idade,atual->dados->rg,atual->dados->entrada->dia,atual->dados->entrada->mes,atual->dados->entrada->ano);
                atual = atual->proximoLista;

            }

        }

    }
    void atualizarLista(Lista *l){ //usado para edicao de dados do cadastro dentro da lista
        char nomeProcurado[LEN];
        int comp = 0;
        printf("Qual o nome do cadastro que deseja olhar?\n");
        fgets(nomeProcurado,LEN,stdin);
        Celula* atual = l->inicio;
        while (atual != NULL){
                comp = comparaNome(atual,nomeProcurado);
                if (comp == 1){
                    break; //achado!
                }
                atual=atual->proximoLista;

        }
        if (atual == NULL){ //caso onde nao existe/nome errado
            printf("Nome nao encontrado/cadastros vazio!\n");
            return;
        }
         else{
            int escolha = -1;
            Registro *registroNovo = atual->dados;
            while (escolha != 0){
                printf("\nNome: %sIdade: %d\nRG: %sEntrada: %d/%d/%d\n\n",atual->dados->nome,atual->dados->idade,atual->dados->rg,atual->dados->entrada->dia,atual->dados->entrada->mes,atual->dados->entrada->ano);
                printf("1-Editar nome\n2-Editar idade\n3-Editar data de entrada\n4-Editar RG\n0-Sair\n");
                scanf("%d",&escolha);
                scanf("%c",&lixo);
                switch (escolha){
                case 1:
                    printf("Digite o novo nome:\n");
                    fgets(registroNovo->nome,LEN,stdin);
                    break;
                case 2:
                    printf("Digite a nova idade:\n");
                    scanf("%d",&registroNovo->idade);
                    scanf("%c",&lixo);
                    break;
                case 3:
                    printf("Digite a nova data de entrada:\n");
                    printf("Dia:\n");
                    scanf("%d",&registroNovo->entrada->dia);
                    scanf("%c",&lixo);
                    printf("Mes:\n");
                    scanf("%d",&registroNovo->entrada->mes);
                    scanf("%c",&lixo);
                    printf("Ano:\n");
                    scanf("%d",&registroNovo->entrada->ano);
                    scanf("%c",&lixo);
                    break;
                case 4:
                    printf("Digite o novo RG:\n");
                    fgets(registroNovo->rg,LEN,stdin);
                    break;
                }


            }
        }

    }

    void removerLista(Lista *l,Queue *q){ //recebe um nome e deleta seu cadastro da lista
        char nomeProcurado[LEN];
        printf("Qual o nome do usuario que sera deletado?\n");
        fgets(nomeProcurado,LEN,stdin);
        int comp = 0;
        Celula* atual = l->inicio;
        while (atual != NULL){
                comp = comparaNome(atual,nomeProcurado);
                if (comp == 1){
                    break; //achado!
                }
                atual=atual->proximoLista;

        }
        if (atual == NULL){
            printf("Nome nao encontrado/cadastros vazio!\n");
            return;
        }
        else if (atual->proximoFila != NULL || atual == q->inicio ){
            printf("Pessoa esta em uma fila! Por favor a atenda antes de deletar o cadastro!\n");
            return;
        }

        else if (l->qtde==1){ //caso lista unitaria (funciona)
                l->inicio = NULL;
                l->qtde--;



        }
        else if (atual->proximoLista == NULL && l->qtde >1){ //caso final
            atual->anteriorLista->proximoLista = NULL;
            l->qtde--;


        }
        else if (atual->proximoLista != NULL && l->qtde>2){ //caso meio
            atual->anteriorLista->proximoLista = atual->proximoLista;
            atual->proximoLista->anteriorLista = atual->anteriorLista;
            l->qtde--;

        }
        else if (atual->anteriorLista == NULL){ //caso primeiro
            atual->proximoLista->anteriorLista = NULL;
            l->inicio = atual->proximoLista;
            l->qtde--;
        }
        printf("Cadastro Deletado!\n");
    }
    void atendimento(Lista* l,Queue *q){ //menu para atendimento

        int escolha=-1;
        while (escolha != 0){
                system("cls");
                printf("\n1-Checar Lista de atendimento atual\n2-Adicionar Alguem a Lista de atendimento\n3-Andar a fila de atendimento\n0-Sair\n");
                scanf("%d",&escolha);
                scanf("%c",&lixo); //limpa buffer
                Celula *latual = l->inicio; //para percorrer listas
                Celula *fatual = q->inicio; //para percorrer filas
                int pos=1;
                char nomeProcurado[LEN];
                int comp = 0;
                switch(escolha){
                case 1:
                    if (q->inicio == NULL){
                        printf("Fila esta vazia!\n");
                    }
                    else{
                        while (fatual!= NULL){
                            printf("%d- %s\n",pos,fatual->dados->nome);
                            fatual =fatual->proximoFila;
                            pos+=1;
                        }

                    }

                    printf("\nEnter para continuar...");
                    scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
                    break;
                case 2:

                    printf("Qual o nome do cadastro que deseja adicionar para a fila?\n");
                    fgets(nomeProcurado,LEN,stdin);
                    while (fatual != NULL){ //checa se esta na fila
                            comp = comparaNome(fatual,nomeProcurado);
                            if (comp == 1){
                                break; //achado!
                            }
                            fatual=fatual->proximoFila;

                    }
                    if (comp == 1){ //nome encontrado!
                        printf("Cadastro ja esta na fila!\n");
                        printf("\nEnter para continuar...");
                        scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
                        break;

                    }
                    while (latual != NULL){
                            comp = comparaNome(latual,nomeProcurado);
                            if (comp == 1){
                                break; //achado!
                            }
                            latual=latual->proximoLista;

                    }
                    if (latual == NULL){ //caso onde nao existe/nome errado
                        printf("Nome nao encontrado/cadastros vazio!\n");

                    }
                    else{
                         adicionarFila(latual,q);
                    }
                    printf("\nEnter para continuar...");
                    scanf("%c",&lixo); //jogando fora a entrada recebida (\n)

                    break;
                case 3:
                    andarFila(q);
                    printf("\nEnter para continuar...");
                    scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
                    break;
                }


        }




    }
    Arvore* montarArvore(Lista *l,int tipo){ //monta a arvore baseada na escolha (escolhi vertice->dir caso igual) //(muito codigo repetido >.>;)
        Arvore* novaArvore = inicializarArvore();
        Celula* atual = l->inicio;

            while (atual != NULL){
                Vertice* novoVertice = inicializarVertice();
                novoVertice->atual = atual;
                if (novaArvore->qtde == 0){ //caso ini (nao importa a comparacao)
                    novaArvore->raiz = novoVertice;
                    novaArvore->qtde++;
                }
                else{
                    Vertice* atualVertice = novaArvore->raiz;
                    int comp; //valor a comparar da celula
                    int vertComp; //valor a comparar do vertice
                    switch (tipo){ //muda o valor a ser comparado baseado
                    case 1:
                        vertComp = atualVertice->atual->dados->entrada->ano;
                        comp = atual->dados->entrada->ano;
                        break;
                    case 2:
                        vertComp = atualVertice->atual->dados->entrada->mes;
                        comp = atual->dados->entrada->mes;
                        break;
                    case 3:
                        vertComp = atualVertice->atual->dados->entrada->dia;
                        comp = atual->dados->entrada->dia;
                        break;
                    case 4:
                        vertComp = atualVertice->atual->dados->idade;
                        comp = atual->dados->idade;
                        break;
                    }


                    while(atualVertice != NULL){
                        if (comp >= vertComp){ //caso onde eh maior ou igual
                            if (atualVertice->dir == NULL){ //caso seja folha
                                novoVertice->pai = atualVertice;
                                atualVertice->dir = novoVertice;
                                novaArvore->qtde++;
                                break;
                            }
                            else{
                                atualVertice = atualVertice->dir;
                            }

                        }
                        if (comp < vertComp){ //caso onde eh menor
                            if (atualVertice->esq ==NULL){ //caso seja folha
                                novoVertice->pai = atualVertice;
                                atualVertice->esq = novoVertice;
                                novaArvore->qtde++;
                                break;
                            }
                            else{
                                atualVertice = atualVertice->esq;
                            }
                        }
                    }

                }

                atual = atual->proximoLista;
            }
            return novaArvore;


    }
    void in_ordem(Vertice * raiz) { // print dos dados copiado do professor :(
    if (raiz != NULL) {
      in_ordem(raiz->esq);
      Registro* dadosAtual = raiz->atual->dados;
      printf("CADASTRO:\nNome:%sRG:%sIdade: %d\nData de registro:%d/%d/%d\n", dadosAtual->nome,dadosAtual->rg,dadosAtual->idade,dadosAtual->entrada->dia,dadosAtual->entrada->mes,dadosAtual->entrada->ano);
      in_ordem(raiz->dir);
    }
  }
    void mostrarArvore(Arvore* a){ //mostra a arvore (escolhi fazer do maior para o menor)
        if (a->qtde == 0){
            printf("Arvore vazia!\nExistem cadastros?\n");
            return;
        }
        else{
            in_ordem(a->raiz);


        }

    }
    void pesquisa(Lista* l){ //ARVORE BINARIA!
        int escolha = -1;
        while (escolha !=0){
            system("cls");
            printf("Ordenar como?\n1-Ano de registro\n2-Mes de registro\n3-Dia de registro\n4-Idade do paciente\n0-Sair\n");
            scanf("%d",&escolha);
            scanf ("%c",&lixo);
            if (escolha != 0 && l->qtde>0){
                    Arvore* a = montarArvore(l,escolha); //chama a funcao para montar e mostrar a arvore binaria
                    mostrarArvore(a);
                    printf("\nEnter para continuar...");
                    scanf("%c",&lixo); //jogando fora a entrada recebida (\n)


            }
            else if (escolha != 0 && l->qtde == 0){
                printf("Lista vazia!\nConsidere carregar um arquivo, ou adicionar cadastros!\n");
                printf("\nEnter para continuar...");
                scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
            }


        }


    }
    void carregar(Lista* l,Queue *q){ //carrega arquivos
        if (q->qtde!= 0){
            printf("Alguem ainda esta na fila!\n");
            return;
        }

        FILE *arquivo; //inicializar arquivo

        arquivo = fopen("dados.txt","r"); //le arquivos
        if (arquivo == NULL){
            printf("SEM ARQUIVO DE DADOS!\n");
        }
        l->qtde = 0;

        l->inicio = NULL;
        int size=0; //qtde de celulas

        fscanf(arquivo,"%d\n",&size); //recebe a qtde de celulas
        printf("CARREGANDO %d PESSOAS!\n",size);
        for(int i = 0; i < size; ++i){
            Celula *novaCelula = inicializarCelula();
            fgets(novaCelula->dados->nome,LEN,arquivo); //usando fgets para pegar strings
            fgets(novaCelula->dados->rg,LEN,arquivo);
            fscanf(arquivo,"%d %d %d %d\n",&novaCelula->dados->idade,&novaCelula->dados->entrada->dia,&novaCelula->dados->entrada->mes,&novaCelula->dados->entrada->ano); //fscanf para nao-strings
            printf("TESTE:\n%s %d %s %d %d %d\n",novaCelula->dados->nome,novaCelula->dados->idade,novaCelula->dados->rg,novaCelula->dados->entrada->dia,novaCelula->dados->entrada->mes,novaCelula->dados->entrada->ano);
            adicionarLista(novaCelula,l);




        }
        fclose(arquivo);


        printf("Lido com sucesso!");
    }
    void salvar(Lista* l,Queue *q){ //salva em arquivos
        if (q->qtde!= 0){
                    printf("Alguem ainda esta na fila!\n");
                    return;
                }


        FILE *arquivo;


        arquivo = fopen("dados.txt","w"); //cria/abre arquivo para sobrescrever

        Celula* atual = l->inicio;
        fprintf(arquivo,"%d\n",l->qtde); //manda a qtde de celulas
        while (atual != NULL){ //manda todos os dados de todas as celulas para o arquivo
            fputs(atual->dados->nome,arquivo); //nome
            fputs(atual->dados->rg,arquivo); //rg
            fprintf(arquivo,"%d %d %d %d\n",atual->dados->idade,atual->dados->entrada->dia,atual->dados->entrada->mes,atual->dados->entrada->ano); //dia mes ano




            atual = atual->proximoLista;
        }

        fclose(arquivo);
        printf("Salvado!\n");
    }
    void sobre(){ //mostra dados sobre o programa
        system("cls");
        printf("\nProjeto individual\n");
        printf("Integrante:\nRodrigo Simoes Ruy R.A. 24.122.092-0\nCiencia da Computacao\n4o Ciclo");
        printf("\n\n");
        //falta data e ciclo






    }
    void cadastrarMenu(Lista* l,Queue* q){ //menu de cadastro

        int escolha = -1;
        while (escolha != 0){
            system("cls");
            printf("1-Cadastrar novo paciente\n2-Consultar Pacientes Cadastrados\n3-Mostrar todos os pacientes\n4-Atualizar dados de pacientes\n5-Remover Paciente\n0-Sair\n");
            scanf("%d",&escolha);
            scanf("%c",&lixo);
            switch(escolha){
            case 1:
                cadastrar(l,q); //manda para a funcao de cadastro
                break;
            case 2:
                consultarLista(l); //manda para a funcao de consultar cadastros especificos na lista
                printf("\nEnter para continuar...");
                scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
                break;
            case 3:
                mostrarLista(l); //manda para a funcao que mostra a lista inteira
                printf("\nEnter para continuar...");
                scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
                break;
            case 4:
                atualizarLista(l); //manda para a funcao de atualizar um cadastro especifico na lista
                printf("\nEnter para continuar...");
                scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
                break;
            case 5:
                removerLista(l,q); //manda para a funcao de remover um cadastro especifico na lista
                printf("\nEnter para continuar...");
                scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
                break;
            }
        }

    }
    //-------------------MAIN----------------------
    Lista *l = inicializarLista(); //inicializando lista l
    Queue *q = inicializarQueue(); //inicializando fila q
    while (escolha !=0){ //menu principal
        system("cls");
        printf("1- Cadastrar\n");
        printf("2- Atendimento\n");
        printf("3- Pesquisa\n");
        printf("4- Carregar\n");
        printf("5- Salvar\n");
        printf("6- Sobre\n");
        printf("0- Sair\n");
        scanf("%d",&escolha);
        scanf("%c",&lixo); //limpa buffer que sobra ('\n') (usado MUITO no codigo)

        switch (escolha){
        case 1:

            cadastrarMenu(l,q); //manda para o menu de cadastros

            break;
        case 2:

            atendimento(l,q); //manda para o menu de atendimento

            break;
        case 3:

            pesquisa(l); //manda para o menu de pesquisa

            break;
        case 4:

            carregar(l,q); //manda para a funcao de carregar de um arquivo
            printf("\nEnter para continuar...");
            scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
            break;
        case 5:

            salvar(l,q); //manda para a funcao de salvar para um arquivo
            printf("\nEnter para continuar...");
            scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
            break;
        case 6:

            sobre(); //mosta dados sobre o programa
            printf("Enter para sair...");
            scanf("%c",&lixo); //jogando fora a entrada recebida (\n)
            break;
        }

    }


return 0;
}
