# Arduino_Osciloscopio
Pequeño codigo para placa de desarrollo Arduino UNO, para visualizar dos señales pequeñas para proyectos pequeños.

Contexto:
Arduino Uno es una placa de desarrollo de código abierto que cuenta con un microcontrolador microchip ATmega328P (circuito integrado en el que se puede grabar instrucciones)  (https://www.microchip.com/en-us/product/atmega328p) y desarrollado por Arduino.cc una compañía de desarrollo de software ( https://www.arduino.cc ).
El código se escribe en un lenguaje basado en C/C++ desarrollado por la propia compañia Arduino, en el proceso de compilación de una placa Arduino UNO, el código escrito en el lenguaje de Arduino (basado en C/C++) se traduce a lenguaje ensamblador específico para el microcontrolador ATmega328P.

<p align="left">
  <img src="https://github.com/user-attachments/assets/7549e83b-3023-4591-bd87-a17529101653" alt="imagen" width="60"/>
   <img src="https://github.com/user-attachments/assets/fafd5f5c-713d-4c96-bbd0-1e3f97bed9db" alt="imagen" width="60"/>
</p>

![arduino drawio](https://github.com/user-attachments/assets/714955eb-b39b-4059-8e13-50c68bbe0059)


Se utilizan las entradas analogícas del microcontrolador para tomar un muestreo simil continuo de la señal a medir y se utiliza el IDE (integrated development environment) del Arduino para visualizarlo, ya que cuenta con un trazador en pantalla de señales seriales (Serial Plotter).


Funcionamiento:
La placa Arduino debe enviar datos a través del puerto serie utilizando funciones especificas para eso, y la comunicación serial en este contexto se realiza a través del puerto USB.
  
Estos datos deben ser enviados en un formato que el Serial Plotter pueda interpretar y graficar. El Serial Plotter espera que los datos estén en un formato de "etiqueta y valor" en cada línea, como: etiqueta: valor.

El Arduino UNO tiene un conversor analógico-digital (ADC) de 10 bits, lo que significa que puede medir valores en un rango de 0 a 1023. Esto se traduce en una resolución de aproximadamente 4.9 mV por paso (si la referencia de voltaje es 5V).

Rango de Medición: El rango típico de entrada analógica es de 0 a 5V. Sin embargo, puedes cambiar la referencia de voltaje interna a 1.1V usando la función analogReference() para medir un rango más pequeño con mayor precisión.

Resolución: La resolución es de 10 bits, lo que da 1024 niveles posibles. Por ejemplo, si estás midiendo un voltaje de 5V, cada nivel representa aproximadamente 4.9 mV.

Muestreo/Velocidad de Baudios: La comunicación serial se realiza a una velocidad determinada en baudios, que indica la cantidad de bits transmitidos por segundo. En el código de Arduino, se especifica con la función Serial.begin(baudRate). Las velocidades comunes son 9600, 115200, etc.


o 

```markdown
```c++
#Constantes para trabajar con los pines de la placa
const float pinSignal1 = A0; // Primer señal en el pin A0
const float pinSignal2 = A1; // Segunda señal en el pin A1

# Funcion de configuración
void setup() 
{
  // Iniciar la comunicación serial
  Serial.begin(115200);
  pinMode(pinSignal1,INPUT),
  pinMode(pinSignal2,INPUT);
}

#Funcion de proceso

void loop()
{
  // Leer las señales de los pines analógicos
  float valorSignal1 = analogRead(pinSignal1);
  float valorSignal2 = analogRead(pinSignal2);
  
  // Enviar los valores leídos al monitor serial
  Serial.print("Signal_A:");
  Serial.println(valorSignal1);
  
  Serial.print("Signal_B:");
  Serial.println(valorSignal2);
 
  #Muestreo en Trazador
  delay(500); // 500 milisegundos (0.5 segundos)
}
}

```


![Captura desde 2024-08-18 09-50-44](https://github.com/user-attachments/assets/b33a1ae5-9481-49b8-a3e7-057d2858a73c)


[Grabación de pantalla desde 2024-08-18 09-54-15.webm](https://github.com/user-attachments/assets/6474c47a-35ad-42cb-a3f6-cca87a97e43c)


Utilizado en proyecto real (Contador digital)

[![Enlace al video]([https://img.youtube.com/vi/soxA6iLSIic?si=A4vQgxyXnyEfhXhk/maxresdefault.jpg](https://github.com/user-attachments/assets/7da64c97-c6cd-4389-96d5-d8f35c14e7c8))](https://www.youtube.com/watch?v=soxA6iLSIic?si=A4vQgxyXnyEfhXhk)

