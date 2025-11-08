#include <IRremote.hpp>

const int irReceiverPin = 7;
decode_results results;

// code values by row
const long power_btn_code = 3125149440;
const long capture_btn_code = 3108437760;
const long mute_btn_code = 3091726080;

const long play_btn_code = 3141861120;
const long prev_btn_code = 3208707840;
const long next_btn_code = 3158572800;

const long eq_btn_code = 4161273600;
const long vol_down_btn_code = 3927310080;
const long vol_up_btn_code = 4127850240;

const long game_btn_code = 3860463360;
const long usb_scan_btn_code = 4061003520;
const long zero_btn_code = 3910598400;

const long one_btn_code = 4077715200;
const long two_btn_code = 3877175040;
const long three_btn_code = 2707357440;

const long four_btn_code = 4144561920;
const long five_btn_code = 3810328320;
const long six_btn_code = 2774204160;

const long seven_btn_code = 3175284480;
const long eight_btn_code = 2907897600;
const long nine_btn_code = 3041591040;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(irReceiverPin, ENABLE_LED_FEEDBACK);
}

void map_ir_code(long code)
{
  switch (code)
  {
  case power_btn_code:
    Serial.println("IRPowerButton");
    break;

  case capture_btn_code:
    Serial.println("IRCaptureButton");
    break;

  case mute_btn_code:
    Serial.println("IRMuteButton");
    break;

  case play_btn_code:
    Serial.println("IRPlayButton");
    break;

  case prev_btn_code:
    Serial.println("IRPrevButton");
    break;

  case next_btn_code:
    Serial.println("IRNextButton");
    break;

  case eq_btn_code:
    Serial.println("IREQButton");
    break;

  case vol_down_btn_code:
    Serial.println("IRVolDownButton");
    break;

  case vol_up_btn_code:
    Serial.println("IRVolUpButton");
    break;

  case zero_btn_code:
    Serial.println("Button_0");
    break;

  case game_btn_code:
    Serial.println("IRGameButton");
    break;

  case usb_scan_btn_code:
    Serial.println("IRUSBScanButton");
    break;

  case one_btn_code:
    Serial.println("Button_1");
    break;

  case two_btn_code:
    Serial.println("Button_2");
    break;

  case three_btn_code:
    Serial.println("Button_3");
    break;

  case four_btn_code:
    Serial.println("Button_4");
    break;

  case five_btn_code:
    Serial.println("Button_5");
    break;

  case six_btn_code:
    Serial.println("Button_6");
    break;

  case seven_btn_code:
    Serial.println("Button_7");
    break;

  case eight_btn_code:
    Serial.println("Button_8");
    break;

  case nine_btn_code:
    Serial.println("Button_9");
    break;

  default:
    break; // ignore unknown codes
  }
}

void loop()
{
  if (IrReceiver.decode())
  {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    map_ir_code(code);
    IrReceiver.resume(); // receive the next value
  }
  delay(600);
}
