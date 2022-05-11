#include <stdio.h>

//TRABALHO PARA A TERCEIRA UNIDADE DA DISCIPLINA DE CONSTRUÇÃO DE ALGORITMOS
//Professor: Chico Dantas
//Desenvolvido por: Talysson Emanoel


typedef struct data //Essa estruct irá armazenar as informações da data de aniversário, que irá dentro da struct contact
{
    char day[2];
    char month[2];
}data;


typedef struct contact //struct para definição armazenamento de contatos
{
	int empty; /*variável para armazenar a informação se o espaço para contato está "vazio"
	ou se já foi inserido informações nele. A variável terá o valor de 0 para preenchido, e 1 para vazio*/
	char name[40];
    char phone[15];
    char celphone[15];
    char email[40];
    data birthday;//Utilizando a strutc data, já criada, para armazenar as informações de aniversário do contato (dia e mês)
    
}contact;

/*Antes de inicar o programa, é importante certificar que todos os espaços para armazenamentos estejam "vazios".
Principalmente as células de strings, que será necessário que estejam "nulas" para ser possível utilizar a função de
comparação futuramente. Desta forma, utilizaremos a função clearvet para limpar as variáveis da nossa lista de contatos*/
contact clearvet(contact x[],int length)
{
	for(int i=0;i<length;i++)//O primeiro for irá varrer os índices do vetor de contact
	{	
		for(int j;j<length;j++)//Já o segundo for irá varrer, e "zerar", os vetores de caracteres(strings).
		{
			x[i].name[j]='\0'; //\0 será utilizado para atibruir o valor de "nulo" para a posição do índice.
			x[i].phone[j]='\0';
			x[i].celphone[j]='\0';
			x[i].email[j]='\0';
		}
		for(int j;j<2;j++)
		{
			x[i].birthday.day[j]='\0';
			x[i].birthday.month[j]='\0';
		}
		x[i].empty=1; //Importante alterar o valor de 'empty' para 1, pois o espaço atual do contact ficará vazio.
	}
}

contact insere_contato(contact x[],int index) //função para inserir contato na lista
{	
    if(x[index].empty==1)
    {
		printf("\nNome: ");
	    fgetc(stdin); //funcao para limpar/ler um \n da leitura anterior
	    gets(x[index].name);
		printf("Telefone fixo: ");
	    gets(x[index].phone);
		printf("Celular: ");
	    gets (x[index].celphone);
	    printf("Email: ");
	    gets(x[index].email);
	    printf("Dia do aniversario: ");
	    scanf("%s",x[index].birthday.day);
	    printf("Mes do aniversario: ");
	    scanf("%s",x[index].birthday.month);
	    x[index].empty=0; /*Novamente, ao final da funcção de inserir contato, o valor 0 será atribuído para o 'empty',
		pois o espaço para contato não estará mais vazio*/
	}   
}

contact listar_contatos(contact x[])//Função que irá listar todos os contatos inseridos até então
{

printf("\n---------- LISTA DE CONTATOS ----------\n");

for(int i=0;i<40;i++)
	{
		if(x[i].empty==0)//A condição irá identificar se o espaço está preenchido (0). Caso true, lista o contato
		{
			printf("\nNome: %s\nTelefone: %s\nCelular: %s\nEmail: %s\nAniversario: %c%c/%c%c\n",x[i].name,x[i].phone,x[i].celphone,x[i].email,x[i].birthday.day[0],x[i].birthday.day[1],x[i].birthday.month[0],x[i].birthday.month[1]);
		}		
	}
printf("---------------------------------------\n");
}


/*Função para encontrar o tamanho, em quantidade de caracteres, de uma string.
Será utilizada na função de comparação de strings, que por sua vez será utilizada na função para buscar contatos.*/
int tamanho(char x[])
{
	int length=0;//variável para armazenar a informação de tamanho da string
	for(int i=0;i<40;i++)
	{
		if(x[i]!='\0')//O for irá varrer todas as posições de memória da string até encontrar uma posição com valor nulo
		{
			length ++;//Enquanto o valor não for nulo, a variável tamanho irá somar +1
		}
		else
		{
			return length;//Quando o for encontrado o primeiro valor nulo, a função irá retornar o tamanho registrado.
		}
	}
	return length;/*Caso o for complete o seu cilo e todos os valores estejam preenchidos, 
	a função também irá retornar o tamanho final.*/
}


/*Função que irá comparar se duas strings são iguais. 0 para diferentes e 1 para iguais*/
int comparar(contact x,char y[],int length)//A função terá três parametros, sendo um deles o tamanho da string, que será muito importante
{
	for(int i=0;i<length;i++)//O for irá varrer até o tamanho informado no parametro de entrada
	{
		if(x.name[i]!=y[i])
		{
			return 0;
		}
	}
	return 1;
}

//funcao para realizar a busta na agenda telefonica
contact busca_contato(contact x[])/*A função terá apenas um parametro, que será o vetor de contact que iremos realizar a busca*/
{	
	int igual;//Variável reservada para receber o valor da função comparar()
	char search[40];//Variável para a entrada do usuário
	fgetc(stdin);
	gets(search);
	int encontrados=0;//Variável reservada para armazenar quantos contatos foram localizados
	
	printf("\n---------- RESULTADO DA BUSCA ----------\n");
	for(int i=0;i<40;i++)
	{
		/*A função 'tamanho()' irá como parametro para a função 'comparar()'.
		Assim ela retornar o valor inteiro que será utilizado para determinar o tamanho da string a ser comparada.*/
		
		igual=comparar(x[i],search,tamanho(search));/*Poderá ser utilizada as variáveis 'x[i]' ou 'search' como parametros
		para a função tamanho(), a diferença é que se escolhermos a variável de tipo contact x[i], a função busca_contato()
		só irá retornar na busca, apenas os contatos que são identicos a string informada.
		Já se utilizarmos'search' como parametro, a função de 'busca_contato()' irá retornar todos os contatos que começam
		com a string informada. Para deixar o programa mais "inteligente", irei usar a variável search, que é a entrada do
		usuário, como parametro para função tamanho()*/

		if(igual==1)
		{
			printf("\nNome: %s\nTelefone: %s\nCelular: %s\nEmail: %s\nAniversario: %c%c/%c%c\n",x[i].name,x[i].phone,x[i].celphone,x[i].email,x[i].birthday.day[0],x[i].birthday.day[1],x[i].birthday.month[0],x[i].birthday.month[1]);
			encontrados++;//Contabilizando a quantidade de contatos localizados
		}
	}
	if(encontrados!=0)
	{
		printf("\n\n%d Contato(s) encontrado(s)\n----------------------------------------",encontrados);
	}
	else//Caso a variável permaneça em 0 ao final do laço for, significa que nenhum contato foi localizado
	{
		printf("\nNenhum contato encontrado\n\n----------------------------------------");
	}
}


int main()
{
    contact vet[40];//Será o espaço para contatos do programa
    int index=0; //Será utilizado para controlar o índice do vetor
    int choice=0; //Será utilizado para controlar a decisão do usuário
  	
	clearvet(vet,40);
 	
 	printf("-------------------\n       MENU\n-------------------\n1 - Inserir Contato\n2 - Listar Contatos\n3 - Buscar Contatos\n4 - Sair\n-------------------\n\n");
	scanf("%d",& choice);
 	
  	do
	{
		/*Para o método de escolha foi utilizado while ao invés de if, pois enquanto a opção do usuario não mudar,
		o programa não irá precisar varrer todo o código até chegar na mesmo opção*/
		
		if(choice!=1 && choice!=2 && choice!=3 && choice!=4)
		{
			printf("\nOpcao nao encontrada!!!\nFinalizando Aplicativo\n\n");
			return 0;
		}
		while(choice==1) //Neste caso o programa só irá sair do laço while caso a escolha do usuario seja diferente de 1
		{
    		insere_contato(vet,index);
    		index++;//Iremos tomar +1 no index, para caso desejar adicionar um novo contato, ele não sobreponha o anterior
	    	printf("\n\n-------------------\n       MENU\n-------------------\n1 - Inserir Contato\n2 - Listar Contatos\n3 - Buscar Contatos\n4 - Sair\n-------------------\n\n");
	    	scanf("%d",& choice);
		}
    	while(choice==2)
    	{
    		listar_contatos(vet);	
			printf("\n\n-------------------\n       MENU\n-------------------\n1 - Inserir Contato\n2 - Listar Contatos\n3 - Buscar Contatos\n4 - Sair\n-------------------\n\n");
	    	scanf("%d",& choice);
		}
		while(choice==3)
		{
			busca_contato(vet);
			printf("\n\n-------------------\n       MENU\n-------------------\n1 - Inserir Contato\n2 - Listar Contatos\n3 - Buscar Contatos\n4 - Sair\n-------------------\n\n");
			scanf("%d",& choice);
		}
	}while(choice!=4);
    
    return 0;

}
