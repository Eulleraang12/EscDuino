/*  Euller Barros
 *   02/2019
    Engenheiro eletricista diretor de eletrônica da Equipe Iron Pirates.
    Robótica Aplicada
    Equipe Iron Pirates
    Protótipo do 1° Robo de batalhada para movimentação
    codigo com movimentação completa
*/
//========== PINOS PONTE H=======================//
//motor_A
const int IN1 = 7;
const int IN2 = 6;
const int pwm_A = 10;

//motor_B
const int IN3 = 5;
const int IN4 = 4;
const int pwm_B = 9;

//===========PINOS Receptor============//
const int elev_sinal = A1;
const int ail_sinal = A0;


//==== variaveis de interpretação ====//
int elev, ail;


void setup() {
  pinMode(elev_sinal, INPUT);
  pinMode(ail_sinal, INPUT);
  Serial.begin(9600);
}
void loop() {
  //==========LENDO PULSOS===========//
  elev = pulseIn(elev_sinal, HIGH);
  ail = pulseIn(ail_sinal, HIGH);

  //================parado com/sem sinal==============//
  if (elev == 0) {
    analogWrite(pwm_A, 0);
    analogWrite(pwm_B, 0);
  }
  if (elev > 1400 && elev < 1500) {
    if (ail > 1400 && ail < 1500) {
      analogWrite(pwm_A, 0);
      analogWrite(pwm_B, 0);
      Serial.println("parado");
    }
  }
  //=============================================================//



  else if (elev > 1600 && elev < 2000) {
    int elev1 = map(elev, 1600, 2000, 0, 255);
    //===========FRENTE===========//
    if (ail > 1600 && ail < 2000) {
      //motor A
      analogWrite(pwm_A, elev1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      //motor B
      analogWrite(pwm_B, elev1);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      Serial.println("y1");
    }
    //===========FRENTE ESQUERDA===========//
    if (ail > 1400 && ail < 1500) {
      //motor A
      analogWrite(pwm_A, elev1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      //motor B
      analogWrite(pwm_B, elev1);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      Serial.println("y2");
    }
    //===========LADO ESQUERDO(anti horario)===========//
    if (ail > 950 && ail < 1050) {
     //motor A
     analogWrite(pwm_A, elev1);
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, HIGH);
     //motor B
     analogWrite(pwm_B, elev1);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
     Serial.println("-xf");
    }
  }

  else if (ail > 1500 && ail < 2000) {
    int ail1 = map(ail, 1500, 2000, 0, 255);
    //===========FRENTE DIREITA===========//
      if (elev > 1450 && elev < 1550) {
      //motor A
      analogWrite(pwm_A, ail1);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      //motor B
      analogWrite(pwm_B, ail1);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      Serial.println("y3");
     }
    //===========LADO DIREITO(HORARIO)===========//
      if (elev > 1000 && elev < 1100) {
      //motor A
      analogWrite(pwm_A, ail1);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      //motor B
      analogWrite(pwm_B, ail1);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      Serial.println("x");
    }
  }

  else if (elev > 1000 && elev < 1400) {
    int elev2 = map(elev, 1000, 1400, 255, 0);
    //===========BAIXO===========//
      if (ail > 1000 && ail < 1400) {
          //motor A
          analogWrite(pwm_A,elev2);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          //motor B
          analogWrite(pwm_B,elev2);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
         Serial.println("-y1");
    }
  }
  //===========BAIXO ESQUERDA===========//
  else if (elev > 1500 && elev < 1550) {
    if (ail > 900 && ail < 1000) {
      int ail2 = map(ail, 1500, 1550, 255, 0);
         //motor A
          analogWrite(pwm_A, ail2);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          //motor B
          analogWrite(pwm_B, ail2);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, HIGH);
          Serial.println("-y2");
    }
  }
  //===========BAIXO DIREITA===========//
  else if (elev > 900 && elev < 1000) {
    int elev3 = map(elev, 900, 1000, 0, 255);
     if (ail > 1400 && ail < 1500) {
          //motor A
          analogWrite(pwm_A, elev3);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, HIGH);
          //motor B
          analogWrite(pwm_B,elev3);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          Serial.println("-y3");

    }
  }
  //=========imprimir==========//

  Serial.print("elev: ");
  Serial.print(elev);

  Serial.print("\t");

  Serial.print("ail: ");
  Serial.println(ail);
  delay(100);
}
