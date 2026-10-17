# Potansiyometre ile Servo Kontrol (Arduino)

Arduino ile bir potansiyometreden okunan analog değeri gerçek zamanlı olarak servo motor açısına dönüştüren, temiz ve anlaşılır bir başlangıç projesi.

## 🎯 Proje Özeti

Bu projede:
- Potansiyometreden `0-1023` aralığında analog veri okunur.
- Bu değer `map()` fonksiyonu ile servo için `0-180` derece aralığına çevrilir.
- Servo motor anlık olarak yeni açıya götürülür.
- Seri Monitör üzerinden açı değeri canlı olarak izlenir.

## 🧠 Kullanılan Mantık

1. `analogRead(A5)` ile potansiyometre değeri okunur.
2. `map(pot_deger, 0, 1023, 0, 180)` ile servo açısına dönüştürülür.
3. `sg90.write(servo_deger)` ile servo yeni konuma getirilir.
4. Seri porta `"Servo = X Degrees"` çıktısı yazdırılır.
5. `delay(15)` ile servo hareketi için kısa bekleme uygulanır.

## 🧩 Donanım Gereksinimleri

- 1× Arduino (Uno/Nano/Mega)
- 1× SG90 veya benzeri servo motor
- 1× 10K potansiyometre
- Jumper kablolar
- (İsteğe bağlı) Harici 5V güç kaynağı (servo için daha stabil çalışma)

## 🔌 Bağlantı Şeması

### Potansiyometre
- Bir uç → `5V`
- Diğer uç → `GND`
- Orta pin (wiper) → `A5`

### Servo Motor
- Sinyal (turuncu/sarı) → `D13`
- VCC (kırmızı) → `5V`
- GND (kahverengi/siyah) → `GND`

> Not: Servo akımı yüksek olabilir. Kararsızlık görürseniz harici güç kullanın ve **GND hatlarını ortaklayın**.

## 📁 Proje Dosyaları

- `Potansiyometre_ile_servo_kontrol.ino` → Ana Arduino kodu
- `README.md` → Proje dokümantasyonu

## 🚀 Kurulum ve Çalıştırma

1. Arduino IDE’yi açın.
2. `Potansiyometre_ile_servo_kontrol.ino` dosyasını açın.
3. Doğru kart ve portu seçin.
4. Kodu karta yükleyin.
5. Seri Monitör’ü `9600 baud` ile açın.
6. Potansiyometreyi çevirerek servo hareketini ve açı çıktısını gözlemleyin.

## 💻 Arduino Kodu

```cpp
#include <Servo.h>
Servo sg90;
const byte potansiyometre = A5;
int pot_deger;

void setup()
{
  Serial.begin(9600);
  sg90.attach(13);
}

void loop()
{
  pot_deger = analogRead(potansiyometre);
  int servo_deger = map(pot_deger, 0, 1023, 0, 180);
  sg90.write(servo_deger);
  Serial.print("Servo = ");
  Serial.print(servo_deger);
  Serial.println(" Degrees");
  delay(15);
}
```

## ✅ Beklenen Çıktı

Seri Monitör’de aşağıdakine benzer satırlar görülür:

```text
Servo = 0 Degrees
Servo = 87 Degrees
Servo = 180 Degrees
```

## 🛠️ Olası İyileştirmeler

- Servo titremesini azaltmak için hareket yumuşatma (smoothing) eklenebilir.
- `D13` yerine farklı PWM uyumlu pinler denenebilir.
- Potansiyometre filtresi (moving average) uygulanabilir.
- Daha gelişmiş kontrol için butonlarla limit açı eklenebilir.

## 📜 Lisans

Bu proje eğitim ve geliştirme amaçlı serbestçe kullanılabilir.
