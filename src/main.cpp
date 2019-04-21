#include <Arduino.h>

const int MQ2_pin = A10; // Пин для датчика MQ-2
const int ledPin = 2;      // Пин для светодиода
int MQ2_Value = 0;        // Переменная для сохранения значения, поступающего с датчика
int threshold_MQ2_Value = 300;   // Пороговое значение для срабатывание датчика

void setup()
{
    Serial.begin(9600);          // Инициализация последовательного соединения и задание скорости передачи данных в бит/с(бод)
    pinMode(ledPin, OUTPUT);     // Установка режима работы пина светодиода на выход
    Serial.println("MQ-2 Test"); // Посылаем текст в монитор порта, чтобы следить за выполнением программы
}

void loop()
{
    MQ2_Value = analogRead(MQ2_pin); // Считывание значения с датчика
    if (MQ2_Value >= threshold_MQ2_Value)     // При превышение порогового значения - загорается светодиод
    {
        digitalWrite(ledPin, HIGH); // Включение светодиода
    }
    else
    {
        digitalWrite(ledPin, LOW); // Выключение светодиода
    }
    // Транслирование, отслеживаемых значений, в монитор порта
    Serial.print("MQ2 value = ");
    Serial.println(MQ2_Value);
    delay(1000); // Задержка 1с
}