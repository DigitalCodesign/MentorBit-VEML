# MentorBit-VEML

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del MentorBit módulo detector de colores.](https://github.com/DigitalCodesign/MentorBit-SensorColor/blob/main/assets/color_module.png)

Con esta librería, podrás detectar el color de los objetos (entre el rojo, verde, azul y blanco), permitiéndote crear proyectos que requieran de la separación de las piezas segun color, sistemas de control distribuido o robots complejos.

---

## Descripción

### ¿Qué es el VEML?

Es un sensor de luz ambiental fabricado por Vishay que permite medir la intensidad de luz en diferentes canales, incluyendo luz blanca y luz de colores (rojo, verde y azul). Es un sensor de bajo consumo, compacto y fácil de integrar en aplicaciones electrónicas, como dispositivos portátiles, sistemas de iluminación, pantallas y aplicaciones de control de iluminación inteligente.

Características principales del VEML6040:

- Medición de luz blanca y de colores (RGB)
- Alta sensibilidad y precisión en la detección de luz
- Interfaz I2C para comunicación con microcontroladores
- Bajo consumo de energía, adecuado para dispositivos portátiles
- Rango de medición amplio y respuesta rápida

Este tipo de módulo es ideal para:

- Aplicaciones que requieren ajuste automático de brillo.
- Reconocimiento de ambientes.
- Control de iluminación basado en la percepción de la luz del entorno.

---

### ¿Qué hace esta librería?

La librería MentorBit-VEML permite:

- Detectar el color de un objeto (solo detecta objetos azules, verdes, rojo o blancos).
- Estimar la luz ambientes.
- Estimar el rango de temperatura de la luz (si es cálida o fría).

---

### ¿Qué puedes construir con este módulo?

- Iluminación ambiental inteligente.
- Calibración de pantallas o cámaras.
- Clasificación o clasificación de objetos por color.
- Arte interactivo y instalación luminosa.
- Monitor de iluminación para cultivo de interiores.
- Medición de color para fotografía
- Detección de presencia de cambios de luz.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo de color al puerto marcado como I2C en la sección de comunicaciones de la placa MentorBit. El módulo utiliza el protocolo I2C para comunicarse con la placa.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-VEML y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-VEML/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: 

Obtener valores

Este ejemplo detecta el color de un objeto y de la luz ambiente e imprime los valores por el monitor serial.

```cpp
// Se incluye la libreria MentorBitMatrizVEML
#include <MentorBitVEML.h>

// Se crea el objeto colorSensor
MentorBit_VEML colorSensor;


void setup() {
    // Inicializamos el bus serial a una velocidad de 9600 baudios
    Serial.begin(9600);
    delay(1000);
    Serial.println("Iniciando sensor de color...");
    // Inicializamos la comunicación por I2C
    Wire.begin();
    // Configuración del sensor (ajustar si es necesario)
    uint8_t configuration = VEML6040_IT_320MS + VEML6040_AF_AUTO + VEML6040_SD_ENABLE;
    colorSensor.setConfiguration(configuration);
}

void loop() {
    // Leer valores de colores
    uint16_t red = colorSensor.getRed();
    uint16_t green = colorSensor.getGreen();
    uint16_t blue = colorSensor.getBlue();
    uint16_t white = colorSensor.getWhite();

    // Mostrar los valores en el monitor serial
    Serial.println("Valores del sensor de color:");
    Serial.print("Rojo: "); Serial.println(red);
    Serial.print("Verde: "); Serial.println(green);
    Serial.print("Azul: "); Serial.println(blue);
    Serial.print("Blanco: "); Serial.println(white);
    Serial.print("Color detectado: "); Serial.println(colorDetectado);
    Serial.println("---------------------------");

    delay(5000); // Espera 1 segundo antes de la siguiente lectura
}
```

---

## Funciones Principales

- bool begin()
  Devuelve true si se ha establecido la comunicación por I2C.

- void setConfiguration(uint8_t)
  Establece la configuración del VEML.

- uint16_t getRed(void)
  Obtiene el valor de rojo que detecte el sensor VEML.

- uint16_t getGreen(void)
  Obtiene el valor de verde que detecte el sensor VEML.

- uint16_t getBlue(void)
  Obtiene el valor de azul que detecte el sensor VEML.

- uint16_t getWhite(void)
  Obtiene el valor de blanco que detecte el sensor VEML.

- uint16_t getCCT(float offset = 0.5)
  Obtiene la temperatura de color correlacionada que detecte el sensor VEML.

- float getAmbientLight(void)
  Obtiene el valor de la luz ambiente (lux) que detecte el sensor VEML.

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo Detector de Colores](https://digitalcodesign.com/shop/00040023-mentorbit-modulo-detector-de-color-8725#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/drive/folders/1U2wufRELMn1eFGYcjdd9GxkwyM0f-3zC)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/drive/folders/1U2wufRELMn1eFGYcjdd9GxkwyM0f-3zC)
