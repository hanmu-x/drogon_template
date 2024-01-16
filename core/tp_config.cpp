#include "tp_config.h"
#include <json/json.h>
#include <fstream>


bool Config::load(const std::string& file)
{
    bool status = false;
    std::fstream input;
    input.open(file, std::ios::binary | std::ios::in);
    if (input.is_open())
    {
        Json::Reader reader;
        Json::Value root;

        if (reader.parse(input, root))
        {
            dem_file = root[TP_CONFIG_DEM_FILE].asString();
            Json::Value pyramidJson = root[TP_CONFIG_PYRAMID];
            pyramid.begin_layer = pyramidJson[TP_CONFIG_B_LAYER].asInt();
            pyramid.end_layer = pyramidJson[TP_CONFIG_E_LAYER].asInt();
            pyramid.image_width = pyramidJson[TP_CONFIG_I_WIDTH].asInt();
            pyramid.image_height = pyramidJson[TP_CONFIG_I_HEITH].asInt();

            top_alpha = root[TP_CONFIG_TOP_ALPHA].asFloat();
            tif_width = root[TP_CONFIG_TIF_WIDTH].asInt();

            Json::Value randerJson = root[TP_CONFIG_RANDER];
            for (Json::ValueIterator it = randerJson.begin(); it != randerJson.end(); ++it)
            {
                evel_color color;
                color.value = (*it)[TP_CONFIG_VALUE].asDouble();
                color.r = (*it)[TP_CONFIG_R].asUInt();
                color.g = (*it)[TP_CONFIG_G].asUInt();
                color.b = (*it)[TP_CONFIG_B].asUInt();
                rander.push_back(color);
            }
        }
        status = true;
    }

    input.close();
    return status;
}
