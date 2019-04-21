#include <Arduino.h>

const int analogInPin = A1; // Пин для датчика MQ-2
const int ledPin = 13;      // Пин для светодиода
int sensorValue = 0;        // Переменная для сохранения значения, поступающего с датчика
int thresholdValue = 300;   // Пороговое значение для срабатывание датчика

void setup()
{
    Serial.begin(9600);          // Инициализация последовательного соединения и задание скорости передачи данных в бит/с(бод)
    pinMode(ledPin, OUTPUT);     // Установка режима работы пина светодиода на выход
    Serial.println("MQ-2 Test"); // Посылаем текст в монитор порта, чтобы следить за выполнением программы
}

void loop()
{
    sensorValue = analogRead(analogInPin); // Считывание значения с датчика
    if (sensorValue >= thresholdValue)     // При превышение порогового значения - загорается светодиод
    {
        digitalWrite(ledPin, HIGH); // Включение светодиода
    }
    else
    {
        digitalWrite(ledPin, LOW); // Выключение светодиода
    }
    // Транслирование, отслеживаемых значений, в монитор порта
    Serial.print("MQ2 value = ");
    Serial.println(sensorValue);
    delay(1000); // Задержка 1с
}