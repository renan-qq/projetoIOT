# projeto de IOT: Sistema de monitoramento de qualidade do ar
Este repositório contém o código-fonte, a documentação e os arquivos necessários para a implementação de um sistema de monitoramento da qualidade do ar baseado em tecnologias de Internet das Coisas (IoT). O projeto utiliza o sensor de monóxido de carbono MQ-7, conectado a um ESP32 para capturar, processar e transmitir dados sobre a concentração de gás no ambiente.
O sistema foi projetado para ser escalável e acessível, visando aplicações em pesquisas ambientais, monitoramento urbano e conscientização sobre a poluição do ar.
Recursos
•	Monitoramento em Tempo Real: Dados capturados pelo sensor MQ-7 são processados em tempo real.
•	Conectividade IoT: Uso do protocolo MQTT para transmissão de dados ao Broker MQTT e ao Node-red para distribuição dos dados com os softwares integrados.
• Armazenamento de Informações: O banco de dados usado foi o InfluxDB, que recebe as informações do Node-red, as armazena e as envia para o Grafana.
•	Visualização Interativa: Painel customizado no Grafana para análise e apresentação de dados.
•	Automação: Integração com Node-RED para automatizar processos, gerenciar fluxos de trabalho e fazer o envio automatico de mensagens com a api CallMeBot.
______________
Tecnologias Utilizadas
1.	Hardware
o	ESP32 DEVKITV1
o	Sensor de gás MQ-7
o	Protoboard, jumpers e cabo micro-USB
2.	Software
o	Arduino IDE (para programação do ESP32)
o	Node-RED (para automação de fluxos)
o	InfluxDB (armazenamento de dados)
o	Grafana (painel de visualização)
o CallMeBot (API para envio de mensagens automatizada para o Whatsapp)
4.	Protocolos e Ferramentas
o	MQTT (transmissão de dados)
o	JSON (estruturação dos dados)
______________
Configuração do Projeto
Pré-requisitos
•	Arduino IDE: Instalar as bibliotecas: PubSubClient e WiFi.h.
•	Node-RED: Configurar os fluxos e os nós para as comunicações e trasmissões funcionarem.
•	InfluxDB: Criar um banco de dados para receber os dados.
•	Grafana: Importar os dados do banco de dados e criar painéis visuais para os dados.
1.	Montagem do Hardware: Conectar o sensor MQ-7 com jumpers ao ESP32 nas entradas D34, VIN e GND.
2.	Upload do código para o ESP32
3.	Configuração do Software: Criação do Broker MQTT com o tópico e a url, inicialização do Node-red e criação dos fluxos para receber as informações do broker, enviar para o InfluxDB e automatizar o envio de mensagens via api.
4.	Visualização dos Dados: Conexão do Grafana com o InfluxDB, configuração com os dados do banco e geração dos painéis e gráficos com o os valores vindos do banco dados. 
______________
Resultados Conquistados
•	Confiabilidade: Captura de dados precisa.
•	Automação Completa: Dados transmitidos, armazenados e visualizados automaticamente.
•	Insights Ambientais: Identificação de concentrações de monóxido de carbono no ambiente.
