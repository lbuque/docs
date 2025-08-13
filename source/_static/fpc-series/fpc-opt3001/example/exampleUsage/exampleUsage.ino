#include <Wire.h>

#define I2C_SDA 8
#define I2C_SCL 10

#define OPT3001_ADDRESS 0x44  // OPT3001 的 I2C 地址，根据 ADDR 引脚连接 GND
// #define OPT3001_ADDRESS 0x45    //  OPT3001 的 I2C 地址，根据 ADDR 引脚连接 VCC

// 配置寄存器值：自动量程、连续转换模式
#define OPT3001_CONFIG 0xCE10

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA,I2C_SCL,100000);     // SDA SCL frequency
  // 配置 OPT3001
  Wire.beginTransmission(OPT3001_ADDRESS);
  Wire.write(0x01);  // 寄存器地址：配置寄存器
  Wire.write(OPT3001_CONFIG >> 8);  // 高字节
  Wire.write(OPT3001_CONFIG & 0xFF);  // 低字节
  Wire.endTransmission();
}

void loop() {
  float lux = readLux();
  Serial.print("光照强度: ");
  Serial.print(lux);
  Serial.println(" lx");

  delay(1000);  // 每秒读取一次
}

float readLux() {
  uint16_t result;

  // 读取结果寄存器
  Wire.beginTransmission(OPT3001_ADDRESS);
  Wire.write(0x00);  // 寄存器地址：结果寄存器
  Wire.endTransmission();

  Wire.requestFrom(OPT3001_ADDRESS, 2);  // 读取 2 字节
  if (Wire.available() == 2) {
    uint8_t high = Wire.read();
    uint8_t low = Wire.read();
    result = (high << 8) | low;
  }

  // 计算光照强度
  uint8_t exponent = (result >> 12) & 0x0F;  // 指数部分
  uint16_t mantissa = result & 0x0FFF;      // 尾数部分
  float lux = 0.01 * pow(2, exponent) * mantissa;
  return lux;
}