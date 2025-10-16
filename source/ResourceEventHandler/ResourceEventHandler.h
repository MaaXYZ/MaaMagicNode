#pragma once

#include <string>

#include <MaaFramework/MaaAPI.h>
#include <meojson/json.hpp>

#include "Utils/SingletonHolder.hpp"

class ResourceEventHandler : public SingletonHolder<ResourceEventHandler>
{
public:
    void on_event(MaaResource* res, std::string_view message, const json::value& details);

private:
    struct LoadingDetails
    {
        MaaId res_id = MaaInvalidId;
        std::string path;
        std::string hash;
    };

    void on_loading_starting(MaaResource* res, const json::value& details);
    void on_loading_succeeded(MaaResource* res, const json::value& details);
    void on_loading_failed(MaaResource* res, const json::value& details);
};
