/*              HONDEAMAKINA C TALDEA
 
Hurrengo programak 4 pultsagailuren irakurketa egiten du, 3 Zilindro pneumatiko kontrolatu eta zilindo bakoitzak bere Errele eta elektrobalbula monoegonkorrak irakurriz.   
   Ondoren Serie Monitorean idazten ditu balioak.
   Modified By C Taldea 2021
   CC. Creatives Commons. 
   This example code is in the public domain.
*/

// Aldagaien deklarazioa      

int botoiaA= 2; //Zilindro Handia
int botoiaB= 3; //Erdiko Zilirdroa
int botoiaC= 4; //3 Zilindroak
int botoiaD= 5; //Muturreko Zilindroa
int relayA= 13;
int relayB= 12;
int relayC= 10;
int balioaA = 0;
int balioaB = 0;
int balioaC = 0;
int balioaD = 0;

// Sarrera-Irteeren Inizializazioa

void setup() {
  
 Serial.begin (9600);
 pinMode (botoiaA, INPUT);
 pinMode (relayA, OUTPUT);
 digitalWrite(relayA,HIGH); //Zilindro Handia ATERATA
  
 pinMode (botoiaB, INPUT);
 pinMode (relayB, OUTPUT);
 digitalWrite(relayB,HIGH); //Erdiko Zilirdroa SARTUTA
  
 pinMode (botoiaC, INPUT);
 pinMode (relayC, OUTPUT);
 digitalWrite(relayC,HIGH); //Muturreko Zilindroa SARTUTA

 pinMode (botoiaD, INPUT);

 pinMode (9, OUTPUT);
 digitalWrite(9,LOW);
}

// Programa nagusia

void loop() 
{
 balioaA = digitalRead(botoiaA); //Pultsadorea irakurri
 balioaB = digitalRead(botoiaB); //Pultsadorea irakurri
 balioaC = digitalRead(botoiaC); //Pultsadorea irakurri
 balioaD = digitalRead(botoiaD); //Pultsadorea irakurri
 
 Serial.print ("Zilindro Handia=  ");
 Serial.println (balioaA);
 Serial.print ("Erdiko Zilirdroa=  ");
 Serial.println (balioaB);
 Serial.print ("Muturreko Zilindroa=  ");
 Serial.println (balioaD);
  Serial.print ("3 Zilindroak=  ");
 Serial.println (balioaC);

  if (balioaC == 1){
  digitalWrite (9,LOW);
 }
 
  if (balioaC == 0){
  digitalWrite(relayB,LOW);
  digitalWrite(relayA,LOW);
  digitalWrite(relayC,LOW);
  digitalWrite (9,HIGH);
 }
 else {
   digitalWrite(relayA,balioaA); //Zilindro Handia SARTU
   digitalWrite(relayB,balioaB); //Erdiko Zilirdroa ATRERA
   digitalWrite(relayC,balioaD); //Muturreko Zilindroa ATERA
    if (balioaA == 0){
  digitalWrite (9,HIGH);
 }
  if (balioaB == 0){
  digitalWrite (9,HIGH);
 }
  if (balioaD == 0){
  digitalWrite (9,HIGH);
 }
  }

 
 
 Serial.println ("");
 delay (0); 
}
