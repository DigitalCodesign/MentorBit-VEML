/*

            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Julio de 2025
    Fecha de version: Julio de 2025
    Repositorio: https://github.com/DigitalCodesign/MentorBit-VEML  
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit VEML
    Metodos principales:
        MentorBitVEML_h -> constructor de la clase
        begin -> inicializador, debe colocarse en el setup
        getRed -> lee el valor de rojo que detecta el sensor
        getGreen -> lee el valor de verde que detecta el sensor
        getBlue -> lee el valor de azul que detecta el sensor
        getWhite() -> lee el valor de azul que detecta el sensor
        getCCT() -> lee el valor de la temperatura de la luz ambiente que detecta el sensor
        getAmbientLight() -> lee el valor de la luminocidad ambiente que detecta el sensor

*/

#ifndef MentorBitVEML_h
#define MentorBitVEML_h

#include <Arduino.h>
#include <Wire.h>
#include <veml6040.h>



    class MentorBit_VEML
    {

        public:

            MentorBit_VEML();
            bool begin();
            void setConfiguration(uint8_t);
            uint16_t getRed(void);
            uint16_t getGreen(void);
            uint16_t getBlue(void);
            uint16_t getWhite(void);
            uint16_t getCCT(float offset = 0.5);  
            float getAmbientLight(void);

        private:
  
            VEML6040 colormeter;

    };

#endif
