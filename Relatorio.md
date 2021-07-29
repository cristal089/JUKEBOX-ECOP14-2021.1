
# Simulador de Jukebox utilizando PICGenios - PIC18F4520 e simulado com PICSimLab

Projeto feito para a disciplina ECOP04 e ECOP14 da Universidade Federal de Itajubá (Unifei) que consiste na simulação de uma máquina de tocar música. 

O usuário pode escolher entre três músicas diferentes simuladas pelo “beep” do componente Buzzer ao apertar botões no teclado matricial da placa (estes especificados no Display LCD).
	
  A linguagem utilizada foi C. Os softwares usados foram MPLAB X IDE v5.45 juntamente com o compilador XC8 v2.32 e o simulador PICSimLab v0.8.2 para a PICGenios com PIC18F4520.

Componentes utilizados:

• Display LCD 16x4;

• Teclado Matricial;

• Display 7 Segmentos;

• Buzzer;

• Cooler.

## Planejamento

Antes de o código ser de fato implementado, foram decididas as funções de cada componente e a ordem da implementação:

1 – Criar uma tela inicial com a animação de um disco de vinil e com o escrito “JUKEBOX”;

2 – Criar um menu para a “inserção do dinheiro”, simulando o momento em que a pessoa coloca as moedas na máquina para utilizá-la. Essa simulação é apenas figurativa, bastando que o usuário aperte o botão do asterisco (*) no teclado;

3 – Criar um menu para a seleção de músicas com três exemplares e a possibilidade de desativar ou ativar novamente o som;

4 – Criar a tela de execução da música com: desenho de uma nota musical no Display LCD, rotação lenta do Cooler e o som sendo reproduzido pelo Buzzer;

5 – Possibilitar que o usuário saia da tela de execução das músicas e volte ao menu de seleção das mesmas.

## Implementação

Para que o projeto pudesse ser desenvolvido foram necessárias algumas bibliotecas, declaradas na main.

A fim de facilitar o código, foram definidas também algumas constantes, como por exemplo L1 e L2, para um acesso mais direto às linhas um e dois do Display LCD.

O desenho da nota musical e a animação do disco de vinil foram implementadas nas funções notaLogo_1 e discoLogo_1, 2 e 3. 

A função apresentaMenu foi utilizada para estruturar o menu de seleção de músicas, recebendo como parâmetro a variável infoSom, necessária para especificar se o som do programa está ativado ou desativado. 

Por fim, as funções musicaLenta, musicaMedia e musicaRapida foram as funções utilizadas para a execução dos exemplares de música.

![Cabeçalho main](https://i.ibb.co/jTLVZRt/codigo-01.png)

