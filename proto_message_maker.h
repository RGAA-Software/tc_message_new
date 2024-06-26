#ifndef TC_MESSAGE_LIBRARY_H
#define TC_MESSAGE_LIBRARY_H

#include <string>
#include <cstdint>

namespace tc
{

    class ProtoMessageMaker {
    public:

        static std::string MakeGamepadState(int32_t buttons, int32_t left_trigger, int32_t right_trigger, int32_t thumb_lx,
                                            int32_t thumb_ly, int32_t thumb_rx, int32_t thumb_ry);

        // only used for Android Touch
        static std::string MakeMouseEventFromTouch(int32_t event, uint32_t mon_idx, float x_ratio, float y_ratio);
    };

}

#endif //TC_MESSAGE_LIBRARY_H
