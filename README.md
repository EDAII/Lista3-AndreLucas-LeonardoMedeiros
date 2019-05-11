# Aplicação de algoritmos de ordenação nLog(n)

4º Exercício Prático - Estrutura de Dados 2 - 2019.1 - UnB - Gama
=========================
André Lucas de Sousa Pinto - 17/0068251
Leonardo de Araujo Medeiros - 17/0038891

## Instalação

1. Faça o clone deste projeto com ```$ git clone https://github.com/EDAII/Lista4_AndrePinto_LeonardoMedeiros.git ```
2. Acesse a pasta do projeto via terminal
3. Compile a aplicação com ``` $ make``` 
4. Execute com ``` $ make run ```
5. Visualize em um editor de texto de sua preferência o arquivo [rank.txt](rank.txt).

## Ideia proposta
Dado o dataset contendo a lista de todos os jogos com mais de 100.000 copias vendidas até 26-06-2016 nas principais plataformas conhecidas, nos propomos a ordena-las de forma a possibilitar uma busca mais eficiente dentro do dataset, alem disto, durante o processo foi gerado um compilado dos melhores jogos de cada plataforma, com custo total  de `n + n log (n)`.

## Resultado
Como resultado final, obtemos uma estrutura na memória que possibilitava buscas mais eficientes, visto que estava ordenada, além disto, foram geradors os dados salvos em [rank.txt](rank.txt) que representam os 3 melhores jogos de cada plataforma, ou todos aqueles que tenham obtido nota 10, caso sejam mais que 3.

```
TOP 3 Best Games of each Platform
Platform: Android
1 > Threes (with: 9.3 score points).
2 > Drop7 (with: 9 score points).
3 > Puzzle Craft (with: 9 score points).
Platform: Arcade
1 > Samba de Amigo (with: 9.4 score points).
2 > Virtua Fighter 5 Final Showdown (with: 8.5 score points).
3 > Space Harrier (with: 8 score points).
...
```
