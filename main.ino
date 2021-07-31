#define LED_amount 6

void setup()
{

    for (uint8_t i = 2; i <= 2 + LED_amount - 1; i++)
    {
        pinMode(i, OUTPUT);
    }
    Serial.begin(9600);
}

volatile int Divisor = 1024 / LED_amount;

void loop()
{
    uint16_t ADC_Value = analogRead(PIN_A0);
    Serial.println(ADC_Value * 5.0 / 1024.0);
    uint8_t LED_level = ADC_Value / Divisor;

    for (uint8_t i = 2; i < 2 + LED_amount; i++)
    {
        digitalWrite(i, LOW);
    }
    for (uint8_t i = 2; i < 2 + LED_level; i++)
    {
        digitalWrite(i, HIGH);
    }
}
