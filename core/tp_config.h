
#include <iostream>
#include <vector>
#include <map>

#include "generic_config.h"


#define TP_CONFIG_DEM_FILE "dem_file"
#define TP_CONFIG_IMA_OUT_PATH "image_out_path"
#define TP_CONFIG_B_LAYER "begin_layer"
#define TP_CONFIG_E_LAYER "end_layer"
#define TP_CONFIG_I_WIDTH "image_width"
#define TP_CONFIG_I_HEITH "image_height"
#define TP_CONFIG_PYRAMID "pyramid"
#define TP_CONFIG_RANDER "rander"
#define TP_CONFIG_VALUE "value"
#define TP_CONFIG_R "r"
#define TP_CONFIG_G "g"
#define TP_CONFIG_B "b"
#define TP_CONFIG_TOP_ALPHA "top_alpha"
#define TP_CONFIG_TIF_WIDTH "tif_width"
#define TP_CONFIG_TIF_HEIGHT "tif_height"
#define TP_CONFIG_PROJ "proj_db_path"

struct pyramid_config
{
    int begin_layer;   // 开始层
    int end_layer;     // 结束层
    int image_width;   // 生成图片宽度
    int image_height;  // 生成图片高度
};
struct evel_color
{
    double value;
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

typedef std::vector<evel_color> rander_config;


class Config : public generic_config<Config>
{
  public:
    bool load(const std::string& file);

    Config() = default;
    ~Config() = default;



    std::string dem_file;
    float top_alpha;
    int tif_width;

    pyramid_config pyramid;
    rander_config rander;

  private:
};


