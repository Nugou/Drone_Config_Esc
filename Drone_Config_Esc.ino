#include <Servo.h>
int pino_motor[4] = {3, 4, 5, 6}; //pino de controle dos motores

int potMotorMax = 180;
int potMotorMin = 10;
String msg;
int option = 0;
int pot = 0;

Servo ServoMotor_0;
Servo ServoMotor_1;
Servo ServoMotor_2;
Servo ServoMotor_3;

void setup() {

	Serial.begin(115200);
	
	while(Serial.available());

	Serial.println("Deixe Este Serial aberto até o fim do procedimento!!!");
	Serial.println();
	Serial.println();
	delay(1000);
	Serial.println("Configurando pinos: ");
	Serial.print("Motor 1: ");Serial.println(pino_motor[0]);
	Serial.print("Motor 2: ");Serial.println(pino_motor[1]);
	Serial.print("Motor 3: ");Serial.println(pino_motor[2]);
	Serial.print("Motor 4: ");Serial.println(pino_motor[3]);
	
 	ServoMotor_0.attach(pino_motor[0]);
	ServoMotor_1.attach(pino_motor[1]);
	ServoMotor_2.attach(pino_motor[2]);
	ServoMotor_3.attach(pino_motor[3]);

	delay(100);

	Serial.println("Aguarde...");
	Serial.println();
	Serial.println();
	
	delay(1000);
	Serial.println("Quando estiver pronto, Ligue os motores na bateria!!!");
	delay(1000);
	Serial.println();
	Serial.println();
	Serial.println("Apos os primeiros bip, Envie qualquer caracter pelo serial!");
	
	while(Serial.read() == -1){
		ServoMotor_0.write(potMotorMax);
		ServoMotor_1.write(potMotorMax);
		ServoMotor_2.write(potMotorMax);
		ServoMotor_3.write(potMotorMax);
	}
	ServoMotor_0.write(potMotorMin);
	ServoMotor_1.write(potMotorMin);
	ServoMotor_2.write(potMotorMin);
	ServoMotor_3.write(potMotorMin);

	Serial.println("Terminado");
	delay(1000);
	Serial.println();
	Serial.println();
	Serial.println("Para selecionar um motor, utilize as letras:");
	Serial.println("a - Para motor 1");
	Serial.println("b - Para motor 2");
	Serial.println("c - Para motor 3");
	Serial.println("d - Para motor 4");
	Serial.println("t - Para todos");
	Serial.println();
	Serial.println();
	Serial.println("Para enviar  a potencia, digite um nuemro inteiro entre 0 e 179");
	Serial.println("Sinta-se a vontade para testar apartir de agora!!!");
	Serial.println();
	Serial.println();
	Serial.println("Todos os motores selecionados!");
}

void loop() {
	if(Serial.available()){
		msg = "";
		while(Serial.available()){
			msg += (char)Serial.read();
			delay(10); 
		}
		if(msg == "a"){Serial.println("Motor 1 selecionado!");option = 1;}
		else if(msg == "b"){Serial.println("Motor 2 selecionado!");option = 2;}
		else if(msg == "c"){Serial.println("Motor 3 selecionado!");option = 3;}
		else if(msg == "d"){Serial.println("Motor 4 selecionado!");option = 4;}
		else if(msg == "t"){Serial.println("Todos os motores selecionados!");option = 0;}
		else if(msg.toInt() > -1 and msg.toInt() < 180){
			Serial.print("Potencia: ");
			Serial.println(msg.toInt());
			if(option == 1){ServoMotor_0.write(msg.toInt());}
			if(option == 2){ServoMotor_1.write(msg.toInt());}
			if(option == 3){ServoMotor_2.write(msg.toInt());}
			if(option == 4){ServoMotor_3.write(msg.toInt());}
			if(option == 0){
				ServoMotor_0.write(msg.toInt());
				ServoMotor_1.write(msg.toInt());
				ServoMotor_2.write(msg.toInt());
				ServoMotor_3.write(msg.toInt());
			}
		}
	}
}

void setupMode(){
	
}

