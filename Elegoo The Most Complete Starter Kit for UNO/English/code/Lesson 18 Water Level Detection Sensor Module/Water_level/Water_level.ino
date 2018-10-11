//www.elegoo.com
//2016.12.9

int adc_id = 0;
int HistoryValue = 0;
char printBuffer[128];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
    int value = analogRead(adc_id); // get adc value

    if(((HistoryValue>=value) && ((HistoryValue - value) > 10)) || ((HistoryValue<value) && ((value - HistoryValue) > 10)))
    {
      sprintf(printBuffer,"ADC%d level is %d\n",adc_id, value);
      Serial.print(printBuffer);
      HistoryValue = value;
    }
}
