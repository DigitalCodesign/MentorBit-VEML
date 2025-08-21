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

#include "MentorBitVEML.h"

MentorBit_VEML::MentorBit_VEML(){

}

bool MentorBit_VEML::begin(){
    
}

void MentorBit_VEML::setConfiguration(uint8_t configuration){
    colormeter.setConfiguration(configuration);
}

// Obtiene la intensidad del componente rojo
uint16_t MentorBit_VEML::getRed(void) {
    return colormeter.getRed();
}

// Obtiene la intensidad del componente verde
uint16_t MentorBit_VEML::getGreen(void) {
    return colormeter.getGreen();
}

// Obtiene la intensidad del componente azul
uint16_t MentorBit_VEML::getBlue(void) {
    return colormeter.getBlue();
}

// Obtiene la intensidad de la luz blanca
uint16_t MentorBit_VEML::getWhite(void) {
    return colormeter.getWhite();
}

// Obtiene la temperatura de correlación de color (CCT) con un offset
uint16_t MentorBit_VEML::getCCT(float offset) {
    return colormeter.getCCT(offset);
}

// Obtiene el nivel de luz ambiental en lúmenes o unidades similares
float MentorBit_VEML::getAmbientLight(void) {
    return colormeter.getAmbientLight();
}
