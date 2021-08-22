//Projeto C feita com os conhecimentos de C adquiridos durante o semestre. 

/*
Segue um pdf com o código fonte do qual retrata um esquema básico em fluxograma do nosso projeto. Devido à limitações de recursos 
*/

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct{

    char id[30], password[30];

} login;

typedef struct {

    char id[30], password[30], nome[30], genero, tipoDeConta;
    int idade, filhos;

} dadosCadastrais;

login telaLogin(login Login){

    int opcao;
    char id[30], password[30];
    FILE *arquivoLogin;

    system("cls");

    printf("Digite o usuario: ");
    scanf(" %[^\n]", id);
    printf("Digite a senha: ");
    scanf(" %[^\n]", password);

    arquivoLogin = fopen("login.txt", "r");

    while (fread(&Login, sizeof(Login), 1, arquivoLogin) == 1) {
        if (strcmp(id, Login.id) == 0)
            if (strcmp(password, Login.password) == 0) {
                printf("Login realizado com sucesso!\n");
                system("pause");
                system("cls");
                fclose(arquivoLogin);
                return Login; 
            }
    }
    fclose(arquivoLogin);
    printf("Login nao encontrado!\n");
    do {
        printf("Deseja criar uma conta? (1-SIM/0-NAO): ");
        scanf("%d", &opcao);
    } while(opcao != 1 || opcao != 0);
    if (opcao == 1)
        realizarCadastro();
    else 
        telaLogin(Login);
    
}

void pesquisaSocioeconomico() {
    int opcaoRenda, opcaoPessoas, opcaoPai, opcaoMae, opcaoBanheiro, opcaoQuarto, opcaoCarro, opcaoGeladeira, opcaoTelevisao, opcaoComputador;
    int situacao = FALSE;
    int pontos;
    login Login;
  
    printf("Qual é a renda total mensal de sua família? \n
            (1) Até 1 SM ou até R$ 1.100,00. \n
            (2) De 1,0 a 2,0 SM ou de R$ 1.100,00 a R$ 2.200,00. \n
            (3) De 2,0 a 3,0 SM ou de R$ 2.200,00 a R$ 3.300,00. \n
            (4) De 3,0 a 4,0 SM ou de R$ 3.300,00 a R$ 4.400,00. \n
            (5) De 4,0 SM ou mais\n");
    scanf("%d", &opcaoRenda);
    
    prinf("Quantas pessoas vivem da renda familiar indicada na pergunta anterior? \n
           (1) Uma. \n
           (2) Duas. \n
           (3) Três. \n
           (4) Quatro. \n
           (5) Cinco. \n
           (6) Seis ou mais. \n");
    scanf("%d", &opcaoPessoas);
    
    printf("Qual é o grau de instrução do pai e/ou responsável? \n
            (1) Analfabeto/ausente. \n
            (2) Ensino fundamental incompleto. \n
            (3) Ensino fundamental completo. \n
            (4) Ensino médio completo. \n
            (5) Superior incompleto. \n
            (6) Superior completo.\n");
    scanf("%d", &opcaoPai);

    printf("Qual é o grau de instrução da mãe e/ou responsável? \n
            (1) Analfabeto/ausente. \n
            (2) Ensino fundamental incompleto. \n
            (3) Ensino fundamental completo. \n
            (4) Ensino médio completo. \n
            (5) Superior incompleto. \n
            (6) Superior completo. \n");
    scanf("%d", &opcaoMae);

    printf("Na sua residência tem banheiro?\n 
            (1) Não. \n 
            (2) Sim, um.\n 
            (3) Sim, dois. \n 
            (4) Sim, três. \n 
            (5) Sim, quatro ou mais.\n");
    scanf("%d", &opcaoBanheiro);
    
    printf("Na sua residência tem quartos para dormir?\n 
            (1) Não. \n 
            (2) Sim, um.\n 
            (3) Sim, dois. \n 
            (4) Sim, três. \n 
            (5) Sim, quatro ou mais.\n");
    scanf("%d", &opcaoQuarto);

    printf("Na sua residência tem veículo?\n 
            (1) Não. \n 
            (2) Sim, um.\n 
            (3) Sim, dois. \n 
            (4) Sim, três. \n 
            (5) Sim, quatro ou mais.\n");
    scanf("%d", &opcaoCarro);

    printf("Na sua residência tem geladeira\n 
            (1) Não. \n 
            (2) Sim, um.\n 
            (3) Sim, dois. \n 
            (4) Sim, três. \n 
            (5) Sim, quatro ou mais.\n");
    scanf("%d", &opcaoGeladeira);

    printf("Na sua residência tem televisão?\n 
            (1) Não. \n 
            (2) Sim, um.\n 
            (3) Sim, dois. \n 
            (4) Sim, três. \n 
            (5) Sim, quatro ou mais.\n");
    scanf("%d", &opcaoTelevisao);

    printf("Na sua residência tem computador?\n 
            (1) Não. \n 
            (2) Sim, um.\n 
            (3) Sim, dois. \n 
            (4) Sim, três. \n 
            (5) Sim, quatro ou mais.\n");
    scanf("%d", &opcaoComputador);

    if(opcaoRenda==1) zpontos+= 10;
    if(opcaoRenda==2) pontos+= 5;
    if(opcaoRenda==3) pontos+= 3;
    if(opcaoRenda==4) pontos+= 1;
    
    if(opcaoPessoas==6) pontos+= 10;
    if(opcaoPessoas==5) pontos+= 5;
    if(opcaoPessoas==4) pontos+= 3;
    if(opcaoPessoas==3) pontos+= 1;

    if(opcaoPai==1) pontos+= 10;
    if(opcaoPai==2) pontos+= 8;
    if(opcaoPai==3) pontos+= 5;
    if(opcaoPai==4) pontos+= 3;

    if(opcaoMae==1) pontos+= 10;
    if(opcaoMae==2) pontos+= 8;
    if(opcaoMae==3) pontos+= 5;
    if(opcaoMae==4) pontos+= 3;

    if(opcaoBanheiro==1) pontos+= 10;
    if(opcaoBanheiro==2) pontos+= 5;
    if(opcaoBanheiro==3) pontos+= 3;

    if(opcaoQuarto==1) pontos+= 10;
    if(opcaoQuarto==2) pontos+= 8;
    if(opcaoQuarto==3) pontos+= 5;

    if(opcaoCarro==1) pontos+= 10;
    if(opcaoCarro==2) pontos+= 5;

    if(opcaoGeladeira==1) pontos+= 10;
    if(opcaoGeladeira==2) pontos+= 3;

    if(opcaoTelevisao==1) pontos+= 10;
    if(opcaoTelevisao==2) pontos+= 5;

    if(opcaoComputador==1) pontos+= 10;
    if(opcaoComputador==2) pontos+= 5;
    if(opcaoComputador==3) pontos+= 1;
    
    if(pontos>= 40) situacao= TRUE;

    if (situacao == FALSE) { 
        printf("Sinto muito, voce nao pode realizar o cadastro em nosso sistema.\n");
        telaLogin(Login);
    }
    printf("Parabens! Voce esta apto para realizar o cadastro em nosso sistema.\n");
    realizarCadastro();
        
}

void realizarCadastro() {
    
    dadosCadastrais p;
    FILE *arquivoLogin;
    login Login;

    system("cls");
    
    printf("******** CADASTRO ********\n");
    printf("Nome: ");
    scanf(" %[^\n]", p.nome); 
    printf("Idade: "); 
    scanf("%d", &p.idade); 
    printf("Genero (M - Masculino; F - Feminino; O - Outro;): "); 
    scanf(" %c", &p.genero); 
    printf("Filhos: "); 
    scanf("%d", &p.filhos); 
    printf("Escolha um ID: ");
    scanf(" %[^\n]", p.id);
    printf("Digite uma senha: ");
    scanf(" %[^\n]", p.password);
    printf("Digite 'd' se voce pretende doar e 'n' se voce pretende receber doacoes: ");
    scanf(" %c", &p.tipoDeConta);
    
    arquivoLogin = fopen("login.txt", "r+");

    while (fread(&Login, sizeof(Login), 1, arquivoLogin) == 1) {
        if (strcmp(p.id, Login.id) == 0) {
            printf("Cadastro nao realizado, pois o id ja existe!\nTente novamente!\n");
            system("pause");
            realizarCadastro();
        }
    }

    fwrite(&p, sizeof(p), 1, arquivoLogin);
    fclose(arquivoLogin);

    if (p.tipoDeConta == 'd') {
        arquivoLogin = fopen("doador.txt", "r+");
        fwrite(&p, sizeof(p), 1, arquivoLogin);
    }
    else if (p.tipoDeConta == 'n') {
        arquivoLogin = fopen("necessitado.txt", "r+");
        fwrite(&p, sizeof(p), 1, arquivoLogin);
    }
    fclose(arquivoLogin);
    printf("Cadastro realizado com sucesso!");
    system("pause");
    telaLogin(Login);

}

void interfaceNecessitado() {

    int opcaoMenu;
    
    system("cls");

    printf("**** MENU ****\n");
    printf("1 - Adicionar um produto que deseja solicitar doacao\n");
    printf("0 - SAIR\n"); 
    do {
        printf("Opcao: ");
        scanf("%d", &opcaoMenu);
    } while(opcao != 1 || opcao != 0);  
    if (opcao == 0)
        return 0;
    
}

void interfaceDoador() {
    
    int opcaoMenu;
    
    system("cls");

    printf("**** MENU ****\n");
    printf("1 - Cadastrar um produto que deseja doar\n");
    printf("2 - Retirar um produto que deseja doar\n");
    printf("0 - SAIR\n");   
    do {
        printf("Opcao: ");
        scanf("%d", &opcaoMenu);
    } while(opcao != 2 || opcao != 1 || opcao != 0);  
    if (opcao == 0)
        return 0;
    
}

void interfaceAdministrador() {
    
    int opcaoMenu;
    
    system("cls");

    printf("**** MENU ****\n");
    printf("1 - Consultar todos os produtos prontos para doacao\n");
    printf("2 - Consultar todos os usuarios necessitados\n");
    printf("3 - Consultar todos os usuarios doadores\n");
    printf("0 - SAIR\n");   
    scanf("%d", &opcaoMenu);
    do {
        printf("Opcao: ");
        scanf("%d", &opcaoMenu);
    } while(opcao != 3 || opcao != 2 || opcao != 1 || opcao != 0);  
    if (opcao == 0)
        return 0;
    
}

int main() {

    login Login;
    telaLogin(Login);
    

    return 0;
}