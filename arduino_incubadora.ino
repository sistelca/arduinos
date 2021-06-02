//initializes/defines the output pin of the LM335 temperature sensor
int outputpin= 0;
int i = 0;
int n = 3000;
float suma = 0;
float celsius = 0;
int estado = 0;

//this sets the ground pin to LOW and the input voltage pin to high
void setup()
{
Serial.begin(9600);
pinMode(13, OUTPUT);
}

//main loop
void loop()
{
   for (int i=0; i < 6; i++){
      int rawvoltage= analogRead(outputpin);
      float millivolts= (rawvoltage/1024.0) * 5000;
      float kelvin= (millivolts/10);
      //Serial.print(kelvin);
      //Serial.println(" degrees Kelvin");
      Serial.print(">");
      celsius= kelvin - 273.15;
      suma = suma + celsius;
      delay(n);
   }
   
   celsius = (suma / 6);
   suma = 0;

  if (celsius < 37.6)
    {
//      Serial.println("Prendida");
      n = 3000;
      estado = 1;
      digitalWrite(13, HIGH);
    // correccion por variacion de voltaje
    // celsius=celsius-0.47;
    }
  else if (celsius > 37.8)
    {
//      Serial.println("Apagada");
      n = 3000;
      estado =0;
      digitalWrite(13, LOW);
      // correccion por variacion de voltaje
      // celsius=celsius+1;
    }
  else
    {
      n = 1500;
    }

Serial.print(celsius);
Serial.println(" Grados Celsius");

Serial.println(">>");

}
