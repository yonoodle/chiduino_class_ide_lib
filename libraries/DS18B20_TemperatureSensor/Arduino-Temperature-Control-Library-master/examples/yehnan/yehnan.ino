
// �פJ�{���w���Y�� 
#include <OneWire.h>
#include <DallasTemperature.h>

// Arduino�Ʀ�}��2����1-Wire�˸m
#define ONE_WIRE_BUS 2

// �B�ε{���w�إߪ���
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(115200);
  Serial.println("Temperature Sensor");
  // ��l�� 
  sensors.begin();
}

void loop(void)
{
  // �n�D�׬y�ƤW���Ҧ��P�����i��ū��ഫ�]���L�ڥu���@�ӡ^ 
  sensors.requestTemperatures();

  // ���o�ū�Ū�ơ]���^�ÿ�X�A
  // �Ѽ�0�N��׬y�ƤW��0��1-Wire�˸m 
  Serial.println(sensors.getTempCByIndex(0));

  delay(1000);
}

��X���G�p�U�A�i���DS18B20�������ūפW�ɡC
 

DallasTemperature�{���w���٦���L�\��i�ΡG

uint8_t getDeviceCount(void)�A�^��1-Wire�׬y�ƤW���h�֭Ӹ˸m�C

typedef uint8_t DeviceAddress[8]�A�˸m����}�C
bool getAddress(uint8_t*, const uint8_t)�A�^�ǬY�Ӹ˸m����}�C

uint8_t getResolution(uint8_t*)�A���o�Y�˸m���ū׸ѪR�ס]9~12 bits�A���O���� 0.5�XC�B0.25�XC�B0.125�XC�B0.0625�XC�^�A�ѼƬ���}�C
bool setResolution(uint8_t*, uint8_t)�A�]�w�Y�˸m���ū׸ѪR�סC

bool requestTemperaturesByAddress(uint8_t*)�A�R�O�Y�P�����i��ū��ഫ�A�ѼƬ���}�C
bool requestTemperaturesByIndex(uint8_t)�A�P�W�A�ѼƬ����ޭȡC

float getTempC(uint8_t*)�A���o�ū�Ū�ơA�ѼƬ���}�C
float getTempCByIndex(uint8_t)�A���o�ū�Ū�ơA�ѼƬ����ޭȡC

�t������R�A�����禡�i�@���ؤ��ഫ�C 
static float toFahrenheit(const float)
static float toCelsius(const float)