
// 匯入程式庫標頭檔 
#include <OneWire.h>
#include <DallasTemperature.h>

// Arduino數位腳位2接到1-Wire裝置
#define ONE_WIRE_BUS 2

// 運用程式庫建立物件
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(115200);
  Serial.println("Temperature Sensor");
  // 初始化 
  sensors.begin();
}

void loop(void)
{
  // 要求匯流排上的所有感測器進行溫度轉換（不過我只有一個） 
  sensors.requestTemperatures();

  // 取得溫度讀數（攝氏）並輸出，
  // 參數0代表匯流排上第0個1-Wire裝置 
  Serial.println(sensors.getTempCByIndex(0));

  delay(1000);
}

輸出結果如下，可對著DS18B20呵氣讓溫度上升。
 

DallasTemperature程式庫裡還有其他功能可用：

uint8_t getDeviceCount(void)，回傳1-Wire匯流排上有多少個裝置。

typedef uint8_t DeviceAddress[8]，裝置的位址。
bool getAddress(uint8_t*, const uint8_t)，回傳某個裝置的位址。

uint8_t getResolution(uint8_t*)，取得某裝置的溫度解析度（9~12 bits，分別對應 0.5°C、0.25°C、0.125°C、0.0625°C），參數為位址。
bool setResolution(uint8_t*, uint8_t)，設定某裝置的溫度解析度。

bool requestTemperaturesByAddress(uint8_t*)，命令某感測器進行溫度轉換，參數為位址。
bool requestTemperaturesByIndex(uint8_t)，同上，參數為索引值。

float getTempC(uint8_t*)，取得溫度讀數，參數為位址。
float getTempCByIndex(uint8_t)，取得溫度讀數，參數為索引值。

另有兩個靜態成員函式可作攝氏華氏轉換。 
static float toFahrenheit(const float)
static float toCelsius(const float)