#include "enemyplane.h"
#include "config.h"

EnemyPlane::EnemyPlane()
{
    // 加载敌机资源
    m_enemy.load(ENEMY_PATH);

    // 敌机位置
    m_x = 0;
    m_y = 0;



    // 敌机状态
    m_free = true;

    // 敌机速度
    m_speed = ENEMY_SPEED;

    // 敌机矩形
    m_rect.setWidth(m_enemy.width());
    m_rect.setHeight(m_enemy.height());
    m_rect.moveTo(m_x, m_y);

    // 初始化发射间隔记录
    m_recorder = 0;
}

// 更新敌机坐标
void EnemyPlane::updatePosition()
{
    // 空闲状态，不计算坐标
    if (m_free) {
        return;
    }

    // 敌机移动
    m_y += m_speed;
    m_rect.moveTo(m_x, m_y);

    // 越界检查
    if (m_y >= GAME_HEIGHT) {
        m_free = true;
    }
}

// 设置敌机位置
//void EnemyPlane::setPosition(int x, int y)
//{
//    m_x = x;
//    m_y = y;
//    m_rect.moveTo(m_x, m_y);
//}

// 敌机发射子弹
void EnemyPlane::shoot()
{
    // 累加时间间隔记录变量
    m_recorder++;

    // 未达到发设置
    if (m_recorder < ENEMY_BULLET_INTERVAL) {
        return;
    }

    // 到达发射时间处理
    // 重置发射时间间隔记录
    m_recorder = 0;

    // 发射子弹
    for (int i = 0; i < ENEMY_BULLET_NUM; i++) {
        // 如果子弹是空闲的，则发射
        if (m_bullets[i].m_free == true) {
            // 修改状态
            m_bullets[i].m_free = false;
            // 设置子弹的坐标
            m_bullets[i].m_x = m_x + m_rect.width() * 0.5 - 10;
            m_bullets[i].m_y = m_y + 25;
            break;
        }
    }
}
