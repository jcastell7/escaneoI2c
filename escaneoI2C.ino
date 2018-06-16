#include <Wire.h>//INICIAMOS LA LIBERIA WIRE
int direccion;//INICIAMOS LA VARIABLE DONDE SE ALMACENARAN LAS DIRECCIONES
int nohayconexion;//CREAMOS ESTA VARIABLE QUE SERA LA QUE OBTENDRA UN VALOR DISTINTO DE 0 SI NO HAY CONEXION, SI HAY PUES OBTIENE EL VALOR 0


void setup()
{
  Wire.begin();//INICIAMOS EL WIRE (I2C)
  Serial.begin(9600);//INICIAMOS EL SERIAL
}

void loop()
{
  if(Serial.available())//SI HAY ENTRADA DE DATOS POR SERIAL
  {

    if(Serial.read() == 'a')//SI ESE DATO ES UNA a
    {

   Serial.print("Vamos a escanear todas la direcciones posibles en I2C: ");//UN MENSAJE DE INICIO

   for(direccion = 1; direccion < 128; direccion++)//BUCLE FOR QUE IRA INCREMENTANDO EN 1 LA VARIABLE DIRECCION HASTA 127 (EL NUMERO MAXIOMO DE DISPOSITIVOS POR I2C)
   {
    
    Wire.beginTransmission(direccion);//INICIAMOS TRANSMISION CON LA DIRECCION QUE SE VA INCREMENTANDO
    nohayconexion = Wire.endTransmission();//SI ESTA NO RESPONDE, LA VARIABLE OBTIENE UN VALOR DISTINTO DE 0, SI RESPONDE OBTIENE 0.

   if(nohayconexion == 0)// SI LA VARIABLE OBTIENE UN VALOR IGUAL A 0 ENTONCES RELLIZARA EL PROCESO SIGIENTE
   {
    Serial.print("Se ha encontrado un dispositivo Conectado en la Direccion: ");//UN MENSAJE POR SERIAL
    Serial.println(direccion,HEX);//IMPRIMIMOS LA DIRECION
   }

   if(nohayconexion != 0)// SI LA VARIABLE OBTIENE UN VALOR DISTINTO A 0 ENTONCES RELLIZARA EL PROCESO SIGIENTE
   {
    Serial.print("No hay dispositivos conectados en la Direccion: ");//NOS DICE QUE NO HAY NADA
    Serial.println(direccion,HEX);// Y NOS SICE LA DIRECCION QUE SE HA PROBADO
   }

    
   }
   }
  }
}
