#ifndef TC_MESSAGE_LIBRARY_H
#define TC_MESSAGE_LIBRARY_H

#include <string>
#include <memory>
#include <cstdint>

namespace tc
{

    class Message;

    class ProtoMessageMaker {
    public:

        static std::string MakeGamepadState(int32_t buttons, int32_t left_trigger, int32_t right_trigger, int32_t thumb_lx, int32_t thumb_ly,
                                            int32_t thumb_rx, int32_t thumb_ry, const std::string& device_id, const std::string& stream_id);

        // only used for Android Touch
        static std::string MakeMouseEventFromTouch(int32_t event, const std::string& mon_name, float x_ratio, float y_ratio, const std::string& device_id,
                                                   const std::string& stream_id);

        // file trans begin
        static std::shared_ptr<Message> MakeGetFileListMsg(const std::string& path);


        // file trans end
    };

}

#endif //TC_MESSAGE_LIBRARY_H
