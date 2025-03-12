# Hareket Algılayıcılı Güvenlik Sistemi

## Proje Konusu ve Amacı
 Bu proje, evlerdeki güvenliği artırmak amacıyla bir hareket algılama güvenlik sistemi
tasarlamayı hedeflemektedir. Sistem, evdeki olası hırsızlık durumlarını tespit edebilmek için
bir hareket algılama sensörü (PIR sensörü) kullanacak ve bu hareket algılandığında
kullanıcılara Telegram üzerinden anlık bildirim gönderecektir. Raspberry Pi Pico W, sistemin
ana kontrol birimi olarak kullanılacaktır.

## Proje Gereksinimleri
- Raspberry Pi Pico W
- PIR sensörü
- İletken Teller
  
## Projeyi Çalıştırma
Bu proje, Raspberry Pi Pico W mikrodenetleyicisi kullanılarak geliştirilen, hareket algılama tabanlı bir güvenlik sistemi sunar. Sistem, PIR (Passive Infrared) sensörü aracılığıyla çevredeki hareketleri algılar ve bu veriyi dijital sinyal olarak Raspberry Pi Pico W'ye iletir. Raspberry Pi Pico W, Wi-Fi modülü sayesinde bu sinyali işleyip bir Telegram botu aracılığıyla kullanıcılara anlık bildirim gönderir.
  
  Sistem akışı şu şekildedir:
- Hareket Algılama: PIR sensörü, hareket algıladığında bir dijital sinyal üretir.
- Veri İşleme: Bu sinyal, Raspberry Pi Pico W tarafından okunur ve hareketin varlığı tespit edilir.
- Bildirim Gönderimi: Tespit edilen hareket bilgisi, Telegram Bot API kullanılarak kullanıcılara anlık mesaj olarak iletilir.
- Hata Kontrolü: Yanlış alarmları önlemek için belirli bir süre içinde sürekli hareket kontrolü yapılır.

## Proje Lisans Bilgileri
Apache 2.0
  
 ## Proje Anahtar Kelimeleri
- IoT (Nesnelerin İnterneti)
- Hareket Algılama
- Güvenlik Sistemi
- Raspberry Pi Pico W
- PIR Sensör
- Telegram Bot
- Anlık Bildirim
- Ev Güvenliği
- Wi-Fi İletişimi
- Otomasyon
- Akıllı Ev Sistemleri
- Sensör Tabanlı Algılama
- Düşük Güç Tüketim
