#include "enemybullet.h"

EnemyBullet::EnemyBullet()
{
    // 加载子弹图片
    m_bullet.load(ENEMY_BULLET_PATH);

    // 子弹坐标，初始值随意设置，后期会重置
    m_x = GAME_WIDTH * 0.5 - m_bullet.width() * 0.5;
    m_y = GAME_HEIGHT;

    // 子弹状态
    m_free = true;

    // 子弹速度
    m_speed = ENEMY_BULLET_SPEED;

    // 子弹矩形框
    m_rect.setWidth(m_bullet.width());
    m_rect.setHeight(m_bullet.height());
    m_rect.moveTo(m_x, m_y);
}

// 更新子弹坐标
void EnemyBullet::updatePosition()
{
    // 如果子弹是空闲状态，不需要计算坐标
    // 玩家飞机可以控制子弹的空闲状态为false
    if (m_free) {
        return;
    }

    m_y += ENEMY_BULLET_SPEED;         // 向下发射子弹
    m_rect.moveTo(m_x, m_y);

    // 越界检查
    if (m_y >= GAME_HEIGHT + m_rect.height()) {
        m_free = true;
    }
}
