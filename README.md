Repositório para a implementação do algoritmo K-Nearest Neighbour.

Para compilar o programa, basta executar o Makefile contido neste repositório, usando o comando make.

O programa pode ser executado de duas formas. O usuário pode passar como único parâmetro a base de dados completa (./KNN data_set). Neste caso, o algoritmo irá gerar dois arquivos, train_data_set e test_data_set, aonde o primeiro contém 80% das instâncias da base original, escolhidas de forma randômica, e a base de teste contém os 20% restantes.

A segunda forma é passando como parâmetros a base de dados de treinamento e a de testes (sendo gerados pelo sistema ou não). A execução neste caso é: ./KNN training_set testing_set. O algoritmo irá construir um modelo utilizando na base de treinamento e irá tentar predizer a classe das instâncias com base nas instâncias do conjunto de dados de treinamento. Ao final, o programa imprime a quantidade de acertos em relação ao total, e a precisão do algoritmo naquela base de dados em particular.

Link do repositório: https://github.com/hialo/AM_TR01