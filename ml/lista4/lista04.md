Lista 4 - Redes Neurais Artificiais

## Instruções
- Com exceção dos casos explicitamente indicados, os algoritmos e modelos devem
ser implementados do início em qualquer linguagem de programação.
- Pacotes auxiliares (sklearn, matplotlib, etc) podem ser usados somente para
facilitar a manipulação dos dados e criar gráficos.
- Para a avaliação do trabalho, recomenda-se o envio de arquivo Jupyter notebook
com os códigos executados e os resultados visíveis nas células.

## Questão 1
Considere o conjunto de dados disponível em concrete.csv, organizado em 9
colunas, sendo as 8 primeiras colunas os atributos e a última coluna a saída.
Os 8 atributos referem-se à caracterização de diferentes tipos de concreto para
construção civil. A saída é a resistência à compressão do concreto (em me-
gapascals, MPa).
- Considere um modelo de regressão não linear baseado em redes neurais
artificiais. Separe os dados aleatoriamente em treino, validação e teste
(por exemplo, 60%, 20% e 20%). Nesse cenário, treine e avalie o modelo MLP (multilayer perceptron): 1 camada oculta e treinamento
em minibatch via gradiente descendente estocástico com termo de
momentum. Utilize o conjunto de validação para ajustar os hiperpa-
râmetros. Realize um grid search com learning rate e momentum pra encontrar os melhores hiperparâmetros.
- Apresente as curvas da função custo nos conjuntos de treinamento e vali-
dação ao longo das épocas. Reporte também para os conjuntos de treino,
validação e teste as métricas:
– RMSE (root mean squared error)
– MAE (mean absolute error)
– MRE (mean relative error)
- Mostre a curva de aprendizado do SGD

## Questão 2
Considere o conjunto de dados disponível em vehicle.csv, organizado em 19 co-
lunas, sendo as 18 primeiras colunas os atributos e a última coluna a saída. Os 18
atributos caracterizam a silhueta de veículos, extraídos pelo método HIPS (Hi-
erarchical Image Processing System). A tarefa consiste em classificar o veículo
em 4 classes (bus, opel, saab, e van).

- Considere um modelo de classificação não linear baseado em redes neurais
artificiais. Separe os dados aleatoriamente em treino, validação e teste
(por exemplo, 60%, 20% e 20%). Nesse cenário, treine e avalie o modelo MLP (multilayer perceptron): 1 camada oculta e treinamento
em minibatch via gradiente descendente estocástico com termo de
momentum. Utilize o conjunto de validação para ajustar os hiperpa-
râmetros. Realize um grid search com learning rate e momentum pra encontrar os melhores hiperparâmetros.
- Apresente as curvas da função custo nos conjuntos de treinamento e va-
lidação ao longo das épocas. Reporte também a acurácia, revocação
(macro), precisão (macro) e F1-score (macro) obtidas para os conjun-
tos de treino, validação e teste. Por último, mostre a matriz de confusão
obtida no conjunto de teste.
- Mostre a curva de aprendizado do SGD