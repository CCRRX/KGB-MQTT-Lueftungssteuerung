#include <UIPEthernet.h>
#include <UIPServer.h>
#include <UIPClient.h>
#include <PubSubClient.h>

byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED }; // Best MAC ^^
IPAddress ip(192, 168, 178, 177);
IPAddress server(192, 168, 178, 112);

const int RelayPin0 = 2;
const int RelayPin1 = 3;
const int RelayPin2 = 4;
const int RelayPin3 = 5;
const int RelayPin4 = 6;
const int RelayPin5 = 7;
const int RelayPin6 = 8;
const int RelayPin7 = 9;

void callback(char* topic, byte* payload, unsigned int length);

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);


void callback(char* topic, byte* payload, unsigned int length) {

    char msg[length+1];
    for (int i = 0; i < length; i++) {
        msg[i] = (char)payload[i];
    }
    msg[length] = '\0';
    
/*    if(strcmp(msg,"00")==0){
      digitalWrite(RelayPin0, HIGH);}
    
    if (strcmp(msg,"01")==0){
      digitalWrite(RelayPin0, LOW);}

    if(strcmp(msg,"10")==0){
      digitalWrite(RelayPin1, HIGH);}
    
    if (strcmp(msg,"11")==0){
      digitalWrite(RelayPin1, LOW);}

    if(strcmp(msg,"20")==0){
      digitalWrite(RelayPin2, HIGH);}
    
    if (strcmp(msg,"21")==0){
      digitalWrite(RelayPin2, LOW);}

    if(strcmp(msg,"30")==0){
      digitalWrite(RelayPin3, HIGH);}
    
    if (strcmp(msg,"31")==0){
      digitalWrite(RelayPin3, LOW);}
 
    if(strcmp(msg,"40")==0){
      digitalWrite(RelayPin4, HIGH);}
    
    if (strcmp(msg,"41")==0){
      digitalWrite(RelayPin4, LOW);}

    if(strcmp(msg,"50")==0){
      digitalWrite(RelayPin5, HIGH);}
    
    if (strcmp(msg,"51")==0){
      digitalWrite(RelayPin5, LOW);}

    if(strcmp(msg,"60")==0){
      digitalWrite(RelayPin6, HIGH);}
    
    if (strcmp(msg,"61")==0){
      digitalWrite(RelayPin6, LOW);}

    if(strcmp(msg,"70")==0){
      digitalWrite(RelayPin7, HIGH);}
    
    if (strcmp(msg,"71")==0){
      digitalWrite(RelayPin7, LOW);}
      */

    if(strcmp(msg,"00")==0){
        digitalWrite(RelayPin0, HIGH);
        digitalWrite(RelayPin1, HIGH);
        digitalWrite(RelayPin2, HIGH);
        digitalWrite(RelayPin3, LOW);
    }
    else if(strcmp(msg,"10")==0){
        digitalWrite(RelayPin0, LOW);
        digitalWrite(RelayPin1, HIGH);
        digitalWrite(RelayPin2, HIGH);
        digitalWrite(RelayPin3, LOW);      
    }
    else if(strcmp(msg,"20")==0){
        digitalWrite(RelayPin0, LOW);
        digitalWrite(RelayPin1, LOW);
        digitalWrite(RelayPin2, HIGH);
        digitalWrite(RelayPin3, LOW);      
    }
    else if(strcmp(msg,"30")==0){
        digitalWrite(RelayPin0, LOW);
        digitalWrite(RelayPin1, HIGH);
        digitalWrite(RelayPin2, LOW);
        digitalWrite(RelayPin3, LOW);      
    }
    else if(strcmp(msg,"50")==0){
        digitalWrite(RelayPin0, LOW);
        digitalWrite(RelayPin1, LOW);
        digitalWrite(RelayPin2, LOW);
        digitalWrite(RelayPin3, LOW);      
    }
        else if(strcmp(msg,"AUS")==0){
        digitalWrite(RelayPin0, HIGH);
        digitalWrite(RelayPin1, HIGH);
        digitalWrite(RelayPin2, HIGH);
        digitalWrite(RelayPin3, HIGH);      
    }
}


void setup()
{

int outMin = 2; // Lowest input pin
int outMax = 9; // Highest input pin
for(int i=outMin; i<=outMax; i++)
{
  pinMode(i, OUTPUT);
  digitalWrite(i, HIGH);
}
  
  Ethernet.begin(mac, ip);
  if (client.connect("FU-Client")) {
    client.publish("/lueftung/fu","FU-Client Booted");
    client.subscribe("/lueftung/fu");
  }
}

void loop()
{
  client.loop();
}
