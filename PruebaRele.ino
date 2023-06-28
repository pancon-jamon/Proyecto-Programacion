int bombaAgua = 8;

void setup()
{
	pinMode(bombaAgua,OUTPUT);
}

void loop()
{
	digitalWrite(bombaAgua, LOW); //Encender Rele
	delay(10000);

	digitalWrite(bombaAgua, HIGH); //Apagar Rele
	delay(8000);	
}
