/*  Euller Barros 
 *  Engenheiro eletricista diretor de eletrônica da Equipe Iron Pirates.
 *  Robótica Aplicada
 *  Equipe Iron Pirates 
 *  Protótipo do 1° Robo de batalhada para movimentação - escduino
 *  
 */

const int ail = A0; 
const int elev = A1;
const int thr = A3;

int leitura_ail;
int leitura_elev;
int leitura_thr;

void setup() {


  pinMode(ail, INPUT); //ail
  pinMode(elev, INPUT); // elev
  pinMode(thr, INPUT); // thr

  Serial.begin(9600); 

}

void loop() {
//reconhecendo frequencia dos pinos// de movimentação 

  leitura_ail = pulseIn(ail, HIGH); 
  leitura_elev = pulseIn(elev, HIGH); 
  leitura_thr = pulseIn(thr, HIGH); 
  delay(100);
  

  Serial.print("ail: "); 
  Serial.print(leitura_ail);  

  Serial.print("\t");

  Serial.print("elev: ");
  Serial.print(leitura_elev);

   Serial.print("\t");
   
  Serial.print("thr: ");
  Serial.println(leitura_thr);

  delay(100); 
              
}
