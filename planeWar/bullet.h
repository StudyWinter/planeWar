#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>


class Bullet
{
public:
    Bullet();
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

#endif // BULLET_H
