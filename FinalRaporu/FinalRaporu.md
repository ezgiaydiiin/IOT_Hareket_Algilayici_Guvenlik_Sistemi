# Final Proje Raporu: IoT Tabanlı Akıllı Güvenlik Sistemi

## Proje Konusu
Bu proje, evdeki üç farklı odanın güvenliğini sağlamak amacıyla, her birine yerleştirilen hareket sensörleriyle çalışan bir IoT tabanlı akıllı güvenlik sistemi geliştirmeyi hedeflemektedir. Sistem, hareket algılandığında kullanıcıya anında Telegram üzerinden bildirim gönderir. Geliştirilen ürün sonucunda kişi, evde yokken evde hangi odada hareket tespit edildiği bilgisine sahip olur.

## Özet
Bu proje, Raspberry Pi Pico W ve üç adet PIR hareket sensörü kullanılarak geliştirilmiş bir IoT tabanlı güvenlik sistemidir. Sistemde her sensör farklı bir odayı temsil eder ve odalarda hareket algılandığında, sistem Telegram botu aracılığıyla kullanıcısına, hareketin tespit edildiği oda bilgisiyle birlikte bildirim gönderir. Proje boyunca çeşitli eklemeler yapılmıştır: kill switch, buzz (sesli uyarı), oda prototipi, ev modeli, kullanıcı testi ve Telegram bot entegrasyonu gibi ek özellikler geliştirilmiştir. Ayrıca, kullanım senaryoları çıkarılmış ve sistemin kullanım kolaylığı üzerine testler yapılmıştır.

## Kullanılan Yöntemler

### Donanım
| Bileşen                  | Açıklama                                                                 |
|--------------------------|--------------------------------------------------------------------------|
| Raspberry Pi Pico W       | Wi-Fi destekli RP2040 mikrodenetleyici tabanlı geliştirme kartı          |
| 3x PIR Sensör (HC-SR501)  | Mutfak (GPIO 20), Garaj (GPIO 19), Koridor (GPIO 18) için hareket algılayıcı |
| Kill Switch (GPIO 21)     | Sistemin çalışmasını fiziksel olarak açma/kapama                       |
| Yerleşik LED              | Sistem durumunu kullanıcıya görsel olarak bildirir                       |
| Buzzer                   | Hareket algılandığında sesli uyarı verir                                 |

### Yazılım
| Bileşen                   | Açıklama                                                                 |
|---------------------------|--------------------------------------------------------------------------|
| Arduino C++ (Arduino-Pico Core) | Pico W ile uyumlu C++ kodlama altyapısı                                |
| UniversalTelegramBot       | Telegram API ile mesaj gönderimi                                         |
| ArduinoJson               | JSON veri formatı için kullanılan kütüphane                             |
| WiFiClientSecure / X509 sertifika | HTTPS üzerinden Telegram sunucusuyla güvenli bağlantı             |
| NTP üzerinden zaman senkronizasyonu | Mesajlara zaman damgası eklemek için                               |

## Metodoloji
Sistem her bir sensör için `pir_sensor()` fonksiyonuyla yapılandırılmıştır. Her sensör, `loop()` fonksiyonunda sürekli olarak izlenir ve hareket algılandığında yalnızca bir defaya mahsus olmak üzere Telegram’a bildirim gönderilir. Bu işlem, `send_message()` fonksiyonu ile gerçekleştirilir. Sensörler, `digitalRead()` komutu ile izlenir ve hareket tespit edildiğinde, Telegram botu üzerinden kullanıcılara zaman damgalı bildirimler iletilir.

## Yapılan Teknik Çalışmalar
Proje, Raspberry Pi Pico W kullanılarak üç PIR sensörle donatılmış bir güvenlik sistemi kurulumunu içerir. Mutfak, Garaj ve Koridor odaları için her sensör belirli GPIO pinlerine yerleştirilmiş ve bu odaların her birine özgü hareket algılandığında Telegram üzerinden bildirim gönderilmiştir. Ayrıca, **Kill Switch** (GPIO 21) eklenerek, sistemin manuel olarak kontrol edilmesi sağlanmıştır.

### Yeni Eklenen Özellikler:
1. **Buzz (Sesli Uyarı)**: Sisteme, hareket algılandığında odada bir buzzer sesi çıkararak kullanıcıyı hem görsel hem de işitsel olarak uyaran bir özellik eklenmiştir. Bu, kullanıcıya daha hızlı tepki verme imkanı sunar.
   
2. **Kill Switch**: Sistemin manuel olarak açılıp kapatılabilmesi için fiziksel bir kill switch entegre edilmiştir. Bu özellik, güvenlik amacıyla sistemin fiziksel olarak kontrol edilmesini sağlar ve kullanıcıya ekstra bir güvenlik katmanı ekler.

3. **Oda Prototipi ve Ev Modeli**: Gerçek bir ev ortamını simüle edebilmek amacıyla bir ev modeli tasarlanmış ve bu modelde üç farklı oda oluşturulmuştur. Her odaya bir PIR sensör yerleştirilmiştir, böylece sistem hangi odada hareket algılandığını doğru bir şekilde tespit edebilir. 

4. **Kullanıcı Testi ve Senaryoları**: Kullanıcı testi yapılmış ve çeşitli kullanım senaryoları çıkarılmıştır. Testler, sistemin kullanıcı dostu olup olmadığını değerlendirmek amacıyla gerçekleştirilmiş, kullanıcı geri bildirimleri alınmıştır. Senaryolar, sistemin gerçek dünya koşullarında nasıl çalıştığını simüle etmeyi amaçlamaktadır.

## PIR Sensörlerin Çalışma Prensibi
HC-SR501 PIR sensörleri, ortamda bulunan nesnelerin yaydığı kızılötesi ışını algılar ve bu sayede hareketi tespit eder. Çıkış olarak dijital bir sinyal (HIGH veya LOW) üretir. Raspberry Pi Pico W üzerindeki GPIO pinleri bu dijital sinyalleri okuyarak olayları tespit eder ve kullanıcıya bildirim gönderir.

## Güvenli Bağlantı
Telegram botu ile iletişim, HTTPS üzerinden güvenli bir şekilde sağlanmıştır. Bunun için `WiFiClientSecure` kütüphanesi ve X.509 sertifikası kullanılmıştır, böylece iletişim araya girme (MITM) saldırılarına karşı korunmuştur.

## Elde Edilen Teknik Sonuçlar
Sistem, her biri farklı bir odada yer alan PIR sensörler aracılığıyla hareket algıladığında, doğru oda bilgisini Telegram üzerinden kullanıcıya iletebilmiştir. Ayrıca, sistemde modüler bir yapı kullanılarak, ilerleyen aşamalarda ek sensörler ve odalar eklenerek sistemin genişletilmesi sağlanabilir.

## Karşılaşılan Sorunlar ve Çözümler
Başlangıç aşamasında Raspberry Pi Pico W kartında yaşanan donanımsal bir arıza nedeniyle sistemin çalışması kesintiye uğramıştır. Yapılan testler ve bağlantı kontrolleri sonucunda kartın zarar gördüğü belirlenmiş ve yenisi temin edilerek sistem tekrar kurulmuştur. Bu süreç, donanım testlerinin önemini ve dikkatli entegrasyonun gerekliliğini ortaya koymuştur.

## Proje Tamamlanması
Proje tamamen tamamlanmış ve mevcut sistem, üç PIR sensör ve Telegram botu ile sorunsuz bir şekilde çalışır hale getirilmiştir. Ek olarak, **Kill Switch**, **Buzz**, **Oda Prototipi**, **Ev Modeli** gibi ek özellikler başarıyla entegre edilmiştir. Kullanıcı testi tamamlanmış ve çıkarılan kullanım senaryoları doğrultusunda sistemin güvenliği ve kullanım kolaylığı sağlanmıştır.

## Sonuç
Bu proje, ev güvenliğini artırmayı hedefleyen etkili bir IoT çözümü sunmaktadır. Raspberry Pi Pico W ve PIR sensörleri kullanarak, çok odalı bir güvenlik sistemi tasarlanmış ve Telegram botu üzerinden kullanıcılara anlık bildirimler gönderilmiştir. Proje, hem yazılım hem de donanım tarafında sağladığı işlevsellikle güvenliğinizi artırmayı amaçlamaktadır. Sistem, tüm belirlenen gereksinimleri başarıyla karşılayarak tamamlanmış ve proje sonlandırılmıştır.
