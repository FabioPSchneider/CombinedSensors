//Combines the sample code for atlas scientific's pH, DO, and Temp sensors




String inputstring = "";                              //a string to hold incoming data from the PC
String sensorstringPH = "";                             //a string to hold the data from the Atlas Scientific product
String sensorstringDO = "";                             //a string to hold the data from the Atlas Scientific product
String sensorstringTEMP = "";                             //a string to hold the data from the Atlas Scientific product
boolean input_string_complete = false;                //have we received all the data from the PC
boolean sensor_string_completePH = false;               //have we received all the data from the Atlas Scientific product
boolean sensor_string_completeDO = false;
boolean sensor_string_completeTEMP = false;
float pH;                                             //used to hold a floating point number that is the pH
float temperature;                                    //used to hold a floating point number that is the temperature
float DO;                                             //used to hold a floating point number that is the DO
String checkpH;
String checkDO;
String checkTemp;


void setup() {                                        //set up the hardware
  Serial.begin(9600);                                 //set baud rate for the hardware serial port_0 to 9600
  Serial3.begin(9600);                                //set baud rate for software serial port_3(pH) to 9600
  Serial2.begin(9600);                                //set baud rate for software serial port_2(DO) to 9600
  Serial1.begin(9600);                                //set baudrate for software serial port_1(Temp) to 9600
  inputstring.reserve(10);                            //set aside some bytes for receiving data from the PC
  sensorstring.reserve(30);                           //set aside some bytes for receiving data from Atlas Scientific product
}

void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC
}


void serialEvent3() {                                 //if the hardware serial port_3 receives a char
  sensorstringTEMP = Serial3.readStringUntil(13);         //read the string until we see a <CR>
  sensor_string_completePH = true;                      //set the flag used to tell if we have received a completed string from the PC
}

void serialEvent2() {                                 //repeats last block but for DO
  sensorstringDO = Serial2.readStringUntil(13);         
  sensor_string_completeDO = true;                      
}

void serialEvent1() {                                 //repeats last block but for temp
  sensorstringTEMP = Serial1.readStringUntil(13);         
  sensor_string_completeTEMP = true;                      
}

void loop() {                                         //here we go...

  Serial.println("Will you be using a pH sensor (y/n)?");
    while (Serial.available() == 0){}
    CheckpH = Serial.parseInt();

   Serial.println("Will you be using a temperature sensor (y/n)?");
    while (Serial.available() == 0){}
    CheckTemp = Serial.parseInt();

   Serial.println("Will you be using a DO sensor (y/n)?");
    while (Serial.available() == 0){}
    CheckDO = Serial.parseInt();



  if (input_string_complete == true) {                //if a string from the PC has been received in its entirety
    Serial3.print(inputstring);                       //send that string to the Atlas Scientific product
    Serial3.print('\r');                              //add a <CR> to the end of the string
    Serial2.print(inputstring);                       //DO
    Serial2.print('\r');                              
    Serial1.print(inputstring);                       //Temp
    Serial1.print('\r');
    inputstring = "";                                 //clear the string
    input_string_complete = false;                    //reset the flag used to tell if we have received a completed string from the PC
  }


  if (sensor_string_completePH == true & CheckpH == "y") {               //if a string from the Atlas Scientific product has been received in its entirety
    Serial.print("pH:  ");
    Serial.print(sensorstringPH);                     //send that string to the PC's serial monitor
  
  
  sensorstringPH = "";                                  //clear the string:
  sensor_string_completePH = false;                     //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }
  if (sensor_string_completeDO == true & CheckTemp == "y") {               //if a string from the Atlas Scientific product has been received in its entirety
    Serial.print("\t");
    Serial.print("Temp:  ");
    Serial.println(sensorstringTEMP);                     //send that string to the PC's serial monitor
  
  
  sensorstring1 = "";                                  //clear the string:
  sensor_string_complete1 = false;                     //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }

  }
  if (sensor_string_completeDO == true & CheckDO == "y") {               //if a string from the Atlas Scientific product has been received in its entirety
    Serial.print("\t");
    Serial.print("DO:  ");
    Serial.println(sensorstringDO);                     //send that string to the PC's serial monitor
  
  
  sensorstringDO = "";                                  //clear the string:
  sensor_string_completeDO = false;                     //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }
}
