#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <U8g2lib.h>
#include <U8x8lib.h>

#include "RemoteCodes.h"

#define IR_SEND_PIN 13

IRsend irsend(IR_SEND_PIN);
const int led = LED_BUILTIN;

const std::string ssid = "";
const std::string pwd = "";
const std::string host_name = "cybie";
MDNSResponder mdns;
ESP8266WebServer server(80);
std::string ip_address;

U8G2_SSD1306_64X48_ER_F_HW_I2C u8g2(U8G2_R0);

namespace {
    void addCrossDomainHeaders()
    {
        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
        server.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    }

    void updateDisplay(const std::string &ip, const std::string &method)
    {
        u8g2.clearBuffer();
        u8g2.drawStr(0, 10, ip.c_str());
        u8g2.drawStr(0, 25, method.c_str());
        u8g2.sendBuffer();
    }
}

void remoteFunction(const remote_codes::KeyCode &code, const std::string &method)
{
    digitalWrite(led, 0);
        
    remote_codes::sendKeyCode(irsend, code);

    addCrossDomainHeaders();
    server.send(200, "text/plain", "");
    digitalWrite(led, 1);
    updateDisplay(ip_address, method);
}

void setup()
{
    u8g2.begin();
    u8g2.setFont(u8g2_font_5x8_tr);

    pinMode(led, OUTPUT);
    digitalWrite(led, 1);

    irsend.begin();
    Serial.begin(115200);
    WiFi.begin(ssid.c_str(), pwd.c_str());
    Serial.println("");

    u8g2.clearBuffer();
    u8g2.drawStr(0, 10, "Connecting...");
    u8g2.sendBuffer();

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Connected to: ");
    Serial.println(ssid.c_str());
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP().toString());

    ip_address = WiFi.localIP().toString().c_str();

    updateDisplay(ip_address.c_str(), "waiting...");

    if (mdns.begin(host_name.c_str(), WiFi.localIP()))
        Serial.println("MDNS responder started");

    server.on("/button_1", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_1, "button_1");
    });
    server.on("/button_2", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_2, "button_2");
    });
    server.on("/button_3", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_3, "button_3");
    });
    server.on("/button_4", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_4, "button_4");
    });
    server.on("/button_5", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_5, "button_5");
    });
    server.on("/button_6", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_6, "button_6");
    });
    server.on("/button_7", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_7, "button_7");
    });
    server.on("/button_8", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_8, "button_8");
    });
    server.on("/button_9", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_9, "button_9");
    });
    server.on("/button_10", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_10, "button_10");
    });
    server.on("/button_11", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_11, "button_11");
    });
    server.on("/button_12", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_12, "button_12");
    });
    server.on("/button_big", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_big, "button_big");
    });
    server.on("/button_small", HTTP_POST, [](){
        remoteFunction(remote_codes::KeyCode::button_small, "button_small");
    });
    server.on("/life", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_1);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);
        updateDisplay(ip_address, "life");
    });
    server.on("/great", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_2);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);       

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);     
        updateDisplay(ip_address, "great");
    });
    server.on("/walk_about", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_3);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);       

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1); 
        updateDisplay(ip_address, "walk_about");    
    });
    server.on("/toggle_mute", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_4);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);       

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);  
        updateDisplay(ip_address, "toggle_mute");   
    });
    server.on("/enable_auto_listen", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_6);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);       

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);   
        updateDisplay(ip_address, "enable_auto_listen");  
    });
    server.on("/disable_auto_listen", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_6);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);       

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);   
        updateDisplay(ip_address, "disable_auto_listen");  
    });
    server.on("/use_voice_command", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_7);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);       

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);    
        updateDisplay(ip_address, "use_voice_command"); 
    });
    server.on("/use_sound_command", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_8);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);       

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);     
        updateDisplay(ip_address, "use_sound_command");
    });
    server.on("/disable_auto_listen", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);       

        server.send(200, "text/plain", "");
        digitalWrite(led, 1);  
        updateDisplay(ip_address, "disable_auto_listen");   
    });
    server.on("/walk_forward", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_1);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);         

        server.send(200, "text/plain", "");
        digitalWrite(led, 1);   
        updateDisplay(ip_address, "walk_forward");  
    });
    server.on("/walk_left", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_2);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);         

        server.send(200, "text/plain", "");
        digitalWrite(led, 1);   
        updateDisplay(ip_address, "walk_left");  
    });
    server.on("/walk_right", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_3);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);         

        server.send(200, "text/plain", "");
        digitalWrite(led, 1);  
        updateDisplay(ip_address, "walk_right");   
    });
    server.on("/stop_walking", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_4);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);         

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);  
        updateDisplay(ip_address, "stop_walking");   
    });
    server.on("/enable_edge_detector", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_5);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);         

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);   
        updateDisplay(ip_address, "enable_edge_detector");  
    });
    server.on("/disable_edge_detector", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_6);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);         

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);  
        updateDisplay(ip_address, "disable_edge_detector");   
    });
    server.on("/clear_words", HTTP_POST, [](){
        digitalWrite(led, 0);

        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_10);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_9);
        delay(1000);
        remote_codes::sendKeyCode(irsend, remote_codes::KeyCode::button_big);         

        addCrossDomainHeaders();
        server.send(200, "text/plain", "");
        digitalWrite(led, 1);   
        updateDisplay(ip_address, "clear_words");  
    });

    server.onNotFound([](){
        server.send(404, "text/plain", "Root not found");
    });
    

    server.begin();
    Serial.println("HTTP Server started");
}

void loop()
{
    server.handleClient();
}