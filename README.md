# Batalha Naval

Este jogo é o batalha naval, feito de forma entre cliente e servidor.
O jogo pode ser jogado de modo multiplayer entre dois jogadores.
Feito para ser utilizado na Virtual Machine com o Linux Ubuntu instalado.

Requisitos:
Oracle VM VirtualBox com 2 VM's Linux utilizando Ubuntu Desktop 
GNS3

Passos para  jogar:
1. Execute o aplçicativo GNS3 e conecte as duas VM's a uma ethernet switch, inicie as duas VM's.
2. Modifique ambos os códigos no IP do servidor para o IP do servidor utilizado.
3. Abra o terminal (Botão direito --> Abrir terminal)
4. Compile o código (gcc Batalha_Naval_Client.c -o Nome_do_executavel)
5. Execute o código ( ./Nome_do_executavel)
6. Divirta-se 

Como o jogo funciona:
Ao executar o jogo, se voce for o cliente você joga primeiro, sendo assim, o servidor sempre joga em segundo.
Você irá ver dois tabuleiros em Ascii art, o primeiro tabuleiro é o seu, com seus navios, o segundo tabuleiro é o inimigo, ele está vazio, pois os navios dele estão escondidos.
Os jogadores possuem 4 tipos de navios, cada um com seu tamanho (De 1 casa até 4 casas).
O jogador então deverá digitar as coordenadas a ser atacadas, digitando primeiro o Y (Vertical) [0 a 9] e logo em seguida o X (Horizontal) [0 a 9]. Se você errar, um simbolo "X" irá aparecer na coordenada digitada, e consequentemente, se você acertar, um simbolo "O" irá aparecer na coordenada digitada.
O jogador vencedor é aquele que destruir todos os navios do inimigo.
Have fun!
