//////////////////////  BATALHA NAVAL  ///////////////////
// 														//
// Lucca Amorim		RA: 1680961913020				    //
// Nathan Branco	RA: 1680961913037					//
// Lucas Silva		RA: 1680961913003					//
// Gabriel Leandro	RA: 1680961913046					//
//														//
//////////////////////////////////////////////////////////

////////////////// UDP SERVER CODE /////////////////

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define linha 10
#define coluna 10

//Tabuleiro do usuário
char myTable[coluna][linha];

//Tabuleiro inimigo
char enemyTable[coluna][linha];

void ZerarMapa(char Mapa[coluna][linha]) {
  int x, y;
  for (y = 0; y < linha; y++) {
    for (x = 0; x < coluna; x++) {
      Mapa[x][y] = ' ';
    }
  }
}

void Submarino(char Mapa[coluna][linha]) {
	//Esse código impede barcos aparecerem perto demais
	//Representado pelo numero 1
	
	int i, c, d, rx, ry;
	int valido = 1;
	for(i = 0; i <4 ;i ++) {
  		rx = rand()%10; ry = rand()%10;
		for (d = 0; d < 3; d++) {
			for (c = 0; c < 3; c++) {
				if(rx == 0 && c == 0) c = c + 1;
				if(ry == 0 && d == 0) d = d + 1;  
				if(Mapa[rx + (- 1 + c)][ry + (- 1 + d)] != ' ')
					valido = 0;
			}
		}
		
		if(valido == 1)
			Mapa[rx][ry] = '#';
		else 
			i--; valido = 1;
	}
}


void Encouracado(char Mapa[coluna][linha]) {
	
	//Esse código impede barcos aparecerem perto demais
	//Representado pelo numero 2
	
	int i, c, d, rx, ry, dir;
	int valido = 1;
	for(i = 0; i <3 ;i ++) {
  		rx = rand()%10; ry = rand()%10; 
		for (d = 0; d < 5; d++) {
			for (c = 0; c < 5; c++) {
				if((rx == 0 && c <= 1) || (rx == 1 && c == 0)) c = c + 1;
				if((ry == 0 && d <= 1) || (ry == 1 && d == 0)) d = d + 1;  
				if(Mapa[rx + (- 2 + c)][ry + (- 2 + d)] != ' ')
					valido = 0;
			}
		}
		
		if(valido) {
			
			Mapa[rx][ry] = '#';
			
			
			dir = rand()%2;
			if(dir == 0 && rx != 0) { Mapa[rx - 1][ry] = '#';}
			else if(dir == 0) Mapa[rx + 1][ry] = '#';
			if(dir == 1 && ry != 0) { Mapa[rx][ry - 1] = '#';}
			else if(dir == 1) Mapa[rx][ry + 1] = '#';
			
		}
		
		else 
			i--; valido = 1;
		
	}

}

void Cruzador(char Mapa[coluna][linha]) {
	
	//Esse código impede barcos aparecerem perto demais
	//Representado pelo numero 3
	
	int i, c, d, t, rx, ry, dir;
	int valido = 1;
	for(i = 0; i < 3; i++) {
		rx = rand()%10; ry = rand()%10;
		dir = rand()%2;
		
		if(dir == 0 && rx >= 3){
			
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 5; c++) {
					if(ry == 0 && d == 0) d++;
					if(Mapa[rx + (- 3 + c)][ry + (- 1 + d)] != ' ')
						valido = 0; 
					if(rx == 9 && c >= 3) c++;
					if(ry == 9 && c >= 4 && d >= 1) d++;
				}
			}
			if(valido ==1) {
				for (t = 0; t < 3; t++) 
					Mapa[rx - t][ry] = '#';
			}
			
		}
		else if(dir == 0) {
			
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 5; c++) {
					if(ry == 0 && d == 0) d++; 
					if(Mapa[rx +(- 1 + c)][ry + (- 1 + d)] != ' ')
						valido = 0; 
					if(rx == 9 && c >= 3) c++;
					if(ry == 9 && c >= 4 && d >= 1) d++;
				}
			}
			if(valido == 1) {
				for (t = 0; t < 3; t++) 
					Mapa[rx + t][ry] = '#';
			}
			
		}
		if(dir == 1 && ry >= 3){
			
			for (d = 0; d < 5; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c++;
					if(Mapa[rx + (- 1 + c)][ry + (- 3 + d)] != ' ')
						valido = 0; 
					if(rx == 9 && c == 1) c++;
					if(ry == 9 && c >= 2 && d == 3 ) d++;
					
				}
			}
			if(valido ==1) {
				for (t = 0; t < 3; t++) 
					Mapa[rx][ry - t] = '#';
			}
			
		}
		else if(dir == 1){
			
			for (d = 0; d < 5; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c++;
					if(Mapa[rx + (- 1 + c)][ry + (- 1 + d)] != ' ')
						valido = 0; 
					if(rx == 9 && c == 1) c++;
					if(ry == 9 && c >= 2 && d == 3 ) d++;
					
				}
			}
			if(valido ==1) {
				for (t = 0; t < 3; t++) 
					Mapa[rx][ry + t] = '#';
			}
			
		}
		
		if (valido == 0){
				i--; valido = 1;	
		}
		
	}	
}


void PortaAviao(char Mapa[coluna][linha]) {
	
	//Esse é o primeiro barco a ser inserido, não precisa verificar
	//Representado pelo numero 4
	
	int i, c, d, t, rx, ry, dir;
	int valido = 1;
	for(i = 0; i <1 ;i ++) {
  		rx = rand()%10; ry = rand()%10; 
			
		Mapa[rx][ry] = '#';
		//if (rx > 3 && rx < 7) valido = 0;
		//if (ry > 3 && ry < 7) valido = 0;
			
		if(valido = 1) {
			
			dir = rand()%2;
			if(dir == 0 && rx >= 4) {
				
				for (t = 1; t < 4; t++) 
					Mapa[rx - t][ry] = '#';
				
			}
			else if(dir == 0) {
			
				for (t = 1; t < 4; t++) 
					Mapa[rx + t][ry] = '#';
			}
			if(dir == 1 && ry >= 4) {
			
				for (t = 1; t < 4; t++) 
					Mapa[rx][ry - t] = '#';
			}
			else if(dir == 1){
			
				for (t = 1; t < 4; t++) 
					Mapa[rx][ry + t] = '#';
			}
	
		}
		else 
			i--; valido = 1;
	
	}
}

int ganhou = 0;//Variavel para verificar se algum jogador ganhou ou perdeu

int contarNavios()
//Verificação para ver se existe algum navio aliado ou inimigo
{
	int i,j;
	ganhou = 1;

	for(i = 0;i<10;i++)
	{
		for(j = 0;j<10;j++)
		{
			if(enemyTable[i][j] == '#')
			{
				ganhou = 0;
				break;
			}
		}
	}

	if(ganhou == 1)
	//Se todos os navios inimigos forem destruidos = VITORIA!
	{
		printf("\nVOCE GANHOU!");
		return 0;
	}
	//Caso isso não ocorra, o jogo continua
	for(i = 0;i<10;i++)
		{
			for(j = 0;j<10;j++)
			{
				if(myTable[i][j] == '#')
				{
					ganhou = 0;
					break;
				}
			}
		}
	if(ganhou == 1)
	//Confere se o jogador perdeu
	{
		printf("\nVOCE PERDEU!!");
		return 0;
	}
}

int Attack(int x, int y)
//Metodo de ataque com as cordenadas digitadas
{
	printf("attacado em: %c %c",x,y);
	printf("attacado em: %c",enemyTable[x][y]);
	switch(enemyTable[x][y])
	{
		case' ':
		//Se a coordenada estiver vazia, o simbolo "X" aparece
		{
			enemyTable[x][y] = 'X';
			break;
		}
		case'#':
			//Se a coordenada possuir um navio inimigo, o simbolo "O" aparece
		{
			enemyTable[x][y] = 'O';
			break;
		}
		case'O':
		//Se a coordenada ja foi atacada, tudo continua igual
		{
			enemyTable[x][y] = 'O';
			break;
		}
		case'X':
		//Se a coordenada ja foi atacada, tudo continua igual
		{
			enemyTable[x][y] = 'X';
			break;
		}
	}
	return 0;
}


int PrintTable()
//Print do seu tabuleiro e o tabuleiro inimigo na tela
{
	int i,j;
	printf("\nMEU TABULEIRO\n");
	printf("  0123456789\n");
	printf("------------\n");

	for(i = 0;i<10;i++)	//linha
	{
		printf("%d|",i);
		for(j = 0;j<10;j++)	//coluna
		{
			printf("%c",myTable[i][j]);
		}
		printf("\n");
	}

		printf("TABULEIRO INIMIGO\n");
		printf("  0123456789\n");
		printf("------------\n");

		for(i = 0;i<10;i++)	//linha
		{
			printf("%d|",i);
			for(j = 0;j<10;j++)	//coluna
			{
				char temp = enemyTable[i][j];
				if (temp == '#')
				//Esconde os navios do inimigo
				{
					temp = ' ';
				}
				printf("%c",temp);
			}
			printf("\n");
		}
	return 0;
}


int main(){
	//Codigos para socket
  int udpSocket, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  //Cria UDP socket
  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

  //Configura o endereço struct
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("10.0.0.2"); //Servidor com IP 10.0.0.2
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  /*Bind socket with address struct*/
  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  //Inicializa variavel de tamanho
  addr_size = sizeof serverStorage;
  
  ZerarMapa(myTable);
  PortaAviao(myTable);
  Encouracado(myTable);
  Cruzador(myTable);
  Submarino(myTable);
  
  ZerarMapa(enemyTable);
  PortaAviao(enemyTable);
  Encouracado(enemyTable);
  Cruzador(enemyTable);
  Submarino(enemyTable);
  
  printf("Voce deve aguardar seu turno para jogar!\n");
  PrintTable();

  while(1){

	  printf("\nAGUARGANDO ADVERSARIO...\n");
	  //Aguarda o adversario fazer a jogada e envia o tabuleiro atualizado para o outro jogador
	  
	  recvfrom(udpSocket,myTable,sizeof(myTable),0,(struct sockaddr *)&serverStorage, &addr_size);
	  printf("\n----------------------------\nTURNO INIMIGO:\n");
	  PrintTable();

	  contarNavios();
	  //Checa se o jogador venceu
	  if(ganhou == 1)
	  {
		  break;
	  }

	  int x, y;

	  printf("Seu turno:\n");
	  printf("Digite posicao y (Vertical):\n");
	  scanf("%d",&x);
	  printf("Digite posicao x (Horizontal):\n");
	  scanf("%d",&y);

	  printf("\n----------------------------\nSEU TURNO:\n");
	  Attack(x,y);
	  PrintTable();
	  sendto(udpSocket,enemyTable,sizeof(enemyTable),0,(struct sockaddr *)&serverStorage,addr_size);
	  //Envia para o inimigo o tabuleiro dele com o ataque realizado com as coordenadas digitadas
	  	
	  contarNavios();
	   //Checa se o jogador perdeu ou venceu
	  if(ganhou == 1)
	  {
		  break;
	  }
  }

  return 0;
}
