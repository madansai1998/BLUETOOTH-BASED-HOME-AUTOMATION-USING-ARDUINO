//Home Automation Bluetooth App Controlled
String readString;
#define relay1 2    //Connect relay1 to pin 2
#define relay2 3    //Connect relay2 to pin 3
#define relay3 4   //Connect relay3 to pin 4
#define relay4 5    //Connect relay4 to pin 5
void setup()
{
  Serial.begin(9600);            //Set rate for communicating with phone
  pinMode(relay1, OUTPUT);       //Set relay1 as an output
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);      //Set relay2 as an output
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);     //Switch relay1 off
  digitalWrite(relay2, HIGH);     //Swtich relay2 off
  digitalWrite(relay3, HIGH);     //Switch relay1 off
  digitalWrite(relay4, HIGH);     //Swtich relay2 off
}
void loop()
{
  while(Serial.available())    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    readString += c;                //Means readString = readString + c
  }
    if (readString.length() >0)
    {
      Serial.println(readString);
      if(readString == "switch all on"){
        switchallon();
      }               
      else if(readString == "switch all off"){
        switchalloff();
      }             
      else if(readString == "relay1 on"){   
        digitalWrite(relay1, LOW);
      }
      else if(readString == "relay1 off"){
        digitalWrite(relay1, HIGH);
      }
       else if(readString == "relay2 on"){   
        digitalWrite(relay2, LOW);
      }
      else if(readString == "relay2 off"){
        digitalWrite(relay2, HIGH);
      }
       else if(readString == "relay3 on"){   
        digitalWrite(relay3, LOW);
      }
      else if(readString == "relay3 off"){
        digitalWrite(relay3, HIGH);
      }
      else if(readString == "relay4 on"){
        digitalWrite(relay4, LOW);
      }
      else if(readString == "relay4 off"){
        digitalWrite(relay4, HIGH);
      }
      readString="";
    }
}
void switchalloff()               //Function for turning OFF all relays
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}
void switchallon()              //Function for turning ON all relays
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
}
