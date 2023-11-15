#include "map.h"
#include "config.h"

Map::Map()
{
    // 加载地图对象
     m_map1.load(MAP_PATH);
     m_map2.load(MAP_PATH);

     // 设置地图起始y坐标
     // 窗口是(0.0)点，第一张图在上面，所以y轴的坐标是-GAME_HEIGHT
     m_map1_posY = -GAME_HEIGHT;
     m_map2_posY = 0;

     // 设置地图滚动速度
     m_scroll_speed = MAP_SCROLL_SPEED;
}

// 地图滚动坐标计算
void Map::mapPosition()
{
    // 处理第一张地图滚动
    // 此时第一张图已经在界面中，重置
    m_map1_posY += m_scroll_speed;
    if (m_map1_posY >= 0) {
        m_map1_posY = -GAME_HEIGHT;
    }

    // 处理第二张地图滚动
    m_map2_posY += m_scroll_speed;
    if (m_map2_posY > GAME_HEIGHT) {
        m_map2_posY = 0;
    }
}
