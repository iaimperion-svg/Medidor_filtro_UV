// TFT ILI9486 480x320, shield paralelo de 16 bits para Mega 2560.
// Pinout contrastado con el ejemplo local de LCDWIKI para Mega:
// DB0..DB7 -> 37,36,35,34,33,32,31,30
// DB8..DB15 -> 22,23,24,25,26,27,28,29
// RS=38, WR=39, CS=40, RESET=41; el shield no expone RD.
// Se reserva D44 (NC en este shield) para la senal RD de la libreria.
// Esta prueba no accede al Wi-Fi ni a la tarjeta SD.

#include <LCDWIKI_GUI.h>
#include <LCDWIKI_KBV.h>
#include <lcd_mode.h>

#if !defined(__AVR_ATmega2560__)
#error "Selecciona Arduino Mega 2560 como placa."
#endif

#if CONFIG_USE_8BIT_BUS != 0
#error "LCDWIKI_KBV debe tener CONFIG_USE_8BIT_BUS=0 en lcd_mode.h."
#endif

// La version local de LCDWIKI_KBV accede al registro de RD incluso al
// construir el objeto: usar D44, no -1/255, para evitar un indice invalido.
LCDWIKI_KBV pantalla(ILI9486, 40, 38, 39, 44, 41);

const uint16_t NEGRO = 0x0000;
const uint16_t BLANCO = 0xFFFF;
const uint16_t ROJO = 0xF800;
const uint16_t VERDE = 0x07E0;
const uint16_t AZUL = 0x001F;
const uint16_t COLORES[] = {NEGRO, BLANCO, ROJO, VERDE, AZUL};

uint8_t etapa = 0;
unsigned long cambioAnterior = 0;

void texto(const char *contenido, int16_t x, int16_t y, uint8_t tamano) {
  pantalla.Set_Text_Size(tamano);
  pantalla.Print_String(reinterpret_cast<const uint8_t *>(contenido), x, y);
}

void mostrarPanelDePrueba() {
  pantalla.Fill_Screen(NEGRO);
  pantalla.Set_Text_Mode(0);
  pantalla.Set_Text_colour(BLANCO);
  pantalla.Set_Text_Back_colour(NEGRO);

  texto("PRUEBA DISPLAY", 25, 20, 3);
  texto("Mega 2560 / ILI9486", 25, 65, 2);
  texto("UV: --", 25, 105, 6);
  texto("Sin datos de Internet", 25, 180, 2);
  texto("Rojo     Verde     Azul", 25, 225, 2);

  const int16_t ancho = pantalla.Get_Display_Width();
  const int16_t alto = pantalla.Get_Display_Height();
  const int16_t tercio = ancho / 3;
  pantalla.Set_Draw_color(ROJO);
  pantalla.Fill_Rectangle(0, alto - 45, tercio - 1, alto - 1);
  pantalla.Set_Draw_color(VERDE);
  pantalla.Fill_Rectangle(tercio, alto - 45, 2 * tercio - 1, alto - 1);
  pantalla.Set_Draw_color(AZUL);
  pantalla.Fill_Rectangle(2 * tercio, alto - 45, ancho - 1, alto - 1);

  Serial.println(F("Prueba enviada al display. Confirmar colores y texto visualmente."));
}

void setup() {
  Serial.begin(115200);
  Serial.println(F("Inicio de prueba TFT ILI9486, bus paralelo de 16 bits."));

  // Deseleccionar SD (D53) y flash opcional (D45) del shield.
  digitalWrite(53, HIGH);
  pinMode(53, OUTPUT);
  digitalWrite(45, HIGH);
  pinMode(45, OUTPUT);

  pantalla.Init_LCD();
  pantalla.Set_Rotation(3);  // Horizontal, girado 180 grados respecto a rotacion 1.
  Serial.print(F("Resolucion configurada: "));
  Serial.print(pantalla.Get_Display_Width());
  Serial.print('x');
  Serial.println(pantalla.Get_Display_Height());
  pantalla.Fill_Screen(COLORES[0]);
  cambioAnterior = millis();
}

void loop() {
  const uint8_t cantidad = sizeof(COLORES) / sizeof(COLORES[0]);
  if (etapa >= cantidad) {
    return;
  }

  const unsigned long ahora = millis();
  if (ahora - cambioAnterior < 1000UL) {
    return;
  }
  cambioAnterior = ahora;
  ++etapa;

  if (etapa < cantidad) {
    pantalla.Fill_Screen(COLORES[etapa]);
  } else {
    mostrarPanelDePrueba();
  }
}
