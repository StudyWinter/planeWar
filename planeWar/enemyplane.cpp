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
