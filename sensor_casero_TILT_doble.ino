   
int piezo=A0;
int piezo2=A1;
int pot=A5;     //introducimos un potenciómetro nuevo de 10K
int valorpot=0;
int valorpiezo=0;
int valorpiezo2=0;
int rele=2;
int rele2=3;

void setup()
{
  Serial.begin (9600);
  pinMode (pot,INPUT);  // declaramoslo
  pinMode (rele,OUTPUT);
  pinMode (rele2,OUTPUT);
  pinMode (piezo,INPUT);//ponemos un elemento piezoelectrico en una entrada analogica
  pinMode (piezo2,INPUT);//ponemos un elemento piezoelectrico en una entrada analogica
}

void loop()

{
  valorpot= analogRead (pot);//inicializamos la lectura de la patilla A5 
  Serial.println (valorpot);
  valorpiezo=0;
  valorpiezo2=0;
  digitalWrite (rele,HIGH);//Los dos dos relés funcionan desde el high, los inicializamos apagados.
  digitalWrite (rele2,HIGH);
  
  valorpiezo=analogRead (piezo);// Hacemos que lo lea...de 0 a 1024.
   if (valorpiezo2 >650)
  {
  digitalWrite (rele,LOW);
  delay (100);
  digitalWrite (rele,HIGH);
  delay (100);
  digitalWrite (rele,LOW);
  delay (100);
  digitalWrite (rele,HIGH);
  delay (100);
  digitalWrite (rele2,LOW);
  delay (100);
  digitalWrite (rele2,HIGH);
  delay (100); 
  digitalWrite (rele2,LOW);
  delay (100);
  digitalWrite (rele2,HIGH);
  delay (100);   
    
  }
  
  if (valorpiezo >650)  
  {
  digitalWrite (rele,LOW);
  delay (200);
  digitalWrite (rele,HIGH);
  delay (200);
  digitalWrite (rele,LOW);
  delay (200);
  digitalWrite (rele,HIGH);
  delay (200);
  digitalWrite (rele2,LOW);
  delay (200);
  digitalWrite (rele2,HIGH);
  delay (200); 
  digitalWrite (rele2,LOW);
  delay (200);
  digitalWrite (rele2,HIGH);
  delay (200);   
  }
 
  if (valorpiezo>valorpot)// Aqui lo calibramos. Notese la alta sensibilidad del piezoelectrico(entre 0-1024),la cual queda
                            //atenuada por la acción del potenciómetro. 

  {
  Serial.print ("valorpiezo=");
  Serial.println (valorpiezo);
  Serial.print ("valorpiezo2=");
  Serial.println (valorpiezo2);
  Serial.print ("valorpot=");
  Serial.println (valorpot);
  
  digitalWrite (rele,LOW);
  delay (100);
  digitalWrite (rele,LOW);
  }
  
  //delay (100);
  valorpiezo2=analogRead (piezo2);
  if (valorpiezo2>valorpot)
  {
  Serial.print ("valorpiezo=");
  Serial.println (valorpiezo);
  Serial.print ("valorpiezo2=");
  Serial.println (valorpiezo2);
  Serial.print ("valorpot=");
  Serial.println (valorpot);
  digitalWrite (rele2,LOW);
  delay (200);
  digitalWrite (rele2,LOW);
  
  }
  
  }
