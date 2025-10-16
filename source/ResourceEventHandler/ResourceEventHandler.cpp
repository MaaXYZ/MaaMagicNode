#include "ResourceEventHandler.h"

#include <functional>
#include <unordered_map>

#include "MaaFramework/MaaMsg.h"

void ResourceEventHandler::on_event(MaaResource* res, std::string_view message, const json::value& details)
{
    using HandlerT = void (ResourceEventHandler::*)(MaaResource*, const json::value&);
    static const std::unordered_map<std::string_view, HandlerT> kHandlerMapping {
        { MaaMsg_Resource_Loading_Starting, &ResourceEventHandler::on_loading_starting },
        { MaaMsg_Resource_Loading_Succeeded, &ResourceEventHandler::on_loading_succeeded },
        { MaaMsg_Resource_Loading_Failed, &ResourceEventHandler::on_loading_failed },
    };

    auto it = kHandlerMapping.find(message);
    if (it != kHandlerMapping.cend()) {
        return;
    }

    (this->*(it->second))(res, details);
}

void ResourceEventHandler::on_loading_starting(MaaResource* res, const json::value& details)
{
    std::ignore = res;
    std::ignore = details;
}

void ResourceEventHandler::on_loading_succeeded(MaaResource* res, const json::value& details)
{
    MaaStringListBuffer* list_buffer = MaaStringListBufferCreate();
    MaaResourceGetNodeList(res, list_buffer);
    for (size_t i = 0; i < MaaStringListBufferSize(list_buffer); ++i) {
        std::string_view node = MaaStringBufferGet(MaaStringListBufferAt(list_buffer, i));

        MaaStringBuffer* node_buffer = MaaStringBufferCreate();
        MaaResourceGetNodeData(res, node.data(), node_buffer);

        std::string_view node_data = MaaStringBufferGet(node_buffer);
        auto jnode_opt = json::parse(node_data);
        if (!jnode_opt) {
            continue;
        }
        //json::value& jnode_data = *jnode_opt;

        MaaStringBufferDestroy(node_buffer);
    }

    MaaStringListBufferDestroy(list_buffer);
}

void ResourceEventHandler::on_loading_failed(MaaResource* res, const json::value& details)
{
    std::ignore = res;
    std::ignore = details;
}
