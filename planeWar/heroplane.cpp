#include "heroplane.h"
#include "config.h"

HeroPlane::HeroPlane()
{
    // 加载飞机资源
    m_plane.load(HERO_PATH);

    // 初始化飞机坐标
    m_x = GAME_WIDTH * 0.5 - m_plane.width() * 0.5;
    m_y = GAME_HEIGHT - m_plane.height();

    // 初始化矩形框
    m_rect.setWidth(m_plane.width());
    m_rect.setHeight(m_plane.height());
    m_rect.moveTo(m_x, m_y);

    //初始化发射间隔记录
    m_recorder = 0;
}

void HeroPlane::shoot()
{
    // 累加时间间隔记录变量
    m_recorder++;

    // 未达到发设置
    if (m_recorder < BULLET_INTERVAL) {
        return;
    }

    // 到达发射时间处理
    // 重置发射时间间隔记录
    m_recorder = 0;

    // 发射子弹
    for (int i = 0; i < BULLET_NUM; i++) {
        // 如果子弹是空闲的，则发射
        if (m_bullets[i].m_free == true) {
            // 修改状态
            m_bullets[i].m_free = false;
            // 设置子弹的坐标
            m_bullets[i].m_x = m_x + m_rect.width() * 0.5 - 10;
            m_bullets[i].m_y = m_y - 25;
            break;
        }
    }
}

// 设置飞机位置
void HeroPlane::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    m_rect.moveTo(m_x, m_y);
}
