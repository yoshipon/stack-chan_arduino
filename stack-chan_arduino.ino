#include <M5Core2.h>
#include <Avatar.h>
#include <ServoEasing.hpp>

#define SRV_PIN_PAN 19
#define SRV_PIN_TLT 27
#define SRV_OFFSET_PAN -5
#define SRV_OFFSET_TLT 0

m5avatar::Avatar avt;

ServoEasing srv_pan;
ServoEasing srv_tlt;
  
void setup() {
  M5.begin();
  avt.init();

  srv_pan.attach(SRV_PIN_PAN, 90 + SRV_OFFSET_PAN);
  srv_tlt.attach(SRV_PIN_TLT, 90 + SRV_OFFSET_TLT);
  
  srv_pan.setEasingType(EASE_QUADRATIC_IN_OUT);
  srv_tlt.setEasingType(EASE_QUADRATIC_IN_OUT);
  setSpeedForAllServos(60);
}

void loop() {
  M5.update();
  
  int target_pan = random(90-40, 90+40) + SRV_OFFSET_PAN;
  int target_tlt = random(90-20, 90+ 5) + SRV_OFFSET_TLT;

  srv_pan.startEaseTo(target_pan);
  srv_tlt.startEaseTo(target_tlt);

  synchronizeAllServosStartAndWaitForAllServosToStop();

  delay(3000 + 100 * random(70));
}
