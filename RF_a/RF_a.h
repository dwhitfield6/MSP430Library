#define trans_polarity
#define ONEshortCONF2 650
#define ONElongCONF2 1750
#define ZEROshortCONF2 650
#define ZEROlongCONF2 1750
#define SYNCsyncCONF2 12000
#define SYNCshortCONF2 650

unsigned char ArrayCompare(unsigned int*, unsigned int*, int, unsigned char);
void ArrayCopy(unsigned int*, unsigned int*, unsigned char);
void resetBuffer(unsigned int*, unsigned char);
void send_rf(unsigned char, unsigned char*);
void zero(unsigned char);
void one(unsigned char);
void send_rf_conf2(unsigned char, unsigned char*);
void zero_conf2(unsigned char);
void one_conf2(unsigned char);
void f(unsigned char);
unsigned char readSwitchP1(unsigned char);
unsigned char readSwitchP2(unsigned char);
void BlinkLED(unsigned char);
void Blink2LED(unsigned char, unsigned char);
void ArrayCopyChar(unsigned char* , unsigned char*, unsigned char );
unsigned char ArrayCompareChar(unsigned char* , unsigned char*, int amount, unsigned char characters);
void resetBufferChar(unsigned char* , unsigned char amount);
