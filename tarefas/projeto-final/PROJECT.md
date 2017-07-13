# Mini Dance Revolution

## Membros do Grupo
[Anny Caroline Chagas](https://github.com/AnnyCaroline/reativos) e [Leonardo Marinho](https://github.com/Leo-Lima-Mar/reativos)

## Descrição

Este projeto é um jogo baseado no Dance Dance Revolution, e é escrito em CÉU utilizando SDL e Arduino.

![Dance Dance Revolution ps1](https://68.media.tumblr.com/aa72eb1c81b9209a6406f93df343960f/tumblr_ndg16wIDv71qd4q8ao1_500.gif)

A parte gráfica e sonora será feita por meio de SDL, enquanto que um teclado de membrana será usado, no Arduino, para simular um tapete de dança.

## Componentes
- 1 teclado

## Vídeos
[Playlist com os vídeos do projeto](https://www.youtube.com/playlist?list=PL-Vy8N4zUqm6epgmOByDoAEiEwYhebnui)  
Os dois primeiros vídeos da playlist são referentes ao [commit 9f6916c](https://github.com/AnnyCaroline/reativos/tree/9f6916ce00c916083de58372b11d49af671aa9ec/tarefas/projeto-final), o qual ainda apresentava poucas teclas e tinha um pequeno bug. Já o terceiro vídeo corresponde à segunda versão (obs: o programa que executa no arduino não sofreu alteração de uma versão para a outra).  

### Explicação sobre o bug da versão 1
A primeira versão retirava um ponto/vida a cada tecla pressionada no tempo errado.  
Porém, como isso estava gerando um bug, a versão 2 não decrementa a pontuação/vida no caso de pressionamento incorreto.

## Divisão de tarefas

### LOAD
1) Montar pool das setas que serão usadas na música - Anny
2) Carregar música no SDL - Anny
3) Carregar imagens - Leonardo

### RUN
1) Executar música - Anny
2) Fazer animação das setas - Leonardo
3) Escutar evento de click (1 paralelo para cada botão) - Anny
4) Fazer verificação da "colisão" - Leonardo
5) Tratar barra de vida - Anny
	- clique sem colisão: perde vida
	- clique com colisão: ganha vida

### END
1) Tratar fim de jogo - Anny
2) Tratar restart - Leonardo
