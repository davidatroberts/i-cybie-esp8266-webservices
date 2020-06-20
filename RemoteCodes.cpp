#include "RemoteCodes.h"

#include <Arduino.h>

namespace
{
    void sendCode(IRsend &irsend, const uint16_t raw_value[][31] )
    {
        irsend.sendRaw(raw_value[0], 31, 38);
        delay(100);
        irsend.sendRaw(raw_value[1], 31, 38);
        delay(100);
        irsend.sendRaw(raw_value[2], 31, 38);
    }
}

namespace remote_codes
{
    void sendKeyCode(IRsend &irsend, const KeyCode &code)
    {
        switch (code)
        {
        case KeyCode::button_1:
            sendCode(irsend, key_1_code);
            break;
        case KeyCode::button_2:
            sendCode(irsend, key_2_code);
            break;
        case KeyCode::button_3:
            sendCode(irsend, key_3_code);
            break;
        case KeyCode::button_4:
            sendCode(irsend, key_4_code);
            break;
        case KeyCode::button_5:
            sendCode(irsend, key_5_code);
            break;
        case KeyCode::button_6:
            sendCode(irsend, key_6_code);
            break;
        case KeyCode::button_7:
            sendCode(irsend, key_7_code);
            break;
        case KeyCode::button_8:
            sendCode(irsend, key_8_code);
            break;
        case KeyCode::button_9:
            sendCode(irsend, key_9_code);
            break;
        case KeyCode::button_10:
            sendCode(irsend, key_10_code);
            break;
        case KeyCode::button_11:
            sendCode(irsend, key_11_code);
            break;
        case KeyCode::button_12:
            sendCode(irsend, key_12_code);
            break;
        case KeyCode::button_big:
            sendCode(irsend, key_big_code);
            break;
        case KeyCode::button_small:
            sendCode(irsend, key_small_code);
            break;
        default:
            break;
        }
    }
}