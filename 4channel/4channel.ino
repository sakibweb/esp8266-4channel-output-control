#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "SmartHome";
const char* password = "password";

IPAddress local_ip(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

int led1Pin = 5;
int led2Pin = 4;
int led3Pin = 0;
int led4Pin = 2;
int led5Pin = 16;
int button1Pin = 14;
int button2Pin = 12;
int button3Pin = 13;
int button4Pin = 15;

bool led1State = false;
bool led2State = false;
bool led3State = false;
bool led4State = false;
bool led5State = false;

void handleRoot() {
  server.sendHeader("Location", String("http://192.168.4.1/"), true);
  server.send(302, "text/plain", "");
  String html = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width,initial-scale=1'><title>Smart Home</title><style>*{box-sizing:border-box;margin:0;padding:0}body{background-color:#1c1c1c;color:#fff;font-family:'Segoe UI',sans-serif;font-size:16px;line-height:1.5}.header{position:fixed;top:0;left:0;width:100%;height:50px;background-color:#000;text-align:center;padding-top:10px;font-size:20px}.content{display:flex;flex-direction:column;align-items:center;justify-content:center;height:calc(100vh - 0px)}.button-group{display:flex;flex-direction:row;align-items:center;justify-content:center;margin-bottom:10px}.button{display:flex;align-items:center;justify-content:center;width:80px;height:80px;border-radius:50%;background-color:#111;margin:0 20px;<!--outline:4px solid #111;-->cursor:pointer;transition:all .3s ease-in-out;font-weight:bold;text-transform:uppercase;letter-spacing:2px;font-size:22px;border:3px solid}.sub{width:80px;margin:0 20px;align-items:center;justify-content:center;justify-content:center;color:#bac6d0;text-shadow:1.5px -1.5px 2px #555555;margin-bottom:30px;letter-spacing:1px;font-weight:bold;text-align:center;font-size:14px}.ON{border-color:#2196f3;color:#2196f3;box-shadow: 0 0 0 4px #111,10px -10px 10px rgba(28,213,230,.2)}.ON:hover{background-color:#2196f3;color:#1c1c1c}.OFF{border-color:#555;color:#555;box-shadow: 0 0 0 4px #111,10px -10px 10px rgba(151,153,156,.2)}.OFF:hover{background-color:#555;color:#1c1c1c}.led-ON,.led-OFF{margin:1em;padding:1em 2em;border:0;border-radius:30px;text-align:center;white-space:nowrap;cursor:pointer;font-size:14px;background-color:transparent}.led-OFF{border:1px solid #555;color:#555}.led-ON{border:1px solid #2196f3;color:#2196f3}.footer{position:fixed;bottom:0;left:0;width:100%;height:50px;background-color:#000;text-align:center;padding-top:10px;font-size:14px}</style></head><body><div class='header'>Smart Home</div><div class='content'>";
  html += "<div class='button-group'>";
  html += "<div onclick=\"location.href='/led1';\" class='button " + String(led1State ? "ON" : "OFF") + "' id='button1'>" + String(led1State ? "ON" : "OFF") + "</div>";
  html += "<div onclick=\"location.href='/led2';\" class='button " + String(led2State ? "ON" : "OFF") + "' id='button2'>" + String(led2State ? "ON" : "OFF") + "</div>";
  html += "</div><div class='button-group'><div class='sub'>Button 1</div><div class='sub'>Button 2</div></div>";
  html += "<div class='button-group'>";
  html += "<div onclick=\"location.href='/led3';\" class='button " + String(led3State ? "ON" : "OFF") + "' id='button3'>" + String(led3State ? "ON" : "OFF") + "</div>";
  html += "<div onclick=\"location.href='/led4';\" class='button " + String(led4State ? "ON" : "OFF") + "' id='button4'>" + String(led4State ? "ON" : "OFF") + "</div>";
  html += "</div><div class='button-group'><div class='sub'>Button 3</div><div class='sub'>Button 4</div></div>";
  html += "<div class='button-group'>";
  html += "<button onclick=\"location.href='/led5';\" class='led-" + String(led5State ? "ON" : "OFF") + "'>Status LED " + String(led5State ? "ON" : "OFF") + "</button></div>";
  html += "</div><div class='footer'>Created By SAKIB</div></body></html>";
  server.send(200, "text/html", html);
}

void handleLed1() {
  led1State = !led1State;
  digitalWrite(led1Pin, led1State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLed2() {
  led2State = !led2State;
  digitalWrite(led2Pin, led2State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLed3() {
  led3State = !led3State;
  digitalWrite(led3Pin, led3State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLed4() {
  led4State = !led4State;
  digitalWrite(led4Pin, led4State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLed5() {
  led5State = !led5State;
  digitalWrite(led5Pin, led5State);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(9600);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
  digitalWrite(led1Pin, led1State);
  digitalWrite(led2Pin, led2State);
  digitalWrite(led3Pin, led3State);
  digitalWrite(led4Pin, led4State);
  digitalWrite(led5Pin, led5State);
  WiFi.mode(WIFI_AP); 
  WiFi.softAPConfig(local_ip, gateway, subnet);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("\n----------SMART  HOME----------\n");
  Serial.print("--------Create By SAKIB--------\n");
  Serial.print("Enter SSID: " + String(ssid) + "\n");
  Serial.print("Enter Password: " + String(password) + "\n");
  Serial.print("Enter Url: http://");
  Serial.print(myIP);
  Serial.print("/\n");
  Serial.print("-------------------------------");
  server.on("/", handleRoot);
  server.on("/led1", handleLed1);
  server.on("/led2", handleLed2);
  server.on("/led3", handleLed3);
  server.on("/led4", handleLed4);
  server.on("/led5", handleLed5);
  server.begin();
}


void loop() {
  server.handleClient();
  if (digitalRead(button1Pin) == LOW) {
    led1State = !led1State;
    digitalWrite(led1Pin, led1State);
    delay(500);
  }
  if (digitalRead(button2Pin) == LOW) {
    led2State = !led2State;
    digitalWrite(led2Pin, led2State);
    delay(500);
  }
  if (digitalRead(button3Pin) == LOW) {
    led3State = !led3State;
    digitalWrite(led3Pin, led3State);
    delay(500);
  }
  if (digitalRead(button4Pin) == LOW) {
    led4State = !led4State;
    digitalWrite(led4Pin, led4State);
    delay(500);
  }
}

