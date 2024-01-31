#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_VOOS 50
#define MAX_PASSAGEIROS 100
#define MAX_PASSAGENS 100

//-------------------------------------------------------------------------------------------------------------------------------
/*
    TRABALHO AEROPORTO - LOGICA DE PROGRAMACAO
    NOMES: IGOR GRIEDER MELO
*/
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
/*

                                            AREA DESTINADA A FUNCOES E PROCEDIMENTOS DA LISTA DE VOOS

*/

// struct no menu Voos
typedef struct No_Voos
{
    int identificador;
    int numero;
    char empresa[1000];
    char origem[1000];
    char destino[1000];
    char dataP[15];
    char horaP[10];
    int passageirosVoo;
    struct No_Voos *proximo;
} VOOS;

// inserir nos voos
void Inserir_Voo(VOOS **lista)
{
    VOOS *novo = (VOOS *)malloc(sizeof(VOOS));
    int identificador;
    int numero;
    char empresa[1000];
    char origem[1000];
    char destino[1000];
    char dataP[15];
    char horaP[10];
    int passageirosVoo;
    printf("Digite o identificador do voo: ");
    scanf("%d", &identificador);
    printf("Digite o numero da aeronave: ");
    scanf("%d", &numero);
    printf("Digite o nome da empresa aerea: ");
    fflush(stdin);
    fgets(empresa, 1000, stdin);
    printf("Digite a sua origem: ");
    fflush(stdin);
    fgets(origem, 1000, stdin);
    printf("Digite o seu destino: ");
    fflush(stdin);
    fgets(destino, 1000, stdin);
    printf("Digite a data de partida (xx/xx/xx): ");
    fflush(stdin);
    fgets(dataP, 15, stdin);
    printf("Digite o horario de partida (xx:xx): ");
    fflush(stdin);
    fgets(horaP, 10, stdin);
    printf("Digite o numero de passageiros do voo: ");
    scanf("%d", &passageirosVoo);
    if (novo != NULL)
    { // verificacao de preenchimento da lista
        novo->identificador = identificador;
        novo->numero = numero;
        strcpy(novo->empresa, empresa);
        strcpy(novo->origem, origem);
        strcpy(novo->destino, destino);
        strcpy(novo->dataP, dataP);
        strcpy(novo->horaP, horaP);
        novo->passageirosVoo = passageirosVoo;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Nao foi possivel cadastrar os dados do voo");
}

// excluir nos voos
VOOS *Excluir_Voo(VOOS **lista, int id)
{
    VOOS *remover = NULL;
    VOOS *aux;
    if (*lista != NULL)
    { // verificacao de preenchimento da lista
        if ((*lista)->identificador == id)
        { // verificando caso o primeiro elemento venha a ser o excluido
            remover = *lista;
            printf("\nDados apagados do Voo ID: %d\n", id);
            printf("\nIdentificador: %d\n", (*lista)->identificador);
            printf("Aeronave: %d\n", (*lista)->numero);
            printf("Empresa aere: %s", (*lista)->empresa);
            printf("Origem: %s", (*lista)->origem);
            printf("Destino: %s", (*lista)->destino);
            printf("Data de partida: %s", (*lista)->dataP);
            printf("Horario de partida: %s", (*lista)->horaP);
            printf("Numero de passageiros: %d\n", (*lista)->passageirosVoo);
            printf("\n\nNova relacao de voos apos remover o voo ID %d do banco de dados do aeroporto: \n", id);
            *lista = remover->proximo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo != NULL && aux->proximo->identificador != id)
            { // caso nao seja o primeiro, ele percorre a lista ate achar o elemento identificador
                aux = aux->proximo;
            }
            if (aux->proximo != NULL)
            { // caso tenha parado por detectar o elemento
                printf("\nDados apagados do Voo ID: %d\n", id);
                printf("\nIdentificador: %d\n", aux->identificador);
                printf("Aeronave: %d\n", aux->numero);
                printf("Empresa aere: %s", aux->empresa);
                printf("Origem: %s", aux->origem);
                printf("Destino: %s", aux->destino);
                printf("Data de partida: %s", aux->dataP);
                printf("Horario de partida: %s", aux->horaP);
                printf("Numero de passageiros: %d\n", aux->passageirosVoo);
                printf("\n\nNova relacao de voos apos remover o voo ID %d do banco de dados do aeroporto: \n", id);
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
            else if (aux->proximo == NULL)
            { // caso tenha parado por nao existir o elemento
                printf("\nNao existe o voo ID %d no banco de dados, tente novamente\n", id);
            }
        }
    }
    return remover;
}

// alternar dados de voo ja existentes
void Alternar_Voo(VOOS **lista)
{
    int numero;
    int altVoo;
    char empresa[1000];
    char origem[1000];
    char destino[1000];
    char dataP[15];
    char horaP[10];
    int passageirosVoo;
    printf("\nDigite o identificador do voo que voce deseja alterar os dados: ");
    scanf("%d", &altVoo);
    printf("Digite o numero da aeronave: ");
    scanf("%d", &numero);
    printf("Digite o nome da empresa aerea: ");
    fflush(stdin);
    fgets(empresa, 1000, stdin);
    printf("Digite a sua origem: ");
    fflush(stdin);
    fgets(origem, 1000, stdin);
    printf("Digite o seu destino: ");
    fflush(stdin);
    fgets(destino, 1000, stdin);
    printf("Digite a data de partida (xx/xx/xx): ");
    fflush(stdin);
    fgets(dataP, 15, stdin);
    printf("Digite o horario de partida (xx:xx): ");
    fflush(stdin);
    fgets(horaP, 10, stdin);
    printf("Digite o numero de passageiros do voo: ");
    scanf("%d", &passageirosVoo);
    VOOS *aux;
    aux = *lista;
    if (aux != NULL)
    { // verificacao de preenchimento da lista

        while (aux != NULL && aux->identificador != altVoo)
        { // percorre ate o fim da lista ou achar o elemento
            aux = aux->proximo;
        }
        if (aux != NULL)
        { // caso tenha parado por detectar o elemento
            aux->numero = numero;
            strcpy(aux->empresa, empresa);
            strcpy(aux->origem, origem);
            strcpy(aux->destino, destino);
            strcpy(aux->dataP, dataP);
            strcpy(aux->horaP, horaP);
            aux->passageirosVoo = passageirosVoo;
        }
        else if (aux == NULL)
        { // caso tenha parado por nao existir o elemento
            printf("\nNao existe o voo ID %d no banco de dados, tente novamente\n", altVoo);
        }
    }
    else
        printf("\nNao existe nenhum voo no banco de dados\n");
}

// impressao dos voos
void Imprimir_Voo(VOOS *voos)
{
    if (voos == NULL)
    { // verificacao de preenchimento da lista
        printf("\nNao existe nenhum voo no banco de dados\n");
    }
    else
    {
        printf("\nVoos: \n");
        while (voos != NULL)
        { // percorre ate o fim da lista
            printf("\nIdentificador: %d\n", voos->identificador);
            printf("Aeronave: %d\n", voos->numero);
            printf("Empresa aerea: %s", voos->empresa);
            printf("Origem: %s", voos->origem);
            printf("Destino: %s", voos->destino);
            printf("Data de partida: %s", voos->dataP);
            printf("Horario de partida: %s", voos->horaP);
            printf("Numero de passageiros: %d\n", voos->passageirosVoo);
            voos = voos->proximo;
            printf("\n");
        }
        printf("\n");
    }
}

//-------------------------------------------------------------------------------------------------------------------------------
/*

                                        AREA DESTINADA A FUNCOES E PROCEDIMENTOS DA LISTA DE PASSAGEIROS

*/

// struct pasageiros
typedef struct No_Passageiros
{
    int identificador;
    char nome[100];
    char identidade[100];
    char endereco[100];
    char telefone[100];
    char sexo[2];
    struct No_Passageiros *proximo;
} PASSAGEIROS;

// inserir nos passageiros
void Inserir_Passageiros(PASSAGEIROS **lista)
{
    PASSAGEIROS *novo = (PASSAGEIROS *)malloc(sizeof(PASSAGEIROS));
    int identificador;
    char nome[100];
    char identidade[100];
    char endereco[100];
    char telefone[100];
    char sexo[2];
    printf("Digite o identificador do passageiro: ");
    scanf("%d", &identificador);
    printf("Digite o nome do passageiro: ");
    fflush(stdin);
    fgets(nome, 100, stdin);
    printf("Digite a identidade do passageiro: ");
    fflush(stdin);
    fgets(identidade, 100, stdin);
    printf("Digite o endereco do passageiro: ");
    fflush(stdin);
    fgets(endereco, 100, stdin);
    printf("Digite o telefone do passageiro: ");
    fflush(stdin);
    fgets(telefone, 100, stdin);
    printf("Digite o sexo do passageiro (F ou M): ");
    fflush(stdin);
    fgets(sexo, 2, stdin);
    if (novo != NULL)
    { // verificacao de preenchimento da lista
        novo->identificador = identificador;
        strcpy(novo->nome, nome);
        strcpy(novo->identidade, identidade);
        strcpy(novo->endereco, endereco);
        strcpy(novo->telefone, telefone);
        strcpy(novo->sexo, sexo);
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Nao foi possivel cadastrar os dados do passageiro");
}

// excluir nos passageiros
PASSAGEIROS *Excluir_Passageiros(PASSAGEIROS **lista, int id)
{
    PASSAGEIROS *remover = NULL;
    PASSAGEIROS *aux;
    if (*lista != NULL)
    { // verificacao de preenchimento da lista
        if ((*lista)->identificador == id)
        { // verificando caso o primeiro elemento venha a ser o excluido
            remover = *lista;
            printf("\nDados apagados do Passageiro numero: %d\n", id);
            printf("Nome: %s", (*lista)->nome);
            printf("Identidade: %s", (*lista)->identidade);
            printf("Endereco: %s", (*lista)->endereco);
            printf("Telefone: %s", (*lista)->telefone);
            printf("Sexo: %s", (*lista)->sexo);
            printf("\n\nNova relacao de passageiros apos remover o passageiro ID %d do banco de dados do aeroporto: \n", id);
            *lista = remover->proximo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo != NULL && aux->proximo->identificador != id)
            { // caso nao seja o primeiro, ele percorre a lista ate achar o elemento identificador
                aux = aux->proximo;
            }
            if (aux->proximo != NULL)
            { // caso tenha parado por detectar o elemento
                printf("\nDados apagados do Passageiro numero: %d\n", id);
                printf("Nome: %s", (*lista)->nome);
                printf("Identidade: %s", (*lista)->identidade);
                printf("Endereco: %s", (*lista)->endereco);
                printf("Telefone: %s", (*lista)->telefone);
                printf("Sexo: %s", (*lista)->sexo);
                printf("\n\nNova relacao de passageiros apos remover o passageiro ID %d do banco de dados do aeroporto: \n", id);
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
            else if (aux->proximo == NULL)
            { // caso tenha parado por nao existir o elemento
                printf("\nNao existe o passageiro ID %d no banco de dados, tente novamente\n", id);
            }
        }
    }
    return remover;
}

// alternar dados de passageiros ja existente
void Alternar_Passageiros(PASSAGEIROS **lista)
{
    int altPassageiros;
    char nome[100];
    char identidade[100];
    char endereco[100];
    char telefone[100];
    char sexo[2];
    printf("\nDigite o numero do passageiro que voce deseja alterar: ");
    scanf("%d", &altPassageiros);
    printf("Digite o nome do passageiro: ");
    fflush(stdin);
    fgets(nome, 100, stdin);
    printf("Digite a identidade do passageiro: ");
    fflush(stdin);
    fgets(identidade, 100, stdin);
    printf("Digite o endereco do passageiro: ");
    fflush(stdin);
    fgets(endereco, 100, stdin);
    printf("Digite o telefone do passageiro: ");
    fflush(stdin);
    fgets(telefone, 100, stdin);
    printf("Digite o sexo do passageiro (F ou M): ");
    fflush(stdin);
    fgets(sexo, 2, stdin);
    PASSAGEIROS *aux;
    aux = *lista;
    if (aux != NULL)
    { // verificacao de preenchimento da lista

        while (aux != NULL && aux->identificador != altPassageiros)
        { // percorre ate o fim da lista ou achar o elemento
            aux = aux->proximo;
        }
        if (aux != NULL)
        { // caso tenha parado por detectar o elemento
            strcpy(aux->nome, nome);
            strcpy(aux->identidade, identidade);
            strcpy(aux->endereco, endereco);
            strcpy(aux->telefone, telefone);
            strcpy(aux->sexo, sexo);
        }
        else if (aux == NULL)
        { // caso tenha parado por nao existir o elemento
            printf("\nNao existe o passageiro ID %d no banco de dados, tente novamente\n", altPassageiros);
        }
    }
    else
        printf("\nNao existe nenhum passageiro no banco de dados\n");
}

// impressao dos passageiros
void Imprimir_Passageiros(PASSAGEIROS *passageiros)
{
    if (passageiros == NULL)
    { // verificacao de preenchimento da lista
        printf("\nNao existe nenhum passageiro no banco de dados\n");
    }
    else
    {
        printf("\nPassageiros: \n");
        while (passageiros != NULL)
        { // percorre ate o fim da lista
            printf("\nIdentificador: %d\n", passageiros->identificador);
            printf("Nome do passageiro: %s", passageiros->nome);
            printf("Identidade do passageiro: %s", passageiros->identidade);
            printf("Endereco do passageiro: %s", passageiros->endereco);
            printf("Telefone do passageiro: %s", passageiros->telefone);
            printf("Sexo do passageiro: %s", passageiros->sexo);
            passageiros = passageiros->proximo;
            printf("\n");
        }
        printf("\n");
    }
}

//-------------------------------------------------------------------------------------------------------------------------------
/*

                                        AREA DESTINADA A FUNCOES E PROCEDIEMNTOS DA LISTA DE PASSAGEMS

*/

// struct de passagens
typedef struct No_Passagens
{
    int numero;
    int identificadorPassageiro;
    int identificadorVoo;
    float valor;
    char data[15];
    struct No_Passagens *proximo;
} PASSAGENS;

// inserir nas passagens
void Inserir_Passagens(PASSAGENS **lista)
{
    PASSAGENS *novo = (PASSAGENS *)malloc(sizeof(PASSAGENS));
    int numero;
    int identificadorPassageiro;
    int identificadorVoo;
    float valor;
    char data[15];
    printf("Digite o numero da passagem: ");
    scanf("%d", &numero);
    printf("Digite o identificador do passageiro: ");
    scanf("%d", &identificadorPassageiro);
    printf("Digite o identificador do voo: ");
    scanf("%d", &identificadorVoo);
    printf("Digite o preco da passagem: ");
    scanf("%f", &valor);
    printf("Digite a data da venda (xx/xx/xx): ");
    fflush(stdin);
    fgets(data, 15, stdin);
    if (novo != NULL)
    { // verificacao de preenchimento da lista
        novo->numero = numero;
        novo->identificadorPassageiro = identificadorPassageiro;
        novo->identificadorVoo = identificadorVoo;
        novo->valor = valor;
        strcpy(novo->data, data);
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Nao foi possivel cadastrar os dados da passagem");
}

// excluir nas passagems
PASSAGENS *Excluir_Passagens(PASSAGENS **lista, int id)
{
    PASSAGENS *remover = NULL;
    PASSAGENS *aux;
    if (*lista != NULL)
    { // verificacao de preenchimento da lista
        if ((*lista)->numero == id)
        { // verificando caso o primeiro elemento venha a ser o excluido
            remover = *lista;
            printf("\nDados apagados da Passagem numero: %d\n", id);
            printf("\nIdentificador do passageiro: %d\n", (*lista)->identificadorPassageiro);
            printf("\nIdentificador do voo: %d\n", (*lista)->identificadorVoo);
            printf("\nValor da passagem: %.2f\n", (*lista)->valor);
            printf("Data da venda: %s", (*lista)->data);
            printf("\n\nNova relacao de passagens apos remover a passagem numero %d do banco de dados do aeroporto: \n", id);
            *lista = remover->proximo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo != NULL && aux->proximo->numero != id)
            { // caso nao seja o primeiro, ele percorre a lista ate achar o elemento identificador
                aux = aux->proximo;
            }
            if (aux->proximo != NULL)
            { // caso tenha parado por detectar o elemento
                printf("\nDados apagados da Passagem numero: %d\n", id);
                printf("\nIdentificador do passageiro: %d\n", (*lista)->identificadorPassageiro);
                printf("\nIdentificador do voo: %d\n", (*lista)->identificadorVoo);
                printf("\nValor da passagem: %.2f\n", (*lista)->valor);
                printf("Data da venda: %s", (*lista)->data);
                printf("\n\nNova relacao de passagens apos remover a passagem numero %d do banco de dados do aeroporto: \n", id);
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
            else if (aux->proximo == NULL)
            { // caso tenha parado por nao existir o elemento
                printf("\nNao existe a passagem numero %d no banco de dados, tente novamente\n", id);
            }
        }
    }
    return remover;
}

// alternar dados de passagem ja existente
void Alternar_Passagens(PASSAGENS **lista)
{
    int altPassagens;
    int identificadorPassageiro;
    int identificadorVoo;
    float valor;
    char data[15];
    printf("\nDigite o numero da passagem que voce deseja alterar: ");
    scanf("%d", &altPassagens);
    printf("Digite o identificador do passageiro: ");
    scanf("%d", &identificadorPassageiro);
    printf("Digite o identificador do voo: ");
    scanf("%d", &identificadorVoo);
    printf("Digite o preco da passagem: ");
    scanf("%f", &valor);
    printf("Digite a data de partida (xx/xx/xx): ");
    fflush(stdin);
    fgets(data, 15, stdin);
    PASSAGENS *aux;
    aux = *lista;
    if (aux != NULL)
    { // verificacao de preenchimento da lista

        while (aux != NULL && aux->numero != altPassagens)
        { // percorre ate o fim da lista ou achar o elemento
            aux = aux->proximo;
        }
        if (aux != NULL)
        { // caso tenha parado por detectar o elemento
            aux->identificadorPassageiro = identificadorPassageiro;
            aux->identificadorVoo = identificadorVoo;
            aux->valor = valor;
            strcpy(aux->data, data);
        }
        else if (aux == NULL)
        { // caso tenha parado por nao existir o elemento
            printf("\nNao existe a passagem numero %d no banco de dados, tente novamente\n", altPassagens);
        }
    }
    else
        printf("\nNao existe nenhuma passagem no banco de dados\n");
}

// impressao das passagens
void Imprimir_Passagens(PASSAGENS *passagens)
{
    if (passagens == NULL)
    { // verificacao de preenchimento da lista
        printf("\nNao existe nenhuma passagem no banco de dados\n");
    }
    else
    {
        printf("\nPassagens: \n");
        while (passagens != NULL)
        { // percorre ate o fim da lista
            printf("\nNumero: %d\n", passagens->numero);
            printf("Identificador do passageiro: %d\n", passagens->identificadorPassageiro);
            printf("Identificador do voo: %d\n", passagens->identificadorVoo);
            printf("Valor da passagem: %.2f\n", passagens->valor);
            printf("Data da venda: %s", passagens->data);
            passagens = passagens->proximo;
            printf("\n");
        }
        printf("\n");
    }
}

//-------------------------------------------------------------------------------------------------------------------------------
/*

                                         AREA DESTINADA AOS PROCEDIMENTOS DO RELATORIO

*/

// quantidade de passagens vendidas por voo
void QtePassagens(VOOS *listaVoo, PASSAGENS *listaPassagens)
{
    VOOS *auxVoo = listaVoo;
    PASSAGENS *auxPassagens = listaPassagens;
    if (auxVoo == NULL)
    { // verificacao de preenchimento da lista
        printf("\nNao existe nenhum voo no banco de dados\n");
    }
    else
    {

        while (auxVoo != NULL)
        {                                  // condicao de encerramento da lista de voos
            auxPassagens = listaPassagens; // reseta para o inicio da lista
            int count = 0;                 // zera o contador
            while (auxPassagens != NULL)
            { // condicao de encerramento da lista de passagens
                if (auxPassagens->identificadorVoo == auxVoo->identificador)
                {
                    count++; // incremento de acordo com a comparacao
                }
                auxPassagens = auxPassagens->proximo;
            }

            printf("\nExiste(em) %d passagem(s) vendida(s) no voo %d\n", count, auxVoo->identificador); // impressao dos dados
            auxVoo = auxVoo->proximo;
        }
    }
}

// quantidade de voos por empresa
void QteVoosPorEmpresa(VOOS *listaVoo)
{
    VOOS *auxLista = listaVoo;
    VOOS *auxPercorrer = listaVoo;
    char empresas[50][100]; // max 50 voos
    int emp = 0;
    int empresaChecar = 0;
    int count = 0;

    if (auxLista == NULL)
    { // verificacao de preenchimento da lista
        printf("\nNao existe nenhum voo no banco de dados\n");
    }
    else
    {
        while (auxLista != NULL)
        { // condicao de encerramento da lista de voos
            empresaChecar = 0;

            for (int i = 0; i < emp; i++)
            { // verificar no vetor caso a empresa a ser analisada ja foi uma vez escrita
                if (strcmp(empresas[i], auxLista->empresa) == 0)
                {
                    empresaChecar++;
                }
            }
            if (empresaChecar == 0)
            {              // caso nao exista no vetor
                count = 0; // zera o contador
                auxPercorrer = listaVoo;

                while (auxPercorrer != NULL)
                {
                    if (strcmp(auxLista->empresa, auxPercorrer->empresa) == 0)
                    {
                        count++; // incrementa de acordo com a comparacao feita
                    }
                    auxPercorrer = auxPercorrer->proximo;
                }

                printf("\nEmpresa: %sNumero de voos no banco de dados: %d\n", auxLista->empresa, count); // impressao dos passageiros do voo
                strcpy(empresas[emp], auxLista->empresa);
                emp++;
            }
            auxLista = auxLista->proximo;
        }
    }
}

// Lista de Passageiros por voo
void ListaPassageirosPorVoo(VOOS *voos, PASSAGEIROS *passageiros, PASSAGENS *passagens)
{
    PASSAGENS *auxPassagem = passagens;
    PASSAGEIROS *auxPassageiro = passageiros;
    if (voos == NULL)
    { // verificacao de preenchimento da lista
        printf("\nNao existe nenhum voo no banco de dados\n");
    }
    if (passageiros == NULL)
    { // verificacao de preenchimento da lista
        printf("\nNao existe nenhum passageiro no banco de dados\n");
    }
    if (passagens == NULL)
    { // verificacao de preenchimento da lista
        printf("\nNao existe nenhuma passagem no banco de dados\n");
    }

    while (voos != NULL)
    { // condicao de encerramento da lista de voos
        printf("\nPassageiros presentes no voo ID %d:\n", voos->identificador);
        auxPassagem = passagens; // volta o auxiliar para o primeiro cadastro
        while (auxPassagem != NULL)
        {
            if (auxPassagem->identificadorVoo == voos->identificador)
            {
                auxPassageiro = passageiros; // volta o auxiliar para o primeiro cadastro
                while (auxPassageiro != NULL)
                {
                    if (auxPassageiro->identificador == auxPassagem->identificadorPassageiro)
                    {                                            // compara os identificadores para achar o passageiro
                        printf("Nome: %s", auxPassageiro->nome); // imprimi o nome do passegiro do voo x
                    }
                    auxPassageiro = auxPassageiro->proximo;
                }
            }
            auxPassagem = auxPassagem->proximo;
        }
        voos = voos->proximo;
        printf("\n");
    }
}

//-------------------------------------------------------------------------------------------------------------------------------

int main()
{
    int comando;
    int comandoVoo;
    int comandoPassagens;
    int comandoPassageiros;
    int comandoRelatorios;
    int altVoo;
    int altPassagens;
    int altPassageiros;
    int voos = 0;
    int passagens = 0;
    int passageiros = 0;
    VOOS *listaVoo = NULL;
    VOOS *removerVoo = NULL;
    PASSAGENS *listaPassagens = NULL;
    PASSAGENS *removerPassagens = NULL;
    PASSAGEIROS *listaPassageiros = NULL;
    PASSAGEIROS *removerPassageiros = NULL;

    do
    {
        printf("\nMenu Principal: \n1- Voos\n2- Passageiros\n3- Passagens\n4- Relatorios\n5- Sair\n");
        scanf("%d", &comando);

        switch (comando)
        {
        case 1: // voos
            do
            {

                printf("\nMenu Voos: \n1- Incluir\n2- Alterar\n3- Excluir\n4- Consultar\n5- Sair\n");
                scanf("%d", &comandoVoo);

                switch (comandoVoo)
                {

                case 1: // incluir
                    voos++;
                    if (voos <= MAX_VOOS)
                    { // LIMITE ESTIPULADO NO COMANDO
                        Inserir_Voo(&listaVoo);
                    }
                    else
                        printf("\nMaximo alcancado de voos\n");
                    break;

                case 2: // alterar
                    Imprimir_Voo(listaVoo);
                    Alternar_Voo(&listaVoo);
                    printf("\nLista de voos apos a atualizacao dos dados: \n");
                    Imprimir_Voo(listaVoo);
                    break;

                case 3: // excluir
                    Imprimir_Voo(listaVoo);
                    printf("\nDigite o identificador do voo que voce deseja remover os dados: ");
                    scanf("%d", &altVoo);
                    removerVoo = Excluir_Voo(&listaVoo, altVoo);
                    free(removerVoo);
                    Imprimir_Voo(listaVoo);
                    break;

                case 4: // consultar
                    Imprimir_Voo(listaVoo);
                    break;
                }
            } while (comandoVoo != 5);
            break;

        case 2: // passageiros
            do
            {

                printf("\nMenu Passageiros: \n1- Incluir\n2- Alterar\n3- Excluir\n4- Consultar\n5- Sair\n");
                scanf("%d", &comandoPassageiros);

                switch (comandoPassageiros)
                {

                case 1: // incluir
                    passageiros++;
                    if (passageiros <= MAX_PASSAGEIROS)
                    { // LIMITE ESTIPULADO NO COMANDO
                        Inserir_Passageiros(&listaPassageiros);
                    }
                    else
                        printf("\nMaximo alcancado de passageiros\n");
                    break;

                case 2: // alterar
                    Imprimir_Passageiros(listaPassageiros);
                    Alternar_Passageiros(&listaPassageiros);
                    printf("\nLista de passageiros apos a atualizacao dos dados: \n");
                    Imprimir_Passageiros(listaPassageiros);
                    break;

                case 3: // excluir
                    Imprimir_Passageiros(listaPassageiros);
                    printf("\nDigite o identificador do passageiro que voce deseja remover os dados: ");
                    scanf("%d", &altPassageiros);
                    removerPassageiros = Excluir_Passageiros(&listaPassageiros, altPassageiros);
                    free(removerPassageiros);
                    Imprimir_Passageiros(listaPassageiros);
                    break;

                case 4: // consultar
                    Imprimir_Passageiros(listaPassageiros);
                    break;
                }
            } while (comandoPassageiros != 5);
            break;

        case 3: // passagens
            do
            {

                printf("\nMenu Passagens: \n1- Incluir\n2- Alterar\n3- Excluir\n4- Consultar\n5- Sair\n");
                scanf("%d", &comandoPassagens);

                switch (comandoPassagens)
                {

                case 1: // incluir
                    passagens++;
                    if (passagens <= MAX_PASSAGENS)
                    { // LIMITE ESTIPULADO NO COMANDO
                        Inserir_Passagens(&listaPassagens);
                    }
                    else
                        printf("\nMaximo alcancado de passagens\n");
                    break;

                case 2: // alterar
                    Imprimir_Passagens(listaPassagens);
                    Alternar_Passagens(&listaPassagens);
                    printf("\nLista de passagens apos a atualizacao dos dados: \n");
                    Imprimir_Passagens(listaPassagens);
                    break;

                case 3: // excluir
                    Imprimir_Passagens(listaPassagens);
                    printf("\nDigite o numero da passagem que voce deseja remover os dados: ");
                    scanf("%d", &altPassagens);
                    removerPassagens = Excluir_Passagens(&listaPassagens, altPassagens);
                    free(removerPassagens);
                    Imprimir_Passagens(listaPassagens);
                    break;

                case 4: // consultar
                    Imprimir_Passagens(listaPassagens);
                    break;
                }
            } while (comandoPassagens != 5);
            break;

        case 4: // relatorios
            do
            {
                printf("\nMenu Relatorio: \n1- Quantidade de passagens vendidas por voo\n2- Quantidades de voo por empresa\n3- Lista de passageiros por voo\n4- Sair\n");
                scanf("%d", &comandoRelatorios);

                switch (comandoRelatorios)
                {

                case 1: // quantidade de passagens por voo
                    QtePassagens(listaVoo, listaPassagens);
                    break;
                case 2: // quantidade de voos por empresa
                    QteVoosPorEmpresa(listaVoo);
                    break;
                case 3: // lista de passageiros por voo
                    ListaPassageirosPorVoo(listaVoo, listaPassageiros, listaPassagens);
                    break;
                }
            } while (comandoRelatorios != 4);
        }
    } while (comando != 5);
    free(listaVoo);
    free(listaPassageiros);
    free(listaPassagens);
    return 0;
}