/*  Euller Barros
 *   02/2019
    Engenheiro eletricista diretor de eletrÃ´nica da Equipe Iron Pirates.
    Robotica Aplicada
    Equipe Iron Pirates
    ProtÃ³tipo do 1Â° Robo de batalhada para movimentaÃ§Ã£o
    codigo com movimentação completa (otimizaÃ§Ã£o com biblioteca prÃ³pria)
*/
#include <IronPirates.h>
//#include<Servo.h>

//========== CRIANDO OBJEITOS COM PINOS DA PONTE H=======================// 
IronPiratesMotors motorsIp(9, 8, 7, 6, 5, 4); // (ENA,IN1,IN2,ENB,IN3,IN4)
                

//===========PINOS Receptor============//
const int ail_sinal = A2
; //vermelho
const int elev_sinal = A3;// laranja 
//const int thr_sinal = ; 

//============= pino arma ===========// 
//const int pino_arma = 3;

//==== variaveis de interpretaÃ§Ã£o ====//
int elev, ail; //thr;

void setup() {
  pinMode(elev_sinal, INPUT);
  pinMode(ail_sinal, INPUT);
 // pinMode(thr_sinal, INPUT);
  //Arma.attach(pino_arma);
  Serial.begin(9600);
}

void loop() {
  
  //==========LENDO PULSOS/ARMA===========//
  elev = pulseIn(elev_sinal, HIGH);
  ail = pulseIn(ail_sinal, HIGH);
  //thr = pulseIn(thr_sinal, HIGH);

  
/*
  //========== Arma ==============//
  if(thr >= 1000 && thr <= 1100) {
       Arma.write(0);
       Serial.println("Arma parada");
  }
else if ( thr > 1100) {
 int  thr1 = map(thr, 1100, 2000, 0, 179);
  Arma.write(thr1);
  Serial.println("Arma Ligado");
}
*/
  //================parado com/sem sinal==============//
  if (elev == 0) {
    motorsIp.stopped();
  }
  if (elev > 1400 && elev < 1500) {
    if (ail > 1400 && ail < 1500) {
      motorsIp.stopped();
      Serial.println("parado");
    }
  }
  //=============================================================//



  else if (elev > 1600 && elev < 2000) {
    int elev1 = map(elev, 1600, 2000, 0, 255);
    //===========FRENTE===========//
    if (ail > 1600 && ail < 2000) {
      motorsIp.twoMotors(elev1, forward);
      Serial.println("y1");
    }
    //===========FRENTE ESQUERDA===========//
    if (ail > 1400 && ail < 1500) {
     motorsIp.leftBrake(elev1);
     motorsIp.rightMotor(elev1, forward);
     Serial.println("y2");
    }
    //===========LADO ESQUERDO(anti horario)===========//
    if (ail > 1000 && ail < 1400) {
     motorsIp.leftMotor(elev1, backward);
     motorsIp.rightMotor(elev1, forward);
     Serial.println("x2");
    }
  }

  else if (ail > 1500 && ail < 2000) {
    int ail1 = map(ail, 1500, 2000, 0, 255);
    //===========FRENTE DIREITA===========           
      if (elev > 1450 && elev < 1550) {
      motorsIp.leftMotor(ail1, forward);
      motorsIp.rightBrake(ail1);
      Serial.println("y3");
     }
    //===========LADO DIREITO(HORARIO)===========//
      if (elev > 1000 && elev < 1400) {
      motorsIp.leftMotor(ail1, forward);
      motorsIp.rightMotor(ail1, backward);
      Serial.println("x1");
    }
  }


  else if (elev > 1000 && elev < 1400) {
    int elev2 = map(elev, 1000, 1400, 255, 0);
    //===========BAIXO===========//
      if (ail > 1000 && ail < 1400) {
         motorsIp.twoMotors(elev2, backward);
         Serial.println("-y1");
    }
  }
  //===========BAIXO ESQUERDA===========//
  else if (elev > 1500 && elev < 1550) {
    if (ail > 900 && ail < 1000) {
      int ail2 = map(ail, 1500, 1550, 255, 0);
         motorsIp.leftBrake(ail2);
         motorsIp.rightMotor(ail2, backward);
         Serial.println("-y2");
    }
  }
  //===========BAIXO DIREITA===========//
  else if (elev > 900 && elev < 1000) {
    int elev3 = map(elev, 900, 1000, 0, 255);
     if (ail > 1400 && ail < 1500) {
        motorsIp.leftMotor(elev3, backward);
        motorsIp.rightBrake(elev3);
        Serial.println("-y3");
    }
  }
  
  //=========imprimir==========//
 
  
  Serial.print("        elev: ");
  Serial.print(elev);

  Serial.print("\t");

  Serial.print("ail: ");
  Serial.println(ail);
 /* 
  Serial.print("\t");
   
   Serial.print("thr: ");
  Serial.println(thr);
  */
  delay(100);
}




