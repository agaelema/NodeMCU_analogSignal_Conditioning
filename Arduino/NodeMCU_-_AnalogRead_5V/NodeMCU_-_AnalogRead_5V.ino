/*
 * Conditioning analog signal to NodeMCU
 * - Conditioning an analog signal bigger than 3.3v
 * using an active circuit with OpAmp LM358
 * the article about this code is available in:
 * http://
 * -------------------------------------------------
 * condicionando sinal analógico para NodeMCU
 * - condicionando um sinal analógico maior que 3.3v
 * utilizando um circuito ativo com o AmpOp LM358
 * o artigo sobre este código esta disponível em:
 * http://
 * 
 * developed by: Haroldo Amaral - agaelema@gmail.com
 * 2017/05/24 - v 1.0
 */

// some constants - algumas constantes
const unsigned int analogInPin = A0;    // Analog input - pino analógico
const float analogLimit = 3.3;          // Limit of Analog In. - Limite da entrada analogica
const float R1 = 46700 + 217000;        // Valores medidos - teóricos de 47k + 220k
const float R2 = 450000;                // valor medido - teórico de 470k

// used variables - variáveis utilizadas
unsigned int RAWanalogInput = 0;        // save the RAW value of A0 - armazena o valor RAW de A0
float analogInputVoltage = 0;           // save the converted A0 voltage - armazena a tensão convertida de A0
float Vusb = 0;                         // save the Vusb voltage - armazena a tensão Vusb

void setup()
{
  // setup the serial communication - configura a comunicacao serial
  Serial.begin(115200);
}

void loop()
{
  // read the analog input - le a entrada analogica
  RAWanalogInput = analogRead(analogInPin);

  // print RAW value - imprime o valor RAW
  Serial.print("RAW value: "); Serial.println(RAWanalogInput);

  // convert RAW value in voltage - converte o valor RAW em tensao
  analogInputVoltage = (float)RAWanalogInput * (analogLimit/1024);
  // print A0 voltage - imprime a tensao em A0
  Serial.print("ADC voltage: "); Serial.println(analogInputVoltage);

  // calculate the Vusb voltage - calcula a tensao Vusb
  Vusb = analogInputVoltage * (R1 + R2) / R2;
  // print Vusb voltage - imprime a tensao Vusb
  Serial.print("Vusb voltage: "); Serial.println(Vusb);
  
  delay(500);
}
