# KGB-MQTT-Lueftungssteuerung
KGB MQTT Lueftungssteuerung mit einem Arduino Nano und passendem Ethernet Shield

Hier ein paar Notizen für mich:  

Benötigte Ausgänge:  
* Start/Stop
* Geschwindigkeitsbit 1
* Geschwindigkeitsbit 2
* Geschwindigkeitsbit 3
* SpareOut 1
* SpareOut 2

Benötigte Eingänge:
* Fehler
* SpareIn 1
* SpareIn 2

Handbuch VLT3500  


TODO: Hartbeat mit einbauen.  

$ mosquitto_pub -h 192.168.178.128 -t "inTopic" -m "1"  
$ mosquitto_pub -h 192.168.178.128 -t "inTopic" -m "0"  

$ mosquitto_sub -h localhost -t "testTopic" -v  
testTopic hello world  
testTopic Light On  
testTopic Light Off  
testTopic Light On  

Library: UIPEthernet  

Eigene IP vom Arduino:  192.168.178.177  
IP vom MQTT-Broker: 192.168.178.128  

THX @ UIPEthernet   
THX @ https://github.com/fedorweems/YouTube/blob/master/MQTT_Ethernet.ino  
