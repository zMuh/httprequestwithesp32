
#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
#define WIFI_CHANNEL 6

const int LED1 = 26;
const int LED2 = 27;
const int LED3 = 25;
const int LED4 = 29;

bool led1State = false;
bool led2State = false;
// the link i've used will show forward response so LED1 will be turn on 
String url = "https://s-m.com.sa/f.html";


void setup(void) {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);
  Serial.print("Connecting to WiFi ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  HTTPClient http;

  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.GET();
  String payload = http.getString();
  if(payload == "forward"){
      digitalWrite(LED1,HIGH);
  delay(1000);
  digitalWrite(LED1,LOW);
  }if(payload == "backward"){
      digitalWrite(LED2,HIGH);
  delay(1000);
  digitalWrite(LED2,LOW);
  }if(payload == "right"){
      digitalWrite(LED3,HIGH);
  delay(1000);
  digitalWrite(LED3,LOW);
  }if(payload=="left"){
digitalWrite(LED4,HIGH);
  delay(1000);
  digitalWrite(LED4,LOW);
  }
  else{
    Serial.println("error");
  }

}

void loop(void) {
  
}
