#include <WiFi.h>
#include <PubSubClient.h>

//configurações wifi
const char* ssid = "sua rede";
const char* password = "senha da rede";

//configurações do broker
const char* brokerURL = "broker.hivemq.com";
const char* brokerUser = "";
const char* brokerPassword = "";
const char* MQTTClientName = "mqtt-mack-pub-sub";
const int brokerPort = 1883;
const char* Topico_01 = "10409432/carbono";

//configurações do sensor
const int pino = 34;

//criando as intâncias
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  //conexão wifi
  Serial.print("Conectando na rede ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Tentando ");
  }

  Serial.println("");
  Serial.println("Conectado ao wifi");
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());

  //configuração do broker
  client.setServer(brokerURL, brokerPort);

  //configuração do sensor
  pinMode(pino, INPUT);
}

void conexaobroker() {
  while (!client.connected()) {
    Serial.println("Conectando ao broker");

    if (client.connect(MQTTClientName, brokerUser, brokerPassword)) {
      Serial.println("Conectado ao broker");
    } else {
      Serial.println("Erro de conexão com o broker. ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void lersensor() {
  int valor = analogRead(pino);
  Serial.print("Valor do sensor: ");
  Serial.println(valor);

  char valortransformado[50];
  sprintf(valortransformado, "%d", valor);
  client.publish(Topico_01, valortransformado);
  Serial.println("Enviado ao broker");
}

void loop() {
  //garantir a conexão wifi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconectando ao wifi ");
    WiFi.begin(ssid, password);
  }

  //garantir conexão com o broker
  conexaobroker();

  //garantir a conexão com o broker e a coleta dos valores
  client.loop();

  //ler e enviar os valores do sensor
  lersensor();

  delay(10000);
}
