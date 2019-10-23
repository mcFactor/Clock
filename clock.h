String fw="2.1";
String vers="BIM v"+fw;
int rssi=0;
File fsUploadFile;
byte packetBuffer[48];
unsigned long UnixTimestamp=0;
char ssid[32]="";
char password[32]="";
char text_buf[255]="";
String httpData="";
bool ds3231Detected=false;
bool bme1Detected=false;
bool bme2Detected=false;
bool shtDetected=false;
uint8_t dsDetected=0;
int sec=0;
float temp=0;
float hum=0;
float pres=0;
bool showTime=true;
bool tempS;
bool humS;
bool presS;
int8_t TimeDisp[6]={0,0,0,0,0,0};
int8_t DispPoint[6]={0,0,0,0,0,0};
bool clockPoint=true;
bool upd=true;
uint16_t oc=0;
int32_t ntt=20;
uint8_t tmupd=0;
time_t lastsync=2100000000;
bool ntpsync=false;
uint8_t w_err=0;
bool net_connected=false;
bool sens_upd=true;

struct{
  uint8_t num=0;
  String ssid[10];
  String pass[10];
} ssids;

struct config_structure{
  char        ap_ssid[32]="Clock";
  char        ap_pass[32]="1234567890";
  String      ap_ip="192.168.4.1";
  String      ap_mask="255.255.255.0";
  int         chnl=1;
  int         hide=0;
  int8_t      zone=0;
  uint8_t     adj=0;
  uint8_t     lang=0;
  uint8_t     timef=0;
  int         bright=0;
  int         bright_n=0;
  int         typ=0;
  String      ip="";
  String      mask="";
  String      gateway="";
  String      dns1="";
  String      dns2="";
  int         temp=0;
  int         hum=0;
  int         pres=0;
  float       t_cor=0;
  float       h_cor=0;
  float       p_cor=0;
  bool        ti_units=false;
  uint8_t     pi_units=0;
  String      mdns="clock";
  int         fh=0;
  int         fm=0;
  int         th=0;
  int         tm=0;
  int         every=0;
  int         duration=0;
  String      ntp="time.windows.com";
  uint8_t     os=0;
  String      out_mac="";
  String      chid="";
  int         disp=1;
  uint32_t    ntp_period;
};
config_structure config;

struct{
  float       temp=0;
  float       pres=0;
  float       humidity=0;
  float       tempi=0;
  float       presi=0;
  float       humidityi=0;
  float       tempe=0;
} outside;

void half(void);
void getNTPtime(void);
void display_temp(float t);
void display_hum(float h);
void display_pres(int p);
void display_time(uint8_t hr,uint8_t mn,uint8_t sc);
void out(void);
void read_eeprom(void);
void is_settings(void);
void connectToWiFi(void);
int viewRSSI(String s);
boolean summertime(void);
void sensors_init(void);
bool get_temp(void);
bool get_humidity(void);
bool get_pres(void);
String getContentType(String filename);
bool handleFileRead(String path);
bool FileRead(String path);
void handleFileUpload(void);
void web_settings(void);
