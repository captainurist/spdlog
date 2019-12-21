// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once
#include <spdlog/cfg/text_loader.h>
#include <spdlog/details/os.h>

//
// Init levels from argv SPDLOG_LEVEL
// Example: my_program.exe "SPDLOG_LEVEL=trace"


namespace spdlog {
namespace cfg {
// search for SPDLOG_LEVEL= in the args and use it to init the levels
void init_from_argv(int args, char *argv[])
{
    const std::string spdlog_level_prefix = "SPDLOG_LEVEL=";
    for (int i = 1; i < args; i++)
    {
        std::string arg = argv[i];
        if (arg.find(spdlog_level_prefix) == 0)
        {
            auto cfg_string = arg.substr(spdlog_level_prefix.size());
            auto levels = text_loader::load_levels(cfg_string);
            spdlog::details::registry::instance().set_levels(levels);
        }
    }
}
} // namespace cfg
} // namespace spdlog