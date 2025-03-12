# Proje Konusu

Bu proje, evlerdeki güvenliği artırmak amacıyla bir hareket algılama güvenlik sistemi tasarlamayı hedeflemektedir. Sistem, evdeki olası hırsızlık durumlarını tespit edebilmek için bir hareket algılama sensörü (PIR sensörü) kullanacak ve bu hareket algılandığında kullanıcılara Telegram üzerinden anlık bildirim gönderecektir. Raspberry Pi Pico W, sistemin ana kontrol birimi olarak kullanılacaktır.

# Proje Hedefleri

Projenin temel amacı, kullanıcıları evlerinde veya işyeri ortamlarında hareket algılandığında anında bilgilendirerek güvenlik seviyesini artırmaktır.

## Proje Amaçları:

  - Raspberry Pi Pico W ve PIR sensörünü kullanarak hareket algılama sistemi kurmak.
  - Telegram API ile entegre edilen bir bot oluşturmak.
  - Telegram botu üzerinden hareketin algılanması sonucu mesaj göndermek.

## Başarı Kriterleri:

  - PIR sensörünün doğru şekilde hareket algılayabilmesi.
  - Telegram botunun, hareket algılandığında hızlı ve doğru bir şekilde mesaj gönderebilmesi.
  - Sistemin güvenilir çalışması (donanım ve yazılım).

# Tahmini Zaman Çizelgesi
 -
Hafta | 1 | 2 - 3 | 4 - 5 | 6 - 7 | 8 - 9 | 10 | 11 - 12 
--- | --- | --- |--- |--- |--- |--- |--- |---
Gorev | Araştırma ve Planlama | Raspberry Pi Pico W ve PIR sensörü kurulumu ve test edilmesi | PIR sensör entegrasyonu | Telegram Botu geliştirme | Sistemin testleri ve hata ayıklama | Test ve final kontrolü | Raporlama ve doküman hazırlama | Son testler ve proje teslimi

# Kaynak Planlaması

Proje ekibi 4 kişiden oluşmaktadır:
•	Serdar Ayvalı: Raspberry Pi Pico W kurulumu ve Telegram botu entegrasyonu
•	Ramazan Aslan: Raspberry Pi Pico W kurulumu ve Telegram botu entegrasyonu
•	Ezgi Aydın: Raporlama, doküman hazırlama ve test senaryolarını gerçekleştirme
•	Ebrar Begüm Şipal: Raporlama, doküman hazırlama ve test senaryolarını gerçekleştirme


## Kaynak Planlaması
Ekipmanlar:
  - 1 x Raspberry Pi Pico W
  - 1 x PIR sensörü
  - 1 x Telegram bot için bir Telegram hesabı
  - Gerekli kablolar ve bağlantı elemanları
  - Bilgisayar ve internet bağlantısı

Yazılımlar:
  - Arduino IDE
  - Telegram Bot API
  - Git

Proje Maliyeti:
  - Raspberry Pi Pico W: 200 TL
  - PIR Sensörü: 50 TL
  - Diğer malzemeler (kablolar, breadboard vs.): 50 TL

Toplam Maliyet (Yaklaşık): 300 TL


# Risk Analizi

Potansiyel Sorunlar ve Çözüm Önerileri:

 - Yanlış Alarm Oranı Yüksekliği: PIR sensörlerinin yanlış tetiklenmesi, gereksiz bildirimlere yol açabilir. Bu sorunun önüne geçmek için sensörlerin hassasiyet ayarlarının doğru yapılandırılması ve çevresel etkenlerin (örneğin evcil hayvan hareketleri) göz önünde bulundurulması gerekmektedir.
   
- Telegram Bildirimlerinde Gecikme: Sistem, kullanıcılara anında bildirim göndermeyi amaçlamaktadır. Ancak ağ trafiği, Telegram API’sindeki yoğunluk veya internet bağlantısındaki kesintiler nedeniyle bildirimlerde gecikme yaşanabilir. Bu riski azaltmak için sistemde yerel bir uyarı mekanizması veya alternatif bildirim yöntemleri (SMS veya e-posta) eklenebilir.
Raspberry Pi Pico W'nin Yetersiz Kalması: Sistemin işlem kapasitesinin yetersiz olması, veri işleme ve bildirimlerin gecikmesine neden olabilir. Bunu önlemek için Raspberry Pi’nin işlem yükü düzenlenmeli ve gerektiğinde daha güçlü donanım seçenekleri değerlendirilmelidir.

- Wi-Fi Kesintileri: Sistem tamamen internet bağlantısına dayandığı için Wi-Fi kesintileri, bildirimlerin ulaşmamasına neden olabilir. Bunu önlemek amacıyla alternatif bağlantı yöntemleri (örneğin GSM modülü ile yedekleme) değerlendirilebilir veya sistem, bağlantı geri geldiğinde bildirimleri tekrar gönderecek şekilde tasarlanmalıdır.


# Ticari Potansiyel

Bu proje, özellikle güvenlik sistemleri ve akıllı ev uygulamaları gibi alanlarda ticari olarak kullanılabilir. Ayrıca, ev ve işyeri güvenliğini artırmaya yönelik bu tür sistemler, geniş bir kullanıcı kitlesine hitap edebilir. Ticari kullanım alanları şunlar olabilir:

  - Ev güvenlik sistemleri: Hareket algılandığında ev sahiplerine anında bildirim gönderme.
  - İş yerleri ve ofisler: Güvenlik sağlama amacıyla kullanılan benzer uygulamalar.
  - Akıllı ev çözümleri: Farklı sensörlerle entegre edilebilen sistemler.
