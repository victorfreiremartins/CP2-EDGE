# Projeto vinharia (CP2)

Nosso projeto foi feito com base na necessidade de uma vinharia monitorar a umidade, a temperatura e a luminosidade em suas instalações. O monitoramento desses parâmetros é essencial para garantir a qualidade dos vinhos (evitar alterações nas características finais do vinho). Portanto, nosso projeto visa fornecer uma solução eficaz e automatizada para monitorar esses fatores ambientais cruciais nesse contexto.

## Contato

RM554739 - Bruno Biletsky

RM556191 - Victor Freire

RM558571 - Enrico Ricarte

RM554561 - Eduardo Levy

RM556935 - Matheus Gushi

## Descrição

Este código é projetado para monitorar e exibir informações sobre temperatura, umidade e luminosidade utilizando um Arduino e componentes periféricos como um sensor DHT22 (para temperatura e umidade), um sensor de luminosidade e um display LCD.

- Ele inicializa os pinos necessários para conexão dos componentes.
- Inicializa o display LCD para exibir as informações.
- Lê os dados do sensor de temperatura e umidade DHT22 e calcula uma média móvel para suavizar as leituras.
- Lê os dados do sensor de luminosidade e também calcula uma média móvel.
- Com base nas leituras, determina o status da umidade, temperatura e luminosidade.
- Atualiza o display LCD para mostrar as informações relevantes, alternando entre temperatura, umidade e luminosidade em intervalos regulares.
- Controla LEDs e um buzzer para indicar o status atual das condições ambientais: verde para adequado, amarelo para condições intermediárias e vermelho para condições críticas.
- Os valores de referência para os diferentes estados (baixo, adequado, alto) são definidos com base em limites pré-estabelecidos e uma margem delta para determinar as condições intermediárias.

Este código permite que uma vinícola monitore constantemente as condições ambientais essenciais para preservar seus vinhos, mantendo a alta qualidade.

## Funcionalidades Principais

1. **Monitoramento de Temperatura e Umidade**: O código lê os dados do sensor DHT22 para medir a temperatura e a umidade do ambiente. Ele calcula uma média móvel para suavizar as leituras e determinar o status desses parâmetros.
2. **Monitoramento de Luminosidade**: Utilizando um sensor de luminosidade, o código monitora os níveis de luz ambiente. Assim como para temperatura e umidade, é calculada uma média móvel para suavizar as leituras.
3. **Exibição de Informações no Display LCD**: O código atualiza um display LCD para exibir as informações sobre temperatura, umidade e luminosidade. Ele alterna entre esses dados em intervalos regulares.
4. **Indicação Visual e Sonora do Status Ambiental**: Com base nas leituras dos sensores, o código controla LEDs e um buzzer para indicar o status das condições ambientais. Os LEDs acendem em verde para condições adequadas, amarelo para condições intermediárias e vermelho para condições críticas. O buzzer emite sons correspondentes aos diferentes estados.
5. **Atualização Contínua das Informações**: Antes de refletir a leitura dos sensores no display LCD e nos indicadores visuais e sonoros, as leituras passam por um processo de média móvel. Essa técnica permite uma maior estabilidade e confiabilidade nas leituras, suavizando possíveis variações abruptas e fornecendo uma representação mais precisa das condições ambientais ao longo do tempo. Essa abordagem aumenta a precisão do monitoramento, fornecendo informações mais consistentes para tomadas de decisão na gestão das condições ambientais na vinharia.

## Instalação

As instalações (hardware) necessárias para o código fornecido incluem:

1. **Sensor DHT11**: Este sensor é utilizado para medir a temperatura e a umidade do ambiente.
2. **Sensor de Luminosidade**: Um sensor de luminosidade é empregado para medir os níveis de luz ambiente.
3. **Display LCD**: Um display LCD é usado para exibir as informações sobre temperatura, umidade e luminosidade.
4. **LEDs**: LEDs são utilizados para indicar visualmente o status das condições ambientais. Normalmente, são empregadas três cores diferentes de LEDs: verde para condições adequadas, amarelo para condições intermediárias e vermelho para condições críticas.
5. **Buzzer**: Um buzzer é utilizado para fornecer feedback sonoro do status das condições ambientais. Ele emite diferentes sons correspondentes aos diferentes estados (adequado, intermediário, crítico).
6. **Arduino Board**: O código é projetado para ser executado em uma placa Arduino, que serve como a unidade de processamento principal.
7. **Conexões e Componentes Eletrônicos**: Além dos componentes mencionados acima, podem ser necessários resistores, fios, jumpers e outros componentes eletrônicos para realizar as conexões entre os sensores, LEDs, buzzer, display LCD e a placa Arduino.

Certifique-se de conectar corretamente os componentes à placa Arduino conforme especificado na simulação.

## Como Usar

O código fornecido é útil quando você precisa monitorar e controlar as condições ambientais, como temperatura, umidade e luminosidade, em um ambiente específico, como uma vinícola.
