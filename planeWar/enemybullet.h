#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include <QPixmap>
#include "config.h"

// 敌机子弹
class EnemyBullet
{
public:
    EnemyBullet();
    // 更新子弹坐标
    void updatePosition();

public:
    // 子弹资源对象
    QPixmap m_bullet;
    // 子弹坐标
    int m_x;
    int m_y;

    // 子弹移动速度
    int m_speed;
    // 子弹是否空闲
    bool m_free;
    // 子弹矩形边框(用于碰撞检测)
    QRect m_rect;

};

#endif // ENEMYBULLET_H
