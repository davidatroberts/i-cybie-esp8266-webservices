#if !defined(REMOTE_CODES_H)
#define REMOTE_CODES_H

#include <stdint.h>
#include <IRsend.h>

namespace remote_codes
{
    const uint16_t key_1_code[3][31] = {
        {1166, 3472,  1140, 3450,  1160, 3472,  1142, 3470,  1142, 3470,  1140, 3472,  1142, 3470,  1140, 3474,  3466, 1148,  1142, 3472,  3466, 1146,  1140, 3472,  1140, 3450,  1160, 3474,  1138, 3472,  1140}
    };
    const uint16_t key_2_code[3][31] = {
        {1166, 3470,  1142, 3470,  1170, 3442,  1142, 3470,  1170, 3442,  1170, 3442,  1164, 3428,  1164, 3470,  3496, 1118,  1142, 3470,  3472, 1144,  1170, 3444,  1168, 3444,  1168, 3446,  1168, 3444,  3470}
    };
    const uint16_t key_3_code[3][31] = {
        {1164, 3472,  1140, 3472,  1140, 3472,  1142, 3472,  1168, 3446,  1166, 3446,  1168, 3446,  1140, 3472,  3468, 1146,  1166, 3426,  3490, 1148,  1140, 3474,  1140, 3472,  1142, 3472,  3468, 1146,  1168}
    };
    const uint16_t key_4_code[3][31] = {
        {1188, 3448,  1164, 3428,  1162, 3474,  1166, 3448,  1168, 3448,  1168, 3446,  1168, 3446,  1140, 3474,  3494, 1122,  1164, 3450,  3470, 1146,  1142, 3474,  1168, 3448,  1168, 3446,  3494, 1122,  3470}
    };
    const uint16_t key_5_code[3][31] = {
        {1166, 3472,  1142, 3472,  1138, 3476,  1142, 3452,  1162, 3474,  1142, 3474,  1138, 3456,  1160, 3476,  3470, 1146,  1142, 3452,  3488, 1150,  1138, 3476,  1140, 3476,  3466, 1150,  1138, 3478,  1138}
    };
    const uint16_t key_6_code[3][31] = {
        {1164, 3476,  1142, 3472,  1142, 3474,  1138, 3476,  1144, 3472,  1138, 3476,  1144, 3472,  1140, 3476,  3468, 1148,  1140, 3476,  3468, 1150,  1142, 3472,  1142, 3476,  3472, 1146,  1140, 3476,  3472}
    };
    const uint16_t key_7_code[3][31] = {
        {1160, 3476,  1140, 3474,  1140, 3454,  1162, 3476,  1140, 3476,  1140, 3454,  1162, 3476,  1144, 3472,  3468, 1150,  1142, 3474,  3468, 1148,  1144, 3472,  1140, 3478,  3470, 1146,  3472, 1146,  1142}
    };
    const uint16_t key_8_code[3][31] = {
        {1162, 3476,  1144, 3474,  1142, 3472,  1142, 3474,  1142, 3474,  1142, 3476,  1166, 3446,  1142, 3474,  3498, 1098,  1160, 3478,  3472, 1144,  1144, 3474,  1172, 3446,  3498, 1120,  3472, 1146,  3474}
    };
    const uint16_t key_9_code[3][31] = {
        {1170, 3470,  1144, 3472,  1146, 3470,  1146, 3472,  1144, 3472,  1144, 3472,  1146, 3468,  1146, 3448,  3496, 1144,  1146, 3470,  3474, 1144,  1144, 3474,  3474, 1144,  1144, 3472,  1172, 3444,  1146}
    };
    const uint16_t key_10_code[3][31] = {
        {1162, 3478,  1138, 3456,  1160, 3456,  1160, 3476,  1138, 3478,  1142, 3474,  1144, 3450,  1162, 3476,  3468, 1128,  1160, 3456,  3490, 1150,  1142, 3474,  3472, 1146,  1142, 3474,  1144, 3474,  3468}
    };
    const uint16_t key_11_code[3][31] = {
        {1164, 3476,  1140, 3474,  1146, 3470,  1144, 3450,  1162, 3478,  1138, 3476,  1142, 3472,  1140, 3476,  3472, 1146,  1140, 3478,  3468, 1150,  1140, 3478,  3472, 1144,  1140, 3478,  3474, 1146,  1144}
    };
    const uint16_t key_12_code[3][31] = {
        {1170, 3468,  1170, 3446,  1170, 3446,  1144, 3452,  1190, 3424,  1166, 3470,  1170, 3446,  1146, 3472,  3472, 1146,  1142, 3474,  3472, 1146,  1144, 3472,  3474, 1144,  1144, 3472,  3498, 1120,  3474}
    };
    const uint16_t key_big_code[3][31] = {
        {1162, 3474,  1144, 3472,  1144, 3472,  1142, 3474,  1142, 3474,  1142, 3474,  1144, 3472,  1168, 3448,  3472, 1146,  1144, 3474,  3498, 1120,  1144, 3474,  3470, 1150,  3468, 1150,  1140, 3476,  3474}
    };
    const uint16_t key_small_code[3][31] = {
        {1166, 3472,  1170, 3446,  1144, 3472,  1142, 3472,  1170, 3446,  1170, 3446,  1170, 3446,  1170, 3446,  3472, 1146,  1166, 3450,  3498, 1120,  1142, 3474,  3496, 1122,  3496, 1122,  1168, 3450,  1142}
    };

    enum class KeyCode
    {
        button_1,
        button_2,
        button_3,
        button_4,
        button_5,
        button_6,
        button_7,
        button_8,
        button_9,
        button_10,
        button_11,
        button_12,
        button_big,
        button_small
    };

    void sendKeyCode(IRsend &irsend, const KeyCode &code);
}

#endif // REMOTE_CODES_H