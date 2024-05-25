#ifndef TC_MESSAGE_LIBRARY_H
#define TC_MESSAGE_LIBRARY_H

#include <string>
#include <cstdint>

namespace tc
{

    class ProtoMessageMaker {
    public:

        // deprecated
        static std::string MakeGamepadState(int32_t buttons, int32_t left_trigger, int32_t right_trigger, int32_t thumb_lx,
                                            int32_t thumb_ly, int32_t thumb_rx, int32_t thumb_ry);

        static std::string MakeGamepadButtonMessage(int32_t buttons);
        static std::string MakeGamepadTriggerMessage(bool left, int trigger_value);
        static std::string MakeGamepadThumbMessage(bool left, int thumb_x, int thumb_y);

    };

}

#endif //TC_MESSAGE_LIBRARY_H
