// Definir los pines analógicos a los que están conectadas las señales
const float pinSignal1 = A0; // Primer señal en el pin A0
const float pinSignal2 = A1; // Segunda señal en el pin A1

void setup() 
{
  // Iniciar la comunicación serial
  Serial.begin(115200);
  pinMode(pinSignal1,INPUT),
  pinMode(pinSignal2,INPUT);
}

void loop() {
  // Leer las señales de los pines analógicos
  float valorSignal1 = analogRead(pinSignal1);
  float valorSignal2 = analogRead(pinSignal2);
  
  // Enviar los valores leídos al monitor serial
  Serial.print("Signal_A:");
  Serial.println(valorSignal1);
  
  Serial.print("Signal_B:");
  Serial.println(valorSignal2);
 

  delay(500); // 500 milisegundos (0.5 segundos)
}
