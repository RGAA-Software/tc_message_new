#include "proto_message_maker.h"
#include "tc_message.pb.h"

namespace tc
{

    std::string ProtoMessageMaker::MakeGamepadState(int32_t buttons, int32_t left_trigger, int32_t right_trigger, int32_t thumb_lx,
                                                    int32_t thumb_ly, int32_t thumb_rx, int32_t thumb_ry) {
        tc::Message msg;
        msg.set_type(tc::MessageType::kGamepadState);
        auto gs = msg.mutable_gamepad_info();
        gs->set_buttons(buttons);
        gs->set_left_trigger(left_trigger);
        gs->set_right_trigger(right_trigger);
        gs->set_thumb_lx(thumb_lx);
        gs->set_thumb_ly(thumb_ly);
        gs->set_thumb_rx(thumb_rx);
        gs->set_thumb_ry(thumb_ry);
        return msg.SerializeAsString();
    }

}