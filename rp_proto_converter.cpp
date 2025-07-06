//
// Created by RGAA on 6/07/2025.
//
#include "rp_proto_converter.h"
#include "tc_common_new/data.h"
#include "tc_render_panel_message.pb.h"

namespace tc
{

    std::shared_ptr<tc::Data> RpProtoAsData(std::shared_ptr<tcrp::RpMessage> msg) {
        return RpProtoAsData(msg.get());
    }

    std::shared_ptr<tc::Data> RpProtoAsData(tcrp::RpMessage* msg) {
        if (!msg) {
            return nullptr;
        }
        auto buffer = Data::Make(nullptr, msg->ByteSizeLong());
        if (auto ok = msg->SerializeToArray(buffer->DataAddr(), buffer->Size()); ok) {
            return buffer;
        }
        return nullptr;
    }

}