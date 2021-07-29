
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

Já na execução da simulação, temos em primeiro lugar a tela inicial, onde ocorre a animação:

![Tela inicial](https://i.ibb.co/ScHbSmW/simula-o-01.png)

Após essa tela, é exibida a tela para inserção do dinheiro, em que o usuário deve apertar a tecla de asterisco (*):

![Inserção do dinheiro](https://i.ibb.co/D43LXdK/simula-o-02.png)
![Tecla de asterisco](https://i.ibb.co/HXDzWjV/teclado-01.png)

Assim que a tecla de asterisco é apertada, o Buzzer emite um curto “beep” para então dar lugar ao menu de seleção de músicas:

![Seleção das músicas](https://i.ibb.co/cYR7ZSx/simula-o-03.png)
![Teclas para escolher músicas](https://i.ibb.co/8D2bXpW/teclado-03.png)

A palavra “mutar”, um neologismo da palavra “mute” do inglês (deixar no mudo), foi usada por ser uma palavra curta, já que “desativar” ultrapassaria o espaço disponível do LCD. 

Quando a tecla de hashtag, ou jogo da velha, é apertada, o som do programa é desativado e o menu é alterado para o qual se segue:

![Seleção das músicas - menu alternativo](https://i.ibb.co/R37yvsV/simula-o-04.png)

A alteração do som pode ser vista também pelo display de 7-segmentos. Quando o som está ativado, sua aparência é a seguinte:

![Indicando som ativado](https://i.ibb.co/vHtX1n1/simula-o-05.png)

Ao desativar-se o som, o display de 7-segmentos é alterado da seguinte maneira:

![Indicando som desativado](https://i.ibb.co/nsCPhzX/simula-o-06.png)

Para a demonstração da execução das músicas, será utilizada o exemplar “Rápida”. Assim que a tecla 3 é apertada, a partir do menu de seleção, é exibida a seguinte tela:

![Executando música](https://i.ibb.co/BZbBfDM/simula-o-07.png)

O Cooler é então ativado a uma taxa de 30%. Essa taxa foi pensada com o intuito de simular um disco de vinil rodando, sem qualquer outro motivo técnico. 

É também ativado o Buzzer, que irá emitir “beeps” rápidos para simular o tempo da música.

Após a execução da música, o Cooler e o Buzzer são interrompidos e o LCD terá a seguinte aparência:

![Execução da música encerrada](https://i.ibb.co/Srv1RTg/simula-o-08.png)

Basta apertar novamente o botão de asterisco (*) para então retornar ao menu de seleção de músicas.

## Animações

Para cada desenho presente no LCD foi utilizado o site de acesso gratuito [LCD Custom Character Generator](https://maxpromer.github.io/LCD-Character-Creator/). Os desenhos foram feitos com no máximo 8x5 pixels por divisão.

A explicação é que o Display LCD conta com 16 “compartimentos” de 8x5 pixels cada. Como cada desenho feito preencheu duas linhas e três colunas, ou seja, 6 “compartimentos”, um único ícone (por exemplo, a nota musical) precisou ser dividido em seis partes, cada parte com um determinado número de pixels que não ultrapassasse o limite de 8x5.

![Nota musical dividida em seis partes](https://i.ibb.co/RQHcjHP/lcd-01.png)

Para que fosse possível realizar uma curta animação, no caso do disco de vinil, foram criados três desenhos, em que cada um apresentou uma mudança na posição dos pixels entre as bordas, criando a sensação de o disco estar rodando.

![Desenho 1 do disco de vinil](https://i.ibb.co/k4DzkrK/lcd-02.png)
![Desenho 2 do disco de vinil](https://i.ibb.co/wWC0nbX/lcd-04.png)
![Desenho 3 do disco de vinil](https://i.ibb.co/D9nPr3T/lcd-06.png)

## Dificuldade e soluções

Uma das dificuldades encontradas foi em relação à utilização do display de 7-segmentos. No escopo inicial do projeto, o display de 7-seg seria utilizado para mostrar a palavra “Som”, em caso de o som estar ativado, e “Mudo”, em caso de o som estar desativado.

Como alternativa foi então decidido que seria exibido quatro números “1” em sequência, indicando que o som está ativado, e quatro números “0”, em caso contrário.

Outra dificuldade encontrada foi em relação à utilização do Buzzer. Por falta de conhecimentos em teoria musical, as músicas ficaram limitadas a “beeps” espaçados sem muita profundidade na experiência sonora do usuário.

## Resumo do funcionamento

Assim que a simulação começar, será exibida uma tela com a animação do disco de vinil e o escrito “JUKEBOX” ao lado, bastando aguardar para que seja exibida a tela do menu de inserção de dinheiro. 

Neste menu, basta que seja apertada a tecla de asterisco do teclado (*). 

O menu seguinte é o de seleção dos exemplares de músicas: tecla 1 para o exemplar Lento; tecla 2 para o exemplar Médio; tecla 3 para o exemplar Rápido; tecla de hashtag/jogo da velha para ativar ou desativar o som. 

Em caso desativar-se o som, o programa ficará mudo. 

Ao selecionar-se um dos exemplares de música, ele tocará por alguns segundos enquanto o Cooler roda a 30% (simulando um disco tocando) e o Buzzer emitirá sons (simulando o tempo da música selecionada). 

Basta que, ao final da execução da música, seja apertado novamente o botão de asterisco (*) para voltar-se ao menu de seleção de músicas/alteração do som.
