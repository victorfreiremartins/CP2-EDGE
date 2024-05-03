# Projeto vinharia (CP2)

Nosso projeto foi feito com base na necessidade de uma vinharia monitorar a umidade, a temperatura e a luminosidade em suas instalaÃ§Ãµes. O monitoramento desses parÃ¢metros Ã© essencial para garantir a qualidade dos vinhos (evitar alteraÃ§Ãµes nas caracterÃ­sticas finais do vinho). Portanto, nosso projeto visa fornecer uma soluÃ§Ã£o eficaz e automatizada para monitorar esses fatores ambientais cruciais nesse contexto.

## Contato

RM554739 - Bruno Biletsky

RM556191 - Victor Freire

RM558571 - Enrico Ricarte

RM554561 - Eduardo Levy

RM556935 - Matheus Gushi

## DescriÃ§Ã£o

Este cÃ³digo Ã© projetado para monitorar e exibir informaÃ§Ãµes sobre temperatura, umidade e luminosidade utilizando um Arduino e componentes perifÃ©ricos como um sensor DHT22 (para temperatura e umidade), um sensor de luminosidade e um display LCD.

- Ele inicializa os pinos necessÃ¡rios para conexÃ£o dos componentes.
- Inicializa o display LCD para exibir as informaÃ§Ãµes.
- LÃª os dados do sensor de temperatura e umidade DHT22 e calcula uma mÃ©dia mÃ³vel para suavizar as leituras.
- LÃª os dados do sensor de luminosidade e tambÃ©m calcula uma mÃ©dia mÃ³vel.
- Com base nas leituras, determina o status da umidade, temperatura e luminosidade.
- Atualiza o display LCD para mostrar as informaÃ§Ãµes relevantes, alternando entre temperatura, umidade e luminosidade em intervalos regulares.
- Controla LEDs e um buzzer para indicar o status atual das condiÃ§Ãµes ambientais: verde para adequado, amarelo para condiÃ§Ãµes intermediÃ¡rias e vermelho para condiÃ§Ãµes crÃ­ticas.
- Os valores de referÃªncia para os diferentes estados (baixo, adequado, alto) sÃ£o definidos com base em limites prÃ©-estabelecidos e uma margem delta para determinar as condiÃ§Ãµes intermediÃ¡rias.

Este cÃ³digo permite que uma vinÃ­cola monitore constantemente as condiÃ§Ãµes ambientais essenciais para preservar seus vinhos, mantendo a alta qualidade.

## Funcionalidades Principais

1. **Monitoramento de Temperatura e Umidade**: O cÃ³digo lÃª os dados do sensor DHT22 para medir a temperatura e a umidade do ambiente. Ele calcula uma mÃ©dia mÃ³vel para suavizar as leituras e determinar o status desses parÃ¢metros.
2. **Monitoramento de Luminosidade**: Utilizando um sensor de luminosidade, o cÃ³digo monitora os nÃ­veis de luz ambiente. Assim como para temperatura e umidade, Ã© calculada uma mÃ©dia mÃ³vel para suavizar as leituras.
3. **ExibiÃ§Ã£o de InformaÃ§Ãµes no Display LCD**: O cÃ³digo atualiza um display LCD para exibir as informaÃ§Ãµes sobre temperatura, umidade e luminosidade. Ele alterna entre esses dados em intervalos regulares.
4. **IndicaÃ§Ã£o Visual e Sonora do Status Ambiental**: Com base nas leituras dos sensores, o cÃ³digo controla LEDs e um buzzer para indicar o status das condiÃ§Ãµes ambientais. Os LEDs acendem em verde para condiÃ§Ãµes adequadas, amarelo para condiÃ§Ãµes intermediÃ¡rias e vermelho para condiÃ§Ãµes crÃ­ticas. O buzzer emite sons correspondentes aos diferentes estados.
5. **AtualizaÃ§Ã£o ContÃ­nua das InformaÃ§Ãµes**: Antes de refletir a leitura dos sensores no display LCD e nos indicadores visuais e sonoros, as leituras passam por um processo de mÃ©dia mÃ³vel. Essa tÃ©cnica permite uma maior estabilidade e confiabilidade nas leituras, suavizando possÃ­veis variaÃ§Ãµes abruptas e fornecendo uma representaÃ§Ã£o mais precisa das condiÃ§Ãµes ambientais ao longo do tempo. Essa abordagem aumenta a precisÃ£o do monitoramento, fornecendo informaÃ§Ãµes mais consistentes para tomadas de decisÃ£o na gestÃ£o das condiÃ§Ãµes ambientais na vinharia.

## InstalaÃ§Ã£o

As instalaÃ§Ãµes (hardware) necessÃ¡rias para o cÃ³digo fornecido incluem:

1. **Sensor DHT11**: Este sensor Ã© utilizado para medir a temperatura e a umidade do ambiente.
2. **Sensor de Luminosidade**: Um sensor de luminosidade Ã© empregado para medir os nÃ­veis de luz ambiente.
3. **Display LCD**: Um display LCD Ã© usado para exibir as informaÃ§Ãµes sobre temperatura, umidade e luminosidade.
4. **LEDs**: LEDs sÃ£o utilizados para indicar visualmente o status das condiÃ§Ãµes ambientais. Normalmente, sÃ£o empregadas trÃªs cores diferentes de LEDs: verde para condiÃ§Ãµes adequadas, amarelo para condiÃ§Ãµes intermediÃ¡rias e vermelho para condiÃ§Ãµes crÃ­ticas.
5. **Buzzer**: Um buzzer Ã© utilizado para fornecer feedback sonoro do status das condiÃ§Ãµes ambientais. Ele emite diferentes sons correspondentes aos diferentes estados (adequado, intermediÃ¡rio, crÃ­tico).
6. **Arduino Board**: O cÃ³digo Ã© projetado para ser executado em uma placa Arduino, que serve como a unidade de processamento principal.
7. **ConexÃµes e Componentes EletrÃ´nicos**: AlÃ©m dos componentes mencionados acima, podem ser necessÃ¡rios resistores, fios, jumpers e outros componentes eletrÃ´nicos para realizar as conexÃµes entre os sensores, LEDs, buzzer, display LCD e a placa Arduino.

Certifique-se de conectar corretamente os componentes Ã  placa Arduino conforme especificado na simulaÃ§Ã£o.

## Como Usar

O cÃ³digo fornecido Ã© Ãºtil quando vocÃª precisa monitorar e controlar as condiÃ§Ãµes ambientais, como temperatura, umidade e luminosidade, em um ambiente especÃ­fico, como uma vinÃ­cola.
