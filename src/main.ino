#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>  // https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>           // https://github.com/bblanchon/ArduinoJson


#define SSID "wifi_adi"
#define PASSWORD "sifre123"

#define CHAT_ID "chat_id" // private chat

#define BOT_TOKEN "bot_token"

typedef struct {
    pin_size_t pin;
    const char* name;
    bool sent_message;
} pir_sensor;

pir_sensor ps[] = {
    { .pin = 20, .name = "Mutfak" },
    { .pin = 19, .name = "Garaj" },
    { .pin = 18, .name = "Koridor" },
};
size_t ps_count = sizeof ps / sizeof ps[0];

#define KILL_SWITCH 21

#define BUF_SIZE 256
char buf[BUF_SIZE] = { 0 };
#define BUF_TIME_SIZE 16
char buf_time[BUF_TIME_SIZE] = { 0 };

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

void led_blink(int amount) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(amount);
    digitalWrite(LED_BUILTIN, LOW);
}

void setup(void) {
    pinMode(KILL_SWITCH, INPUT);

    for (size_t i = 0; i < ps_count; i++) {
        pinMode(ps[i].pin, INPUT_PULLDOWN);
    }

    pinMode(LED_BUILTIN, OUTPUT);

    led_blink(200);

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);
    client.setTrustAnchors(&cert);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    led_blink(200);

    configTime(0, 0, "0.tr.pool.ntp.org", "pool.ntp.org");
    time_t now = time(nullptr);
    while (now < 24 * 60 * 60) {
        delay(100);
        now = time(nullptr);
    }

    led_blink(200);

    struct tm* t = localtime(&now);
    strftime(buf, BUF_SIZE, "[%H:%M:%S] Bot: Baslatildi.", t);
    bot.sendMessage(CHAT_ID, buf);
    digitalWrite(LED_BUILTIN, HIGH);
}

bool currently_working = true;
bool flipped = false;
bool led_flip = false;

void loop(void) {
    delay(1000);

    time_t t = time(nullptr);
    struct tm* tm = localtime(&t);
    strftime(buf_time, BUF_TIME_SIZE, "%H:%M:%S", tm);

    bool flip = digitalRead(KILL_SWITCH);

    if (flip == HIGH && flipped == false) {
        flipped = true;

        currently_working = !currently_working;
        if (currently_working) {
            digitalWrite(LED_BUILTIN, HIGH);
            snprintf(buf, BUF_SIZE, "[%s] Bot: Baslatildi.", buf_time);
            bot.sendMessage(CHAT_ID, buf);
        } else {
            led_flip = true;
            snprintf(buf, BUF_SIZE, "[%s] Bot: Durduruldu.", buf_time);
            bot.sendMessage(CHAT_ID, buf);
        }
    }

    if (flip == LOW) flipped = false;
    if (currently_working == false) {
        led_flip = !led_flip;
        digitalWrite(LED_BUILTIN, led_flip);
        return;
    }

    for (size_t i = 0; i < ps_count; i++) {
        PinStatus res = digitalRead(ps[i].pin);
        if (res == HIGH && ps[i].sent_message == false) {
            ps[i].sent_message = true;
            snprintf(buf, BUF_SIZE, "[%s] %s: Hareket Tespit Edildi!", buf_time, ps[i].name);
            bot.sendMessage(CHAT_ID, buf);
        } else if (res == LOW) {
            ps[i].sent_message = false;
        }
    }
}
