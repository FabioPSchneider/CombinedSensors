//This code was written to be easy to understand.
//Modify this code as you see fit.
//This code will output data to the Arduino serial monitor.
//Type commands into the Arduino serial monitor to control the pH circuit.
//This code was written in the Arduino 1.8.9 IDE
//An Arduino MEGA was used to test this code.
//This code was last tested 6/2019



String inputstring = "";                              //a string to hold incoming data from the PC
String sensorstringPH = "";                             //a string to hold the data from the Atlas Scientific product
String sensorstringTEMP = "";                             //a string to hold the data from the Atlas Scientific product
String sensorstringDO = "";
boolean input_string_complete = false;                //have we received all the data from the PC
boolean sensor_string_completePH = false;               //have we received all the data from the Atlas Scientific product
boolean sensor_string_completeTEMP = false;
boolean sensor_string_completeDO = false;
float pH;                                             //used to hold a floating point number that is the pH
float temperature;
float DO;


void setup() {                                        //set up the hardware
  Serial.begin(9600);                                 //set baud rate for the hardware serial port_0 to 9600
  Serial3.begin(9600);                                //set baud rate for software serial port_3 to 9600
  Serial2.begin(9600);
  Serial1.begin(9600);
  inputstring.reserve(10);                            //set aside some bytes for receiving data from the PC
  sensorstringPH.reserve(30);                           //set aside some bytes for receiving data from Atlas Scientific product
}

void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC
}


void serialEvent3() {                                 //if the hardware serial port_3 receives a char
  sensorstringPH = Serial3.readStringUntil(13);         //read the string until we see a <CR>
  sensor_string_completePH = true;                      //set the flag used to tell if we have received a completed string from the PC
}

void serialEvent2() {                                 //if the hardware serial port_3 receives a char
  sensorstringDO = Serial2.readStringUntil(13);         //read the string until we see a <CR>
  sensor_string_completeDO = true;                      //set the flag used to tell if we have received a completed string from the PC
}

void serialEvent1() {                                 //if the hardware serial port_3 receives a char
  sensorstringTEMP = Serial1.readStringUntil(13);         //read the string until we see a <CR>
  sensor_string_completeTEMP = true;                      //set the flag used to tell if we have received a completed string from the PC
}

void loop() {                                         //here we go...


  if (input_string_complete == true) {                //if a string from the PC has been received in its entirety
    Serial3.print(inputstring);                       //send that string to the Atlas Scientific product
    Serial3.print('\r');                              //add a <CR> to the end of the string
    Serial2.print(inputstring);                       //send that string to the Atlas Scientific product
    Serial2.print('\r');                              //add a <CR> to the end of the string
    Serial1.print(inputstring);                       //send that string to the Atlas Scientific product
    Serial1.print('\r');                              //add a <CR> to the end of the string
    inputstring = "";                                 //clear the string
    input_string_complete = false;                    //reset the flag used to tell if we have received a completed string from the PC
  }


  if (sensor_string_completePH == true) {               //if a string from the Atlas Scientific product has been received in its entirety
    Serial.print("pH:  ");
    Serial.print(sensorstringPH);                     //send that string to the PC's serial monitor
  
  
  sensorstringPH = "";                                  //clear the string:
  sensor_string_completePH = false;                     //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }
  
if (sensor_string_completeDO == true) {               //if a string from the Atlas Scientific product has been received in its entirety
   
    Serial.print("  DO:  ");
    Serial.print(sensorstringDO);                     //send that string to the PC's serial monitor
  
  
  sensorstringDO = "";                                  //clear the string:
  sensor_string_completeDO = false;                     //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }
  
  if (sensor_string_completeTEMP == true) {               //if a string from the Atlas Scientific product has been received in its entirety
    Serial.print("\t");
    Serial.print("Temp:  ");
    Serial.println(sensorstringTEMP);                     //send that string to the PC's serial monitor
  
  
  sensorstringTEMP = "";                                  //clear the string:
  sensor_string_completeTEMP = false;                     //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }
}
