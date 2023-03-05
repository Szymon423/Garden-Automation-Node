#include "hardware.h"

void defineIO()
{
  pinMode(LED_in_1, OUTPUT);
  pinMode(LED_in_2, OUTPUT);
  pinMode(LED_out_1, OUTPUT);
  pinMode(LED_out_2, OUTPUT);
  pinMode(LED_info_1, OUTPUT);
  pinMode(LED_info_2, OUTPUT);

  pinMode(output_1, OUTPUT);
  pinMode(output_2, OUTPUT);

  pinMode(input_1, INPUT);
  pinMode(input_2, INPUT);
}


void setOutput(int outputNo, bool state)
{
    int outputPins[2] = {output_1, output_2};
    int outputLEDs[2] = {LED_out_1, LED_out_2};

    digitalWrite(outputPins[outputNo - 1], state);
    digitalWrite(outputLEDs[outputNo - 1], state);
}