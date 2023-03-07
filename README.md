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

**Create By [SAKIB](https://github.com/sakibweb).**
