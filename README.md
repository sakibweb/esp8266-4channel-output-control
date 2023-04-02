# 4channel
## ESP8266 4channel output control
ESP8266 4 channel output control with wifi and physical switch work without internet.


## Hotspot & assign IP
```c
const char* ssid = "SmartHome";
const char* password = "password";

IPAddress apIP(192, 168, 4, 1);
```


## Destinations

```c
int led1Pin = 5;
int led2Pin = 4;
int led3Pin = 0;
int led4Pin = 2;
int led5Pin = 16;
int button1Pin = 14;
int button2Pin = 12;
int button3Pin = 13;
int button4Pin = 15;
```


## Switch
```c
int button1Pin = 14;
int button2Pin = 12;
int button3Pin = 13;
int button4Pin = 15;
```


## Signal Out
```c
int led1Pin = 5;
int led2Pin = 4;
int led3Pin = 0;
int led4Pin = 2;
```

## Pin Map
![image](https://user-images.githubusercontent.com/23399426/223462919-ab55a11b-597c-4c8e-b36f-f241d67a6128.png)

```sh
    +-----+-----+---------+------+---+---Pi 3B+-+---+------+---------+-----+-----+
    | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name | wPi | BCM |
    +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
    |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v    |     |     |
    |   0 |   8 |     D0  |  OUT | 0 |  3 || 4  |   |      | 5V    |     |     |
    |   1 |   9 |     D1  |  OUT | 0 |  5 || 6  |   |      | 0v    |     |     |
    |   2 |  10 |     D2  |  OUT | 0 |  7 || 8  |   | ALT5 | TxD   | 15  | 14  |
    |     |     |    0v   |      |   |  9 || 10 |   | ALT5 | RxD   | 16  | 15  |
    |   3 |   0 |     D3  |  OUT | 0 | 11 || 12 | 0 | OUT  | D6    | 1   | 18  |
    |   4 |   1 |     D4  |  OUT | 0 | 13 || 14 |   |      | 0v    |     |     |
    |     |     |   3.3v  |      |   | 15 || 16 | 0 | OUT  | D5    | 4   | 23  |
    |  17 |  28 |    D17  |  OUT | 0 | 19 || 20 |   |      | 0v    |     |     |
    |  27 |  30 |    D27  |  OUT | 0 | 21 || 22 |   |      | D25   | 5   | 24  |
    |  22 |  31 |    D22  |  OUT | 0 | 23 || 24 | 0 | OUT  | D23   | 6   | 25  |
    |     |     |    0v   |      |   | 25 || 26 | 0 | OUT  | D24   | 7   | 28  |
    |  10 |  12 |    D10  |  OUT | 0 | 29 || 30 |   |      | 0v    |     |     |
    |   9 |  13 |     D9  |  OUT | 0 | 31 || 32 | 0 | OUT  | D11   | 8   | 30  |
    |  11 |  14 |    D11  |  OUT | 0 | 33 || 34 |   |      | 0v    |     |     |
    |  12 |  15 |    D12  |  OUT | 0 | 35 || 36

```

## Output
```sh
----------SMART  HOME----------
--------Create By SAKIB--------
Enter SSID: SmartHome
Enter Password: password
Enter Url: http://192.168.4.1/
-------------------------------
```
![image](https://user-images.githubusercontent.com/23399426/223452619-b3e1160f-d85c-4211-832e-6b2fb46d9565.png)


## In Chrome (Phone)
![image](https://user-images.githubusercontent.com/23399426/223451439-b82d88cf-304a-480d-b7f3-c6bc576cdc2e.png)


## License
Open Source

**Create By [SAKIB](https://sakibweb.github.io).**
