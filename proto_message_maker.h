#ifndef TC_MESSAGE_LIBRARY_H
#define TC_MESSAGE_LIBRARY_H

#include <string>
#include <memory>
#include <cstdint>

namespace tc
{

    class Data;
    class Message;

    class ProtoMessageMaker {
    public:

        static std::shared_ptr<Data> MakeGamepadState(int32_t buttons, int32_t left_trigger, int32_t right_trigger, int32_t thumb_lx, int32_t thumb_ly,
                                            int32_t thumb_rx, int32_t thumb_ry, const std::string& device_id, const std::string& stream_id);

        // only used for Android Touch
        static std::shared_ptr<Data> MakeMouseEventFromTouch(int32_t event, const std::string& mon_name, float x_ratio, float y_ratio, const std::string& device_id,
                                                   const std::string& stream_id);

        // change monitor
        static std::shared_ptr<Data> MakeChangeMonitor(int index, const std::string& name, const std::string& device_id, const std::string& stream_id);

        // file trans begin
        static std::string s_file_conn_token_;
        static std::shared_ptr<Message> MakeGetFileListMsg(const std::string& path);


        // file trans end
    };

}

#endif //TC_MESSAGE_LIBRARY_H
